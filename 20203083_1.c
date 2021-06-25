#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Insert(int idx, int input[], int searchnum) {
	
	memmove(input + idx + 1, input + idx, sizeof(int) * (6-idx));
	
	input[idx] = searchnum;
}


void main(void)
{
	int input[7];
	int i;
	int Set,In;
	
	printf("Enter 5 elements in array: ");
	
	for (i=0; i<5; i++) {
		
		//처음 숫자 입력 5번 
		
		scanf_s("%d", &input[i]);
	}
	
	printf("Stored element in array:");
	
	for (i=0; i<5; i++) {
		printf("%d ", input[i]);
	}
	
	printf("\n");
	printf("\n");
	//
	printf("Enter position for enter element: ");
	
	scanf_s("%d", &Set);

	printf("Enter new element: ");
	
	scanf_s("%d", &In);
	
	Insert(Set, input-1, In);
	
	printf("Stored data in array: ");
	
	for(i=0; i<6; i++) {
		
		printf("%d ", input[i]);
	}

} 
