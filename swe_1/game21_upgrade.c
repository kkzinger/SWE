/*
	File: game21_upgrade.c
	Author: Katzinger G.
	Date 29.10.2013

	Small game for two players. 21 Sticks are there at the begining. Every Player
	takes 1-4 Sticks each turn. The Player who will take the last one loses.

	UPGRADE: Game won't chrash if Player types wrong number format (1.5 , 1,4 ,.....)

*/


#include <stdio.h>
#include <stdlib.h>

/*-------------------- Functions ---------------------*/
int iGetNewNumber(){

	int iNumber;
	char cNumber[200];

	do{
		printf("\nWrong Number! Please choose one from 1 to 4: ");
		scanf("%s", cNumber);

		iNumber = atoi(cNumber); //Convert cNumber in an integer Value

	}while(iNumber < 1 || iNumber > 4);

	return iNumber;
}

/*-------------------- Main Routine ---------------------*/


int main(){

	int iSticks, iPlayer1=0, iPlayer2=0;
	char cPlayer1[200], cPlayer2[200];


	iSticks=21; //End of game at 21

	printf("\nWelcome to 21 Sticks\n\nThe player who takes the last Stick will lose!\n");
	printf("Choose a number of sticks you will take from 1 to 4 every turn\n");

	do{

		/*----------------------------------- Read in Player 1 ------------------------------------------------------*/
		printf("\nPlayer 1: ");
		scanf("%s", cPlayer1);

		iPlayer1 = atoi(cPlayer1); 	//Convert cPlayer1 in an integer Value

						//printf("%d\n", iPlayer1); //DEBUG

		if(iPlayer1 < 1 || iPlayer1 > 4)
			iPlayer1 = iGetNewNumber();

		iSticks = iSticks - iPlayer1;

						//printf("%d",iSticks); //DEBUG

		/*--------- Control iSticks -----------*/

		if(iSticks <= 0){

			printf("\n---------- Player 2 wins !!! ----------\n\n");
			break;
		}
		/*----------------------------------- Read in Player 2 ----------------------------------------------------*/

		printf("\nPlayer 2: ");
		scanf("%s", cPlayer2);

		iPlayer2 = atoi(cPlayer2); 	//Convert cPlayer1 in an integer Value

						//printf("%d\n", iPlayer2); //DEBUG

		if(iPlayer2 < 1 || iPlayer2 > 4)
			iPlayer2 = iGetNewNumber();


		iSticks = iSticks - iPlayer2;

						//printf("%d",iSticks); //DEBUG

		/*---------- Control iSticks ----------*/

		if(iSticks <= 0){

			printf("\n--------- Player 1 wins !!! ---------\n\n");
			break;
		}


	}while(iSticks>0);





return 0;
}

