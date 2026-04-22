RFC 9213 Priority Scheduler (API Gateway)
Bu proje, modern HTTP önceliklendirme standardı olan RFC 9213'ü kullanarak, gelen istekleri Min-Heap veri yapısı ile önceliklendiren modüler bir API Gateway zamanlayıcısıdır.

🏗 Mimari Şema
Proje; parser, veri yapısı ve ana kontrolcü olmak üzere 3 ana modülden oluşur

🛠 Teknik Detaylar
Dil: C
Algoritma: Min-Heap (Priority Queue)
Karmaşıklık (Complexity): * Ekleme (Push): O(\log n)
En Öncelikliyi Çıkarma (Pop): O(\log n)
En Üst Elemana Erişim:O(1)
Modülerlik: Header (.h) ve Source (.c) dosyaları ayrılarak düşük bağımlılık (low coupling) sağlanmıştır.

Proje Yapısı
main.c: Sistem giriş noktası ve test senaryoları.

priority_queue.h/c: Min-Heap algoritmasının ve kuyruk yönetiminin bulunduğu modül.

rfc_parser.h/c: RFC 9213 formatındaki ("u=2, i") metinleri işleyen modül.

Nasıl Çalıştırılır?
Dev-C++ veya herhangi bir C derleyicisi ile projeyi açın.

Tüm .c ve .h dosyalarını aynı projeye dahil edin.

main.c dosyasını derleyip çalıştırın (F11).

🧹 Bellek Yönetimi
Sistem dinamik bellek tahsisi (malloc, realloc) üzerine kurulmuştur. Program sonunda tüm bellek free() fonksiyonu ile temizlenerek memory leak (bellek sızıntısı) oluşumu engellenmiştir.
