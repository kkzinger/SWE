	#include <stdlib.h>
	#include <stdio.h>

	/*------------------ STRUCTS --------------------*/

	struct list_node
	{
        	struct list_node *next;
       		struct list_node *prev;

        	int *data;

	};
	typedef struct list_node NODE;

	struct list_head
	{
	        int length;
	        NODE *first;
      		NODE *last;

	};
	typedef struct list_head HEAD;



	/*------------------------------------------------
	--------------------- MAIN --------------------
	-----------------------------------------------*/

	int main()
	{
		HEAD *list;

		if((list = init()) == NULL) printf("FEHLER");;

		return EXIT_SUCCESS;
	}

	HEAD *init()
	{
		HEAD *h_list;

		if((h_list = (HEAD*)malloc(sizeof(HEAD))) == NULL) return NULL;

		h_list->first = NULL;
		h_list->last = NULL;
		h_list->length = 0;

		return h_list;
	}

	NODE *new_node()
	{
		NODE *n_list;

		if((n_list = (NODE*)malloc(sizeof(NODE))) == NULL) return NULL;

		n_list->next = NULL;
		n_list->prev = NULL;

		n_list->data = NULL;

		return n_list;
	}

	int append_front(HEAD *xyz,int *d)
	{
		NODE *n;
		n = new_node();

		if(xyz->length == 0)
		{
			n->data = d;
			xyz->first = xyz->last = n;
			xyz->length ++;
			return EXIT_SUCCESS;
		}

		n->prev = NULL;
		n->next = xyz->first;
		n->data = d;
		xyz->first->prev = n;
		xyz->first = n;

		xyz->length ++;
		return EXIT_SUCCESS;
	}
