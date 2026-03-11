#include <stdio.h>
#include <stdlib.h>
#include "structs.h"    // Personel bilgilerinin başlıklarını görebilmek için
#include "personel.h"   // Ana listebaşı pointer'ını (extern) görebilmek için
#include "dosya.h"

#include <string.h>

#include "urun.h"

void personelleriKaydet()
{
    //Liste zaten boşsa kayıt işlemlerine hiç başlamasın



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

void urunleriKaydet()
{


    Urun* scout = urunListesininBasi;

    FILE* kytptr = NULL;

    //ürünler için yeni bir txt dosyası oluşturuyorum
    kytptr = fopen("urunKayitlari.txt", "w");

    if (kytptr == NULL)
    {
        printf("HATA: Ürün kayıt dosyası oluşturulamadı.\n");
    }
    else
    {
        while (scout != NULL)
        {
            fprintf(kytptr, "%d,%s,%s,%d,%.2lf,%d\n", scout->id, scout->urunadi, scout->kategori, scout->stokAdedi, scout->fiyat, scout->zimmetliPersonelid);

            scout = scout->sonraki;
        }

        // Dosyayı güvenli bir şekilde kapatıyorum
        fclose(kytptr);
        printf("Ürün listesi basariyla urunKayitlari.txt dosyasina kaydedildi!\n");
    }
}

void urunleriYukle()
{
    int i=0;

    int tempId, tempStok, tempZimmetli;
    double tempFiyat;
    char tempUrunadi[20], tempKategori[30];

    FILE* ykleptr=NULL;

    // Ürün kayıtlarını okuma modunda (r) açıyorum
    ykleptr=fopen("urunKayitlari.txt","r");

    if (ykleptr==NULL)
    {
        // Dosya yoksa veya ilk kez açılıyorsa sorun çıkarmaması için sessizce dönüyorum
        printf("HATA: Kayıtlı ürün dosyası okunamadı veya henüz oluşturulmadı.\n");
        return;
    }
    else
    {
        // fscanf ile dosyadaki 6 veriyi sırasıyla ve virgüle kadar okuyup geçici değişkenlerime alıyorum
        // 6 veriyi de başarıyla okuduğum sürece (== 6) döngüyü çalıştırıyorum
        while (fscanf(ykleptr, "%d,%[^,],%[^,],%d,%lf,%d\n", &tempId, tempUrunadi, tempKategori, &tempStok, &tempFiyat, &tempZimmetli) == 6)
        {
            Urun* yeniUrun=(Urun*) malloc(sizeof(Urun));
            yeniUrun->id=tempId;
            strcpy(yeniUrun->urunadi,tempUrunadi);
            strcpy(yeniUrun->kategori,tempKategori);
            yeniUrun->stokAdedi=tempStok;
            yeniUrun->fiyat=tempFiyat;
            yeniUrun->zimmetliPersonelid=tempZimmetli;

            // Ürünleri birbirine bağlamadan önce ramde tahsis edilen yerleri temizliyorum ki çöp değerler olmasın
            yeniUrun->sonraki=NULL;
            yeniUrun->onceki=NULL;

            // Eğer tren boşsa, ilk vagonu yerleştiriyorum
            if(urunListesininBasi==NULL)
            {
                urunListesininBasi=yeniUrun;
            }
            else
            {
                Urun* scout=urunListesininBasi;

                // Trenin en sonuna kadar gidiyorum
                while (scout->sonraki!=NULL)
                {
                    scout=scout->sonraki;
                }
                // Yeni vagonu trenin sonuna takıyorum
                scout->sonraki = yeniUrun;
                yeniUrun->onceki = scout;
            }
            i++; // Yüklenen ürün sayısını artırıyorum
        }
        fclose(ykleptr);
        printf("%d Ürünün bilgisi başarılı şekilde yüklendi.\n\n",i);
    }
}