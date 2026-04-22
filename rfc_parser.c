#include "rfc_parser.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_rfc9213(const char *header, HttpRequest *req) {
    // Varsayýlan deðerler (RFC 9213'e göre urgency varsayýlaný 3'tür)
    req->urgency = 3;
    req->incremental = false;

    // Basit bir arama: "u=" ifadesini bul
    char *u_ptr = strstr(header, "u=");
    if (u_ptr) {
        // "u="dan sonra gelen ilk rakamý al
        req->urgency = atoi(u_ptr + 2);
        
        // RFC sýnýr kontrolü (0-7 arasý olmalý)
        if (req->urgency < 0) req->urgency = 0;
        if (req->urgency > 7) req->urgency = 7;
    }

    // "i" harfi var mý kontrol et (Incremental)
    if (strstr(header, "i")) {
        req->incremental = true;
    }
}
