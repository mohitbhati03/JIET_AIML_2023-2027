from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize

ps = PorterStemmer()

text = input("Enter a sentence: ")

words = word_tokenize(text)

print("\nOriginal Word  ->  Stemmed Word")
for w in words:
    print(w, " -> ", ps.stem(w))

# Running runs runner easily connected connections