#include "list.h"
#include <assert.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	int how;
	int doi;
	char* host;
} jeesus;

int main() {
	list* list = list_new(sizeof(int), 4);
	
	int* val = list_create_elem(list);
	*val = 50;
	int* val2 = list_create_elem(list);
	*val2 = 100;
	list_add(list, val, sizeof(int));
	list_add(list, val2, sizeof(int));

	int *end = list_end(list);
	for (int i = 0; i < list->count; i++) {
		int *val = list->buf[i];
		printf("%d\n", *val);
	}
	

	list_free(list);
	
	return 0;
}