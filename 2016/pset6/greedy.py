"""
Time for Change exercise for pset1 from cs50: http://goo.gl/MLYo8g
File greedy.py 

This program first asks the user how much change is owed 
and then spits out the minimum number of coins
with which said change can be made. 
"""
import math


quarter = 25
dime = 10
nickel = 5
penny = 1
change_owed = -1
#quarter coins
qc = 0
#dime coins
dc = 0
#nickel coins
nc = 0
#penny coins
pc = 0
#placeholder for coin count
c = 0


while change_owed <= 0:
	change_owed = float(input("O hai! How much change is owed?: "))

#TODO include a main function?

change = round((change_owed * 100))

if change/quarter >= 1:
    qc = change//quarter
    change %= quarter
    c += qc
    print(c)

if change/dime >= 1:
    dc = change//dime
    change %= dime
    c += dc
    print(c)

if change/nickel >= 1:
    nc = change//nickel
    change %= nickel
    c += nc
    print(c)

if change/penny >= 1:
    pc = change//penny
    change %= penny
    c += pc
    print(c)


print(change_owed)

print(c)