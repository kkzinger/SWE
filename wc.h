/*
 * wc.h
 *
 *  Created on: Apr 25, 2014
 *      Author: martin
 */

#ifndef WC_H_
#define WC_H_

#include "list.h"
#include "wc.h"

#include <string.h>		/** to use string-functions **/
#include <stdio.h>
#include <stdlib.h>


void save_to_list(void *, char *, FILE*);
char* getoutputname(char*);
char* set_lower_case(char*);
FILE* openfile_r(char*);
FILE* openfile_w(char*);
void read_strings(FILE*, FILE*);
void write_to_file(FILE*, char*, int);
int in_list(void*, char*);
void incr_in_list(void*, char*);



#endif /* WC_H_ */
