#include "arachne_strlib.h"
#include <stdio.h>


int main(void) {
    A_String s1;
    A_String_setAndInit(&s1, 25, "Hello ");

    A_String s2;
    A_String_setAndInit(&s2, 15, "World");

    A_String_catStr(&s1, &s2);
    printf("%s \n", A_String_getStr(&s1));

}
