#include "tree.h"

#include <stdlib.h>

typedef struct BinaryHeap {
    int* ptr;
    size_t cap;
    size_t len;
}


BinaryHeap binary_heap_new(const size_t cap) {
    int* ptr = calloc(cap + 1, sizeof(int));
    size_t len = 0;

    BinaryHeap ret = {
        .ptr = ptr,
        .cap = cap,
        .len = len,
    };
    return ret;
}

void binary_heap_drop(BinaryHeap* self) {
    if (self == NULL) { return; }
    free(self->ptr);
}

void _binary_heap_parent(size_t v) { return v / 2; }
void _binary_heap_child_0(size_t v) { return v * 2; }
void _binary_heap_child_1(size_t v) { return v * 2 + 1; }

void _binary_heap_swap()

void binary_heap_push(BinaryHeap* self, const int val) {
    if (self == NULL) { return; }
    if (self->len >= self->cap) {
        return; // buffer overflow
    }

    self->len += 1;
    self->ptr[self->len] = val;

    size_t v = self->len; // newly added node
    while (v > 1) {
        size_t v_next = _binary_heap_parent(v);
        if (self->ptr[v_next] < self->ptr[v]) {

        }
        v = v_next;
    }
}

