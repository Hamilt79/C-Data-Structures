#include <stdlib.h>
#include <stdio.h>
#include "vec.h"

int main() {
    struct Vec vec;
    for (size_t i = 0; i < 4000000UL; i++) {
        int *temp = (int*) malloc(sizeof(int));
        *temp = i;
        push_back(&vec, temp);
    }
    printf("Vec Size: %lu\n", vec.size);
    printf("Vec Len: %lu\n", vec.arrLen);
    vec_free_elements(&vec);
    vec_clear(&vec);
    printf("Vec Size: %lu\n", vec.size);
    printf("Vec Len: %lu\n", vec.arrLen);

    for (int i = 0; i < 4; i++) {
        int *temp = (int*) malloc(sizeof(int));
        *temp = i;
        push_back(&vec, temp);
    }

    printf("Vec Size: %lu\n", vec.size);
    printf("Vec Len: %lu\n", vec.arrLen);

    int *removed = (int*) vec_remove(&vec, 1);
    free(removed);

    printf("Vec Size: %lu\n", vec.size);
    printf("Vec Len: %lu\n", vec.arrLen);

    for (int i = 0; i < vec.size; i++) {
        printf("Vec[%d]: %d\n", i, *(int*)vec_get(&vec, i));
        free(vec_get(&vec, i));
    }

    free_vec(&vec);
    return EXIT_SUCCESS;
}
