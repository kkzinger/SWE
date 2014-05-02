/*
 * main.c
 *
 *  Created on: Apr 25, 2014
 *      Author: martin
 */

#include "wc.h"
#include "list.h"


int main(int argc, char **argv){

	if(argc<2){
		printf("\nUsage: ./count_words file.txt");
		return EXIT_FAILURE;
	}

	char *in_name = argv[1];


	/*** open files ***/
	FILE *fp_input = openfile_r(argv[1]);
	FILE *fp_output = openfile_w(getoutputname(in_name));


	/*** read from File, (word after word), set it lower-case and save it to structure***/
	read_strings(fp_input, fp_output);


	/*** close the files ***/
	fclose(fp_input);
	fclose(fp_output);

	return EXIT_SUCCESS;
}

