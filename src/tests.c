#include "arachne_strlib.h"
#include <stdio.h>


int main(void) {
    A_String* str_one = A_String_init("Hello, World", 50);
    puts(str_one->data);
}
