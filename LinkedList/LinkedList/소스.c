#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int data;
	struct listNode* next;
};

struct listNode* first = 0;
struct listNode* left = 0;

void printAll();
void addNode(int);
void leftN(int);
void rightN(int);

void main()
{
	addNode(10);
	addNode(20);
	addNode(30);
	addNode(40);
	addNode(50);
	addNode(60);
	addNode(70);
	addNode(80);
	addNode(90);
	addNode(100);
	addNode(110);
	addNode(120);
	addNode(130);
	addNode(140);
	addNode(150);
	addNode(160);
	addNode(170);
	addNode(180);
	addNode(190);
	addNode(200);

	while (1) {

		int l, n, num;
		printf("linked list: ");
		printAll();
		printf("\n���° ����Ʈ���� �������� ����: ");
		scanf_s("%d", &l);
		rightN(l - 1);
		printf("\n1.�־��� ��ġ���� n��常ŭ ���������� �̵� \n");
		printf("\n2.�־��� ��ġ���� n��常ŭ �������� �̵�  \n");
		printf("\n3.���α׷� ����\n");
		printf("\n���� �Է�: ");
		scanf_s("%d", &num);

		if (num == 1) {
			printf("\nn�� ũ��: ");
			scanf_s("%d", &n);
			rightN(n);
			printf("\n");
			printAll();
			printf("\n");
		}
		else if (num == 2) {
			printf("\nn�� ũ��: ");
			scanf_s("%d", &n);
			leftN(n);
			printf("\n");
			printAll();
			printf("\n");
		}
		else if (num == 3)
			exit(1);
		else
			printf("�ùٸ� ���ڸ� �Է��ϼ���.\n\n");
	}
	return 0;
}

void printAll()
{
	struct listNode* temp;
	temp = first;
	while (temp != 0) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void addNode(int i)
{
	struct listNode* p;
	p = malloc(sizeof(struct listNode));
	p->data = i;
	p->next = 0;
	if (first == 0)
	{
		first = p;
	}
	else
	{
		struct listNode* temp;
		temp = first;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = p;
	}
}

void leftN(int n)
{
	struct listNode* temp = 0;
	int i = 0;
	while (i < n && left != 0)
	{
		temp = left->next;
		left->next = first;
		first = left;
		left = temp;
		i++;
	}
}

void rightN(int n)
{
	struct listNode* temp = 0;
	int i = 0;
	while (i < n && first != 0)
	{
		temp = first->next;
		first->next = left;
		left = first;
		first = temp;
		i++;
	}
}