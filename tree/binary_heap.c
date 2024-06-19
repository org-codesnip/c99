#include "tree.h"

#include <stdlib.h>

// Max-heap implementation
typedef struct BinaryHeap_t {
    int* ptr;
    size_t cap;
    size_t len;
} BinaryHeap;

BinaryHeap binary_heap_new(const size_t cap) {
    int* ptr = calloc(cap, sizeof(int));
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

void _binary_heap_swap(BinaryHeap* self, size_t op_0, size_t op_1) {
    int t_0 = self->ptr[op_0];
    self->ptr[op_0] = self->ptr[op_1];
    self->ptr[op_1] = t_0;
}

void _binary_heap_swap_up(BinaryHeap* self, size_t v) {
    if (v < 1) { return; }
    size_t v_next = (v - 1) / 2; // parent
    if (self->ptr[v_next] >= self->ptr[v]) {
        // already completed max-heap
        return;
    }
    _binary_heap_swap(self, v, v_next);
    _binary_heap_swap_up(self, v_next);
}

void binary_heap_push(BinaryHeap* self, const int val) {
    if (self == NULL) { return; }
    if (self->len >= self->cap) {
        return; // buffer overflow
    }

    self->ptr[self->len] = val;
    self->len += 1;

    _binary_heap_swap_up(self, self->len - 1);
}

void _binary_heap_swap_down(BinaryHeap* self, size_t v) {
    if (v >= self->len) { return; }
    size_t v_next = v;
    size_t v_child_0 = v * 2 + 1;
    size_t v_child_1 = v * 2 + 2;
    if (v_child_0 < self->len && self->ptr[v_child_0] > self->ptr[v_next]) {
        v_next = v_child_0;
    }
    if (v_child_1 < self->len && self->ptr[v_child_1] > self->ptr[v_next]) {
        v_next = v_child_1;
    }
    if (v == v_next) { return; }
    _binary_heap_swap(self, v, v_next);
    _binary_heap_swap_down(self, v_next);
}

int binary_heap_pop(BinaryHeap* self) {
    if (self->len < 1) { return 0xEADBEEF; }

    int ret = self->ptr[0];
    self->len -= 1;
    _binary_heap_swap(self, 0, self->len);

    _binary_heap_swap_down(self, 0);

    return ret;
}

