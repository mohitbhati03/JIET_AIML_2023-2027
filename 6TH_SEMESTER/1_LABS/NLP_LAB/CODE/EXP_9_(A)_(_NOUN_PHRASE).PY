import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag
from nltk import RegexpParser

nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')

sentence = input("Enter a sentence: ")

words = word_tokenize(sentence)

pos_tags = pos_tag(words)

grammar = "NP: {<DT>?<JJ>*<NN>}"

chunk_parser = RegexpParser(grammar)

chunk_tree = chunk_parser.parse(pos_tags)

print("\nPOS Tags:", pos_tags)
print("\nNoun Phrase Chunks:")
chunk_tree.pretty_print()

# The small boy is playing with a red ball