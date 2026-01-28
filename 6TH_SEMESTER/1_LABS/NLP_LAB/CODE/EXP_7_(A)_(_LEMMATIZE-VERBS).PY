import nltk
from nltk.stem import WordNetLemmatizer
from nltk.corpus import wordnet

lemmatizer = WordNetLemmatizer()

sentence = input("Enter a sentence: ")

words = sentence.split()

print("\nLemmatized Verbs:\n")

for word in words:
    lemma = lemmatizer.lemmatize(word, pos=wordnet.VERB)
    print(word, "→", lemma)

# I am running and eating food