import re

text = input("Enter the text: ")

pattern = r'[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}'

emails = re.findall(pattern, text)

if emails:
    print("Email IDs found:")
    for email in emails:
        print(email)
else:
    print("No Email IDs found")

#Contact us at support@gmail.com or admin123@yahoo.in for help