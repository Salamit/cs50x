"""
Mario exercise in Python for pset6 (Ported from c)

This program recreates a half-pyramid found at the link 
above by using hashes for blocks. It first prompts the user 
the half-pyramid's height, a non-negative integer no greater
than 23. Should the user fail to provide a non-negative integer
greater than 23, the user is re-prompted. Upon providing 
/appropriate value, the half-pyramid is build using printf.
"""

#Get user input
half_pyramid_height = -1
while half_pyramid_height > 23 or half_pyramid_height < 0:
	half_pyramid_height = int(input("Height> "))
	

""" 
Plus 1 is needed because take a max height of 3 (assuming that each blank below is a space)
__##
"""
#number of hashes is always initially two and then increments
num_of_hashes = 2
#the max length of a line is always the given height + 1
max_line_length = half_pyramid_height + 1

#The number of spaces is then equals to the max line length minus the number of hashes
init_num_of_spaces = max_line_length - num_of_hashes

range_limit = max_line_length + 1

#TODO: keep prompting till user provides an input between 0 and 23


#loop to create the pyramid
for i in range(0, half_pyramid_height):
	print(" " * init_num_of_spaces, end='')
	init_num_of_spaces -= 1
	print("#" * num_of_hashes)
	num_of_hashes += 1
	#print("\n")




