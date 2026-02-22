//
// Created by Emre on 18.02.2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "structs.h"


Personel* personelListesininBasi=NULL;

void personelEkle()
{
    //Ram de yenipersonel kutusu için yer açıyoruz
    Personel* yeniPersonel= (Personel*) malloc(sizeof(Personel));

    //Yer açılmazsa
    if(yeniPersonel==NULL)
    {
        printf("Yeni personel eklemek için hafızada yer ayrılamadı\n");
        return;
    }

    printf("Personel İD Numarasını Giriniz\n");
    printf("İD:");
    scanf("%d",&yeniPersonel->id);

    printf("\n\n");

    printf("Personel İsmini Giriniz\n");
    printf("İsim:");
    scanf("%s",yeniPersonel->isim);

    printf("\n\n");

    printf("Personel Soyismini Giriniz\n");
    printf("İsim:");
    scanf("%s",yeniPersonel->soyisim);

    printf("\n\n");

    printf("Personel Departmanını Giriniz\n");
    printf("Departman:");
    scanf("%s",yeniPersonel->departman);

    printf("\n\n");

    printf("Personel Şifre Giriniz\n");
    printf("Şifre:");
    scanf("%s",yeniPersonel->sifre);

    printf("\n\n");

    printf("Personel Maaş Giriniz:\n");
    printf("Maaş:");
    scanf("%lf",&yeniPersonel->maas);

    printf("\n\n");

    //Çalışanın başta bir performansı olmayacağı için varsayılan olarak 0 atadım
    yeniPersonel->performansPuani = 0;

    printf("Personelin Bağlı Olduğu Müdürün ID Numarasını Giriniz(Bağlı Olduğu Müdür Yoksa \"0\")");
    scanf("%d",&yeniPersonel->bagliolduguYonetici);

    printf("\n\n");

    //Oluşan yenipersonele önceki ve sonrakini bağlamadan önce önünü ve arkasını temizledik
    //yeniPersonel için malloc fonksiyonun tahsislediği ram adreslerinde çöp değerler varsa kurtulmak için
    yeniPersonel->sonraki = NULL;
    yeniPersonel->onceki = NULL;

    //Liste başı NULL değerine eşit mi
    if (personelListesininBasi==NULL)
    {
        //Eğer NULL değerine eşitse yani liste başı boşsa yenipersoneli listebaşına koyduk
        personelListesininBasi = yeniPersonel;
    }

    //Liste başı varsa burası çalışcak
    else
    {
        //Listeyi gezip sonraki değişkeni NULL olan bir yer bulması için gezici yani scout oluşturduk
        //Listenin en başından başlamsı scout değişkenini listenin en başına atadık
       Personel* scout=personelListesininBasi;

        while(scout->sonraki!=NULL)
        {
            scout=scout->sonraki;
        }

        scout->sonraki = yeniPersonel;
        yeniPersonel->onceki = scout;
    }

}

void personelListele()
{
    int i=1;
    if (personelListesininBasi==NULL)
    {
     printf("HATA:Kayıtlı personeller bulunamadı");
    }

    else
    {
        Personel* scout=personelListesininBasi;

        while(scout!=NULL)
        {
            printf("%d\n",i);
            printf("İD:%d\n",scout->id);
            printf("İSİM:%s\n",scout->isim);
            printf("SOYİSİM:%s\n",scout->soyisim);
            printf("DEPARTMAN:%s\n",scout->departman);
            printf("MAAŞ:%lf\n",scout->maas);
            printf("PERFORMANS:%d\n",scout->performansPuani);
            printf("MÜDÜR İD:%d\n",scout->bagliolduguYonetici);

            printf("\n\n");

            i++;
            scout=scout->sonraki;
        }
    }
}

void personelAra()
{
    if (personelListesininBasi==NULL)
    {
        printf("Kayıtlı Hiç Bir Kullanıcı Yok");
        return;
    }

    //Esnek aramada birden fazla kişi bulabilceği için sayaç ekledim budluğu her kişinin üstüne kaçıncı kişi olduğunu yazsın diye
    int i=1;

    //Bayrak kontrolü fonksiyon kapanmadan önce bayrak hala 0 mı diye kontrol edicez bayrak hala 0 ise hiç bir şey bulunamadı anlamına gelicek
    //Kullanıcıya bir şey bulunamadığının haberini net bir şekilde vermek için
    int flag=0;

    int arananId;
    char arananIsim[20];
    char arananSoyisim[20];
    char arananDepartman[30];

    printf("Aramak İstediğiniz Kişinin Bilgilerini Girin (Bilmiyorsanız \"0\" Girin)");

    printf("Arancak Kişinin İD numarasını Girin\n");
    printf("İD:");
    scanf("%d",&arananId);

    //ID numarası bize kesin sonuç verdiğinden dolayı zaten ID biliniyorsa diğer kriterleri sormaya gerek yok
    if (arananId!=0)
    {
            Personel* scout=personelListesininBasi;

            while (scout!=NULL)
            {
                if (arananId==scout->id)
                {
                    printf("%d.\n",i);
                    printf("İD:%d\n",scout->id);
                    printf("İSİM:%s\n",scout->isim);
                    printf("SOYİSİM:%s\n",scout->soyisim);
                    printf("DEPARTMAN:%s\n",scout->departman);
                    printf("MAAŞ:%lf\n",scout->maas);
                    printf("PERFORMANS:%d\n",scout->performansPuani);
                    printf("MÜDÜR İD:%d\n",scout->bagliolduguYonetici);
                    //Bayrak birini buldu ve değer değişti
                    flag=1;
                    return;
                }
                //İşarietçiyi bir sornaki adrese geçirdik
                scout=scout->sonraki;
            }
    }

    //ID numarası girilmediyse burası çalışır ve diğer kriterler sorgulanır
    else
    {
        printf("Arancak Kişinin İsmini Girin\n");
        printf("İSİM:");
        scanf("%s",arananIsim);

        printf("Arancak Kişinin Soyismini Girin\n");
        printf("SOYİSİM:");
        scanf("%s",arananSoyisim);

        printf("Arancak Kişinin Departmanını Girin\n");
        printf("Departman:");
        scanf("%s",arananDepartman);

        Personel* scout=personelListesininBasi;

        while (scout!=NULL)
        {
            if ((strcmp(arananIsim, "0") == 0 || strcmp(scout->isim, arananIsim) == 0)&&
                (strcmp(arananSoyisim, "0") == 0 || strcmp(scout->soyisim, arananSoyisim) == 0)&&
                (strcmp(arananDepartman,"0")==0 || strcmp(scout->departman, arananDepartman) == 0))
            {
                printf("%d.\n",i);
                printf("İD:%d\n",scout->id);
                printf("İSİM:%s\n",scout->isim);
                printf("SOYİSİM:%s\n",scout->soyisim);
                printf("DEPARTMAN:%s\n",scout->departman);
                printf("MAAŞ:%lf\n",scout->maas);
                printf("PERFORMANS:%d\n",scout->performansPuani);
                printf("MÜDÜR İD:%d\n",scout->bagliolduguYonetici);
                i++;

                //Bayrak birini buldu ve değer değişti
                flag=1;

            }
            scout=scout->sonraki;
        }
    }
    //Bayrak fonksiyon bitmesine rağmen hala 0 ise birini bulamamştır
    if (flag==0)
    {
        printf("Aradığınız kriterlere uygun bir personel bulunamadı.");
    }
}