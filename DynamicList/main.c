#include "list.h"
#include <assert.h>

int main() {
	list* list = list_new(sizeof(int));

	assert(list_count(list) == 0);

	list_free(list);
	
	return 0;
}