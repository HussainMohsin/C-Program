#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void menu();
double compute_pi(int nthTerm);
double compute_sqrt(double x);
int is_prime(int number);
void display_primes(int n);
void process_scores();
double compute_tax(int income, char *status,  char  state);
int quadratic(double a, double b, double c, double *solution1, double *solution2);
int factorial(int n);
void  file_count(char  *file,  int  *characters, int *lines);
void  file_sort(char  *infile,  char  *outfile);
void file_student(char *infile);

int main(){
	int option, nthTerm, primeNum, income, factorialNum, characters=0, lines=0;
	double num, a, b, c, solution1, solution2;
	char status[10], state, charFile[30], stdInFile[30], stdOutFile[30], studentFile[30];
	
	do{
		printf("\n");
		menu();
		printf("Enter an option number: ");
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
			case 1:
				printf("Enter the nth term you would like to use: ");
				scanf("%d",& nthTerm);
				double pi = compute_pi(nthTerm);
				
				printf("pi is %lf",pi);
				break;
				
			case 2:
				printf("Enter in a number you would like to find the square root of: ");
				scanf("%lf", &num);
				
				printf("The square root of %.2lf is: %.2lf \n" ,num, compute_sqrt(num));
				break;
				
			case 3:
				printf("Enter in the number you would like to check: ");
				scanf("%d", &primeNum);
				
				is_prime(primeNum);
				display_primes(primeNum);
				
				break;
				
			case 4:
				process_scores();
				break;
				
			case 5:
				printf("Enter your yearly income: $");
				scanf("%d",&income);
				getchar();
				printf("Enter your marital status: ");
				gets(status);
				printf("Enter I if you are in State, or O if you are out of State: ");
				scanf("%c", &state);
				
				if(compute_tax(income, status, state) > -1)
					printf("The tax amount for an %c State, %s status with an income of $%d is $%.2lf. ",state, status, income, compute_tax(income, status, state));
				else 
					printf("You have entered an invalid input, try again.");
				break;
				
			case 6:
				printf("Quadratic Equation: ax^2+ bx + c\n");
				printf("Enter in a: ");
				scanf("%lf", &a);
				printf("Enter in b: ");
				scanf("%lf", &b);
				printf("Enter in c: ");
				scanf("%lf", &c);
				
				if(quadratic(a, b, c, &solution1, &solution2)){
					printf("Solution 1 is : %.2lf", solution1);
					printf("\nSolution 2 is : %.2lf", solution2);
				}else 
					printf("There are no soltions, Try Again");
				
				break;
				
			case 7:
				printf("Enter in a number you would like to find the factorial of: ");
				scanf("%d", & factorialNum);
				
				printf("The factorial of %d is %d ",factorialNum, factorial(factorialNum));
				break;
				
			case 8:
				getchar();
				printf("Enter the file name you would like to find the character count of: ");
				gets(charFile);
				
				file_count(charFile, &characters, &lines);
				printf("There are %d characters and %d lines in the file %s.", characters, lines, charFile);
				break;
				
			case 9:
				getchar();
				printf("Enter the file name you are reading from: ");
				gets(stdInFile);
				printf("Enter the file name you are writing to: ");
				gets(stdOutFile);
				
				file_sort(stdInFile,stdOutFile);
				break;
				
			case 10:
				getchar();
				printf("Enter the student file name you are reading from: ");
				gets(studentFile);
				
				file_student(studentFile);
				break;
				
			case 11:
				printf("Thank You, Have a nice day!\n");
				break;
			default:
				printf("Error invalid option\n");
				break;
		}
		if(option==11)
			break;	
		
	} while (option > 0 || option < 11);
}
void menu(){
	printf("\n1-computing pi \n");
	printf("2-computing square root\n");
	printf("3-displaying primes\n");
	printf("4-processing  grades\n");
	printf("5-computing  tax\n");
	printf("6-solving  quadratic\n");
	printf("7-computing factorial\n");
	printf("8-counting file\n");
	printf("9-sorting file\n");
	printf("10-student file\n");
	printf("11-quit\n\n");
}

