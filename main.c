#include <stdio.h>
#include <windows.h>
#include "personel.h"

int main(void)
{

    //Türkçe çalışmak için
    SetConsoleOutputCP(65001); // Ekranı UTF-8
    SetConsoleCP(65001);       // Klavyeyi de UTF-8

    int secim;
    while (1)
    {
        printf("SİSTEM KONTROL PANELİNE HOŞ GELDİNİZ.\n\n\n");
        printf("Lütfen bir seçim yaparak başlayınız.\n");
        printf("1-)Personel eklemek için\n");
        printf("2-)Personel Listesini Görüntülemek İçin\n");
        printf("3-)Çıkış Yapmak için\n");
        printf("Seçim:");
        scanf("%d",&secim);

        switch (secim)
        {
            case 1:
                personelEkle();
                break;

            case 2:
                personelListele();
                break;
            case 3:
                printf("Çıkış Yapılıyor");
                return 0;
            default:


        }

    }


    return 0;
}