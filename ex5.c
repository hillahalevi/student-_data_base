#define _CRT_SECURE_NO_WARNINGS
/**************************
Student name : hilla halevi
Student : 208953083
Course Exercise Group : 01
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

///help function declarations
/****************************************************************************************
* Function Name:IsNameValid
* Input:char array[], int i, char a
* Output:int (-1||(1-200))
* Function the function gets an array a starting point and a stoping condition and checks
if the name is vallid (abc letters /spaces)&&no more than 20 chars  if its valid it returns
the  position (i) of the last char else returns WRONG.
******************************************************************************************/
int IsNameValid(char array[], int i, char a);
///help function
/****************************************************************************************
* Function Name:IsNumberValid
* Input:char array[], int i
* Output:int (-1||(1-200))
* Function the function gets an array a starting point and checks
if the nunber is vallid (0<=x=<100) if its valid it returns
the  position (i) of the last char else returns -1.
******************************************************************************************/
int IsNumberValid(char array[], int i);
///help function
/****************************************************************************************
* Function Name:IsAllValid
* Input:char array[]
* Output:int (-1G||(1-200))
* Function the function gets an array and checks if its all valid .
if its valid it returns the  position (i) of the last char else returns -1.
******************************************************************************************/
int IsAllValid(char array[]);
///help function
/****************************************************************************************
* Function Name:Convetion
* Input:char data[DETAILS]
* Output:int(0-100)
* Function the function gets a specific spot in an array and convert it from chars to
numirical number
***************************************************************************************/
int Convetion(char data[DETAILS]);

/****************************************************************************************
* Function Name:PrintMassege
* Input:long int n
* Output:no return value
* Function the function prints masseges according to the operation number(n) she gets
******************************************************************************************/
void PrintMassege(int n)
{
	switch (n)
	{
	case 1: {
		printf("Please select the operation: \n");
		printf("\t0. Exit. \n ");
		printf("\t1. Insert or update student grades.\n");
		printf("\t2. Delete student information.\n");
		printf("\t3. Print the student with maximal computed grade.\n");
		printf("\t4. Print all the students with their computed grades.\n");
		printf("\t5. Print the menu.\n");
		break;
	}
	case 2: {
		printf("Select the next operation (insert 5 for complete menu).\n");
		break;
	}
	case 3: {
		printf("Error: unrecognized operation.\n");
		break; }
	case 4: {
		printf("Error: invalid name or grade.\n");
		break;
	}
			
	case 5: {
		printf("Error: there is no more space.\n"); 
		break; }
			
	case 6: {
		printf("Error: invalid name.\n"); break; }
	case 7: {
		printf("Error: student name does not exist.\n"); break; }
	case 8:{	
		printf("Please select the aggregation method:\n");
		printf("\ta. Average grade. \n");
		printf("\tb. Maximal grade.\n");
		printf("\tc. Minimal grade.\n");
		printf("\td. Sum.\n");
		printf("\te. Count.\n");
		printf("\t0. Return the main menu.\n");
		break;
}
	case 9: {
		printf("Error: there are no students.\n"); break; }
	
	default:
		break;
	}


}

/****************************************************************************************
* Function Name:InTake
* Input:char array[]
* Output:int i(1-200))
* Function the function gets an empty array inserinng the user input and checks if its valid
and returning the reasult
******************************************************************************************/
int InTake(char array[]) {
	char dummy;
	int legitLen = 0;
	//dummy gets the /n char
	scanf("%c", &dummy);
	//gets the details from the user
	fgets(array, INPUT, stdin);
	//sends it to a special function to check if its vallid
	legitLen = IsAllValid(array);
	return legitLen;
}

/****************************************************************************************
* Function Name:IsNameValid
* Input:char array[], int i, char a
* Output:int (-1||(1-200))
* Function the function gets an array a starting point and a stoping condition and checks
if the name is vallid (abc letters /spaces)&&no more than 20 chars  if its valid it returns
the  position (i) of the last char else returns WRONG.
******************************************************************************************/
int IsNameValid(char array[], int i, char a) {
	int flag = 0;
	//running on the array char by char
	for (i; (array[i] != a) || (flag == 0); i++)
	{	//checks every char if its valid letter
		if ((array[i] >= 'a' && array[i] <= 'z') || (array[i] >= 'A' && array[i] <= 'Z')) {
			//remenbers the number of the letters
			flag++;
		}
		else if (array[i] == ' '&& flag == 0)
		{	//ignoring spaces until letter 
			continue;
		}
		else if (array[i] == ' '&& flag != 0)
		{	//spaces after inserting letter count
			flag++;
			continue;
		}
		else {
			//the char is not space or a valid letter 
			i = WRONG;
			break;
		}

	}
	//checks is the word has more than 20 chars
	if (flag > 20) { i = WRONG; }
	return i;

}


