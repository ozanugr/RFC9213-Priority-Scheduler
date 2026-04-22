#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "rfc_parser.h"

int main() {
    PriorityQueue gateway_queue;
    int i; 
    const char *incoming_headers[] = {"u=7, i", "u=0", "u=3, i"};
    const char *labels[] = {"Görsel_Dosyasi", "KRITIK_FREN_SINYALI", "Standart_Veri"};

    init_queue(&gateway_queue, 10);

    printf("=== API Gateway Baslatildi (RFC 9213 Uyumlu) ===\n\n");

    for (i = 0; i < 3; i++) {
        HttpRequest new_req;
        new_req.id = i + 1;
        sprintf(new_req.label, "%s", labels[i]);
        parse_rfc9213(incoming_headers[i], &new_req);
        
        printf("[GELEN] ID:%d | Etiket:%-20s | Urgency:%d\n", 
               new_req.id, new_req.label, new_req.urgency);
        push(&gateway_queue, new_req);
    }

    printf("\n=== Zamanlayici: Islem Sirasi (Min-Heap) ===\n");
    while (!is_empty(&gateway_queue)) {
        HttpRequest processed = pop(&gateway_queue);
        printf("[ISLEM] Oncelik Sirasiyla -> ID:%d | %-20s | Urgency:%d\n", 
               processed.id, processed.label, processed.urgency);
    }

    free(gateway_queue.heap);
    printf("\nBellek temizlendi. Proje basariyla sonlandi.\n");
    return 0;
}
