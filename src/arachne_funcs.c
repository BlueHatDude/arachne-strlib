#include "arachne_strlib.h"
#include <stdlib.h>
#include <string.h>


void A_String_init(A_String* astr, size_t maxLen) {
    astr->_maxLen = maxLen;
    astr->_len = 0;
    astr->_data = calloc(maxLen, sizeof(char));
}


/**
 * @brief sets data of A_String
 * 
 * @param astr A_String reference 
 * @param data data being assigned to A_String 
 * @return -1 if data isn't set, else returns 0
 */
int A_String_setStr(A_String* astr, char* data) {

    size_t len = strlen(data);

    if (len < astr->_maxLen) {
        astr->_data = data;
        astr->_len = len;
        return 0;
    } else {
        return -1;
    }

}


char* A_String_getStr(const A_String* astr) {
    return astr->_data;
}
