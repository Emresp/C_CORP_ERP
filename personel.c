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

    //Eğer liste tamamen boşsa, bu kişi ilk personel olur
    if (personelListesininBasi==NULL)
    {
        //Eğer varsa yenipersonelimiz liste basşı olabilir
        personelListesininBasi = yeniPersonel;
    }

    //Yoksa listeyi gezicez
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