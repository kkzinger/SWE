/*

	file: my_list.h
	author:	G.Katzinger
	date: 01.04.14

*/
#ifndef MY_LIST_H
#define MY_LIST_H



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
typedef struct list_node NODE;

struct list_head
{
	int length;
	NODE *first;
	NODE *last;

};
typedef struct list_head HEAD;

//----------------------------------------------------
//		FUNCTION - PROTOTYPES
//----------------------------------------------------

HEAD *init_list();	//Function sets up a List Head and returns pointer to list head
NODE *new_node();	//Function creates new Node and returns pointer to the new node
int insert_node(HEAD *head, NODE *act, void *data);	 //Insert node after lAct-Node and returns pointer off new node
int append_back(HEAD *head, void *data);	 //Appends Node at back end of the list
int append_front(HEAD *head, void *data);	//Appends Node at front of the list
void print_list(HEAD *head);	//prints whole list
int isfirst_node(HEAD *head);	//Check if there is only one empty node in list. Like the situation after init_list
int del_node(HEAD *head, NODE *act);     //Delete act(ual) node and set the corect pointers at neighbor nodes and head
int del_list(HEAD *head);        //Delete whole list, free all allocated memory



#endif
