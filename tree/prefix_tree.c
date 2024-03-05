#include "tree.h"

#include <stdlib.h>
#include <stdio.h>

#define CHILD_CAP 26

struct PrefixTree {
    bool epsilon;
    PrefixTree* children[CHILD_CAP];
};

PrefixTree* prefix_tree_new() {
    return calloc(1, sizeof(PrefixTree));
}

void prefix_tree_drop(PrefixTree* self) {
    if (!self) { return; }

    for (size_t i = 0 ; i < CHILD_CAP; i += 1) {
        prefix_tree_drop(self->children[i]);
    }
    free(self);
}

void prefix_tree_push(
    PrefixTree* self,
    char* word_ptr, size_t word_len
) {
    if (self == NULL) { return; }
    if (word_len < 1) {
        self->epsilon = true;
        return;
    }

    // pop char from stack
    char c = word_ptr[word_len - 1];
    if (islower(c) < 1) { return; }
    size_t e = (size_t) (c - 'a');

    PrefixTree* self_next = self->children[e];
    if (self_next == NULL) {
        self_next = prefix_tree_new();
    }
    prefix_tree_push(self_next, word_ptr, word_len - 1);
    self->children[e] = self_next;
}

bool prefix_tree_search(
    PrefixTree* self,
    char* word_ptr, size_t word_len
) {
    if (self == NULL) { return false; }
    if (word_len < 1) { return self->epsilon; }
    
    const char c = word_ptr[word_len - 1];
    if (islower(c) < 1) { return false; }
    size_t e = (size_t) (c - 'a');

    PrefixTree* self_next = self->children[e];
    if (self_next == NULL) {
        return false; // mismatch
    }

    return prefix_tree_search(self_next, word_ptr, word_len - 1);
}

void prefix_tree_print(PrefixTree* self) {
    if (self == NULL) { return; }
    
    printf("{ epsilon: %u, children: [", self->epsilon);
    for (size_t i = 0; i < CHILD_CAP; i += 1) {
        PrefixTree* self_next = self->children[i];
        if (self_next == NULL) { continue; }

        prefix_tree_print(self_next);
        printf(", ");
    }
    printf("] }");
}
