import re

text = input("Enter the text: ")

pattern = r'\d+'

numbers = re.findall(pattern, text)

if numbers:
    print("Numbers found:")
    for num in numbers:
        print(num)
else:
    print("No numbers found")

#I bought 3 books for 450 rupees on 12th May