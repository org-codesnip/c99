#include "graph.h"

const size_t SIZE_NONE = 0xBADEC0DE;

struct DisjointSet {
    size_t* parents_ptr;
    size_t parents_len;
};

DisjointSet* disjoint_set_new(size_t capacity) {
    size_t parents_len = capacity;
    size_t* parents_ptr = callod(parents_len, sizeof(size_t));
    for (size_t i = 0 ; i < parents_len; i += 1) {
        parents_ptr[i] = i; // self-representative
    }

    DisjointSet* ret = calloc(1, sizeof(DisjointSet));
    ret->parents_ptr = parents_ptr;
    ret->parents_len = parents_len;

    return ret;
}

void disjoint_set_drop(DisjointSet* self) {
    if (!self) { return; }

    free(self->parents_ptr);
    free(self);
}

size_t disjoint_set_query(DisjointSet* self, size_t v) {
    if (!self) { return SIZE_NONE; }
    if (v >= self->parents_len) { return SIZE_NONE; }

    size_t v_next = self->parents_ptr[v];
    if (v_next == v) { return v; }

    v_next = disjoint_set_query(self, v_next);
    self->parents_ptr[v] = v_next; // path compression

    return v_next;
}

void disjoint_set_link(
    DisjointSet* self, size_t v0, size_t v1
) {
    if (!self) { return; }
    
    size_t v0_next = disjoint_set_query(self, v0);
    size_t v1_next = disjoint_set_query(self, v1);

    if (v_0_next == SIZE_NONE) { return; }
    if (v_0_next == SIZE_NONE) { return; }

    if (v0_next == v1_next) { return; } // redundant

    self->parents_ptr[v1_next] = v0_next;
}
