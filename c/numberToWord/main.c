/*
 * the user enters a number, numberEntry
 * numberEntry is then validated
 * if the number is valid, we convert it else we prompt the user to enter a new valid number
 * the number in word is displayed
 * the program pauses
 * */
 
#include <stdio.h>
#include <string.h>

#define ZERO 48
#define NINE 57
#define MAXSIZE 3

int validateNumber(char *numberEntry){
	int response = 0;
	
//	printf("%s", numberEntry);

	for (size_t i = 0; i < strlen(numberEntry); i++){
		if(numberEntry[i] < ZERO || numberEntry[i] > NINE){response = 1;}
	}
	
	return response;
}
//the function that converts numbers to words
int convertToWord(char *numberEntry){//takes one string parameter
	
//	strrev(numberEntry); // we first reverse the number to ease further manipulation
	char numberInWord[256];
	
	
	char *digitToWord[] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	
	char *tensToWord[] = {
		"",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};
	
	char *positionToWord[] = {
		"",
		"",
		"hundred",
		"thousand",
		"million",
		"billion"
	};
	//lets first reverse the order of the digits in this number
	
	for (size_t i = 0, j = strlen(numberEntry) - 1; i < strlen(numberEntry) && j >= 0; i++, j--){
		
		strcat(numberInWord, digitToWord[(int) numberEntry[i] - ZERO]);
		strcat(numberInWord, " ");
		strcat(numberInWord, positionToWord[j]);
		strcat(numberInWord, " ");
		
//		switch(i){
//			case 0:{
//				strcat(numberInWord, digitToWord[(int) numberEntry[i] - 48]);
//				break;
//			};
//			case 1:{
//				
//			};
//			default: {
//				printf("blue");
//			};
//		}
		
		
	} 
	
	printf("%s", numberInWord);
	
	return 0;
}
 
int main(){
	char numberEntry[10];

	printf("Convert a number into words: MAXSIZE[%i]", MAXSIZE);

	while(1){

		printf("Enter a number -->");
		scanf("%s", &numberEntry);
		if(validateNumber(&numberEntry)){
			printf("the number is invalid");
			break;
		}
		convertToWord(&numberEntry);
		
	}

	system("pause");
	 
	return 0;
}