/****************************************************************************************
* Function Name:IsNumberValid
* Input:char array[], int i
* Output:int (-1||(1-200))
* Function the function gets an array a starting point and checks
if the nunber is vallid (0<=x=<100) if its valid it returns
the  position (i) of the last char else returns -1.
******************************************************************************************/
int IsNumberValid(char array[], int i) {
	int flag = 0;
	//running on the array char by char
	for (i; (array[i] != ';') || (flag == 0); i++)
	{	//checks every char if its valid letter
		if ((array[i] >= '0' && array[i] <= '9')) {
			//remenbers the number digits
			flag++;
		}
		else if (array[i] == ' '&& flag == 0)
		{	//ignoring spaces until number
			continue;
		}
		else
		{
			//the char isnt a vallid digit
			return WRONG;
		}
	}
		if (flag>3)
		{	//the number has more than 3 digits-not in range
			return WRONG;
		}
		else if (flag == 3)
		{
			if (array[i - 1] == '0' && array[i - 2] == '0' && array[i - 3] == '1')
			{	//the only valid 3 digits number is 100
				return i;
			}
			else
			{	//not valid
				return WRONG;
			}
		}
		else
		{	//regular number betwin 0-99
			return i;
		}
	}



/****************************************************************************************
* Function Name:IsAllValid
* Input:char array[]
* Output:int (-1G||(1-200))
* Function the function gets an array and checks if its all valid .
if its valid it returns the  position (i) of the last char else returns -1.
******************************************************************************************/
int IsAllValid(char array[]) {
	int i = 0;
	int len = 0;
	int counter = 0;
	//the length of the input without '/n','0'
	len = strlen(array) - 2;
	i = IsNameValid(array, i, ' ');
	//checking the first name
	if (i == WRONG) {
		//not valid
		return WRONG;
	}
	else
	{
		i = IsNameValid(array, i, ':');
		//cheacking the last name
		if (i == WRONG)
		{
			//not valid
			return WRONG;
		}
		else
		{	//checking the curses
			//i+1 avoiding the special chars
			//this while loop will excute until reaching 5 courses or reching the end of the input
 			while (counter != 5 && i != len)
			{	//checking the name of the course
				i = IsNameValid(array, i + 1, ',');
				if (i == WRONG)
				{	//not valid 
					return WRONG;
				}
				else
				{	//checks the grade
					i = IsNumberValid(array, i + 1);
					if (i == WRONG)
					{	//not valid
						return WRONG;
					}
					else
					{	//counting the amount of courses
						counter++;
					}
				}
			}
	
			if (counter == 0) { 
				//if there are no courses
				return -1; }
			else
			{
				//this i is the final index we want in this array
				return i;
			}
			

		}

	}
}

/****************************************************************************************
* Function Name:Update
* Input:char array[], int n,char a,char array2[]
* Output:int i(1-200))
* Function the function gets an input array ,a starting point,a stoping point and another
array and inserts the info according to it
***************************************************************************************/
int Update(char array[], int n, char a, char array2[]) {
	int k = 0;
	char c = 0;
	//goes threw letter by letter until passing a stop condition 
	for (n; (array[n] != a) || (k == 0); n++)
	{

		if (array[n] == ' '&& k == 0)
		{	//ignoring spaces until letter 
			continue;
		}
		else
		{
			
			array2[k] = array[n];
			//moving on to the next letter in array2
			k++;
		}
	}
	//signing the array
	array2[k] = 0;

	return n;
}

/****************************************************************************************
* Function Name:Excist
* Input:int limit, char data[STUDANTS][INFO][DETAILS], char studant[2][DETAILS]
* Output:int,-1--49
* Function the function gets a sertin studant a data base and the amount od studants that in
it and finds if the studant is in the system if it does it sends the specific line
else sends -1
***************************************************************************************/
int Excist(int limit, char data[STUDANTS][INFO][DETAILS], char studant[2][DETAILS]) {
	for (int line = 0; line < limit; line++)
	{
		//this  loop loops to search if the student is already in the system
		if ((strcmp(data[line][0], studant[0]) == 0) && (strcmp(data[line][1], studant[1]) == 0))
		{
			return line;

		}

	}
	return WRONG;
}

/****************************************************************************************
* Function Name:Initial
* Input:char data[INFO][DETAILS]
* Output:no output
* Function the function gets a sertin studant and delete his whole info
***************************************************************************************/
void Initial(char data[INFO][DETAILS]) {
	char delete[DETAILS] = { 0 };
	int i = 0;
	for (i; i < 11; i++)
	{
		strcpy(data[i], delete);
	}
}


/****************************************************************************************
* Function Name:TransferUp
* Input:char data[INFO][DETAILS], int line
* Output:no output
* Function the function moves all the studane info from a specific given line up
***************************************************************************************/
void TransferUp(char data[STUDANTS][INFO][DETAILS], int line) {
	int i = 0;
	for (i; i < 11; i++)
	{
		strcpy(data[line][i], data[line + 1][i]);
	}
}

