//Program to hold a funciton that inserts an entry into a linked list. 

#include <stdio.h>

struct entry
{
	int 		 value;
	struct entry *next;

} n1, n2, n2_3, n3, *list_pointer = &n1;


void insertEntry (struct entry *listEntry, struct entry *after_this_entry)
{

	//insert entry into linked list
	//n2_3.next = n2.next;
	listEntry->next = after_this_entry->next;
	//n2.next = &n2_3;
	after_this_entry->next = listEntry;

}



int main (void)
{


	//int i;

	//need a beginning listStartpointer?
	n1 = (struct entry) 	{100, &n2};
	n2 = (struct entry) 	{200, &n3};
	n2_3 = (struct entry)	{230, };
	n3 = (struct entry) {300, (struct entry *) 0};


	//n1.value = 100;
	//n2.value = 200;
	//n3.value = 300;

	//n1.next = &n2;
	//n2.next = &n3;
	//n3.next = (struct entry *) 0;

	//loop through printing the list


	printf("Values before using the insertEntry function\n");
	while (list_pointer != (struct entry *) 0 ) {
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}
	printf("\n");

	list_pointer = &n1;

	insertEntry (&n2_3, &n2);
	
	/*
	n2_3.next = n2.next;
	n2.next = &n2_3;

	*/

	printf("Values after using the insertEntry function\n");
	while (list_pointer != (struct entry *) 0 ) {
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}

	return 0;





	

}