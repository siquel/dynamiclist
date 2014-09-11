#ifndef LIST_H
#define LIST_H

typedef struct {
	void** buf;
	unsigned long count;
	unsigned long element_size;
	unsigned long capacity;
} list;


list* list_new(unsigned long elem_size, unsigned long capacity);
void list_free(list* list);

unsigned long list_count(list* list);

void list_add(list* list, void* data, unsigned long elem_size);

void* list_get(list* list, unsigned long index);

void list_grow(list* list);

void* list_begin(list* list);

void* list_end(list* list);

void* list_create_elem(list* list);
#endif