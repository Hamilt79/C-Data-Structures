#include <stdio.h>
#include "vec.h"

size_t vec_size(struct Vec *vec) {
    return vec->size;
}

void push_back(struct Vec *vec, void *element) {
    if (vec->size == 0UL) {
        vec->arr = (void**) malloc(sizeof(void*) * 1);
        if (vec->arr == NULL) {
            perror("Fail malloc\n");
            exit(1);
        }
        vec->arrLen++;
        vec->size++;
        vec->arr[0UL] = element;
        return;
    } 

    if (vec->arrLen == vec->size) {
        vec->arrLen *= 2UL;
        void* temp = realloc(vec->arr, sizeof(void*) * vec->arrLen);
        if (temp == NULL) {
            perror("Fail realloc\n");
            exit(1);
        }
        vec->arr = (void**) temp;
    }

    vec->arr[vec->size] = element; 
    vec->size++;
}

void free_vec(struct Vec* vec) {
    if (vec->arr != NULL && vec->arrLen > 0UL) {
        free(vec->arr);
    }
}

void* vec_get(struct Vec *vec, size_t index) {
    if (index < vec->size && index >= 0UL) {
        return vec->arr[index];
    }
    return NULL;
}

void vec_free_elements(struct Vec* vec) {
    for (size_t i = 0UL; i < vec->size; i++) {
        free(vec->arr[i]);
    }
}

void* vec_remove(struct Vec* vec, size_t index) {
    if (index < vec->size && index >= 0UL) {
        void *ptr = vec->arr[index];
        for (size_t i = index; i < (vec->size - 1UL); i++) {
           vec->arr[i] = vec->arr[i+1UL]; 
        }
        vec->size--;
        return ptr;
    }
    return NULL;
}

void vec_clear(struct Vec *vec) {
    vec->size = 0UL;
    vec->arrLen = 0UL;
    free_vec(vec);
}
