/*
 * list.h
 *
 *  Created on: Mar 30, 2014
 *      Author: martin
 */

#ifndef LIST_H_
#define LIST_H_


#include "list.h"
#include "wc.h"

#include <string.h>		/** to use string-functions **/
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char *word;
	int number_of_appearence;
}S_WORDS;


struct list_elem {
	struct list_elem	*next,		/* pointer to the next element */
						*prev;		/* pointer to the previous element */

	S_WORDS *data;

};
typedef struct list_elem S_ELEM;


typedef struct list_head {
	int num_Elemtents;

	S_ELEM 	*first,	/* position of the first element in the list */
			*last;	/* position of the last element in the list */
} S_LIST;


S_LIST * new_list();
int insert_first (S_LIST * , char *);
int insert_last (S_LIST *, char *);
int delete_first (S_LIST *);
int delete_last (S_LIST *);


#endif /* LIST_H_ */
