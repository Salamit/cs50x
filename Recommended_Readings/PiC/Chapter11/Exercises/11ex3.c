//Program to insert an element at the beginning of a list

#include <stdio.h>

struct entry 
{
	int 			value;
	struct entry	*next;

}n1, n2, n3, entry, *list_pointer = &n1;

void insertEntry (struct entry *listEntry, struct entry *front_of_list)
{

	//my next points to the first list item.
	listEntry->next = front_of_list;
	list_pointer = listEntry; 
}

int main (void)
{

	n1 = (struct entry)			{100, &n2};
	n2 = (struct entry)			{200, &n3};
	entry = (struct entry)		{230, };
	n3 = (struct entry)			{300, (struct entry *) 0};


	insertEntry (&entry, list_pointer);

	while(list_pointer != (struct entry *) 0 ){
		printf("%i\n", list_pointer->value);
		list_pointer = list_pointer->next;
	}

	return 0;


}