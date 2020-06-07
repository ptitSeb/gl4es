#ifndef _GL4ES_ARBPARSER_H_
#define _GL4ES_ARBPARSER_H_

#include <stddef.h>

#include "arbhelper.h"

eToken readNextToken(sCurStatus* curStatus);
void parseToken(sCurStatus *curStatus, int vertex, char **error_msg, int *hasFogFragCoord);

#endif // _GL4ES_ARBPARSER_H_
