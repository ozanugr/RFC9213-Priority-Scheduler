#ifndef RFC_PARSER_H
#define RFC_PARSER_H

#include "priority_queue.h"

// Gelen "u=3, i" gibi bir string'i parçalayýp HttpRequest struct'ýna doldurur
void parse_rfc9213(const char *header, HttpRequest *req);

#endif
