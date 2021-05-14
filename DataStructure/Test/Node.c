#include <stdio.h>

//��� ����ü
typedef struct node {
	int data;
	struct node* next;	//�ڱ� ����ü�� �����ϴ� ������(�ڽ��� ���� ��带 ����Ű�� ���� ������)
}Node;

//��� ����
Node* head = NULL;
Node* tail = NULL;	//�ƹ� ���� ������� ���� ���� ���

//��� �ʱ�ȭ
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
	Node* front = createNode(data);		//����Ʈ�� ������� ���� ��� ����.

	//�Ǿ��� head �����̱� ������ �ݺ������� ��带 ã�� �ʿ����.
	front->next = head->next;	//head->next�� newNode�� next�� �ִ´�.
	head->next = front;			//head->next�� ���� ó������ �� newNode�� �ּҰ��� �ִ´�.
}

//key ���� ���� node�� ã�Ƽ� data�� �� �ڿ� �����Ѵ�.
void insert_Node(int key, int data) {
	Node* newNode = createNode(data);

	//key���� ã�´�.
	Node* p = head->next;
	while (p != tail) {
		//p�� data�� key�� ������ �ݺ��� Ż��
		if (p->data == key) break;
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
}

//�տ��� ���� ����
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

//�ڿ��� ���� ����
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

//������ ������ ���� ��� ����
void remove_Node(int key) {
	//if (empty()) return;

	//key�� ã��
	Node* p = head->next;
	while (p != tail) {
		//p�� data�� key�� ������ �ݺ��� Ż��
		if (p->data == key) break;
		p = p->next;
	}

	Node* tmp = head->next;
	Node* pre_p = head;//������ ����� �� ���

	while (pre_p->next->data != p->data) {
		pre_p = tmp;
		tmp = tmp->next;
	}

	pre_p->next = p->next;
	free(p);
}

//��ü ������
void AllRemove() {
	while (head->next != tail) {
		pop_Front();
	}
	free(head);
	free(tail);
}

//��� ������ ���
void print_Node() {
	Node* p = head->next;
	while (p != tail) {
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

//����
void main()
{
	//��� �ʱ�ȭ
	init();

	//��� ����
	for (int i = 0; i < 10; i++) {
		add_Front(i);
	}
	for (int i = 10; i < 20; i++) {
		add_Back(i);
	}
	insert_Node(7, 777);	//key ���� ���� node�� ã�Ƽ� data�� �� �ڿ� �����Ѵ�.

	//���-����Ȯ��
	print_Node();

	//��� ����
	pop_Front();
	pop_Back();
	remove_Node(5);		//������ ������ ���� ��� ����

	//���-�Ϻ� ���� Ȯ��
	print_Node();

	//��ü��� ����
	AllRemove();

	//���-��ü ���� Ȯ��
	print_Node();
}