#include <string.h>
#include "keyCode.h"

keyCode createKC(char code[11])
{
    keyCode kc;
    strcpy(kc.code, code);
    return kc;
}