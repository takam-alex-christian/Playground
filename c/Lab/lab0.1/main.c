/*
 * Program starts
 * user enters length of rectangle
 * user enters width of rectangle
 * both entries are validated
 * area is calculated
 * perimeter is calculated too
 * */

int validateSide(float *side){
	int response = 0;
	
	if(side < 0 || side == 0) response = 1; 
	
	return response;
}

#include <stdio.h>

int main(){
	
	float length = 0, width =  0;
	
	printf("\n\nProgram to calculate the area and perimeter of a rectangle\n\n\tEnter sides:\n\n");
	
	//again, the program loop.
	while(1){
		printf("\n\tLength -> ");
		scanf("%f", &length);
		
		if(!validateSide(&length)){
			printf("\n\tWidth -> ");
			scanf("%f", &width);
//			printf("%f");
			if(!validateSide(&width)){
				printf("\n\n\tOutput\n\n\tArea: %.2f square units\n\tPerimeter: %.2f units\n\n", length * width, 2*(length) + 2*(width));
				break;
			}
		}
	}
	
	system("pause");
	
	return 0;
}