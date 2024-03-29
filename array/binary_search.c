#include "array.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Given a partitioned vector of [True, True, ..., False, False],
//   find the index to the partition point.
//
// This function is identical to Vec::partition_point(),
//   but it generates elements in the vector on-demand from `predicate`,
//   making it O(\log n) space-wise.
//
// This is especially useful when searching across a large solution space.
size_t partition_point(
    size_t p0, size_t p1,
    bool (*predicate)(size_t)
) {
    if (p0 >= p1) { return p0; }

    size_t p_bound = p0 + (p1 - p0) / 2;
    size_t p0_next = p0;
    size_t p1_next = p_bound;
    if (predicate(p_bound)) {
        p0_next = p_bound + 1;
        p1_next = p1;
    }

    return partition_point(p0_next, p1_next, predicate);
}
