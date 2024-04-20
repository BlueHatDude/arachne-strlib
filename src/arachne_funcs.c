#include "arachne_strlib.h"


void A_String_init(A_String* astr, size_t maxLen) {
    astr->_len = maxLen;
    astr->_data = NULL;
}

void A_String_setStr(A_String* astr, char* data) {
    
}

char* A_String_getStr(const A_String* astr) {
    return astr->_data;
}
