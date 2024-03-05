#pragma once

typedef struct PrefixTree PrefixTree;

PrefixTree* prefix_tree_new();
void prefix_tree_drop(PrefixTree* self);

void prefix_tree_push(PrefixTree* self, char* word_ptr, size_t word_len);
void prefix_tree_search(PrefixTree* self, char* word_ptr, size_t word_len);
void prefix_tree_print(PrefixTree* self);
