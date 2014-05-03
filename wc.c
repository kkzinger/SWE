/*
 * wc.c
 *
 *  Created on: Apr 25, 2014
 *      Author: martin
 */


#include "wc.h"


/*************************************************************
 * getoutputname
 *
 * Parameters:	Filename of the input
 * Return:		Filename of the output
 *
 * Function:
 * 		appends on the filename of the inputfile a string
 * 		to identify the outputfile.
 *
 ************************************************************/
char* getoutputname(char *inputname){
	char append[] = "_out.txt";
	int dot_pos = 0;

	dot_pos = strcspn(inputname, ".");	/** looks for '.' in the string **/
	if(dot_pos == 0)
	{
		printf("\n\nERROR: Filename unusable\n\n");
		return EXIT_FAILURE;
	}

	char *outputname = (char*) malloc( sizeof(char) *  (strlen(inputname) +strlen(append)) );
	if(outputname ==NULL)
		{
			printf("\n\nERROR: Filename could not be created\n\n");
			return EXIT_FAILURE;
		}

	strncpy(outputname, inputname, dot_pos);
	strcat(outputname, append);

	return outputname;
}

/*************************************************************
 * set_lower_case
 *
 * Parameters:	string
 * Return:		string
 *
 * Function:
 * 		sets all letters of the string to lower-case
 *
 ************************************************************/

char* set_lower_case(char *word){
	int i=0;

	for(i = 0; word[i]; i++)
		word[i] = tolower(word[i]);

	return word;
}


/*************************************************************
 * openfile_r openfile_w
 *
 * Parameters:	Filename
 * Return:		Filepointer
 *
 * Function:
 * 		opens the give in r(ead) or w(rite) mode
 *
 ************************************************************/
FILE* openfile_r(char *name){

	FILE *fp;
	fp = fopen(name, "r");
	if(fp == NULL)
	{
		printf("ERROR: File could not get opened.");
		return EXIT_FAILURE;
	}
	return fp;
}

FILE* openfile_w(char *name){
	FILE *fp;
		fp = fopen(name, "w");
		if(fp == NULL)
		{
			printf("ERROR: File could not get opened.");
			return EXIT_FAILURE;
		}
		return fp;
}


/*************************************************************
 * read_strings
 *
 * Parameters:	Filepointer
 * Return:		void
 *
 * Function:
 * 		reads from the filepointer word by word, separated
 * 		by the 'to_cut' string
 *
 ************************************************************/
void read_strings(FILE* fp, FILE *fp_out){;
	S_LIST *string_list = new_list();

	int line_cnt_max = 500;
	char line[line_cnt_max];
	char *word;

	char *to_cut = "\n\t . , - ( ) % $ § \" \' # ";

	while(!feof(fp))
	{
		fgets(line, line_cnt_max, fp);
		set_lower_case(line);
		word =strtok(line, to_cut);
		while(word != NULL){
			save_to_list((void*)string_list, word, fp_out);
			word = strtok(NULL, to_cut);
		}
	}
}

/*************************************************************
 * save_to_list
 *
 * Paramters:	- List-Header
 * 				- string to save
 * 				- Filepointer of the outputfile
 * Return:		void
 *
 * Function:
 * 		decides to save a string into a own structure or if
 * 		a structure with this string is already existing
 *
 ************************************************************/
void save_to_list(void *string_list, char *to_save, FILE *fp){
	int status = in_list(string_list, to_save);

	if(status == EXIT_SUCCESS){
		printf("\nif");
		incr_in_list(string_list, to_save);
	}else{
		printf("\nelse");
		printf("\n%p %p %d", ((S_LIST*)string_list)->first, ((S_LIST*)string_list)->last, ((S_LIST*)string_list)->num_Elemtents++);
		status = insert_first(string_list, to_save);
	}

	//write_to_file(fp, to_save,  status);
}


/*************************************************************
 * write_to_file
 *
 * Parameters:	- Filepointer to the outputfile
 * 				- string to save
 * 				- number of appearance
 * Return:		void
 *
 * Function:
 * 		writes the given string with the number of appearence
 * 		into the filepointer
 *
 ************************************************************/
void write_to_file(FILE *fp, char* word, int app){



	fprintf(fp,"\n%s \t\t%d", word, app);
}

/*************************************************************
 * in_list
 *
 * Parameters:	- List-Header
 * 				- string to save
 * Return:		void
 *
 * Function:
 * 		search if string is already stored in a struct
 *
 ************************************************************/
int in_list(void* string_list, char *to_save){

	S_ELEM *struct_elem = ((S_LIST*)string_list)->first;

	while(struct_elem != NULL){
		if (strcmp(struct_elem->data->word, to_save) )
			return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

/*************************************************************
 * incr_in_list
 *
 * Parameters:	- List-Header
 * 				- string to save
 * Return:		void
 *
 * Function:
 * 		increases the number ofappearence in the struct
 *
 ************************************************************/
void incr_in_list(void* string_list, char *to_save){

	S_ELEM *struct_elem = ((S_LIST*)string_list)->first;

	while(struct_elem != NULL){
		if (strcmp(struct_elem->data->word, to_save) )
			struct_elem->data->number_of_appearence++;
	}
}

