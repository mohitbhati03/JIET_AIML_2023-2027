import nltk
from nltk.corpus import wordnet as wn

nltk.download('wordnet')

word = input("Enter a word: ")

synonyms = set()

for syn in wn.synsets(word):
    for lemma in syn.lemmas():
        synonyms.add(lemma.name())

print("Synonyms of", word, "are:")
for s in synonyms:
    print(s)

# happy