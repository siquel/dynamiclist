#ifndef LIST_H
#define LIST_H

typedef struct {
	unsigned char* buf;
	unsigned long count;
	unsigned long element_size;
	unsigned long reserve;
	unsigned long capacity;
} list;


list* list_new(unsigned long elem_size);
void list_free(list* list);

unsigned long list_count(list* list);

void list_add(list* list, void* data, unsigned long elem_size);

void* list_get(list* list, unsigned long index);

#endif