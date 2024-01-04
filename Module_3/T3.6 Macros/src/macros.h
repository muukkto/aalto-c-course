/* In this task, you are required to implement two function-like macros.
 *  1. Implement macro #define EQ3(a,b,c) using ternary operator that takes
 *     three arguments, and tests their equality. The evaluation result is 1
 *     if all of its three arguments are equal, 0 if not.
 *  2. Implement macro #define MIN3(a,b,c) using ternary operator that takes
 *     three arguments, and returns the smallest one.
 * This exercise does not contain *.c files other than main.c in the template.
 * You will need to implement the macros in macros.h header.
 */

#ifndef AALTO_MACROS_H
#define AALTO_MACROS_H

#define EQ3(a,b,c) ((a == b && b == c) ? 1 : 0)
#define MIN3(a,b,c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c))

#endif
