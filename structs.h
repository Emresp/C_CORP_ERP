//
// Created by Emre on 18.02.2026.
//

#ifndef C_CORP_ERP_STRUCTS_H
#define C_CORP_ERP_STRUCTS_H

//log kayıtlarını sağlıklı bir şekilde tutmak için
typedef struct
{
    int gun,ay,yil;
    int saat,dakika,saniye;
}TarihSaat;

//personel bilgileri
typedef struct Personel
{
    int id;
    char isim[20];
    char soyisim[20];
    char departman[30];
    char sifre[30];
    double maas;
    int performansPuani;

    int bagliolduguYonetici; //Müdürünün id numarası

    //personel listeini yönetirken esnek hareket edebilmek için önceki ve sonrakini tutuyoruz.
    struct Personel* onceki;
    struct Personel* sonraki;

}Personel;

typedef struct Urun
{
    int id; //Ürün id'si
    char urunadi[20];
    char kategori[30];
    int stokAdedi;
    double fiyat;


    //ürün stokta var ama bir çalışana tahsis edilmiş ve o kullanıyor.
    int zimmetliPersonelid;

    //listeyi esnek takip etmek için
    struct Urun* onceki;
    struct Urun* sonraki;
}Urun;

#endif //C_CORP_ERP_STRUCTS_H