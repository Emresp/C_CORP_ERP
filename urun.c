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

void urunGuncelle()
{
    int guncellenecekUrunid;
    char kullanicigirdi[50]; // Kullanıcının girdiği metni tutacağım değişken

    if (urunListesininBasi == NULL)
    {
        printf("HATA: Güncellenecek hiçbir ürün bulunamadı.\n");
        return;
    }

    Urun* scout = urunListesininBasi;

    printf("Güncellemek istediğiniz ürünün ID numarasını giriniz: ");
    scanf("%d", &guncellenecekUrunid);

    // DİKKAT: scanf'ten sonra klavyede basılan Enter (\n) karakterini temizliyorum ki
    // aşağıdaki ilk fgets bu Enter'ı görüp direkt satırı atlamasın.
    getchar();

    while (scout != NULL)
    {
        if (scout->id == guncellenecekUrunid)
        {
            // Aranan id numarası bulunursa döngüyü kırıyorum
            break;
        }
        // Döngü döndükçe bir sonraki ürüne geçiyorum
        scout = scout->sonraki;
    }

    // scout boş mu kontrolü yapıyorum
    if (scout == NULL)
    {
        printf("Bu ID numarasina sahip bir ürün bulunamadi.\n");
        return;
    }

    printf("\nÜRÜNÜN YENİ BİLGİLERİNİ GİRİP ENTER TUŞUNA BASIN. DEĞİŞİKLİK YAPMAK İSTEMEDİĞİNİZ YERLERDE SADECE ENTER TUŞUNA BASIN.\n\n");

    // --- ÜRÜN ADI ---
    // Eski bilgisini gösteriyorum
    printf("Ürün Adı [%s]: ", scout->urunadi);
    // Kullanıcıdan girdi bekliyorum
    fgets(kullanicigirdi, sizeof(kullanicigirdi), stdin);

    // Kullanıcı ENTER tuşuna basarsa fgets onu \n diye kayıt eder
    // Aslında boş mu geçti, yeni bir bilgi mi girdi diye bakıyorum
    if (kullanicigirdi[0] != '\n')
    {
        // Yeni bilgi girildiyse bu blok çalışır
        // fgets kelimenin sonuna otomatik olarak bir Enter (\n) ekler. Onu siliyorum.
        kullanicigirdi[strcspn(kullanicigirdi, "\n")] = '\0';
        strcpy(scout->urunadi, kullanicigirdi);
    }

    // --- KATEGORİ ---
    // Eski bilgisini gösteriyorum
    printf("Kategori [%s]: ", scout->kategori);
    fgets(kullanicigirdi, sizeof(kullanicigirdi), stdin);

    if (kullanicigirdi[0] != '\n')
    {
        kullanicigirdi[strcspn(kullanicigirdi, "\n")] = '\0';
        strcpy(scout->kategori, kullanicigirdi);
    }

    // --- STOK ADEDİ ---
    // Eski bilgisini gösteriyorum
    printf("Stok Adedi [%d]: ", scout->stokAdedi);
    fgets(kullanicigirdi, sizeof(kullanicigirdi), stdin);

    if (kullanicigirdi[0] != '\n')
    {
        kullanicigirdi[strcspn(kullanicigirdi, "\n")] = '\0';
        // ASCII türünde olan int veri tipine çeviriyorum ve öyle atama yapıyorum
        scout->stokAdedi = atoi(kullanicigirdi);
    }

    // --- FİYAT ---
    // Eski bilgisini gösteriyorum
    printf("Fiyat [%.2lf]: ", scout->fiyat);
    fgets(kullanicigirdi, sizeof(kullanicigirdi), stdin);

    if (kullanicigirdi[0] != '\n')
    {
        kullanicigirdi[strcspn(kullanicigirdi, "\n")] = '\0';
        // ASCII türünde olan double veri tipine çeviriyorum ve öyle atama yapıyorum
        scout->fiyat = atof(kullanicigirdi);
    }

    // --- ZİMMETLİ PERSONEL ID ---
    // Eski bilgisini gösteriyorum
    printf("Zimmetli Personel ID [%d]: ", scout->zimmetliPersonelid);
    fgets(kullanicigirdi, sizeof(kullanicigirdi), stdin);

    if (kullanicigirdi[0] != '\n')
    {
        kullanicigirdi[strcspn(kullanicigirdi, "\n")] = '\0';
        // ASCII türünde olan int veri tipine çeviriyorum ve öyle atama yapıyorum
        scout->zimmetliPersonelid = atoi(kullanicigirdi);
    }

    printf("\nÜrün bilgileri başarıyla güncellendi!\n");
}

void urunSil()
{
    if (urunListesininBasi==NULL)
    {
        printf("Ürün listesi boş arancak ürün yok");
        return;
    }
    int silincekUrunid;
    char cevap[10];

    printf("Silmek istedeiğiniz ürünün id numarasını giriniz.");
    scanf("%d", &silincekUrunid);
    getchar();

    Urun* scout = urunListesininBasi;

    while (scout != NULL)
    {

        if (scout->id == silincekUrunid)
        {
            printf("AŞAĞIDA BİLGİLERİ BULUNAN %d ID NUMARASINA SAHİP ÜRÜNÜ SİLMEYİ ONAYLIYOR MUSUNUZ ?\n",silincekUrunid);
            printf("bu işlemin geri dönüşü yoktur\n\n");

            printf("İD:%d\n",scout->id);
            printf("İSİM:%s\n",scout->urunadi);
            printf("KATEGORİ:%s\n",scout->kategori);
            printf("STOK:%d\n",scout->stokAdedi);
            printf("FİYAT:%.2lf\n",scout->fiyat);
            printf("ZİMMETLİ PERSONELİN İD NUMARASI:%d\n",scout->zimmetliPersonelid);

            //Kontrol sorusu
            printf("İŞLEMİN SONLANMASI İÇİN 'ONAY' YAZIN, İŞLEMİN DURDURULMASI İÇİN HERHANGİ BİR SAYI GİRİN");
            scanf("%s",cevap);
            break;
        }

        scout=scout->sonraki;
    }

    if (scout == NULL)
    {
        printf("Bu id numarasına sahip ürün bulunamadı");
        return;
    }

    if (strcmp(cevap,"ONAY")==0)
    {
        if (scout==urunListesininBasi&&scout->sonraki==NULL)
        {
             urunListesininBasi=NULL;
        }
        else if (scout==urunListesininBasi && scout->sonraki!=NULL)
        {
            urunListesininBasi=scout->sonraki;
            scout->sonraki->onceki=NULL;
        }
        else if (scout->sonraki==NULL&&scout->onceki!=NULL)
        {
            scout->onceki->sonraki=NULL;
        }
        else
        {
            scout->onceki->sonraki=scout->sonraki;
            scout->sonraki->onceki=scout->onceki;
        }
        free(scout);
        printf("%d Numarasına Sahip ürün basariyla kalıcı bir şekilde sirketten silindi.\n",silincekUrunid);
    }
    else
    {
        printf("işlem durdurulmuştur.");
        return;
    }
}