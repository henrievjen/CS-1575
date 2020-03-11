/* Implement your MyException::what() function by overriding it here:
 */

#include "my_exception.h"

// implement here -- see class notes and code for example
const char *MyException::what() const noexcept
{
    // const char *message = "Custom error has occurred";
    // return message;
    return "Custom error has occurred";
}