import cv2
import os
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential, load_model
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout
from tensorflow.keras.preprocessing.image import ImageDataGenerator, img_to_array


# -----------------------------
# SETTINGS
# -----------------------------
IMG_SIZE = 128
DATASET_PATH = "dataset/train"
MODEL_PATH = "face_cnn_model.h5"

AUTO_IMAGES = 25
EPOCHS = 15


# -----------------------------
# STEP 1: AUTO FACE CAPTURE
# -----------------------------
def collect_data():

    name = input("Enter Your Name: ")

    save_path = os.path.join(DATASET_PATH, name)
    os.makedirs(save_path, exist_ok=True)

    cam = cv2.VideoCapture(0)

    face_detector = cv2.CascadeClassifier(
        cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
    )

    count = 0

    print("\nAuto Capture Started... Look at Camera")

    while True:

        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = face_detector.detectMultiScale(gray,1.3,5)

        for (x,y,w,h) in faces:

            cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)

            face = frame[y:y+h, x:x+w]
            face = cv2.resize(face,(IMG_SIZE,IMG_SIZE))

            if count < AUTO_IMAGES:

                file_name = os.path.join(
                    save_path, f"{name}_{count}.jpg"
                )

                cv2.imwrite(file_name, face)

                count += 1

                print("Saved:", count)

                cv2.waitKey(150)   # delay


        cv2.imshow("Auto Face Capture", frame)

        if count >= AUTO_IMAGES:
            print("Auto Capture Completed!")
            break

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


    cam.release()
    cv2.destroyAllWindows()

    print("Total Images Saved:", count)



# -----------------------------
# STEP 2: TRAIN CNN MODEL
# -----------------------------
def train_model():

    datagen = ImageDataGenerator(
        rescale=1./255,
        zoom_range=0.2,
        horizontal_flip=True
    )

    train_data = datagen.flow_from_directory(
        DATASET_PATH,
        target_size=(IMG_SIZE, IMG_SIZE),
        batch_size=32,
        class_mode="categorical"
    )

    num_classes = train_data.num_classes

    model = Sequential()

    model.add(Conv2D(32,(3,3),activation="relu",
                     input_shape=(IMG_SIZE,IMG_SIZE,3)))
    model.add(MaxPooling2D(2,2))

    model.add(Conv2D(64,(3,3),activation="relu"))
    model.add(MaxPooling2D(2,2))

    model.add(Conv2D(128,(3,3),activation="relu"))
    model.add(MaxPooling2D(2,2))

    model.add(Flatten())

    model.add(Dense(256,activation="relu"))
    model.add(Dropout(0.5))

    model.add(Dense(num_classes,activation="softmax"))

    model.compile(
        optimizer="adam",
        loss="categorical_crossentropy",
        metrics=["accuracy"]
    )

    print("\nTraining Started...")

    model.fit(train_data, epochs=EPOCHS)

    model.save(MODEL_PATH)

    print("Model Saved:", MODEL_PATH)



# -----------------------------
# STEP 3: LIVE FACE RECOGNITION
# -----------------------------
def recognize_face():

    model = load_model(MODEL_PATH)

    class_names = os.listdir(DATASET_PATH)

    cam = cv2.VideoCapture(0)

    face_detector = cv2.CascadeClassifier(
        cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
    )

    print("\nPress Q to Quit")

    while True:

        ret, frame = cam.read()
        if not ret:
            break

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = face_detector.detectMultiScale(gray,1.3,5)

        for (x,y,w,h) in faces:

            face = frame[y:y+h, x:x+w]
            face = cv2.resize(face,(IMG_SIZE,IMG_SIZE))
            face = img_to_array(face)/255.0
            face = np.expand_dims(face,axis=0)

            pred = model.predict(face, verbose=0)

            index = np.argmax(pred)
            name = class_names[index]
            conf = np.max(pred)*100

            text = f"{name} ({conf:.1f}%)"

            cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)
            cv2.putText(frame,text,(x,y-10),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.8,(0,255,0),2)

        cv2.imshow("Face Recognition",frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


    cam.release()
    cv2.destroyAllWindows()



# -----------------------------
# MAIN MENU
# -----------------------------
while True:

    print("\n--- FACE RECOGNITION CNN PROJECT ---")
    print("1. Auto Collect Face Data (25 Photos)")
    print("2. Train Model")
    print("3. Start Recognition")
    print("4. Exit")

    choice = input("Enter Choice: ")

    if choice == "1":
        collect_data()

    elif choice == "2":
        train_model()

    elif choice == "3":
        recognize_face()

    elif choice == "4":
        break

    else:
        print("Invalid Choice")