double compute_pi(int nthTerm){
	double series = 1;
	int i;
	for(i = 1; i <= nthTerm - 1; i++){
		double constant = 1.0/((2*i) + 1);

		if(i % 2 != 0)
			series = series - constant;
		else
			series = series + constant;
	}
	return 4 * series;
}

double compute_sqrt(double x){
	double sqrt = 1.0;
	int iterations = 10;
	int i;
	
	for(i = 0 ; i < iterations ; i++){
		sqrt = 0.5*(sqrt + x / sqrt);
	}
	return sqrt;
}

int is_prime(int number){

	int i, prime=1;
	
	if (number==1)
		prime=0;
		
	for (i = 2; i < number; i++)
    {
        if (number % i == 0 && i != number)
            prime=0;
    }
    return prime;

}

void display_primes(int n){
	int i;
	printf("\nAll the prime numbers up to %d are:-\n", n);
	
	for(i=2; i<= n; i++){
		if(is_prime(i))
			printf("%d\n",i);
	}
}

void process_scores(){
	char name[15], minScoreStd[15], maxScoreStd[15];
	double totalStudents=0.0, score, totalScores=0.0, minScore=10000.0, maxScore=0.0, avgScore=0.0;
	printf("The name is a single word and the score is a positive integer");
	printf("\nEnter Q to Quit");
	
	while(1){
	
		printf("\nEnter the name and the score separated by blank in one line: ");
		scanf("%s",name);
		if(strcmp(name,"q")==0 || strcmp(name,"Q")==0)
			break;
		scanf("%lf",&score);
		
		totalStudents++;
		totalScores= totalScores + score;
		
		if(score < minScore){
			minScore=score;
			strcpy(minScoreStd,name);
		}
		
		if(score > maxScore){
			maxScore=score;
			strcpy(maxScoreStd,name);
		}	
	}
	if(totalStudents > 0){
		avgScore= totalScores/totalStudents;
		printf("\nThe average score is %.2lf.", avgScore);
		printf("\n%s had the lowest score of %.2lf.", minScoreStd, minScore);
		printf("\n%s had the highest score of %.2lf.", maxScoreStd, maxScore);
	}else{
		printf("No students were entered");
	}
	
	
}

double compute_tax(int income, char *status,  char  state){
	double taxAmount=-1.0;
	if(state=='i'|| state == 'I'){
		if(strcmp(status, "Single") == 0 || strcmp(status, "single") == 0){
			if (income < 30000)
				taxAmount= income * .20;
			else
				taxAmount= income * .25;
		}	
		
		if(strcmp(status, "Married") == 0 || strcmp(status, "married") == 0){
			if (income < 50000)
				taxAmount= income * .10;
			else
				taxAmount= income * .15;
			
		}	
	}else if(state=='o'|| state == 'O'){
	
		if(strcmp(status, "Single") == 0 || strcmp(status, "single") == 0){
			if (income < 30000)
				taxAmount= income * .17;
			else
				taxAmount= income * .22;
		}	
		
		if(strcmp(status, "Married") == 0 || strcmp(status, "married") == 0){
			if (income < 50000)
				taxAmount= income * .07;
			else
				taxAmount= income * .12;
			
		}	
	}
		
	return taxAmount;
}

int quadratic(double a, double b, double c, double *solution1, double *solution2){
	double solution= (b*b) - (4.0 *a*c);
	int hasSolution=0;
	
	if (solution >= 0){
		*solution1= (-b + sqrt(solution)) / (2.0 * a);
		*solution2= (-b - sqrt(solution)) / (2.0 * a);
		hasSolution =1;
	}else{
		*solution1= 0.0;
		*solution2= 0.0;
	}
	return hasSolution;
}

int factorial(int n){
	if (n <= 0)
		return 1;
	else
		return n * factorial(n-1);
}

void  file_count(char *file,  int  *characters, int *lines){
	char ch;
	int charCount=0, lineCount=1;
	FILE *inFile;
	inFile= fopen(file,"r");

	if(inFile == NULL){
		printf("[ERROR] Couldn't Open FIle");
		exit(0);
	}
	while ((ch = getc(inFile)) != EOF){
		charCount++;
		
		if(ch == '\n')
			lineCount++;
	}
	*characters = charCount;
	*lines = lineCount;
	fclose(inFile);
}

