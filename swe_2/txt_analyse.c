//---------------------------------------------------
//
//	file: txt_analyse.c
//	author: G.Katzinger
//	date: 16.04.2014
//
//---------------------------------------------------

#include "my_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1000

struct word_stat
{
	char *word;
	double cnt;
};
typedef struct word_stat WSTAT;


//-------------- Function Prototypes -------------------------

int txt_analyse(HEAD *head, char *file_path);

//------------------------------------------------------------


int main(int argc, char **argv)
{
	int i, modus=0;
	char *filepath_source = NULL,*filepath_result = NULL;
	HEAD *list_pt;
	//Read programm parameters

	if(argc <= 1)
        {
                fprintf(stderr,"To few options for function!");
                return EXIT_FAILURE;
        }

	for(i=1;i<argc;i++)
        {
                if(strcmp(argv[i],"-f") == 0) //Sourcefile path
                {
                        i++;
                        filepath_source = (char*) malloc(strlen(argv[i]));
                        filepath_source = argv[i];

                }else if(strcmp(argv[i],"-o") == 0) //Option if Output should be stored in File
                {
                        i++;
                        filepath_result = (char*) malloc(strlen(argv[i]));
                        filepath_result = argv[i];
                        modus = 1;

                }

        }

	if((list_pt = init_list()) == NULL) 
	{
		fprintf(stderr,"Failed to init List Header\n");
		return EXIT_FAILURE;
	}
	if(txt_analyse(list_pt,filepath_source) == EXIT_FAILURE)
	{
		fprintf(stderr,"Failed to analyse text\n");
		return EXIT_FAILURE;
	}

	print_list(list_pt);

	return EXIT_SUCCESS;
}

int txt_analyse(HEAD *head, char *file_path)
{
	FILE *fp;
	char *buf,*buf_ptr;
	char delimiter[] = " ., :;";
	int flag = 0, first_run;
	size_t len;
	WSTAT *data_ptr;
	NODE *node_ptr;


	if((buf = (char*)malloc(BUFF_SIZE)) == NULL) return EXIT_FAILURE;
	if((fp = fopen(file_path,"r")) == NULL) return EXIT_FAILURE;

//	printf("head: %p\n",head);
//	printf("head->first: %p\n",head->first);

	while(fgets(buf,BUFF_SIZE,fp))
	{
		len = strlen(buf);
		buf[len-1]='\0';
		buf_ptr = strtok(buf,delimiter);
		first_run = 1;
		while(buf_ptr != NULL)
		{

			if(first_run != 1)
			{
				printf("head->first: %p\n",head->first);
				node_ptr = head->first;
				do
				{
					if((strcmp(((WSTAT*)node_ptr->data)->word,buf_ptr)) == 0)
					{
						((WSTAT*)node_ptr->data)->cnt++;
						flag = 1;
					}
					node_ptr = node_ptr->next;

				}while(node_ptr != NULL);
			}
			if(flag == 0)
			{
				if((data_ptr = (WSTAT*)malloc(sizeof(WSTAT))) == NULL) return EXIT_FAILURE;
				data_ptr->cnt = 1;
				if((data_ptr->word = (char*)malloc(strlen(buf_ptr))) == NULL) return EXIT_FAILURE;

				strcpy(data_ptr->word,buf_ptr);

				if((append_front(head,data_ptr)) == EXIT_FAILURE) return EXIT_FAILURE;
			}
			buf_ptr = strtok(NULL,delimiter);
			flag = 0;
			first_run = 0;
		}
	}
	fclose(fp);
	free(buf);
	return EXIT_SUCCESS;
}
int print_result(HEAD *head, int modus, char *path) //Print Function, modus 0 - print in File modus - 1 print in stdout
{
	NODE *p;
	FILE *fp, *output = stdout;

	p = head->first;

	if(modus == 0)
	{
		if(path != NULL)
		{
			fopen(fp,path,"w");
		}else
		{
			fopen(fp,"txt_result.txt","w");
		}
		output = fp;
	}


	while(p-next != NULL)
	{
		//fprintf(output,"%s: %d\n",

	}


	return EXIT_SUCCESS;
}

