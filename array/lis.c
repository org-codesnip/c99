#include "array.h"

#include <stdlib.h>
#include <limits.h>

// Returns the length of LIS for vector `vec`.
// Implementation notice:
//   all elements in `vec` must be strictly larger than i32::MIN.
size_t longest_inc_subseq(
    int* vec_ptr, size_t vec_len
) {
    int* stack_ptr = calloc(vec_len, sizeof(int)); // monotonic stack
    if (stack_ptr == NULL) { return 0; }
    size_t stack_len = 0;

    for (size_t i = 0 ; i < vec_len; i += 1) {
        int e = vec_ptr[i];

        size_t bound = 0;
        while (bound < stack_len) {
            if (stack_ptr[bound] >= e) {
                break;
            }
            bound += 1;
        } // can be improved with binary search

        if (stack_len <= bound) {
            stack_len = bound + 1;
        }
        stack_ptr[bound] = e;
    }
    free(stack_ptr);

    return stack_len;
}
