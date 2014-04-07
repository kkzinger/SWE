#include "my_list.h"

//---------------------------------------------------
//			FUNCTIONS
//----------------------------------------------------


HEAD *init_list()	//Function sets up a List Head and returns pointer to list head
{
	HEAD *p;
	NODE *n;

	if((p=(HEAD*)malloc(sizeof(HEAD))) == NULL) return NULL;

	p->length = 0;

	if((n = new_node()) == NULL) return NULL;

	p->first = n;
	p->last = n;
	p->length += 1;

	return p;
}
NODE *new_node()	//Function creates new Node and returns pointer to the new node
{
	NODE *p;

	if((p=(NODE*)malloc(sizeof(NODE))) == NULL) return NULL;

	p->next = NULL;
	p->prev = NULL;
	p->data = NULL;

	return p;
}
int insert_node(HEAD *head, NODE *act, void *data) //Insert node after Act(ual)-Node and returns pointer off new node
{
	NODE *p;

	if(isfirst_node(head))
	{
		head->first->data = data;
		return EXIT_SUCCESS;
	}

	if((p =  new_node()) == NULL) return EXIT_FAILURE;

	p->prev = act;
	p->next = act->next;

	if(act->next != NULL)
	{
		p->next->prev = p;
	}else
	{
		head->last = p;
	}

	act->next = p;
	p->data = data;

	head->length +=1;

	return EXIT_SUCCESS;
}
int append_back(HEAD *head, void *data) //Appends Node at back end of the list
{

	NODE *p;

	if(isfirst_node(head))
	{
		head->first->data = data;
		return EXIT_SUCCESS;
	}

	if((p =  new_node()) == NULL) return EXIT_FAILURE;

	p->prev = head->last;
	head->last->next = p;
	head->last = p;
	p->data = data;

	head->length +=1;

	return EXIT_SUCCESS;
}
int append_front(HEAD *head, void *data)	//Appends Node at front of the list
{
	NODE *p;

	if(isfirst_node(head))
	{
		head->first->data = data;
		return EXIT_SUCCESS;
	}

	if((p = new_node()) == NULL) return EXIT_FAILURE;

	p->next = head->first;
	head->first->prev = p;
	head->first = p;
	p->data = data;

	head->length +=1;

	return EXIT_SUCCESS;
}

void print_list(HEAD *head)	//prints whole list
{
	NODE *p;
	int i = 0;

	p = head->first;

	printf("------------------------------\n------------------------------\n\n");
	printf("----- HEAD -----\n",i);
	printf("Adress: %p\n",head);
	printf("First:   %p\n",head->first);
	printf("Last:   %p\n",head->last);
	printf("Length:   %d\n\n",head->length);

	while(p->next != NULL)
	{

		printf("----- NODE - %d -----\n",i);
		printf("Adress: %p\n",p);
		printf("Next:   %p\n",p->next);
		printf("Prev:   %p\n",p->prev);
		printf("Data:   %p\n\n",p->data);

		p = p->next;
		i += 1;
	}

	printf("----- NODE - %d -----\n",i);
	printf("Adress: %p\n",p);
	printf("Next:   %p\n",p->next);
	printf("Prev:   %p\n",p->prev);
	printf("Data:   %p\n\n",p->data);
}
int isfirst_node(HEAD *head)	//Check if there is only one empty node in list. Like the situation after init_list
{
	if((head->first == head->last) && (head->first->data == NULL)) return 1;

	return 0;
}
