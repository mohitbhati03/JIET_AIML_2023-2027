from nltk.stem import PorterStemmer

ps = PorterStemmer()

text = input("Enter a sentence: ")

words = text.lower().split()

freq = {}

for word in words:
    stem = ps.stem(word)

    if stem in freq:
        freq[stem] += 1
    else:
        freq[stem] = 1

print("\nStem Frequency:\n")

for stem in freq:
    print(stem, ":", freq[stem])

# Running runs running eating eats