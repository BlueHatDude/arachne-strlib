#ifndef ARACHNE_STRING_LIB_H_
#define ARACHNE_STRING_LIB_H_

    #include <stddef.h>

    typedef struct A_String {
        char* data;
        size_t _len;
        size_t _maxLen;
    } A_String;

    typedef enum {
        A_STRING_INIT_FAILED,
        A_STRING_NULL_SET_ERROR,
        A_STRING_INSUFFICIENT_SPACE,
        A_STRING_NO_ERROR,
    } A_StringErrorCode;

    extern A_String* A_String_init(const char* init_value, const size_t maxLen);
    extern A_StringErrorCode A_String_setStr(A_String* astr, const char* data);
    extern void A_String_deinit(A_String* astr);
    extern char* A_String_getStr(const A_String* astr);
    extern int A_String_catStr(A_String* dest, const A_String* src);

#endif
