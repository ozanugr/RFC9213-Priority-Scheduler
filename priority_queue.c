#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

// Kuyruðu baþlatýyoruz (Bellekte yer ayýrma)
void init_queue(PriorityQueue *q, int capacity) {
    q->capacity = capacity;
    q->size = 0;
    q->heap = (HttpRequest *)malloc(sizeof(HttpRequest) * capacity);
}

// Boþ mu kontrolü
bool is_empty(PriorityQueue *q) {
    return q->size == 0;
}

// Yardýmcý Fonksiyon: Ýki isteðin yerini deðiþtirir
void swap(HttpRequest *a, HttpRequest *b) {
    HttpRequest temp = *a;
    *a = *b;
    *b = temp;
}

// Yukarý Kaydýrma (Ekleme yaparken kullanýlýr)
void heapify_up(PriorityQueue *q, int index) {
    // Ebeveyn (parent) ile karþýlaþtýr, eðer daha acilse (urgency daha küçükse) yukarý taþý
    while (index > 0 && q->heap[(index - 1) / 2].urgency > q->heap[index].urgency) {
        swap(&q->heap[(index - 1) / 2], &q->heap[index]);
        index = (index - 1) / 2;
    }
}

// Yeni Ýstek Ekleme
void push(PriorityQueue *q, HttpRequest req) {
    if (q->size == q->capacity) {
        // Kapasite dolarsa alaný 2 katýna çýkar (Dinamik Bellek Yönetimi)
        q->capacity *= 2;
        q->heap = (HttpRequest *)realloc(q->heap, sizeof(HttpRequest) * q->capacity);
    }
    q->heap[q->size] = req;
    heapify_up(q, q->size);
    q->size++;
}

// Aþaðý Kaydýrma (Kökü silerken kullanýlýr)
void heapify_down(PriorityQueue *q, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < q->size && q->heap[left].urgency < q->heap[smallest].urgency)
        smallest = left;
    if (right < q->size && q->heap[right].urgency < q->heap[smallest].urgency)
        smallest = right;

    if (smallest != index) {
        swap(&q->heap[index], &q->heap[smallest]);
        heapify_down(q, smallest);
    }
}

// En Öncelikli Ýsteði Al ve Kuyruktan Çýkar
HttpRequest pop(PriorityQueue *q) {
    HttpRequest root = q->heap[0];
    q->heap[0] = q->heap[q->size - 1];
    q->size--;
    heapify_down(q, 0);
    return root;
}
