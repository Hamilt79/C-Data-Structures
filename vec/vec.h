#ifndef _VEC_H
#define _VEC_H

#include <stdlib.h>
#include <stddef.h>

struct Vec {
    size_t size;
    size_t arrLen;
    void **arr;
};

size_t vec_size(struct Vec *vec);
void push_back(struct Vec *vec, void *element);
void free_vec(struct Vec* vec);
void* vec_get(struct Vec *vec, size_t index);
void vec_free_elements(struct Vec* vec);
void* vec_remove(struct Vec* vec, size_t index);
void vec_clear(struct Vec* vec);

#endif
