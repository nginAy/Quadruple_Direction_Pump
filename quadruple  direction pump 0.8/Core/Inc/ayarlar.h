/*
 * ayarlar.h
 *
 *  Created on: 29 Oca 2023
 *      Author: MONSTER
 */

#ifndef INC_AYARLAR_H_
#define INC_AYARLAR_H_

void Genel_Ekran_Ayar();
void Ayar_Gun();
void Ayar_Pompa();
void pompa1_ayar();
void pompa2_ayar();
void pompa3_ayar();
void pompa4_ayar();
void sivi_doldurma();
void ana_ekran();
void saat_ayarlar();

void pazartesi();
void sali();
void carsamba();
void persembe();
void cuma();
void cumartesi();
void pazar();

void Flash_Write(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read(uint32_t Flash_Address);

void Flash_Write2(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read2(uint32_t Flash_Address);

void Flash_Write3(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read3(uint32_t Flash_Address);

void Flash_Write4(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read4(uint32_t Flash_Address);

void Flash_Write5(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read5(uint32_t Flash_Address);

void Flash_Write6(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng);
uint32_t *Flash_Read6(uint32_t Flash_Address);

#endif /* INC_AYARLAR_H_ */
