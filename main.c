#include "lib/stack.h"
#include <stdio.h>

int main() {
	stackPtr st = createStack();
	if (st == NULL) {
		exit(-1);
	}
	char* p = malloc(sizeof(char));
	if (p == NULL) {
		exit(-1);
	}
	*p = 65;
	printf("now len: %lld\n", st->size);
	for (; (int)*p < 91; (*p)++) {
		int ret = stackPush(st, p, sizeof(int));
		printf("ret: %d\n", ret);
		printf("now len: %lld\n", st->size);
	}
	printf("------------------------------------\n");
	for (int i = 0; i < 26; i++) {
		p = stackPop(st);
		printf("res: %c\n", *p);
		printf("now len: %lld\n", st->size);
	}
	printf("------------------------------------\n");
	//stackClean(st);
	//printf("now len: %lld\n", st->size);
	stackDestory(st);
	st = NULL;
	return 0;
}