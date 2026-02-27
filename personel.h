#include "structs.h"

#ifndef C_CORP_ERP_PERSONEL_H
#define C_CORP_ERP_PERSONEL_H

//Personel.c dosyasının içindeki personellistesinin bası pointerını her yerde kullanabilmek için extern kullandık
extern Personel* personelListesininBasi;

void personelEkle();
void personelListele();
void personelAra();
void personelSil();
void personelGuncelle();


#endif //C_CORP_ERP_PERSONEL_H