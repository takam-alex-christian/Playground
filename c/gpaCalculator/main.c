#include <stdio.h>
#include <string.h>

struct dataEntry{
	char courseName[25];
	int credit;
	float mark;
};

int validateEntry(struct dataEntry *entry,  char *err){
	int response = 0;
	if ( sizeof(entry->courseName) == 0){  response = 1; strcpy(err, "course name was empty");}
	
	if (entry->credit > 4 || entry->credit < 1){response = 1; strcpy(err, "invalid credit inserted");}
	
	if (entry->mark < 0 || entry->mark > 100){response = 1; strcpy(err, "invalid mark inserted");}
	
	return response; //so if the entry is validated, then reponse is unchanged
	
	}

int main(){
	//the user enters a subject as a string of chars, then its correspoding mark and credit
	//after collecting necessary data, total mark is calculated by summing (mark multiplied by credit) for each subject
	//total credit is also calculated by summing credit for each subject
	//the gpa is then equal to the total mark, divided by the total credit. this result is ofcourse displayed to the screen
	
	char courses[10][25]; 
	// this program will not be able to accept names longer than 25 chars and will be limited to calculated gpa for a maximum of 10 courses
	
	float marks[10];
	int credits[10];
	char courseStatuses[10][25];
	
	int courseNumber = 0; //this will hold the number of courses entered by the user
	
	float totalCredit = 0;
	float totalMark= 0;
	
	float gpaCalculated = 0; //initialized to zero, to prevent querying garbage from memory
	char gpaRemark[] = "";
	
	char err[256];// will hold error messaged, of course no longer than 256
	
	
	printf("Enter data below to calculate your gpa \n");
	printf("Course name, credit and mark is entered in a single line as such (name credit mark) \n");
	printf("example:\"#1 course: physics 4 80\" \n\n");
	
	printf("Enter an invalid entry such as a \'/\' fo credit to end data entry \n");
	
	for (size_t c = 0; c < sizeof(courses); c++){
		struct dataEntry tmp;
		
		printf("#%i course: ", c);
		scanf("%s %i %f", &tmp.courseName, &tmp.credit, &tmp.mark);
		
		if(!validateEntry(&tmp, err)){
			
			strcpy(courses[c], tmp.courseName);
			credits[c] = tmp.credit;
			marks[c] = tmp.mark;
			
			if ( marks[c] >= 60){strcpy(courseStatuses[c], "passed");}
			else if (marks[c] < 60){strcpy(courseStatuses[c], "failed");}
			//if the data provided by the student is valid, then we store them to memory along with the statuses.
		}else{courseNumber = c; break;}
	}
	
	printf("reason for breaking: \"%s\" \n\n",err);
	
	for (size_t i = 0; i < courseNumber; i++ ){
		
		totalMark += marks[i] * credits[i];
		totalCredit += credits[i];
		
		printf("\n\n %s -> %s \n", courses[i], courseStatuses[i]);
		
	}
	
	gpaCalculated = totalMark/totalCredit;
	
	if (gpaCalculated >= 2 < 3){strcpy(gpaRemark, "Good!");}
	else if (gpaCalculated >= 3 < 3.5){strcpy(gpaRemark, "very good!");}
	else if (gpaCalculated >= 3.5 <= 4){strcpy(gpaRemark, "Excellent !!!!");}
	
	//now that all the logics have been carried out, let's display the results
	printf("\n Your Gpa: %.2f [%s] \n\n", gpaCalculated, gpaRemark);
	system("pause");
	
	return 0;
	}