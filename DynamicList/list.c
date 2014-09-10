#include "list.h"


list* list_new(unsigned long elemSize) {
	list* vec = (list*)malloc(sizeof(list));
	vec->capacity = 10;
	vec->count = 0;
	vec->element_size = elemSize;
	vec->reserve = vec->capacity;
	vec->buf = (unsigned char*)malloc(vec->reserve * vec->element_size);
	return vec;
}


void list_free(list* list) {
	free(list->buf);
	free(list);
}

unsigned long list_count(list* list) {
	return list->count;
}