/****************************************************************************************
* Function Name:Convetion
* Input:char data[DETAILS]
* Output:int(0-100)
* Function the function gets a specific spot in an array and convert it from chars to
numirical number
***************************************************************************************/
int Convetion(char data[DETAILS]){
	int amount = 0;
	int num = 0;
	//checks how many digits are there
	amount =strlen(data);
	if (amount == 3) { return 100; }
	else if (amount==1)
	{//one digited number
		num = data[0] - '0';
		return num;
	}
	else
	{	//two digited number 
		num = 10 * (data[0] - '0') + (data[1] - '0');
		return num;
	}
}

/****************************************************************************************
* Function Name:MaxGrade
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and checks for the highes grade there
***************************************************************************************/
int MaxGrade(char data[STUDANTS][INFO][DETAILS], int line) {
	int maxCourse = 0;
	//find hoe many courses are there
	maxCourse = Count(data, line);
	int grade = 0;
	//convert it to a numerical grade
	grade = Convetion(data[line][3]);
	//the highest indeax we check
	maxCourse = 2 * maxCourse - 1;
	for (int i = 3; i <=  maxCourse ; i = i + 2)
	{
		int temp = 0;
		temp = Convetion(data[line][i + 2]);
		if (grade < temp) { grade = temp; }
	}
	//now we have the highest grade
	return grade;
}


/****************************************************************************************
* Function Name:MinGrade
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and checks for the lowest grade there
***************************************************************************************/
int MinGrade(char data[][INFO][DETAILS], int line) {
	int maxCourse = 0;
	//find hoe many courses are there
	maxCourse = Count(data, line);
	int grade = 0;
	//convert it to a numerical grade
	grade = Convetion(data[line][3]);
	for (int i = 3; i <= 2 * maxCourse - 1; i = i + 2)
	{
		int temp = 0;
		temp = Convetion(data[line][i + 2]);
		if (grade > temp) { grade = temp; }
	}
	//now we have the lowest grade
	return grade;
}


/****************************************************************************************
* Function Name:Count
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-5)
* Function the function gets an array and a line and checks how many courses are registered
***************************************************************************************/
int Count(char data[][INFO][DETAILS], int line){
	int counter = 0;
	for (int i = 2; i < 11; i=i+2)
	{
		if (data[line][i][0] != '\0')
		{ 
			//theres a course -count it
			counter++;
		}
		
	}
	return counter;
}


/****************************************************************************************
* Function Name:Sum
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-500)
* Function the function gets an array and a line and checks the total sum of the grades
***************************************************************************************/
int Sum(char *** data,int line) {
	int sum= 0;

	printf("%s",  (data));
	printf("%s", data[0][1]);



	for (int i = 2; i < 11; i=i+2)
	{
		if (data[line][i][0]!='\0')
		{
			sum = sum + Convetion(data[line][i + 1]);
			
		}
	}
	return sum;
}

/****************************************************************************************
* Function Name:Sum
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and calculates the avarage grade
***************************************************************************************/
int Avarage(char data[STUDANTS][INFO][DETAILS],int line) {
	
	return Sum(data, line) / Count(data, line);
}

/****************************************************************************************
* Function Name:Mx
* Input:char data[STUDANTS][INFO][DETAILS],int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS
* Output:no output
* Function the function prints for the max score from all the studants with a given function
***************************************************************************************/
void Mx(char data[STUDANTS][INFO][DETAILS],int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS], int line))
{
	int final = 0;
	char Fullname[FIRST_LAST][DETAILS] = { 0 };
	//copy the first's studant full name
	strcpy(Fullname[0], data[0][0]);
	strcpy(Fullname[1], data[0][1]);
	//the wanted score
	final = funcName(data, 0);
	char FullName1[FULLNAME] = { 0 };
	strcat(FullName1, data[0][0]);
	strcat(FullName1,  data[0][1]);
	
	for (int i = 0; i < maxStudant-1; i++)
	{
		//in this loop we try to find the studant with the highest score
		int temp= funcName(data, i+1);
		if (final <= temp)
		{//if we found a score that is equel or highre we check
			char FullName2[40] = { 0 };
			strcat(FullName2, data[i+1][0]);
			strcat(FullName2,  data[i+1][1]);
			if(final == temp && strcmp(FullName2,FullName1)>0){
				//if the grades are equel but his name id higher we continue
				continue;
			}
			else
			{//we update the score and the studant's full name to the highest one
				final = funcName(data, i + 1);
				strcpy(Fullname[0], data[i + 1][0]);
				strcpy(Fullname[1], data[i + 1][1]);
			}
			
		}
	}
	printf("%s %s, %d\n", Fullname[0], Fullname[1], final);

}


/****************************************************************************************
* Function Name:AllMax
* Input:char data[STUDANTS][INFO][DETAILS],int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS
* Output:no output
* Function the function prints all the studants with there calculated score with a given function
***************************************************************************************/
void AllMax(char *** data, int total,int(*funcName)(char data[STUDANTS][INFO][DETAILS], int line))
{
	for (int i = 0; i < total; i++)
	{

		printf("%s %s, %d\n", data[i][0], data[i][1], funcName(data,i));
	}
}



