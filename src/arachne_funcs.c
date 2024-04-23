#include "arachne_strlib.h"
#include <stdlib.h>
#include <string.h>


/**
 * @brief initializes values of astr struct, should be called before any other 'A_String' function
 * 
 * @param astr 
 * @param maxLen 
 * @return 0 if A_String not successfully initialized, else 1
 */
int A_String_init(A_String* astr, const size_t maxLen) {
    astr->_maxLen = maxLen;
    astr->_len = 0;
    astr->_data = calloc(maxLen, sizeof(char) * maxLen);

    if (astr->_data == NULL) {
        return 0;
    } else {
        return 1;
    }

}


/**
 * @brief checks to see if astr data is NULL
 * 
 * @param astr 
 * @return 0 if is null, 1 if isn't null
 */
int A_String_getStatus(const A_String* astr) {
    if (astr->_data == NULL) {
        return 0;
    } else {
        return 1;
    }
}


/**
 * @brief frees memory used by astr, should be called after last use of astr
 * 
 * @param astr 
 */
void A_String_deinit(A_String* astr) {
    free(astr->_data);
}


/**
 * @brief sets data of A_String
 * 
 * @param astr A_String reference 
 * @param data data being assigned to A_String 
 * @return 0 if data isn't set, else returns 1
 */
int A_String_setStr(A_String* astr, char* data) {

    size_t len = strlen(data);

    if (len < astr->_maxLen) {
        memset(astr->_data, '\0', sizeof(char) * astr->_maxLen);
        memcpy(astr->_data, data, len);
        astr->_len = len;
        return 1;
    } else {
        return 0;
    }

}


/**
 * @brief returns refernce to astr._data
 * 
 * @param astr 
 * @return char* 
 */
char* A_String_getStr(const A_String* astr) {
    return astr->_data;
}


/**
 * @brief concatenates A_String data from src onto dest
 * 
 * @param dest 
 * @param src 
 * @return 0 if concatenation unsucessful, 1 elsewise
 */
int A_String_catStr(A_String* dest, const A_String* src) {
    
    if ( (src->_len + dest->_len) < dest->_maxLen) {
        memset(dest->_data + dest->_len, '\0', sizeof(char) * dest->_maxLen);
        memcpy(dest->_data + dest->_len, src->_data, sizeof(char) * src->_len);

        return 1;
    } else {
        return 0;
    }

}


/**
 * @brief initializes astr with default value
 * 
 * @param astr 
 * @param maxLen 
 * @param data 
 * @return 0 if full initialization unsuccessful, else 1 
 */
int A_String_setAndInit(A_String* astr, size_t maxLen, char* data) {
    int initStatus = A_String_init(astr, maxLen);
    
    if (initStatus) {
        return A_String_setStr(astr, data);
    } else {
        return initStatus;
    }

}
