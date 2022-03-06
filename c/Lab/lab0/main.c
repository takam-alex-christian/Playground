/*
 * the program starts
 * the user is prompted for his name
 * name is then validated
 * the user is then prompted for his student id as studentId.
 * studentId is then validated
 * upon validation failure, user is reprompted for the same entry
 * then unix time is queried and formated
 * infinite loop is broken
 * all 3 components are printed to screen
 * programs pauses
 * */

#include <stdio.h>
#include <time.h>
#include <string.h>

//let's set a character filter
//this allows me to later easily change the filter to suite it for a different language encoding
#define ASCII_START 97
#define ASCII_STOP 122

#define STUDENT_ID_LENGTH 12
#define NAME_LENGTH 25

int validateName(char *name){
	
	int response = 0;
	
	if((int) strlen(name) < 2) response = 1;
	else{
		for(size_t i = 0; i < (int) strlen(name); i++) {
			if((int) name[i] != 32){
				if((int) tolower(name[i]) < ASCII_START || tolower(name[i]) > ASCII_STOP){ response = 1; break;}
			}
		}
	}
	
	return response;
}
	

int validateStudentId(char *studentId){
	int response = 0;
	if((int) strlen(studentId) != STUDENT_ID_LENGTH) response = 1;
	else{
		for(size_t i = 0; i < (int) strlen(studentId); i++) {
			if((int) studentId[i] < 48 || (int) studentId[i] > 57){ response = 1; break;}//StudentId is always inteded to be a string of numbers
		}
	}
	
	return response;
}

int main(){
	
	char name[NAME_LENGTH];
	
	char studentId[STUDENT_ID_LENGTH + 1];
	time_t todayDateTime;
	
	printf("\n\nProgram to display name and student id \n\n\tData Entry!");
	
	//program loop, is broken at some point to terminate the program.
	while(1){
		printf("\n\tName ->  ");
		scanf("%[^\n]", &name); //just a quick reminder here, the program bugs when the name has a space in it

		if(!validateName(&name)){
			printf("\tStudent Id ->  ");
			scanf("%s", &studentId);
			
			if(!validateStudentId(&studentId)){
				time(&todayDateTime);
				printf("\n\n\tOutput!\n\tName: %s \n\tID: %s \n\tDate: %s \n\n\n\n", name, studentId, ctime(&todayDateTime));
				break;
			}
		}
	}
	
	system("pause");//the user presses a key to terminate the console window
	
	return 0;
}