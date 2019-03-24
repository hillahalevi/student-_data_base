/**************************
Student name : hilla halevi
Student : 208953083
Course Exercise Group : 01
Exercise name : ex5.c
***************************/
#define INPUT 202
#define WRONG -1
#define STUDANTS 50
#define INFO 12
#define DETAILS 21
#define FULLNAME 41
#define FIRST_LAST 2


/****************************************************************************************
* Function Name:PrintMassege
* Input:long int n
* Output:no return value
* Function the function prints masseges according to the operation number(n) she gets
******************************************************************************************/
void PrintMassege(int n);
/****************************************************************************************
* Function Name:InTake
* Input:char array[]
* Output:int i(1-200))
* Function the function gets an empty array inserinng the user input and checks if its valid
and returning the reasult
******************************************************************************************/
int InTake(char array[]);

/****************************************************************************************
* Function Name:Update
* Input:char array[], int n,char a,char array2[]
* Output:int i(1-200))
* Function the function gets an input array ,a starting point,a stoping point and another
array and inserts the info according to it
***************************************************************************************/
int Update(char array[], int n, char a, char array2[]);

/****************************************************************************************
* Function Name:Excist
* Input:int limit, char data[STUDANTS][INFO][DETAILS], char studant[2][DETAILS]
* Output:int,-1--49
* Function the function gets a sertin studant a data base and the amount od studants that in
it and finds if the studant is in the system if it does it sends the specific line
else sends -1
***************************************************************************************/
int Excist(int limit, char data[STUDANTS][INFO][DETAILS], char studant[2][DETAILS]);

/****************************************************************************************
* Function Name:Initial
* Input:char data[INFO][DETAILS]
* Output:no output
* Function the function gets a sertin studant and delete his whole info
***************************************************************************************/
void Initial(char data[INFO][DETAILS]);
/****************************************************************************************
* Function Name:TransferUp
* Input:char data[INFO][DETAILS], int line
* Output:no output
* Function the function moves all the studane info from a specific given line up
***************************************************************************************/
void TransferUp(char data[STUDANTS][INFO][DETAILS], int line);


/****************************************************************************************
* Function Name:MaxGrade
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and checks for the highes grade there
***************************************************************************************/
int MaxGrade(char data[STUDANTS][INFO][DETAILS], int line);
/****************************************************************************************
* Function Name:MinGrade
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and checks for the lowest grade there
***************************************************************************************/
int MinGrade(char data[STUDANTS][INFO][DETAILS], int line);

/****************************************************************************************
* Function Name:Count
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-5)
* Function the function gets an array and a line and checks how many courses are registered
***************************************************************************************/
int Count(char data[STUDANTS][INFO][DETAILS], int line);

/****************************************************************************************
* Function Name:Sum
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-500)
* Function the function gets an array and a line and checks the total sum of the grades
***************************************************************************************/
int Sum(char data[STUDANTS][INFO][DETAILS], int line);
/****************************************************************************************
* Function Name:Sum
* Input:char data[STUDANTS][INFO][DETAILS], int line
* Output:int(0-100)
* Function the function gets an array and a line and calculates the avarage grade
***************************************************************************************/
int Avarage(char data[STUDANTS][INFO][DETAILS], int line);

/****************************************************************************************
* Function Name:Mx
* Input:char data[STUDANTS][INFO][DETAILS],int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS
* Output:no output
* Function the function prints for the max score from all the studants with a given function
***************************************************************************************/
void Mx(char data[STUDANTS][INFO][DETAILS], int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS], int line));

/****************************************************************************************
* Function Name:AllMax
* Input:char data[STUDANTS][INFO][DETAILS],int maxStudant, int(*funcName)(char data[STUDANTS][INFO][DETAILS
* Output:no output
* Function the function prints all the studants with there calculated score with a given function
***************************************************************************************/
void AllMax(char data[STUDANTS][INFO][DETAILS], int total, int(*funcName)(char data[STUDANTS][INFO][DETAILS], int line));


