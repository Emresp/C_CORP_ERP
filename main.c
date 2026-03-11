#include <stdio.h>
#include <windows.h>

#include "dosya.h"
#include "personel.h"
#include "urun.h"

int main(void)
{

    //Türkçe çalışmak için
    SetConsoleOutputCP(65001); // Ekranı UTF-8
    SetConsoleCP(65001);       // Klavyeyi de UTF-8

    personelleriYukle();

    int secim;
    while (1)
    {
        printf("SİSTEM KONTROL PANELİNE HOŞ GELDİNİZ.\n\n\n");
        printf("Lütfen bir seçim yaparak başlayınız.\n");
        printf("1-)Personel eklemek için\n");
        printf("2-)Personel Listesini Görüntülemek İçin\n");
        printf("3-)Personel Aramak için\n");
        printf("4-)Personel Silmek için\n");
        printf("5-) Personel Güncellemek için\n");
        printf("6-) Ürun Eklemek için\n");
        printf("7-) Ürün Listesini Görmek için\n");
        printf("8-) Ürün aramak için\n");
        printf("9-)Ürün güncellemek için\n");
        printf("10-)Çıkış Yapmak için\n");
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
                personelAra();
                break;
            case 4:
                personelSil();
                break;
            case 5:
                personelGuncelle();
                break;
            case 6:
                urunEkle();
                break;
            case 7:
                urunListele();
                break;
            case 8:
                urunAra();
                break;
            case 9:
                urunGuncelle();
                break;
            case 10:
                printf("Çıkış Yapılıyor\n");
                personelleriKaydet();
                return 0;

            default:
                printf("Lütfen Geçerli Bir Seçim Yapınız.");
                break;


        }

    }


    return 0;
}
