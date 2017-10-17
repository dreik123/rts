#include <iostream>
/* See the import.pl script for potential modifications */
/* The original libm wrapper may call the Double implementation
   and declares Double constants.
   This wrapper purely wraps the Simple version
*/

#include "math_private.h"

namespace streflop_libm {
Simple
__expf(Simple x)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
