#define _CRT_SECURE_NO_WARNINGS

/**************************
Student name : hilla halevi
Exercise name : ex5.c
***************************/
#include "ex5.h"
#include <stdio.h>
#include <string.h>
#define INPUT 202
#define WRONG -1
#define STUDANTS 50
#define INFO 12
#define DETAILS 21
#define FULLNAME 41
#define FIRST_LAST 2

int main()
{
	char bigData[STUDANTS][INFO][DETAILS] = { 0 };
	int amountStudant = 0;
	int option=0;
	PrintMassege(1);
	while (1)
	{
		scanf(" %d", &option);
		switch (option) {
		case 0: {
			//exiting the program
			return 0;
		}
		case 1: {
			char input[INPUT] = { 0 };
			int legitLen = 0;
			int line = 0;
			//afunction that insert the info from the user and checks its validty
			legitLen = InTake(input);
			if (legitLen == WRONG) {
				//the input isnt valid an error notice
				PrintMassege(4);
			}
			else {
			
				//inserting the studant data into a temp array for comparing
				char studant[INFO][DETAILS] = { 0 };
				int countCourse = 0;
				int stoPoint = 0;
				int course = 0;
				int grade = 0;
				int i = 0;
				//first name
				stoPoint = Update(input, stoPoint, ' ', studant[0]);
				//last name
				stoPoint = Update(input, stoPoint, ':', studant[1]) + 1;

				//updating courses
				for (course = 2; stoPoint < legitLen; course = course + 2)
				{
					//courSe
					stoPoint = Update(input, stoPoint, ',', studant[course]) + 1;
					//grade
					grade = course + 1;
					stoPoint = Update(input, stoPoint, ';', studant[grade]) + 1;
					countCourse++;

				}
				//now we have a temp array that holds all the info we need

				//sanding the temp studant we have to a function that checks if the studant is already in the system
				line=Excist(amountStudant, bigData, studant);
				
				if (line != WRONG)
				{	//the studant excist 
					//an indicator to see if there were any updates in the process
					int flag1 = 0; int flag2 = 0;
					for (int j = 2; j <= countCourse * 2 + 1; j = j + 2)
					{	/*in each loop we take a diffrent course from the temp array and see if it accure in the data base;
						if it excist we update the grade if not and theres room we insert the new course*/
						//j=the index of the course (from the temp)
						int k = 0;
						//k=the index of the grade (from the temp)
						k = j + 1;

						int m = 0;
						//m=the index of the grade in the course(from the database)
						for (int i = 2; i < 11; i = i + 2)
						{
							/*in each loop we take a diffrent course from the data base array and see if it is a match for the cuurent course;
							if it excist we update the grade if not and theres room we insert the new course*/
							flag1 = 0;
							if ((strcmp(bigData[line][i], studant[j]) == 0))
							{
								m = i + 1;
								flag1 = 1;
								//we need to update !
								break;

							}

						}
						if (flag1 == 0 && bigData[line][11][0] == '\0')
						{	//the course is not in the system and theres a place to insert a new one
							for (int i = 4; i < 11; i = i + 2)
							{ //checking wherw we have room to put in the new course
								if (bigData[line][i][0] == '\0')
								{	//theres a place ,insert the coure
									strcpy(bigData[line][i], studant[j]);
									//insert the grade
									strcpy(bigData[line][i + 1], studant[k]);
									break;


								}

							}
							flag2++;
							//an input was made!
							

						}
						else if (flag1 == 0 && bigData[line][11][0] != '\0')
						{
							//the course doesnt exist and there is no room to insert a new one
							break;
						}
						if (flag1 == 1)
						{ //the coure excist al left to do is update the grade !
							//initial the grade
							bigData[line][m][0] = '\0';
							//copy the current grade
							strcpy(bigData[line][m], studant[k]);
							//initial the inner indicator
							flag1 = 0;
							///an act was made
							flag2++;

						}


					}
					if (flag2 == 0)
					{	//an error notice
						//no updates or inserting new info accure
						PrintMassege(4);
					}
					else
					{
						printf("Student \"%s %s\" updated.\n", bigData[line][0], bigData[line][1]);
					}
				}
				else {
					
					if (amountStudant<STUDANTS)
					{ 
						//the sudant is not in the system and theres a place
						i = 0;
						int line = 0;
						stoPoint = 0;
						/*we take the first and last name and put it together in a new array*/
						char fullName[FULLNAME] = { 0 };
						strcat(fullName, studant[0]);
						strcat(fullName, studant[1]);
						//in this loop we try to find a line to put in our new studant leksigrphy
						for (line; line < amountStudant; line++) {
							char fullName1[FULLNAME] = { 0 };
							strcat(fullName1, bigData[line][0]);
							strcat(fullName1, bigData[line][1]);
							if (strcmp(fullName, fullName1)<0) {
								break;
								//found a place where our studant name has lower assci value than the rest
							}
						}
						for (int j = amountStudant - 1; line <= j; j--)
						{ 
							//copy the info to a lower line 
							//first name
							strcpy(bigData[j + 1][0], bigData[j][0]);
							//initial the line we jast copied
							strcpy(bigData[j][0], "");
							//last name
							strcpy(bigData[j + 1][1], bigData[j][1]);
							strcpy(bigData[j][1], "");
							//updating courses
							for (i = 2; i <INFO; i++)
							{
								strcpy(bigData[j + 1][i], bigData[j][i]);
								strcpy(bigData[j][i], "");

							}
							//in each loop we will lower all the studants so the line will become free to our use
						}
						//in the line we just found and cleared  we put in our studant
						//first name
						strcpy(bigData[line][0], studant[0]);
						//last name
						strcpy(bigData[line][1], studant[1]);

						//updating courses
						for (i = 2; i <= countCourse * 2 + 1; i++)
						{
							//coure
							strcpy(bigData[line][i], studant[i]);

						}
					

						printf("Student \"%s %s\" added.\n", bigData[line][0], bigData[line][1]);
						amountStudant++;
					}
					else
					{	
						//no room for u !
						PrintMassege(5);
					}

				}

			}
				break; }
		case 2: {
			char input2[INPUT] = { 0 };
			char dummy;
			int line = 0;
			int i = 0;
			int j = 0;
			//dummy gets the /n char
			scanf("%c", &dummy);
			//gets the details from the user
			fgets(input2, INPUT, stdin);
			//sending to an external function to check validty
			i = IsNameValid(input2, i, ' ');
			//checking the first name
			if (i == WRONG) {
				//not valid
				PrintMassege(6);
				break;
			}
			else
			{
				i = IsNameValid(input2, i, '\n');
				if (i == WRONG) {
					//not valid
					PrintMassege(6);
					break;
				}
			}
			char tempName[FIRST_LAST][DETAILS] = { 0 };
			j=Update(input2, j, ' ', tempName[0]);
			Update(input2, j, '\n', tempName[1]);
             //now we have the full name from the user
			//check if the studant is in the system
			line = Excist(amountStudant, bigData, tempName);
			if (line==WRONG)
			{   //the name is not in the system
				PrintMassege(7);
			}
			else
			{ //this loop will delete the studant info and bring up all the studants that come after
				for( line; line <=amountStudant; line++)
				{	//erase all info
					Initial(bigData[line]);
					//move the next line to the line we just initial
					TransferUp(bigData, line);
				}
				printf("Student \"%s %s\" deleted.\n", tempName[0], tempName[1]);
				//decrease the amount of student in the system
				amountStudant--;
			}
		 break; }
		case 3: {
			if (amountStudant == 0) { //thera are no studants in the system
				PrintMassege(9); break; }
			//printing tha manu
			PrintMassege(8);
			char method;
			//scaning the method choice from the user
			scanf(" %c", &method);
			switch (method)
			{
			case 'a':
				//finds the studant with the highest avarage of grades
				Mx(bigData, amountStudant, Avarage);
				break;
			case 'b':
				//finds the studant with the highest grade
				Mx(bigData, amountStudant, MaxGrade);
				break;
			case 'c':
				//finds the studant with the highest lowest grade
				Mx(bigData, amountStudant, MinGrade);
				break;
			case 'd':
				//finds the studant with the highest sum of his grades
				Mx(bigData, amountStudant, Sum);
				break;
			case 'e':
				//finds the studant with the nost courses
				Mx(bigData, amountStudant, Count);
				break;
			default:
				break;
				//zero input bye bye
			}
			break; }
		case 4: {
				if (amountStudant == 0) {//thera are no studants in the system
					PrintMassege(9); break; }
				//printing tha manu
				PrintMassege(8);
				char method;
				//scaning the method choice from the user
				scanf(" %c", &method);
				switch (method)
				{
				case 'a':
					//print all the studants each with his grade's avarage
					AllMax(bigData, amountStudant, Avarage);
					break;
				case 'b':
					//print all the studants each with his max grade
					AllMax(bigData, amountStudant, MaxGrade);
					break;
				case 'c':
					//print all the studants each with his lowest grade
					AllMax(bigData, amountStudant, MinGrade);
					break;
				case 'd':
					//print all the studants each with sum of scores
					AllMax(bigData, amountStudant, Sum);
					break;
				case 'e':
					//print all the studants each with his count of all courses
					AllMax(bigData, amountStudant, Count);
					break;
				default:
					break;
					//zero input bye bye
				}
				break; }
		case 5: {
			//printing menu
			PrintMassege(1);
			break;
		}
		default: 
			//invalid input
			PrintMassege(3);
		}
		
		if (option != 5){
		//printing a massesge to move on to the next option
			PrintMassege(2);
		}



	}

	return 0;
}