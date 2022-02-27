#include <stdio.h>
#include <string.h>

struct dataEntry{
	char courseName[25];
	int credit;
	float mark;
};

//int function validateEntry(&){
//	
//	return 0;
//	}

int main(){
	//the user enters a subject as a string of chars, then its correspoding mark and credit
	//after collecting necessary data, total mark is calculated by summing (mark multiplied by credit) for each subject
	//total credit is also calculated by summing credit for each subject
	//the gpa is then equal to the total mark, divided by the total credit. this result is ofcourse displayed to the screen
	
	char courses[10][25]; 
	// this program will not be able to accept names longer than 25 chars and will be limited to calculated gpa for a maximum of 10 courses
	
	float marks[10];
	int credits[10];
	int courseNumber; //this will hold the number of courses entered by the user
	
	float totalCredit;
	float totalMark;
	
	
	printf("Enter data below to calculate your gpa \n");
	printf("Course name, credit and mark is entered in a single line as such (name credit mark) \n");
	printf("example:\"#1 course: physics 4 80\" \n\n");

	//the summing loop;
	for (size_t tmp = 0; tmp < sizeof(courses); tmp++){
		struct dataEntry tmp;
		
		printf("#%i course: ", tmp);
		scanf("%s %i %f", &tmp.courseName, &tmp.credit, &tmp.mark);
		
		if (sizeof(tmp.courseName) < 1 || tmp.credit )
		
		}
	
	for (size_t i = 0; i < courseNumber; i++ ){
		
		
	}
	
		system("pause");
	
	return 0;
	}