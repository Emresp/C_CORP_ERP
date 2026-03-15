#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "structs.h"

void ekraniTemizle()
{
    system("cls");
}

void devamIcinBekle()
{
    printf("\nDevam etmek icin herhangi bir tusa basin...\n");
    // Windows'un kendi bekletme komutunu cagiriyorum.
    // '> nul' kismi ise Windows'un o varsayilan Ingilizce "Press any key..." yazisini gizler.
    system("pause > nul");
}

void sistemSaatiniYazdir()
{
    // 1. Senin tasarladığın struct'tan bir tane "suAn" isimli kutu oluşturuyoruz
    TarihSaat suAn;

    // 2. C'nin kendi motorunu çalıştırıp anlık zamanı çekiyoruz
    time_t anlikZaman = time(NULL);
    struct tm *zamanBilgisi = localtime(&anlikZaman);

    // 3. C'nin motorundan gelen verileri, SENİN struct'ının içine dolduruyoruz
    suAn.gun = zamanBilgisi->tm_mday;
    suAn.ay = zamanBilgisi->tm_mon + 1;         // Aylar 0'dan başladığı için +1
    suAn.yil = zamanBilgisi->tm_year + 1900;    // Yıllar 1900'den başladığı için +1900

    suAn.saat = zamanBilgisi->tm_hour;
    suAn.dakika = zamanBilgisi->tm_min;
    suAn.saniye = zamanBilgisi->tm_sec;

    // 4. Verileri şık bir ERP paneli formatında ekrana basıyoruz
    printf("==================================================\n");
    printf("  TARIH: %02d/%02d/%d  |  SAAT: %02d:%02d:%02d\n",
           suAn.gun, suAn.ay, suAn.yil,
           suAn.saat, suAn.dakika, suAn.saniye);
    printf("==================================================\n\n");

}