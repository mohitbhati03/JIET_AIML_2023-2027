import nltk
from nltk.corpus import wordnet as wn

nltk.download('wordnet')

word = input("Enter a word: ")

synsets = wn.synsets(word)

print("All synsets of", word, ":")

for syn in synsets:
    print("Synset Name:", syn.name())
    print("Definition :", syn.definition())
    print("Examples   :", syn.examples())
    print()

# bank