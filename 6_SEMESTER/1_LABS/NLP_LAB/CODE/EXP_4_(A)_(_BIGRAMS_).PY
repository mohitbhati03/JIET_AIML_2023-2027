import nltk
from nltk.util import bigrams
from nltk.tokenize import word_tokenize

nltk.download('punkt')

text = input("Enter a sentence: ")

tokens = word_tokenize(text)

print("\nTokens:")
print(tokens)

bigram_list = list(bigrams(tokens))

print("\nBigrams:")
for bg in bigram_list:
    print(bg)
