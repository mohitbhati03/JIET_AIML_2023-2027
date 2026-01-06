import nltk
from nltk.util import trigrams
from nltk.tokenize import word_tokenize
from nltk.probability import FreqDist

nltk.download('punkt')

text = input("Enter a sentence: ")

tokens = word_tokenize(text)

tri_grams = list(trigrams(tokens))

freq_dist = FreqDist(tri_grams)

print("\nTrigram Frequency Table:")
for trigram, freq in freq_dist.items():
    print(trigram, ":", freq)


# Natural language processing is very important