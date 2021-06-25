// 싱글 링크드 리스트

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
	int key;
	struct _list* next;
}List; 

List* head, * tail;

void init_list(void) {
	head = (List*)malloc(sizeof(List));
	tail = (List*)malloc(sizeof(List));
	head->next = tail;
	tail->next = tail;
} 

void insert_list(int data) {
	
	List* new1;
	new1 = (List*)malloc(sizeof(List));
	new1->key = data;
	new1->next = head->next;
	head->next = new1;
} // Element

void display_list(void) {
	List* cur;
	cur = head->next;
	printf("Items : ");
	while (cur != tail) {
	printf("%d  ", cur->key);
	cur = cur->next;
	}
	printf("\n\n");
} // Display

void delete_list(int data) {
	List* cur, * del;
	del = head;
	cur = head;
	while (cur != tail) {
		if (data == cur->next->key) {
			del = cur->next;
			cur->next = del->next;
			free(del);
			break;
		}
		cur = cur->next;
	}
	if (cur == tail) {
		printf("Fail..\n\n");
	}
} // Deleted item

void main(void) {

	init_list();
	int sel=0;
	int a;
	while (sel != 4) {
		printf("Select Option : \n");
		printf("1. Insertion \n2. Deletion \n3. Display \n4. Exit\n");
		scanf_s("%d", &sel);
		puts("");
		
		switch (sel)
		{
		a = 0;
		case 1: printf("Element : ");
				scanf_s("%d", &a);
				puts("");
				insert_list(a); 
				printf("Successfully Insert\n\n");
				break;
				
		case 2: printf("Deleted item : ");  
				scanf_s("%d", &a);
				puts("");
				delete_list(a); break;
				
		case 3: display_list(); break;
		
		case 4: break;
		
		default:
			puts("Try again");
		}
	}
}
