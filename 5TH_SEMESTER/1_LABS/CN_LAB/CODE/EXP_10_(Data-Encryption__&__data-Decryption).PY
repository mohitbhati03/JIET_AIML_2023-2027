def caesar_cipher(text, key):
    result = ""
    for ch in text:
        if ch.islower(): 
            result += chr((ord(ch) - ord('a') + key) % 26 + ord('a'))
        elif ch.isupper():  
            result += chr((ord(ch) - ord('A') + key) % 26 + ord('A'))
        elif ch.isdigit(): 
            result += chr((ord(ch) - ord('0') + key) % 10 + ord('0'))
        else:  
            return "Invalid Message"
    return result

text = input("Enter a message to encrypt: ")
key = int(input("Enter the key: "))

encrypted = caesar_cipher(text, key)
print("Encrypted message:", encrypted)
