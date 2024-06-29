#include "arachne_strlib.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief sets data of A_String
 * 
 * @param astr A_String reference 
 * @param data data being assigned to A_String 
 * @return 0 if data isn't set, else returns 1
 */
A_StringErrorCode A_String_setStr(A_String* astr, const char* data) {

    if (data == NULL)
        return A_STRING_NULL_SET_ERROR;

    size_t len = strlen(data);

    if (len < astr->_maxLen) {
        memset(astr->data, '\0', sizeof(char) * astr->_maxLen);
        memcpy(astr->data, data, len);
        astr->_len = len;
        return A_STRING_NO_ERROR;
    } else {
        return A_STRING_INSUFFICIENT_SPACE;
    }
}


/**
 * @brief returns refernce to astr._data
 * 
 * @param astr 
 * @return char* 
 */
char* A_String_getStr(const A_String* astr) {
    return astr->data;
}


/**
 * @brief concatenates A_String data from src onto dest
 * 
 * @param dest 
 * @param src 
 * @return 0 if concatenation unsucessful, 1 elsewise
 */
int A_String_catStr(A_String* dest, const A_String* src) {
    
    if (src->_len == 0) {
        return 0;
    }

    if ( (src->_len + dest->_len) < dest->_maxLen) {
        memset(dest->data + dest->_len, '\0', sizeof(char) * dest->_maxLen);
        memcpy(dest->data + dest->_len, src->data, sizeof(char) * src->_len);

        return 1;
    } else {
        return 0;
    }

}


/**
 * @brief initializes values of astr struct, should be called before any other 'A_String' function
 * 
 * @param astr 
 * @param maxLen 
 * @return NULL if astr not successfully initialized
 */
A_String* A_String_init(const char* init_value, const size_t maxLen) {
    A_String* astr = malloc(sizeof(A_String));
    
    if (astr == NULL)
        return NULL;

    astr->_maxLen = maxLen;
    astr->_len = 0;
    astr->data = calloc(maxLen, sizeof(char) * maxLen);

    if (astr->data == NULL)
        return NULL;

    A_String_setStr(astr, init_value);

    return astr;
}


/**
 * @brief frees memory used by astr, should be called after last use of astr
 * 
 * @param astr 
 */
void A_String_deinit(A_String* astr) {
    free(astr->data);
}

