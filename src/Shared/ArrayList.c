#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ArrayList.h"

array_list* list_new(const int32_t element_size) {
    array_list* list = (array_list*) malloc(sizeof(array_list));
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    list->entry_size = element_size;
    list->array = (void*)malloc(INITIAL_CAPACITY * element_size);
    return list;
}

void list_add(array_list* list, void* p) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->array = (void*)realloc(list->array, list->capacity * list->entry_size);
    }
    memcpy((char*)list->array + list->size * list->entry_size, p, list->entry_size);
    list->size += 1;
}

void* list_get(array_list* list, int32_t i) {
    return (void*)((char*)list->array + i * list->entry_size);
}

void list_set(array_list* list, int32_t i, void* value_p) {
    memcpy((char*)list->array + i * list->entry_size, value_p, list->entry_size);
}

void list_clear(array_list* list) {
    list->size = 0;
}

void list_free(array_list* list) {
    free(list->array);
    free(list);
}