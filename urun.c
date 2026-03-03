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
    printf("Ad");
    scanf("%s",yeniUrun->urunadi);

    printf("Urunun katogorsini giriniz\n");
    printf("Katogori:");
    scanf("%s",yeniUrun->kategori);

    printf("Urunde kaç adet odluğunu giriniz(stok)\n");
    printf("Adet");
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
            printf("Fiyat:%lf\n",scout->fiyat);
            printf("Ziimetli Personel ID:%d\n",scout->zimmetliPersonelid);

            printf("\n\n");

            i++;
            scout=scout->sonraki;
        }
    }

}