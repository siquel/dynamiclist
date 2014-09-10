#include "list.h"
#include <assert.h>

int main() {
	list* list = list_new(sizeof(int));

	assert(list_count(list) == 0);
	list_add(list, 2, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));
	list_add(list, 3, sizeof(int));

	assert(list_get(list, 0) == 2);
	assert(list_get(list, 4) == 3);
	list_free(list);
	
	return 0;
}