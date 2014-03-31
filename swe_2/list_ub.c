#include <stdlib.h>
#include <stdio.h>

//-----------------------------------------------------
//			STRUCTS
//----------------------------------------------------
struct list_node
{
	struct list_node *next;
	struct list_node *prev;

	void *data;

};
typedef struct list_node node;

struct list_head
{
	int length;
	node *first;
	node *last;

};
typedef struct list_head head;

//----------------------------------------------------
//		FUNCTION - PROTOTYPES
//----------------------------------------------------

head *init_list();	//Function sets up a List Head and returns pointer to list head
node *new_node();	//Function creates new Node and returns pointer to the new node
int insert_node(head *head, node *act, void *data);	 //Insert node after lAct-Node and returns pointer off new node
int append_back(head *head, void *data);	 //Appends Node at back end of the list
int append_front(head *head, void *data);	//Appends Node at front of the list
void print_list(head *head);	//prints whole list
int isfirst_node(head *head);	//Check if there is only one empty node in list. Like the situation after init_list

//----------------------------------------------------
//			MAIN
//----------------------------------------------------

int main()
{
	head *head;
	int a=15,b=10, c=23;
	int *ptra, *ptrb, *ptrc;

	ptra = &a;
	ptrb = &b;
	ptrc = &c;


	if((head=init_list()) == NULL)
	{
		fprintf(stdout,"Error at list_init()");
		return EXIT_FAILURE;
	}


	print_list(head);
	append_front(head,ptra);
	print_list(head);
	append_back(head,ptrb);
	print_list(head);
	insert_node(head,head->first,ptrc);
	print_list(head);
	insert_node(head,head->last,ptrc);
	print_list(head);

	printf("DATA: %d",*((int*)head->first->data));

	return 0;
}

//---------------------------------------------------
//			FUNCTIONS
//----------------------------------------------------


head *init_list()	//Function sets up a List Head and returns pointer to list head
{
	head *p;
	node *n;

	if((p=(head*)malloc(sizeof(head))) == NULL) return NULL;

	p->length = 0;

	if((n = new_node()) == NULL) return NULL;

	p->first = n;
	p->last = n;
	p->length += 1;

	return p;
}

node *new_node()	//Function creates new Node and returns pointer to the new node
{
	node *p;

	if((p=(node*)malloc(sizeof(node))) == NULL) return NULL;

	p->next = NULL;
	p->prev = NULL;
	p->data = NULL;

	return p;
}
int insert_node(head *head, node *act, void *data) //Insert node after Act(ual)-Node and returns pointer off new node
{
	node *p;

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
int append_back(head *head, void *data) //Appends Node at back end of the list
{

	node *p;

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
int append_front(head *head, void *data)	//Appends Node at front of the list
{
	node *p;

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

void print_list(head *head)	//prints whole list
{
	node *p;
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
int isfirst_node(head *head)	//Check if there is only one empty node in list. Like the situation after init_list
{
	if((head->first == head->last) && (head->first->data == NULL)) return 1;

	return 0;
}
