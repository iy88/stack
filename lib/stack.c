#include "stack.h"

void copy(void* dst, void* src, int size) {
	char* d = dst;
	char* s = src;
	while (size-- > 0) {
		*d++ = *s++;
	}
}

stackPtr createStack() {
	stackPtr st = (stackPtr)malloc(sizeof(stack));
	if (st == NULL) {
		return NULL;
	}
	st->size = 0;
	st->head = (Node*)malloc(sizeof(Node));
	if (st->head == NULL) {
		free(st);
		return NULL;
	}
	st->head->next = NULL;
	st->head->data = NULL;
	st->head->size = NULL;
	return st;
}

int stackPush(stackPtr st, void* data, int size) {
	NodePtr current = st->head;
	if (current->data == NULL) {
		current->data = malloc(size);
		if (current->data == NULL) {
			return 0;
		}
		current->size = size;
		copy(current->data, data, size);
		st->size++;
		return 1;
	}
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = (Node*)malloc(sizeof(Node));
	if (current->next == NULL) {
		return 0;
	}
	current->next->data = malloc(size);
	if (current->next->data == NULL) {
		return 0;
	}
	current->next->size = size;
	copy(current->next->data, data, size);
	current->next->next = NULL;
	st->size++;
	return 1;
}

void* stackPop(stackPtr st) {
	NodePtr current = st->head;
	if (current->next == NULL) {
		if (current->data == NULL) {
			return NULL;
		}
		else {
			void* res = malloc(current->size);
			if (res == NULL) {
				return NULL;
			}
			copy(res, current->data, current->size);
			free(current->data);
			current->data = NULL;
			current->size = NULL;
			st->size = 0;
			return res;
		}
	}
	while (current->next->next != NULL) {
		current = current->next;
	}
	void* res = malloc(current->next->size);
	if (res == NULL) {
		return NULL;
	}
	copy(res, current->next->data, current->next->size);
	free(current->next->data);
	free(current->next);
	current->next = NULL;
	st->size--;
	return res;
}

void cleanNode(NodePtr node) {
	if (node->next != NULL) {
		cleanNode(node->next);
	}
	free(node->data);
	free(node);
}

void stackClean(stackPtr st) {
	NodePtr current = st->head;
	if (current->next == NULL) {
		if (current->data) {
			free(current->data);
			current->data = NULL;
			current->size = NULL;
		}
	}
	else {
		free(current->data);
		current->data = NULL;
		current->size = NULL;
		cleanNode(current->next);
		current->next = NULL;
	}
	st->size = 0;
}

void stackDestory(stackPtr st) {
	free(st);
}