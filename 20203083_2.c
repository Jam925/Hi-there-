#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Delete(int idx, int input[])
{
	memmove(input + idx, input + idx + 1, sizeof(int) * (6-idx));
}

void main()
{
	int input[5];
	int i;
	int Set;
	
	printf("Enter 5 elements in array: ");
	
	for (i=0; i<5; i++) {
		
		//처음 숫자 입력 5번 
		
		scanf("%d", &input[i]);
	}
	
	printf("Stored element in array:");
	
	for (i=0; i<5; i++) {
		printf("%d ", input[i]);
	}
	
	printf("\n");
	printf("\n");

	printf("Enter poss. of element to delete: ");
	
	scanf("%d", &Set);
	
	Delete(Set, input-1);
	
	printf("After deletion elements in array: ");
	
	for(i=0; i<4; i++) {
		
		printf("%d ", input[i]);
	}

}
