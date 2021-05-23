#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define  StackSize  1000

typedef struct {
	int* data;
	int top;
	int Size;
}MyStack;

MyStack* Create() {
	MyStack* obj = malloc(sizeof(MyStack));
	obj->data = malloc(sizeof(int) * StackSize);
	obj->top = -1;
	obj->Size = StackSize;
}

void StackPush(MyStack* obj, int val) {
	if (obj->top == StackSize - 1) {

	}
	else {
		obj->top++;
		obj->data[obj->top] = val;
	}
}

void StackPop(MyStack* obj) {
	if (obj->top == -1) {

	}
	obj->top--;
}

int StackTop(MyStack* obj) {
	if (obj->top == -1) {
		return;
	}
	return obj->data[obj->top];
}

int MinStack(MyStack* obj) {
	if (obj->top == -1) {
		return;
	}
	if (obj->top == 0) {
		return obj->data[0];
	}
	int min = obj->data[0];
	for (int i = 0; i <= obj->top; i++) {
		if (obj->data[i] < min) {
			min = obj->data[i];
		}
	}
	return min;
}

void StackFree(MyStack* obj) {
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}

/*
* һ��ջ��Ԫ����:data(������),top(ջ��)
* 1.��ʼ��ջ
* 2.��ջ(Push)
* 3.��ջ(Pop)
* 4.���ջ��Ԫ��
* 5.���ջ����Сֵ
* 6.�ͷ�ջ�ռ�
*/
