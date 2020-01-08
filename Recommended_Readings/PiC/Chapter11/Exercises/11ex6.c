//Program to insert an Entry and remove an Entry in a doubly linked list

#include <stdio.h>

struct entry 
{
	struct entry 		*previous;
	int 				value;
	struct entry 		*next;
	


}n1, n2, n3, entry, *list_pointer = &n1;

void insertEntry (struct entry *listEntry, struct entry *front_of_list)
{
	listEntry->next = front_of_list;
	list_pointer = listEntry;
}
void removeEntry(struct entry *removed_entry)
{	//Got help for this here: http://bit.ly/benbrandtkochan11ex6
	struct entry *prvEntry, *nextEntry;

	prvEntry = removed_entry->previous;
	nextEntry = removed_entry->next;

	prvEntry->next = removed_entry->next;
	nextEntry->previous = removed_entry->previous;


}

int main(void)
{
	//n1.value = 100;
	//n1.next = &n2;
	n1 = (struct entry)		{(struct entry*) 0, 100, &n2};
	n2 = (struct entry)		{&n1, 200, &n3};
	n3 = (struct entry)		{&n2, 300, (struct entry*) 0};

	removeEntry(&n2);

	while (list_pointer != (struct entry *) 0 ){
		printf("%i\n", list_pointer -> value);
		list_pointer = list_pointer->next;
	}

	return 0;
}