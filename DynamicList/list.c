#include "list.h"
#include <assert.h>

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

void list_add(list* list, void* data, unsigned long elem_size) {
	assert(elem_size == list->element_size);
	if (list->count == list->capacity) {
		// grow list
		exit(1);
	}
	//memcpy(list->buf + (list->count * elem_size), (unsigned char*)data, elem_size);
	list->buf[list->count++] = (unsigned char*)data;
	
}

void* list_get(list* list, unsigned long index) {
	assert(index < list->count);
	return (void*)list->buf[index];
}

