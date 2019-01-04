#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct stack {
	Node *top;
	int count;
};

struct list
{
	Node *pHead;
	Node *next;
};

struct queue
{
	Node *front;
	Node *rear;
	int count;
};

bool emptyStack(stack *s) {
	if (!s) return true;
	if (s->top == NULL || s->count == 0) return true;
	else return false;
}

bool emptyQueue(queue *s) {
	if (!s) return true;
	if (s->front == NULL || s->count == 0) return true;
	else return false;
}

void clearStack(stack *s) {
	if (!s) return;
	Node *pDel;
	while (!emptyStack(s)) {
		pDel = s->top;
		s->top = s->top->next;
		s->count--;
		delete pDel;
		pDel = NULL;
	}
}
	
void clearQueue(queue *s) {
	if (!s) return;
	Node *pDel;
	while (!emptyQueue(s))
	{
		pDel = s->front;
		s->front = s->front->next;
		if (s->count == 1) s->rear->next;
		s->count--;
		delete pDel; 
		pDel = NULL;
	}
}

void PushStack(stack *s, int data) {
	if (!s) return;
	Node *pNew = new Node;
	pNew->data = data;
	if (emptyStack(s)) {
		s->top = pNew;
		pNew->next = NULL;
	}
	else {
		pNew->next = s->top;
		s->top = pNew;
	}
	s->count++;
}

void PopStack(stack *s, int data) {
	if (!s) return;
	if (!emptyStack(s)) {
		data = s->top->data;
		Node *pDel = s->top;
		s->top = s->top->next;
		delete pDel;
		pDel = NULL;
		s->count--;
	}
}

int sizeStack(stack *s) {
	return s->count;
}

int sizeQueue(queue *q) {
	return q->count;
}

int topStack(stack *s) {
	if (!s) return NULL;
	if (!emptyStack(s)) return s->top->data;
}

void enQueue(queue *q, int data) {
	if (!q) return;
	Node *pNew = new Node;
	pNew->data = data;
	if (emptyQueue(q)) {
		q->front = pNew;
		q->rear = pNew;
		pNew->next = NULL;
	}
	else {
		q->rear->next = pNew;
		pNew->next = NULL;
		q->rear = pNew;
	}
	q->count++;
}

void deQueue(queue *q) {
	int data;
	if (!q) return;
	if (emptyQueue(q)) {
		data = q->front->data;
		Node *pDel = q->front;
		if (q->count == 1)
			q->rear = q->rear->next;
		q->front = q->front->next;
		q->count--;
		delete pDel;
	}
}

void queueFront(queue *q, int data) {
	if (!q) return;
	if (!emptyQueue(q)) data = q->front->data;
}

void queueRear(queue *q, int data) {
	if (!q) return;
	if (!emptyQueue(q)) data = q->rear->data;
}

void stackToQueue(stack *s, queue *q){
	//queue *q = new queue;
	while (!emptyStack(s))
	{
		Node *pNew = new Node;
		pNew= s->top;
		enQueue(q, pNew->data);
		s->top = s->top->next;
		delete pNew;
	
	}
}

void queueToStack(queue *q, stack *s) {
	while (!emptyQueue(q))
	{
		Node *pNew = new Node;
		pNew = q->rear;
		PushStack(s, pNew->data);
		q->rear = q->rear->next;
		delete pNew;
	}
}

void printStack(stack *s) {
	Node *p;
	p = s->top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void printQueue(queue *q) {
	Node *p;
	p = q->front;
	cout << "front: ";
	while (p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{	
	cout << "Stack: " << endl;
	stack *myStack = new stack();
	queue *myQueue = new queue();
	stack *myStack1 = new stack();
	queue *myQueue1 = new queue();
	int val;
	PushStack(myStack, 7);
	PushStack(myStack, 9);
	PushStack(myStack, 2);
	PushStack(myStack, 10);
	PushStack(myStack, 5);
	
	printStack(myStack);
	stackToQueue(myStack, myQueue);
	printQueue(myQueue);
	if (emptyStack(myStack)) cout << "Stack is NULL"<<endl;
	
	enQueue(myQueue1, 2);
	enQueue(myQueue1, 3);
	enQueue(myQueue1, 7);
	enQueue(myQueue1, 1);
	enQueue(myQueue1, 0);
	enQueue(myQueue1, 9);
	printQueue(myQueue1);
	//queueToStack(myQueue1, myStack1);
	//printStack(myStack1);
	//printQueue(myQueue1);
	//delete myStack;
	system("pause");
	return 0;
}
