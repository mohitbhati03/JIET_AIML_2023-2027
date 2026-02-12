import nltk
from nltk.tokenize import word_tokenize

nltk.download('punkt')

sentence = input("Enter a sentence: ")

sentence = sentence.lower()

words = word_tokenize(sentence)

input_sequences = []
output_words = []

for i in range(len(words) - 1):
    input_sequences.append(words[i])
    output_words.append(words[i + 1])

print("\nInput-Output Sequences for RNN:")
for i in range(len(input_sequences)):
    print("Input:", input_sequences[i], " -> Output:", output_words[i])

# Mohit is studying AI