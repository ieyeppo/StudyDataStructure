#include <stdio.h>

//0-��� ����ü
typedef struct node {
	int data;
	struct node* next;	//�ڱ� ����ü�� �����ϴ� ������(�ڽ��� ���� ��带 ����Ű�� ���� ������)
}Node;

//1-��� ����
Node* head = NULL;
Node* tail = NULL;	//�ƹ� ���� ������� ���� ���� ���

//2-��� �ʱ�ȭ
void init() {
	head = (Node*)malloc(sizeof(Node));		//�����Ҵ�
	tail = (Node*)malloc(sizeof(Node));		//�����Ҵ�
	head->next = tail;	//next�� tail�� ����Ų��.
	tail->next = NULL;	//NULL�� ���������ν� ����Ʈ�� ���� �ǹ��Ѵ�.
}

//��� ����(����Ʈ�� ������� ����)
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	//�����Ҵ�
	newNode->data = data;
	newNode->next = NULL;	//���� ����Ʈ�� �������� ����.
	return newNode;
}

//�ڿ��� ���� ����(���� ����)
void add_Back(int data) {
	Node* newNode = createNode(data);	//����Ʈ�� ������� ���� ��� ����.
	Node* back = head;					//head���� next���� tail�� ���� ã�´�.

	//back-next�� tail�� ���ö����� ã�´�.
	//�ݺ����� ������ back-next�� tail�� ����Ű�� �ȴ�.
	while (back->next != tail) {
		back = back->next;
	}
	
	//(�߿�)��ũ ������ �� ����� ��ũ���� �����ؾ� ��.
	//back->next = newNode ���� ������ �ȵǴ� ���� : �ٸ� ��忡�� ���� newNode�� �����Ű�� newNode���� tail ���� �Ұ�
	newNode->next = tail;	
	back->next = newNode;
}

//�տ��� ���� ����(���� ����)
void add_Front(int data) {
	Node* front = create(data);		//����Ʈ�� ������� ���� ��� ����.

	//�Ǿ��� head �����̱� ������ �ݺ������� ��带 ã�� �ʿ����.
	front->next = head->next;	//head->next�� newNode�� next�� �ִ´�.
	head->next = front;			//head->next�� ���� ó������ �� newNode�� �ּҰ��� �ִ´�.
}

//key ���� ���� node�� ã�Ƽ� data�� �� �ڿ� �����Ѵ�.
void insertNode(int key, int data) {
	Node* newNode = createNode(data);

	//key���� ã�´�.
	Node* insert = findNode(key);
	newNode->next = insert->next;
	insert->next = newNode;
}

//key�� ���� ã�� �� ��ġ�� Node* �������� ��ȯ�ϴ� �Լ�.
Node* findNode(int key) {
	Node* p = head->next;
	while (p != tail) {
		//p�� data�� key�� ������ �ݺ��� Ż��
		if (p->data == key) break;
		p = p->next;
	}
	return p;
}

void pop_Front() {
	//�� ����Ʈ�� ���� ����ó��
	//if (empty()) return;

	//head->next�� �� �� ���� �ǹǷ� �����Ѵ�.(�����Ҵ������� ���)
	Node* p = head->next;	

	//������ head->next�� ���� ���
	//���� �� head->next�� head->next->next�� �ǹǷ� ������ head->next�� ���� �Ұ�.
	head->next = head->next->next;	

	free(p);
}

void pop_Back() {
	//�� ����Ʈ�� ���� ����ó��
	if (head->next == tail) return;

	Node* p = head->next;
	Node* pre_p = head;		//p�� ���� �ּҰ�(������ ���� �������� �����Ѿ� �Ѵ�.)��

	while (p->next != tail) {
		pre_p = p;
		p = p->next;
	}
	pre_p->next = tail;		//pop_back�� ������ ���� �����ϹǷ� p�� �������� ������ ���� �ȴ�.
	free(p);				//p(������ ���) �����Ҵ� ����
}

void removeNode(int key) {
	//if (empty()) return;

	//key�� ã��
	Node* p = findNode(key);

	Node* tmp = head->next;
	Node* pre_p = head;//������ ����� �� ���

	while (pre_p->next->data != p->data) {
		pre_p = tmp;
		tmp = tmp->next;
	}

	pre_p->next = p->next;
	free(p);
}

void clear() {
	while (head->next != tail) {
		pop_Front();
	}
}

void print_Node() {
	Node* p = head->next;
	while (p != tail) {
		printf("%5d", p->data);
		p = p->next;
	}
}

void main()
{
	//2-��� �ʱ�ȭ
	init();

	//3-��� ����
	for (int i = 0; i < 10; i++) {
		add_Front(i);
	}
	for (int i = 10; i < 20; i++) {
		add_Back(i);
	}
	insertNode(7, 777);

	//���-����Ȯ��
	print_Node();

	//��� ����
	pop_Front();
	pop_Back();
	removeNode(5);

	//���-�Ϻ� ���� Ȯ��
	print_Node();

	//��ü��� ����
	clear();

	//���-��ü ���� Ȯ��
	print_Node();
}