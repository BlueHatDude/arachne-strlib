#include "arachne_strlib.h"
#include <stdio.h>


int main(void) {
    /*
        A_String s1;
        init(s1, 20);
        set(s1, "Hello");
    */

    A_String s1;
    A_String_init(&s1, 20);
    A_String_setStr(&s1, "Hello, World");

    printf("%s | %zu \n", A_String_getStr(&s1), s1._len);
}
