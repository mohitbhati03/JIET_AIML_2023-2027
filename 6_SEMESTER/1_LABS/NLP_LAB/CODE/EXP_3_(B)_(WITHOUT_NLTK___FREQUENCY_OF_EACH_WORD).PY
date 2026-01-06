text = input("Enter text: ")

words = text.lower().split()
freq = {}

for word in words:
    freq[word] = freq.get(word, 0) + 1

print("Word Frequency:")
for word, count in freq.items():
    print(word, ":", count)



# This is a test. This test is easy.