//Program to implement and print a double linked list 

#include <stdio.h>

struct entry
{
	int 				value;
	struct entry		*previous;
	struct entry		*next;
	

}n1, n2, n3, *list_pointer = &n1;

int main(void)
{
	n1.value = 100;
	n1.next = &n2;
	n2 = (struct entry)		{200, &n1, &n3};
	n3 = (struct entry)		{300, &n2, (struct entry*) 0};

	while (list_pointer != (struct entry *) 0 ) {
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}

	return 0;
}