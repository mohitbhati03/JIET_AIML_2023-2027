import nltk
from nltk import word_tokenize, pos_tag

nltk.download('punkt')
nltk.download('averaged_perceptron_tagger_eng')   

sentence = input("Enter a sentence: ")

words = word_tokenize(sentence)

labels = pos_tag(words)

print("Sequence Labeling Output:")
for word, label in labels:
    print(word, "->", label)
