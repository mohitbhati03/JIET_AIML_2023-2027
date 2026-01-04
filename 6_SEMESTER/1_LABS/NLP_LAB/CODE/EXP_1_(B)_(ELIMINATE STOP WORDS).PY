import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

nltk.download('punkt')
nltk.download('stopwords')

text = input("Enter your text: ")

words = word_tokenize(text)

stop_words = set(stopwords.words('english'))

filtered_words = [word for word in words if word.lower() not in stop_words]

print("\nOriginal Words:")
print(words)

print("\nAfter Removing Stop Words:")
print(filtered_words)



# This is a simple example to show how stopwords are removed.