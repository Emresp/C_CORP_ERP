#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "urun.h"


Urun* urunListesininBasi=NULL;

void urunEkle()
{
    Urun* yeniUrun=(Urun*)malloc(sizeof(Urun));

    if(yeniUrun==NULL)
    {
        printf("HATA: Yeni urun eklemek için hafızada yer açılmadı\n");
        return;
    }

    printf("Urun ID numarasını giriniz\n");
    printf("ID:");
    scanf("%d",&yeniUrun->id);

    printf("Urunun adını giriniz\n");
    printf("Ad:");
    scanf("%s",yeniUrun->urunadi);

    printf("Urunun katogorsini giriniz\n");
    printf("Katogori:");
    scanf("%s",yeniUrun->kategori);

    printf("Urunde kaç adet odluğunu giriniz(stok)\n");
    printf("Adet:");
    scanf("%d",&yeniUrun->stokAdedi);

    printf("Urunun fiyatını giriniz\n");
    printf("Fiyat:");
    scanf("%lf",&yeniUrun->fiyat);

    printf("Ürün zimmetli ise personel ID numarsını giriniz:\n");
    printf("Personel ID:");
    scanf("%d",&yeniUrun->zimmetliPersonelid);

    yeniUrun->sonraki = NULL;
    yeniUrun->onceki = NULL;

    if(urunListesininBasi==NULL)
    {
        urunListesininBasi=yeniUrun;
    }
    else
    {
        Urun* scout=urunListesininBasi;

        while(scout->sonraki!=NULL)
        {
            scout=scout->sonraki;
        }

        scout->sonraki = yeniUrun;
        yeniUrun->onceki = scout;

    }

    printf("\nUrun stoga basariyla eklendi!\n");
}

void urunListele()
{

    int i=1;
    if (urunListesininBasi==NULL)
    {
        printf("HATA: Listelencek ürün bulunamadı.");
    }

    else
    {
        Urun* scout=urunListesininBasi;

        while (scout!=NULL)
        {
            printf("%d\n",i);
            printf("ID:%d\n",scout->id);
            printf("Ürün Adı:%s\n",scout->urunadi);
            printf("Kategori:%s\n",scout->kategori);
            printf("Stok Adedi:%d\n",scout->stokAdedi);
            printf("Fiyat:%.2lf\n",scout->fiyat);
            printf("Ziimetli Personel ID:%d\n",scout->zimmetliPersonelid);

            printf("\n\n");

            i++;
            scout=scout->sonraki;
        }
    }

}

void urunAra()
{
    if (urunListesininBasi==NULL)
    {
        printf("Kayıtlı Hiçbir ürün bulunamadı.");
        return;
    }

    //Bir şey bulunup bulunmadığının kontrolünü sağlamak için
    int flag=0;

    int arananUrunID;
    char arananUrunAdi[30];
    char arananUrunKategori[30];

    printf("Aramak İstediğiniz Ürünün Bilgilerini Girin (Bilmiyorsanız \"0\" Girin)");

    printf("Arancak Ürünün İD numarasını Girin\n");
    printf("İD:");
    scanf("%d",&arananUrunID);

    if(arananUrunID!=0)
    {
        Urun* scout=urunListesininBasi;

        while (scout!=NULL)
        {

            if(scout->id==arananUrunID)
            {
                printf("ID:%d\n",scout->id);
                printf("Ürün Adı:%s\n",scout->urunadi);
                printf("Kategori:%s\n",scout->kategori);
                printf("Stok Adedi:%d\n",scout->stokAdedi);
                printf("Fiyat:%.2lf\n",scout->fiyat);
                printf("Ziimetli Personel ID:%d\n",scout->zimmetliPersonelid);
                //Bayrak birini Buldu
                flag=1;
                return;
            }

            //Bir sonraki adrese bakması için
            scout=scout->sonraki;
        }
    }
    //ID numarsı girilmediyse burası çalışır
    else
    {
        printf("Arancak Ürünün Adini Girin\n");
        printf("Ad:");
        scanf("%s",arananUrunAdi);

        printf("Arancak Ürünün Kategorisini Girin\n");
        printf("Kategori:");
        scanf("%s",arananUrunKategori);

        Urun* scout=urunListesininBasi;

        while (scout!=NULL)
        {
            if ( (strcmp(arananUrunAdi, "0") == 0 || strcmp(scout->urunadi, arananUrunAdi) == 0) &&
                 (strcmp(arananUrunKategori, "0") == 0 || strcmp(scout->kategori, arananUrunKategori) == 0) )
            {
                // İki şarttan (veya opsiyonel geçişlerden) başarıyla geçtik, ürünü bulduk!
                printf("--- BULUNAN URUN ---\n");
                printf("ID: %d\n", scout->id);
                printf("Urun Adi: %s\n", scout->urunadi);
                printf("Kategori: %s\n", scout->kategori);
                printf("Stok Adedi: %d\n", scout->stokAdedi);
                printf("Fiyat: %.2lf TL\n", scout->fiyat);
                printf("Zimmetli Personel ID: %d\n\n", scout->zimmetliPersonelid);

                flag = 1;
            }

            scout = scout->sonraki;
        }
    }

    if (flag == 0)
    {
        printf("HATA: Aradiginiz kriterlere uygun urun bulunamadi.\n");
    }


}