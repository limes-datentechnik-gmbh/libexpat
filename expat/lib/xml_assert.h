/*
 * XMLASSRT.c
 *
 *  Created on: Oct 23, 2013
 *      Author: Tilo Eckert
 *
 *  Defines an assert() function that overrides MingW's assert()
 *  which causes compile errors on 64 Bit Windows. Replaces the include
 *  of assert.h in XMLPARSE.c
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define assert(expr)                                        \
            ((expr)                                         \
               ? (void) (0)                                 \
               : __xml_assert_fail(__FILE__, __LINE__, __STRING(expr)))

void __xml_assert_fail( const char *file, int line, const char *test )
{
   fprintf(stderr, "Assertion failed: %s, file %s, line %d\n",
         test, file, line);

   abort();
}
