#include <stdio.h>

//노드 구조체
typedef struct node {
	int data;
	struct node* next;	//자기 구조체를 참조하는 포인터(자신의 다음 노드를 가리키기 위한 포인터)
}Node;

//노드 생성
Node* head = NULL;
Node* tail = NULL;	//아무 값이 저장되지 않은 더미 노드

//노드 초기화
void init() {
	head = (Node*)malloc(sizeof(Node));		//동적할당
	tail = (Node*)malloc(sizeof(Node));		//동적할당
	head->next = tail;	//next는 tail을 가르킨다.
	tail->next = NULL;	//NULL로 설정함으로써 리스트의 끝을 의미한다.
}

//노드 생성(리스트에 연결되지 않음)
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));	//동적할당
	newNode->data = data;
	newNode->next = NULL;	//아직 리스트에 연결하지 않음.
	return newNode;
}

//뒤에서 부터 삽입(후위 삽입)
void add_Back(int data) {
	Node* newNode = createNode(data);	//리스트에 연결되지 않은 노드 생성.
	Node* back = head;					//head부터 next값이 tail인 값을 찾는다.

	//back-next가 tail이 나올때까지 찾는다.
	//반복문이 끝나면 back-next는 tail을 가르키게 된다.
	while (back->next != tail) {
		back = back->next;
	}

	//(중요)링크 변경은 새 노드의 링크부터 변경해야 함.
	//back->next = newNode 먼저 나오면 안되는 이유 : 다른 노드에서 먼저 newNode에 연결시키면 newNode에서 tail 접근 불가
	newNode->next = tail;
	back->next = newNode;
}

//앞에서 부터 삽입(전위 삽입)
void add_Front(int data) {
	Node* front = createNode(data);		//리스트에 연결되지 않은 노드 생성.

	//맨앞은 head 다음이기 때문에 반복문으로 노드를 찾을 필요없음.
	front->next = head->next;	//head->next를 newNode의 next에 넣는다.
	head->next = front;			//head->next에 가장 처음값이 된 newNode의 주소값을 넣는다.
}

//key 값을 갖는 node를 찾아서 data를 그 뒤에 삽입한다.
void insert_Node(int key, int data) {
	Node* newNode = createNode(data);

	//key값을 찾는다.
	Node* p = head->next;
	while (p != tail) {
		//p의 data가 key와 같으면 반복문 탈출
		if (p->data == key) break;
		p = p->next;
	}
	newNode->next = p->next;
	p->next = newNode;
}

//앞에서 부터 삭제
void pop_Front() {
	//빈 리스트에 대한 예외처리
	//if (empty()) return;

	//head->next를 알 수 없게 되므로 저장한다.(동적할당해제에 사용)
	Node* p = head->next;

	//삭제한 head->next의 다음 노드
	//삭제 후 head->next가 head->next->next가 되므로 기존의 head->next는 접근 불가.
	head->next = head->next->next;

	free(p);
}

//뒤에서 부터 삭제
void pop_Back() {
	//빈 리스트에 대한 예외처리
	if (head->next == tail) return;

	Node* p = head->next;
	Node* pre_p = head;		//p의 이전 주소값(삭제된 것의 다음값을 가르켜야 한다.)ㄴ

	while (p->next != tail) {
		pre_p = p;
		p = p->next;
	}
	pre_p->next = tail;		//pop_back은 마지막 값을 삭제하므로 p의 이전값이 마지막 값이 된다.
	free(p);				//p(삭제된 노드) 동적할당 해제
}

//동일한 데이터 값인 노드 삭제
void remove_Node(int key) {
	//if (empty()) return;

	//key값 찾기
	Node* p = head->next;
	while (p != tail) {
		//p의 data가 key와 같으면 반복문 탈출
		if (p->data == key) break;
		p = p->next;
	}

	Node* tmp = head->next;
	Node* pre_p = head;//삭제할 노드의 앞 노드

	while (pre_p->next->data != p->data) {
		pre_p = tmp;
		tmp = tmp->next;
	}

	pre_p->next = p->next;
	free(p);
}

//전체 노드삭제
void AllRemove() {
	while (head->next != tail) {
		pop_Front();
	}
	free(head);
	free(tail);
}

//노드 데이터 출력
void print_Node() {
	Node* p = head->next;
	while (p != tail) {
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}

//메인
void main()
{
	//노드 초기화
	init();

	//노드 삽입
	for (int i = 0; i < 10; i++) {
		add_Front(i);
	}
	for (int i = 10; i < 20; i++) {
		add_Back(i);
	}
	insert_Node(7, 777);	//key 값을 갖는 node를 찾아서 data를 그 뒤에 삽입한다.

	//출력-삽입확인
	print_Node();

	//노드 삭제
	pop_Front();
	pop_Back();
	remove_Node(5);		//동일한 데이터 값인 노드 삭제

	//출력-일부 삭제 확인
	print_Node();

	//전체노드 삭제
	AllRemove();

	//출력-전체 삭제 확인
	print_Node();
}