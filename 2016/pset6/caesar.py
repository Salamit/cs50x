"""Program to encrypt messages using Caesar's cipher.
Program accepts only a single command-line 
argument: non-negative integer"""

character = 0

from sys import argv
import sys
"""
k = int(argv[1])
print(k)
"""

argc = len(sys.argv)

if argc == 2:
    k = int(argv[1])
    plainText = list(input("> "))
    print(k)
    for text in plainText:

        if text.isalpha():
            #print(text, end='')
            #TODO if text isupper and if text islower

            if text.isupper():
                #print(chr((ord(text) + k)))
                character = chr(((ord(text) - 65 + k) % 26) + 65)
                print(character, end='')
            if text.islower():
                character = chr(((ord(text) - 97 + k) % 26) + 97)
                print(character, end='')



        else:
            print(text, end = '')

    print('\n')



else:
    print("You bad person! Your free reign has come to an end.")