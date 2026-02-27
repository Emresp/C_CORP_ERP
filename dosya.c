#include <stdio.h>
#include <stdlib.h>
#include "structs.h"    // Personel bilgilerinin başlıklarını görebilmek için
#include "personel.h"   // Ana listebaşı pointer'ını (extern) görebilmek için
#include "dosya.h"

#include <string.h>

void personelleriKaydet()
{
    //Liste zaten boşsa kayıt işlemlerine hiç başlamasın
    if (personelListesininBasi==NULL)
    {
        return;
    }


    Personel* scout=personelListesininBasi;

    FILE* kytptr=NULL;

    kytptr=fopen("personelKayitlari.txt","w");

    if (kytptr==NULL)
    {
        printf("HATA:Kayıt dosyası oluşturulamadı.");
    }
    else
    {
        while (scout!=NULL)
        {
            fprintf(kytptr,"%d,%s,%s,%s,%s,%.2lf,%d,%d\n",scout->id,scout->isim,scout->soyisim,scout->departman,scout->sifre,scout->maas,scout->performansPuani,scout->bagliolduguYonetici);
            scout=scout->sonraki;
        }

        //Dosya kapatma işlemi
        fclose(kytptr);
        printf("Personel listesi basariyla personelKayitlari.txt dosyasina kaydedildi!\n");
    }
}

void personelleriYukle()
{
    int i=0;

    int tempId, tempPerformans, tempYonetici;
    double tempMaas;
    char tempIsim[20], tempSoyisim[20], tempDepartman[30], tempSifre[30];

    FILE* ykleptr=NULL;

    ykleptr=fopen("personelKayitlari.txt","r");

    if (ykleptr==NULL)
    {
        printf("HATA: Kayıtlı personel dosyası okunamadı");
        return;
    }
    else
    {


        while (fscanf(ykleptr, "%d,%[^,],%[^,],%[^,],%[^,],%lf,%d,%d\n", &tempId, tempIsim, tempSoyisim, tempDepartman, tempSifre, &tempMaas, &tempPerformans, &tempYonetici) == 8)
        {
            Personel* yeniPersonel=(Personel*) malloc(sizeof(Personel));
            yeniPersonel->id=tempId;
            strcpy(yeniPersonel->isim,tempIsim);
            strcpy(yeniPersonel->soyisim,tempSoyisim);
            strcpy(yeniPersonel->departman,tempDepartman);
            strcpy(yeniPersonel->sifre,tempSifre);
            yeniPersonel->maas=tempMaas;
            yeniPersonel->performansPuani=tempPerformans;
            yeniPersonel->bagliolduguYonetici=tempYonetici;

            //Personelleri birbirine bağlamadan önce ramde tahsis edilen yerleri temizliyoruz ki çöp değerler olmasın
            yeniPersonel->sonraki=NULL;
            yeniPersonel->onceki=NULL;

            if(personelListesininBasi==NULL)
            {
                personelListesininBasi=yeniPersonel;
            }
            else
            {
                Personel* scout=personelListesininBasi;

                while (scout->sonraki!=NULL)
                {
                    scout=scout->sonraki;
                }
                scout->sonraki = yeniPersonel;
                yeniPersonel->onceki = scout;
            }
            i++;
        }
        fclose(ykleptr);
        printf("%d Personelin bilgisi başarılı şekilde yüklendi.\n\n",i);
    }
}
