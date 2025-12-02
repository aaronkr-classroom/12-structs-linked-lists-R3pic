#include <stdio.h>
#include <malloc.h>

typedef struct {
	int number;
	struct Node* p_next;
} Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node));
		*pp_tail = (*pp_tail)->p_next; 
	}
	else {
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;

	}
	(*pp_tail)->number = data;
	(*pp_tail)->p_next = NULL;

}

int main() {
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	while (1) {

		printf("숫자를 입력하세요 (9999를 누르면 종료): ");
		scanf_s("%d", &temp);

		if (9999 == temp)break;
		AddNumber(&p_head, &p_tail, temp);
		
	}

	p = p_head;
	while (NULL != p) {
		if (p != p_head) {
			printf(" + "); 
		}
		printf("%d", p->number);

		sum = sum + p->number;
		p = p->p_next;

	}

	printf(" = %d\n", sum);

	while (NULL != p_head) {
		p = p_head;
		p_head = p_head->p_next;
		free(p);

	}
	p_tail = p_head;

	return 0;
}