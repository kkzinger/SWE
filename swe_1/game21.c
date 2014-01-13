/*
	File: game21.c
	Author: Katzinger G.
	Date 29.10.2013

	Small game for two players. 21 Sticks are there at the begining. Every Player
	takes 1-4 Sticks each turn. The Player who will take the last one loses.

*/


#include <stdio.h>


int iGetNewNumber(){
	int iNumber;

	do{
		printf("\nWrong Number! Please choose one from 1 to 4: ");
		scanf("%d", &iNumber);

	}while(iNumber < 1 || iNumber > 4);

	return iNumber;
}

int main(){

	int iSticks, iPlayer1=0, iPlayer2=0;



	iSticks=21; //End of game at 21

	printf("Welcome to 21 Sticks\n\n The player who takes the last Stick will lose!\n");
	printf("Choose a number of sticks you will take from 1 to 4 every turn\n");

	do{

		/* Read in Player 1 */
		printf("\nPlayer 1: ");
		scanf("%d", &iPlayer1);

		if(iPlayer1 < 1 || iPlayer1 > 4)
			iPlayer1 = iGetNewNumber();

		iSticks = iSticks - iPlayer1;

		/* Control iSticks */

		if(iSticks <= 0){

			printf("\n---------- Player 2 wins !!! ----------\n\n");
			break;
		}
		/* Read in Player 2 */

		printf("\nPlayer 2: ");
		scanf("%d", &iPlayer2);

		if(iPlayer2 < 1 || iPlayer2 > 4)
			iPlayer2 = iGetNewNumber();


		iSticks = iSticks - iPlayer2;

		/* Control iSticks */

		if(iSticks <= 0){

			printf("\n--------- Player 1 wins !!! ---------\n\n");
			break;
		}


	}while(iSticks>0);





return 0;
}

