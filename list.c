/*
 * list.c
 *
 *  Created on: Mar 30, 2014
 *      Author: martin
 */

#include "list.h"

S_LIST * new_list(){
	S_LIST *new = (S_LIST *)malloc(sizeof(S_LIST));

	new->first = NULL;
	new->last = NULL;

	new->num_Elemtents = 0;

	return new;
}


int insert_first(S_LIST *list, char *to_insert){

	printf("\nInsert_First");

	S_ELEM *new;
	new = malloc( sizeof(S_ELEM) );	/* create new list-element */

	printf("--Elem created");
	if(new == NULL){
		//printf("\new == NULL");
		return EXIT_FAILURE;
	}
	printf("tütütütüüüü");

	printf("--Elem created");

	new->data->word = to_insert;
	new->data->number_of_appearence = 0;
	new->prev = NULL;

	printf("\nELEM written");

	if(list->first == NULL){
		new->next = NULL;
		list->last = new;
		list->first = new;
	}else{
		list->first->prev = new;
		new->next = list->first;
		list->first = new;
	}

	list->num_Elemtents++;

	printf("\nlala, kaka");
	printf("\nElem -1");

	return EXIT_SUCCESS;
}



int insert_last (S_LIST *list, char *to_insert){

	S_ELEM *new = (S_ELEM *)malloc(sizeof(S_ELEM));	/* create new list-element */
	if(new == NULL)
		return -1;

	new->data->word = to_insert;
	new->data->number_of_appearence = 0;
	new->next = NULL;

	if(list->last == NULL){
		new->prev = NULL;
		list->first = new;
		list->last = new;
	}else{
		list->last->next = new;
		new->prev = list->last;
		list->last = new;
	}

	list->num_Elemtents++;

	return 0;
}


int delete_first(S_LIST * list){

	if(list->num_Elemtents == 0)
		return -1;

	S_ELEM *to_delete = list->first;

	if(list->num_Elemtents == 1){
		list->last = NULL;
		list->first = NULL;
	} else {
		list->first->next->prev = NULL;
		list->first = list->first->next;
	}

	free(to_delete->data->word);
	free(to_delete->data);
	free(to_delete);

	list->num_Elemtents--;

	return 0;
}


int delete_last(S_LIST * list){

	if(list->num_Elemtents == 0)
		return -1;

	S_ELEM *to_delete = list->last;

	if(list->num_Elemtents == 1){
		list->last = NULL;
		list->first = NULL;
	} else {
		list->last->prev->next = NULL;
		list->last = list->last->prev;
	}

	free(to_delete->data->word);
	free(to_delete->data);
	free(to_delete);

	list->num_Elemtents--;

	return 0;
}

