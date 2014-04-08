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
	int i, d, e, shift_len, modus;
	char *filepath_source, *filepath_result;
	char solved;
	FILE *fp_source, *fp_result;
	printf("argc %d\n",argc);

	filepath_result = (char*) malloc(50);

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
			modus = 0;

		}else if(strcmp(argv[i],"-d") == 0)
		{
			i++;
			shift_len = 0;
			modus = 1;
		}

	}

	printf("filepath: %s \nshift_len: %d\n",filepath_source,shift_len);

	fp_source = fopen(filepath_source, "r");

	if(modus == 0)
	{
		strcpy(filepath_result,"encoded.txt");
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

	}else if(modus == 1)
	{
		strcpy(filepath_result,"result_decode.txt");

		fp_result = fopen(filepath_result, "w");

		shift_len = 0;
		solved = 'n';

		while(solved == 'n')
		{
			while((d=fgetc(fp_source))!=EOF)	//Scan file and count number of lines
			{
				//printf("dd\n");
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

				putc(d,fp_result);
				printf("%c",d);
			}
			printf("Is this the decoded text? [y/n] ");
			fflush(stdin);
			scanf("%s",&solved);
			if(solved != 'y')
			{
				//solved = 'n';
				shift_len++;
				rewind(fp_source);
				rewind(fp_result);
			}
		}

	}
	fclose(fp_source);
	fclose(fp_result);

	//free(filepath_source);
	free(filepath_result);

	return EXIT_SUCCESS;
}


