//Program to remove an entry from a linked list.

#include <stdio.h>

struct entry
{
	int 			value;
	struct entry	*next;
}n1, n2, n3, *list_pointer = &n1;

void removeEntry(struct entry *listPointer)
{
	
	listPointer->next = (&n2)->next;
	//(&n1)->next = listPointer->next;


}

int main(void)
{
	n1 = (struct entry)		{100, &n2};
	n2 = (struct entry)		{200, &n3};
	n3 = (struct entry)		{300, (struct entry*) 0};

	removeEntry(list_pointer);
	//removeEntry(&n2);


	while(list_pointer != (struct entry *)0){
		printf("%i\n", list_pointer->value);
		list_pointer = list_pointer->next;
	}

	return 0;
}