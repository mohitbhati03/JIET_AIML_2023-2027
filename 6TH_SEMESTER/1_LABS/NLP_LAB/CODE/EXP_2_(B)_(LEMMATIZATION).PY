from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
import nltk

nltk.download('wordnet')
nltk.download('omw-1.4')

lemmatizer = WordNetLemmatizer()

text = input("Enter a sentence: ")

words = word_tokenize(text)

print("\nOriginal Word  ->  Lemmatized Word")
for w in words:
    print(w, " -> ", lemmatizer.lemmatize(w))

# The boys were running and eating better apples.