void  file_sort(char  *infile,  char  *outfile){
	
	int *studentId, students;
	char *studentGrade;
	double *studentGpa;
	
	FILE *studentsInFile;
	FILE *studentsOutFile;
	studentsInFile = fopen(infile, "r");
	studentsOutFile = fopen(outfile, "w");
	
	if(studentsInFile == NULL){
		printf("[ERROR] Couldn't Open FIle");
		exit(0);
	}
	
	fscanf(studentsInFile, "%d", &students);

	studentId= (int *) malloc(students*sizeof(int));
	studentGrade= (char *) malloc(students*sizeof(char));
	studentGpa= (double *) malloc(students*sizeof(double));
	
	int k;
	for (k=0; k< students; k++)
		fscanf(studentsInFile, "%d %c %lf", &studentId[k], &studentGrade[k], &studentGpa[k]);
	
	fclose(studentsInFile);
	
	int tempId, i, x;
	double tempGpa;
	char tempGrade;

	for (i = 0; i< students-1; i++) {
		
	    for ( x = 0; x <students-i-1; x++) {
	    	
	        if (studentId[x] > studentId[x+1]) {
	        	
	            tempId = studentId[x+1];
	            studentId[x+1] = studentId[x];
	            studentId[x] = tempId;
	
	            tempGpa = studentGpa[x+1];
	            studentGpa[x+1] = studentGpa[x];
	            studentGpa[x] = tempGpa;
	
	            tempGrade = studentGrade[x+1];
	            studentGrade[x+1]= studentGrade[x];
	            studentGrade[x] = tempGrade;
	        } 
	    }
	}
	
	int j;
	fprintf(studentsOutFile,"The %d students are sorted in ascending order by their ID\n", students);
	for (j = 0; j < students; j++) {
	   fprintf(studentsOutFile, "%d %c %.2lf\n",studentId[j], studentGrade[j], studentGpa[j]);
	}
	free(studentId);
	free(studentGrade);
	free(studentGpa);
	fclose(studentsOutFile);
	
	printf("File %s has been sorted, the sorted data is in file %s.", infile, outfile);
}

void file_student(char *infile){
	
	struct Student{
		char name[20];
		int age;
		double gpa;
	};
	
	int students;
	double totalGpas=0.0, avgGpa=0.0; 
	
	FILE *studentsInFile;
	studentsInFile = fopen(infile, "r");
	
	if(studentsInFile == NULL){
		printf("[ERROR] Couldn't Open FIle");
		exit(0);
	}
	
	fscanf(studentsInFile, "%d", &students);
	
	struct Student *student=(struct Student *)malloc(students*sizeof(struct Student));

	
	int k;
	for (k=0; k< students; k++)
		fscanf(studentsInFile, "%s %d %lf", &student[k].name, &student[k].age, &student[k].gpa);
	
	fclose(studentsInFile);
	
	int i;
	for (i = 0; i < students; i++) {
		totalGpas += student[i].gpa;
	}
	
	avgGpa= totalGpas / students;
	printf("The average gpa amount the %d students is %.2lf.\n", students, avgGpa);
	
	printf("\nThese are the students that had a 2.0 or higher gpa:\n");
	
	for (k = 0; k < students; k++) {
		
		if (student[k].gpa >= 2.0)
			printf("%s\n", student[k].name);
	}
	
	//sort the students
	struct Student temp;
	for (i = 0; i < students-1; i++) {	
	    for ( k = 0 ; k < students-i-1; k++) {
	    	
	        if (strcmp(student[k].name,student[k+1].name) > 0) {
	        	
	        	temp = student[k];
	        	student[k] = student[k+1];
	        	student[k+1] = temp;
	    	}
	    }
	}
	
	printf("\nStudents Listed is ascending order by their name:\n");
	printf("\nName\t\t Age\t Gpa\n");
	
	for (k = 0; k < students; k++)
		printf("%s\t\t %d\t %.2lf\n", student[k].name, student[k].age, student[k].gpa);
	
	free(student);
	
	
}
