import nltk
from nltk.util import trigrams
from nltk.tokenize import word_tokenize

nltk.download('punkt')

text = input("Enter a sentence: ")

tokens = word_tokenize(text)

tri_grams = list(trigrams(tokens))

print("\nGenerated Trigrams:")
for t in tri_grams:
    print(t)


# Natural language processing is very important
