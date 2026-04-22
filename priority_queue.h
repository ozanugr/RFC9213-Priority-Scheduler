#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

// Her bir HTTP isteðini temsil eden yapý
typedef struct {
    int id;             // Ýsteðin benzersiz numarasý
    int urgency;        // RFC 9213: 0 (En acil) - 7 (En yavaþ)
    bool incremental;   // RFC 9213: true/false
    char label[50];     // Ýsteðin ne olduðunu anlamak için (örn: "Görüntü", "JS")
} HttpRequest;

// Kuyruðumuzu (Min-Heap) temsil eden yapý
typedef struct {
    HttpRequest *heap;  // Ýsteklerin tutulduðu dinamik dizi
    int size;           // Mevcut eleman sayýsý
    int capacity;       // Toplam kapasite
} PriorityQueue;

// Fonksiyon tanýmlarý (Bunlarý .c dosyasýnda dolduracaðýz)
void init_queue(PriorityQueue *q, int capacity);
void push(PriorityQueue *q, HttpRequest req);
HttpRequest pop(PriorityQueue *q);
bool is_empty(PriorityQueue *q);

#endif
