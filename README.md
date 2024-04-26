# Arachne String Library

A small, native string manipulation library for ensuring that you don't encounter memory-related errors such as "out of bounds" errors. All string manipulation operations should be done using the appropriate `A_String` function. All operations are made on `A_String` structs. `A_String_init(astr, maxlen)` or  `A_String_setAndInit(astr, maxlen, initvalue)` should be called before any other `A_String` operations. `A_String_deinit(astr)` should be called after the last use of an `A_String` struct. 

## Building
```
git clone https://github.com/BlueHatDude/arachne-strlib.git
cd arachne-strlib
make lib
```

## Initialization & Deinitialization
```
#include "arachne_strlib.h"


int main(void) {
    A_String s1;
    A_String_init(&s1, 20);
    A_String s2;
    A_String_setAndInit(&s2, 25, "Hello");

    A_String_deinit(&s1);
    A_String_deinit(&s2);
}
```
