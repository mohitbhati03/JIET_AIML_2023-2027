import nltk
from nltk.tokenize import word_tokenize
from nltk.util import bigrams
from nltk.probability import FreqDist

nltk.download('punkt')

text = input("Enter a sentence: ")

tokens = word_tokenize(text.lower())

bigram_list = list(bigrams(tokens))

freq_table = FreqDist(bigram_list)

print("\nBigram Frequency Table:")
for bg, freq in freq_table.items():
    print(f"{bg} : {freq}")
