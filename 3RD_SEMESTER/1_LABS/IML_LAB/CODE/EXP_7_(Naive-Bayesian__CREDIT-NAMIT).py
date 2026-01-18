import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import CategoricalNB
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score
data = pd.read_csv(r"D:\1 DO NOT CLICK  [MOHIT]\COLLEGE\1             EXCEL FILE\7     PlayTennis.csv")
print(data.head())
label_encoders = {}
for column in data.columns:
    le = LabelEncoder()
    data[column] = le.fit_transform(data[column])
    label_encoders[column] = le
X = data.drop(columns='Play')
y = data['Play']
print("\nSplitting the data into training and testing sets...")
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
nb_classifier = CategoricalNB()
nb_classifier.fit(X_train, y_train)
y_pred = nb_classifier.predict(X_test)
print(f"Predictions: {y_pred}")
accuracy = accuracy_score(y_test, y_pred)
print(f"\nAccuracy of the classifier: {accuracy * 100:.2f}%")