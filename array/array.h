#pragma once

size_t partition_point(
    size_t p0, size_t p1,
    bool (*predicate)(size_t)
);

size_t longest_inc_subseq(
    int* vec_ptr, size_t vec_len
);
