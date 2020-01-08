from sys import argv
import sys

argc = len(sys.argv)
shift = 0
#count = 0
character = 0


if argc == 2:
    #save the string
    k = (argv[1])
    #Break up string into its letters
    #broken_string = list(k)
    #save string length
    n = len(k)

    for letter in k:
        if letter.isalpha():
            count = 1

        else:
            print("Evil")
            count = 0
            break


    if count == 1:
        plainText = input('> ')

        i = 0
        for p in range(len(plainText)):


            if plainText[p].isalpha():
                i %= n;

                if k[i].isupper():
                    shift = ord(k[i]) - 65

                if k[i].islower():
                    shift = ord(k[i]) - 97


                if plainText[p].isupper():
                    character = chr((((ord(plainText[p]) - 65 + shift) % 26) + 65))
                    print(character, end='')

                if plainText[p].islower():
                    character = character = chr((((ord(plainText[p]) - 97 + shift) % 26) + 97))
                    print(character, end='')

                i += 1

            else:
                print(plainText[p])

        print("")


else:
    print("Evil2!")












