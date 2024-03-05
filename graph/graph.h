#pragma once

typedef struct DisjointSet DisjointSet;

DisjointSet* disjoint_set_new(size_t capacity);
void disjoint_set_drop(DisjointSet* self);

size_t disjoint_set_query(DisjointSet* self, size_t v);
void disjoint_set_link(DisjointSet* self, size_t v0, size_t v1);
