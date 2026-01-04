import nltk
from nltk.tokenize import word_tokenize, sent_tokenize

nltk.download('punkt')

text = input("Enter your text: ")

sentences = sent_tokenize(text)
print("\nSentence Tokens:")
for s in sentences:
    print(s)

words = word_tokenize(text)
print("\nWord Tokens:")
print(words)



# I love Python. It is very easy to learn.
