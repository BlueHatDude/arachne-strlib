#include "arachne_strlib.h"
#include <stdio.h>


int main(void) {
    A_String s1;
    A_String_init(&s1, 25);
    A_String_setStr(&s1, "Hello ");
    printf("%s \n", A_String_getStr(&s1));

    A_String s2;
    A_String_setAndInit(&s2, 15, "World");

    A_String_catStr(&s1, &s2);
    printf("%s \n", A_String_getStr(&s1));

    A_String s3;
    A_String_setAndInit(&s3, 20, "AAAAAAAAAAAAAAAAAAAA");

    A_String_catStr(&s1, &s3);
    printf("%s \n", A_String_getStr(&s1));

    A_String_deinit(&s1);
    A_String_deinit(&s2);    
    A_String_deinit(&s3);
}
