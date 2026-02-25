import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag
from nltk import RegexpParser

nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')

sentence = input("Enter a sentence: ")

words = word_tokenize(sentence)

pos_tags = pos_tag(words)

grammar = r"""
  NP: {<DT>?<JJ>*<NN>}      
  VP: {<VB.*><NP|PP>*}       
"""

chunk_parser = RegexpParser(grammar)

chunk_tree = chunk_parser.parse(pos_tags)

print("\nPOS Tags:", pos_tags)
print("\nChunk Tree:")
chunk_tree.pretty_print()

# The small boy eats a red apple