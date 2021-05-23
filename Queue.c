#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* data;
	int front;
	int tail;
	int size;
	int flag;
}MyQueue;

MyQueue* Create(int k) {
	if (k < 0) {
		return NULL;
	}
	MyQueue* obj = malloc(sizeof(MyQueue));
	if (obj == NULL) {
		return NULL;
	}
	obj->data = malloc(sizeof(int) * k);
	if (obj->data == NULL) {
		return NULL;
	}
	obj->front = obj->tail = 0;
	obj->size = k;
	obj->flag = 0;

	return obj;
}

bool IsEmpty(MyQueue* obj) {
	if (obj->flag == 0 && obj->front == obj->tail) {
		return true;
	}
	return false;
}

bool IsFull(MyQueue* obj) {
	if (obj->flag == 1) {
		return true;
	}
	return false;
}

bool EnQueue(MyQueue* obj, int value) {
	if (IsFull(obj)) {
		return false;
	}

	obj->data[obj->tail] = value;
	obj->tail = ((obj->tail + 1) < obj->size) ? (obj->tail + 1) : 0;

	if (obj->front == obj->tail) {
		obj->flag = 1;
	}
	return true;
}

bool DeQueue(MyQueue* obj) {
	if (IsEmpty(obj)) {
		return false;
	}

	obj->data[obj->front] = 0;
	obj->front = ((obj->front + 1) < obj->size) ? (obj->front + 1) : 0;

	obj->flag = 0;
	return true;
}

int FrontQueue(MyQueue* obj) {
	if (IsEmpty(obj)) {
		return -1;
	}
	return obj->data[obj->front];
}

int TailQueue(MyQueue* obj) {
	if (IsEmpty(obj)) {
		return false;
	}
	int i = (obj->tail == 0) ? (obj->size - 1) : (obj->tail - 1);
	return obj->data[i];
}

void FreeQueue(MyQueue* obj) {
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}

/*
* һ�����е�Ԫ����:
* data(������),front,tail(ͷָ�룬βָ��),
* size(���еĴ�С),flag(�Ǳ�Ҫ������������־����״̬:��/��)
* 1.����һ��k��ʼ������
* 2.�ж϶����Ƿ�Ϊ��
* 3.�ж϶����Ƿ�����
* 4.���һ������(���)
* 5.ɾ��һ������(����)
* 6.������е�ͷԪ��
* 7.������е�βԪ��
* 8.�ͷŶ��пռ�
*/