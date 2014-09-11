#include "list.h"
#include <assert.h>

list* list_new(unsigned long elemSize, unsigned long capacity) {
	list* vec = (list*)malloc(sizeof(list));
	vec->capacity = capacity;
	vec->count = 0;
	vec->element_size = elemSize;
	vec->buf = calloc(vec->capacity, sizeof(void*));
	
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
		list_grow(list);
	}
	//memcpy(list->buf + (list->count * elem_size), data, elem_size);
	list->buf[list->count++] = data;
	
}

void* list_get(list* list, unsigned long index) {
	assert(index < list->count);
	return list->buf[index];
}

void* list_create_elem(list* list) {
	return calloc(1, list->element_size);
}

void list_grow(list* list)
{
	unsigned long newcap = list->capacity * 2;
	void* mem = realloc(list->buf, newcap * sizeof(void*));
	//memcpy(mem, list->buf, list->capacity * list->element_size);
	//free(list->buf);
	list->buf = mem;
	list->capacity = newcap;
}

void* list_begin(list* list) {
	return list->buf[0];
}

void* list_end(list* list) {
	return list->buf[list->count - 1];
}

