#ifndef ARACHNE_STRING_LIB_H_
#define ARACHNE_STRING_LIB_H_

    #include <stddef.h>

    typedef struct A_String {
        char* _data;
        size_t _len;
        size_t _maxLen;
    } A_String;

    extern void A_String_init(A_String* astr, size_t maxLen);
    extern int A_String_setStr(A_String* astr, char* data);
    extern char* A_String_getStr(const A_String* astr);

#endif
