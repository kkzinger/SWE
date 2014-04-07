/*
	File: ceasar_cipher.c
	Author: G. Katzinger
	Date 07.04.2014
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char **argv)
{
	int i, d, shift_len;
	char *filepath_source, *filepath_result;
	FILE *fp_source, *fp_result;
	printf("argc %d\n",argc);

	filepath_result = (char*) malloc(50);
	strcpy(filepath_result,"result.txt");

	if(argc <= 1)
	{
		fprintf(stderr,"To few options for function!");
		return EXIT_FAILURE;
	}
	printf("%s\n",argv[2]);

	for(i=1;i<argc;i++)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			i++;
			filepath_source = (char*) malloc(strlen(argv[i]));
			filepath_source = argv[i];

		}else if(strcmp(argv[i],"-s") == 0)
		{
			i++;
			shift_len = atoi(argv[i]) % 26;
		}

	}

	printf("filepath: %s \nshift_len: %d\n",filepath_source,shift_len);

	fp_source = fopen(filepath_source, "r");
	fp_result = fopen(filepath_result, "w");

	while((d=fgetc(fp_source))!=EOF)	//Scan file and count number of lines
	{
		if(d >=65 && d <=90)
		{
			d -= 65;
			d += shift_len;
			d %= 26;
			d += 65;
		}else if(d >= 97 &&  d <= 122)
		{
			d -= 97;
			d += shift_len;
			d %= 26;
			d += 97;
		}

		fputc(d,fp_result);
	}

	fclose(fp_source);
	fclose(fp_result);

//	free(filepath_source);
//	free(filepath_result);

	return EXIT_SUCCESS;
}


