
/*
 * ayarlar.c
 *
 *  Created on: 29 Oca 2023
 *      Author: MONSTER
 */

#include "stm32f4xx_hal.h"
#include "main.h"
#include "STM32F407_I2C_LCD16x02_Driver.h"
#include "stm32f4xx_hal_conf.h"
#include "ayarlar.h"
#include "stdlib.h"
#include "liquidcrystal_i2c.h"
#include "rtc.h"

uint8_t degisken=0;
uint8_t degisken2=0;
uint8_t degisken3=0;
uint8_t degisken4=0;
uint8_t degisken5=0;
uint8_t degisken6=0;
uint8_t degisken7=0;
uint8_t degisken8=0;
uint8_t degisken9=0;
uint8_t degisken10=0;
uint8_t degisken11=0;
uint8_t degisken12=0;
uint8_t degisken13=0;
uint8_t degisken14=0;
uint8_t degisken15=0;
uint8_t degisken16=0;

uint32_t *data;
uint32_t veri[12];
uint32_t read[12];
uint32_t p1_ml=0;
uint32_t p1_tkrr=0;
uint32_t p1_saat;
uint32_t flash_datas[6];


uint32_t *data2;
uint32_t veri2[12];
uint32_t read2[12];
uint16_t p2_ml=0;
uint16_t p2_tkrr=0;
uint32_t flash_datas2[6];

uint32_t *data3;
uint32_t veri3[12];
uint32_t read3[12];
uint16_t p3_ml=0;
uint16_t p3_tkrr=0;
uint32_t flash_datas3[6];

uint32_t *data4;
uint32_t veri4[12];
uint32_t read4[12];
uint16_t p4_ml=0;
uint16_t p4_tkrr=0;
uint32_t flash_datas4[6];

uint32_t pazartesi_pompa1=0;
uint32_t  pazartesi_pompa2=0;
uint32_t  pazartesi_pompa3=0;
uint32_t  pazartesi_pompa4=0;
uint32_t  sali_pompa1=0;
uint32_t  sali_pompa2=0;
uint32_t  sali_pompa3=0;
uint32_t  sali_pompa4=0;
uint32_t  carsamba_pompa1=0;
uint32_t  carsamba_pompa2=0;
uint32_t  carsamba_pompa3=0;
uint32_t  carsamba_pompa4=0;
uint32_t  persembe_pompa1=0;
uint32_t  persembe_pompa2=0;
uint32_t  persembe_pompa3=0;
uint32_t  persembe_pompa4=0;
uint32_t  cuma_pompa1=0;
uint32_t  cuma_pompa2=0;
uint32_t  cuma_pompa3=0;
uint32_t  cuma_pompa4=0;
uint32_t  cumartesi_pompa1=0;
uint32_t  cumartesi_pompa2=0;
uint32_t  cumartesi_pompa3=0;
uint32_t  cumartesi_pompa4=0;
uint32_t  pazar_pompa1=0;
uint32_t  pazar_pompa2=0;
uint32_t  pazar_pompa3=0;
uint32_t  pazar_pompa4=0;
uint32_t *data5;
uint32_t veri5[29];
uint32_t read5[40];
uint32_t flash_datas5[6];
uint32_t firsttime=0,lasttime=0;



int saat,dakika,gun;
Time_Struct setTimer;

extern int main(void);
uint32_t veri_sifirlama[35];




void Genel_Ekran_Ayar(){



	 LCD_Send_String_On_Line1("  Ayarlar   ");
	 HAL_Delay(2000);
     LCD_Send_Cmd(LCD_CLEAR_DISPLAY);



     while(1){
     if(degisken==0){
    	 LCD_Send_String_On_Line1(">>Gun Secimi  ");
    	 LCD_Send_String_On_Line2(" Pompa Ayarlar  ");



    	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  || HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1 )
    	  {

    		  degisken=1;
    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

    	  }
    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
    		  Ayar_Gun();


    	  }

    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
    	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
    	  	    	 																				 					 main();
    	  	    	 																				 					                                          }
     }
     if(degisken==1){

    	 LCD_Send_String_On_Line1("Gun Secimi   ");
    	 LCD_Send_String_On_Line2(">>Pompa Ayarlar  ");


    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1 || HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1 )
    	     	  {
    	     		  degisken=2;
    	     		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

    	     	  }
    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
    		 Ayar_Pompa();

    	 	}
    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
    	 	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
    	 	    	 																				 					main();
    	 	    	 																				 					                                          }
     }
     if(degisken==2){

         	 LCD_Send_String_On_Line1("Pompa Ayarlar  ");
         	 LCD_Send_String_On_Line2(">>Saat Ayarlar ");


         	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1 )
         	     	  {
         	     		  degisken=0;
         	     		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

         	     	  }
         	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1 ){
         		degisken=3;
         		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
         	 }
         	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
         		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
         		 saat_ayarlar();

         	 	}
         	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
         	 	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
         	 	    	 																				 					main();
         	 	    	 																				 					                                          }
          }
     if(degisken==3){

             	 LCD_Send_String_On_Line1(">>Pompa Ayarlar  ");
             	 LCD_Send_String_On_Line2("Saat Ayarlar ");


             	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1 )
             	     	  {
             	     		  degisken=2;
             	     		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

             	     	  }
             	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1 ){
             		degisken=0;
             		         	  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
             	 }
             	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
             		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
             		 Ayar_Pompa();

             	 	}
             	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
             	 	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
             	 	    	 																				 					main();
             	 	    	 																				 					                                          }
              }

}

}
void Ayar_Gun(){
	 data5=Flash_Read5(0x080E0000);

				 		 	                         for(int i=0;i<30;i++){

				 		 	    	 								 		  read5[i]=data5[i];
				 		 	    	 								 	   }



	if(read5[0]!=0 && read5[0]!=1  ){ Flash_Write5(0x080E0000,veri_sifirlama,30);}



	while(1){
	 if(degisken7==0){
	    	 LCD_Send_String_On_Line1(">>Pazartesi");
	    	 LCD_Send_String_On_Line2("Sali ");



	    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
	    	     	  {
	    	     		  degisken7=1;
	    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	    	     	  }

	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    		  pazartesi();


	    	  }
	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 																				 					 	Genel_Ekran_Ayar();
	    	 																				 					                                          }


	     }
	 if(degisken7==1){
	 	    	 LCD_Send_String_On_Line1("Pazartesi ");
	 	    	 LCD_Send_String_On_Line2(">>Sali ");




		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
		    	     	  {
		    	     		  degisken7=2;
		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		    	     	  }
		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
		    			    	     	  {
		    			    	     		  degisken7=0;
		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		    			    	     	  }
	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	    		  sali();
                                              }
	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	 	    		    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	    		    	 																				 					 	Genel_Ekran_Ayar();
	 	    		    	 																				 					                                          }
	 	     }
	 if(degisken7==2){
	 	 	    	 LCD_Send_String_On_Line1("Sali");
	 	 	    	 LCD_Send_String_On_Line2(">>Carsamba ");




	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
	 		    	     	  {
	 		    	     		  degisken7=3;
	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	 		    	     	  }
	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
	 		    			    	     	  {
	 		    			    	     		  degisken7=4;
	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 		    			    	     	  }
	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	    		carsamba();


	 	 	    	  }
	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	 	 	    		    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	    		    	 																				 					 	Genel_Ekran_Ayar();
	 	 	    		    	 																				 					                                          }
	 	 	     }
	 if(degisken7==4){
		 	 	 	    	 LCD_Send_String_On_Line1(">>Sali");
		 	 	 	    	 LCD_Send_String_On_Line2("Carsamba");




		 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
		 	 		    	     	  {
		 	 		    	     		  degisken7=2;
		 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		 	 		    	     	  }
		 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
		 	 		    			    	     	  {
		 	 		    			    	     		  degisken7=0;
		 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 		    			    	     	  }
		 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
		 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 	 	    		 sali();


		 	 	 	    	  }
		 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
		 	 	 	    		    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 	 	    		    	 																				 					 	Genel_Ekran_Ayar();
		 	 	 	    		    	 																				 					                                          }
		 	 	 	     }
	 if(degisken7==3){
	 	 	 	    	 LCD_Send_String_On_Line1("Carsamba");
	 	 	 	    	 LCD_Send_String_On_Line2(">>Persembe ");




	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
	 	 		    	     	  {
	 	 		    	     		  degisken7=5;
	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	 	 		    	     	  }
	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
	 	 		    			    	     	  {
	 	 		    			    	     		  degisken7=6;
	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 		    			    	     	  }
	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	 	    		persembe();


	 	 	 	    	  }
	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	 	 	 	    		    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	 	    		    	 																				 					 	Genel_Ekran_Ayar();
	 	 	 	    		    	 																				 					                                          }
	 	 	 	     }
	 if(degisken7==6){
	 	 	 	 	    	 LCD_Send_String_On_Line1(">>Carsamba");
	 	 	 	 	    	 LCD_Send_String_On_Line2("Persembe ");




	 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
	 	 	 		    	     	  {
	 	 	 		    	     		  degisken7=3;
	 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	 	 	 		    	     	  }
	 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
	 	 	 		    			    	     	  {
	 	 	 		    			    	     		  degisken7=4;
	 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	 		    			    	     	  }
	 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	 	 	    		carsamba();


	 	 	 	 	    	  }
	 	 	 	 	      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	 	 	 	 	    	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 	 	 	 	    	    	 																				 					 	Genel_Ekran_Ayar();
	 	 	 	 	    	    	 																				 					                                          }
	 	 	 	 	     }
	 if(degisken7==5){
		 	 	 	 	    	 LCD_Send_String_On_Line1("Persembe");
		 	 	 	 	    	 LCD_Send_String_On_Line2(">>Cuma ");




		 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
		 	 	 		    	     	  {
		 	 	 		    	     		  degisken7=7;
		 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		 	 	 		    	     	  }
		 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
		 	 	 		    			    	     	  {
		 	 	 		    			    	     		  degisken7=8;
		 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 	 		    			    	     	  }
		 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
		 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 	 	 	    		cuma();


		 	 	 	 	    	  }
		 	 	 	 	      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
		 	 	 	 	    	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 	 	 	 	    	    	 																				 					 	Genel_Ekran_Ayar();
		 	 	 	 	    	    	 																				 					                                          }
		 	 	 	 	     }

	 if(degisken7==8){
			 	 	 	 	    	 LCD_Send_String_On_Line1(">>Persembe");
			 	 	 	 	    	 LCD_Send_String_On_Line2("Cuma ");




			 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
			 	 	 		    	     	  {
			 	 	 		    	     		  degisken7=5;
			 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

			 	 	 		    	     	  }
			 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
			 	 	 		    			    	     	  {
			 	 	 		    			    	     		  degisken7=6;
			 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
			 	 	 		    			    	     	  }
			 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
			 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
			 	 	 	 	    		persembe();


			 	 	 	 	    	  }
			 	 	 	 	      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
			 	 	 	 	    	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
			 	 	 	 	    	    	 																				 					 	Genel_Ekran_Ayar();
			 	 	 	 	    	    	 																				 					                                          }
			 	 	 	 	     }
	 if(degisken7==7){
				 	 	 	 	    	 LCD_Send_String_On_Line1("Cuma");
				 	 	 	 	    	 LCD_Send_String_On_Line2(">>Cumartesi ");




				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
				 	 	 		    	     	  {
				 	 	 		    	     		  degisken7=9;
				 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

				 	 	 		    	     	  }
				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
				 	 	 		    			    	     	  {
				 	 	 		    			    	     		  degisken7=10;
				 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				 	 	 		    			    	     	  }
				 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
				 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				 	 	 	 	    		cumartesi();


				 	 	 	 	    	  }
				 	 	 	 	      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
				 	 	 	 	    	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				 	 	 	 	    	    	 																				 					 	Genel_Ekran_Ayar();
				 	 	 	 	    	    	 																				 					                                          }
				 	 	 	 	     }
	 if(degisken7==10){
					 	 	 	 	    	 LCD_Send_String_On_Line1(">>Cuma");
					 	 	 	 	    	 LCD_Send_String_On_Line2("Cumartesi ");




					 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
					 	 	 		    	     	  {
					 	 	 		    	     		  degisken7=7;
					 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

					 	 	 		    	     	  }
					 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
					 	 	 		    			    	     	  {
					 	 	 		    			    	     		  degisken7=8;
					 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
					 	 	 		    			    	     	  }
					 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
					 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
					 	 	 	 	    		cuma();


					 	 	 	 	    	  }
					 	 	 	 	      if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
					 	 	 	 	    	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
					 	 	 	 	    	    	 																				 					 	Genel_Ekran_Ayar();
					 	 	 	 	    	    	 																				 					                                          }
					 	 	 	 	     }
	 if(degisken7==9){
	 				 	 	 	 	    	 LCD_Send_String_On_Line1("Cumartesi");
	 				 	 	 	 	    	 LCD_Send_String_On_Line2(">>Pazar");




	 				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
	 				 	 	 		    	     	  {
	 				 	 	 		    	     		  degisken7=0;
	 				 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	 				 	 	 		    	     	  }
	 				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
	 				 	 	 		    			    	     	  {
	 				 	 	 		    			    	     		  degisken7=11;
	 				 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 				 	 	 		    			    	     	  }
	 				 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
	 				 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 				 	 	 	 	    		pazar();


	 				 	 	 	 	    	  }
	 				 	 	 	 	     if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	 				 	 	 	 	   	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	 				 	 	 	 	   	    	 																				 					 	Genel_Ekran_Ayar();
	 				 	 	 	 	   	    	 																				 					                                          }
	 				 	 	 	 	     }
	 if(degisken7==11){
		 				 	 	 	 	    	 LCD_Send_String_On_Line1(">>Cumartesi");
		 				 	 	 	 	    	 LCD_Send_String_On_Line2("Pazar");




		 				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
		 				 	 	 		    	     	  {
		 				 	 	 		    	     		  degisken7=9;
		 				 	 	 		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		 				 	 	 		    	     	  }
		 				 	 	 		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
		 				 	 	 		    			    	     	  {
		 				 	 	 		    			    	     		  degisken7=10;
		 				 	 	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 				 	 	 		    			    	     	  }
		 				 	 	 	 	    	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
		 				 	 	 	 	    		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 				 	 	 	 	    		cumartesi();


		 				 	 	 	 	    	  }
		 				 	 	 	 	     if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
		 				 	 	 	 	   	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		 				 	 	 	 	   	    	 																				 					 	Genel_Ekran_Ayar();
		 				 	 	 	 	   	    	 																				 					                                          }
		 				 	 	 	 	     }

	}
}

void Ayar_Pompa(){


	while(1){


		if(degisken2==0){
		    	 LCD_Send_String_On_Line1(">>Pompa 1   ");
		    	 LCD_Send_String_On_Line2(" Pompa 2  ");

		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
		    	     	  {
		    	     		  degisken2=1;
		    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		    	     	  }
		    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
		    			    	     	  {
		    			    	     		  degisken2=3;
		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		    			    	     	  }
		    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
		    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		    		    		  LCD_Send_String_On_Line1("     POMPA 1");
		    		    		  HAL_Delay(1000);
		    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

		    		 pompa1_ayar();


		    	 }
		    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
		    	     	  	    	 																				 					Genel_Ekran_Ayar();
		    	     	  	    	 																				 					                                          }
		}
		if(degisken2==1){
				    	 LCD_Send_String_On_Line1(" Pompa 1   ");
				    	 LCD_Send_String_On_Line2(">>Pompa 2  ");

				    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1 )
				    	     	  {
				    	     		  degisken2=2;
				    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

				    	     	  }
				    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
				    	 		    			    	     	  {
				    	 		    			    	     		  degisken2=0;
				    	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

				    	 		    			    	     	  }

				    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
				    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				    			    		    		  LCD_Send_String_On_Line1("     POMPA 2");
				    			    		    		  HAL_Delay(1000);
				    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				    			    		 pompa2_ayar();

				    			    	 }
				    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
				    	 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
				    	 		    	     	  	    	 																				 					Genel_Ekran_Ayar();
				    	 		    	     	  	    	 																				 					                                          }
				}
		if(degisken2==2){
						    	 LCD_Send_String_On_Line1(" Pompa 2   ");
						    	 LCD_Send_String_On_Line2(">>Pompa 3  ");

						    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
						    	     	  {
						    	     		  degisken2=3;
						    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

						    	     	  }
						    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
						    	 		    			    	     	  {
						    	 		    			    	     		  degisken2=5;
						    	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

						    	 		    			    	     	  }
						    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
						    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
						    			    		    		  LCD_Send_String_On_Line1("     POMPA 3");
						    			    		    		  HAL_Delay(1000);
						    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
						    			    		pompa3_ayar();
						    			    	 }
						    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
						    	 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
						    	 		    	     	  	    	 																				 					Genel_Ekran_Ayar();
						    	 		    	     	  	    	 																				 					                                          }
						}

		if(degisken2==5){
								    	 LCD_Send_String_On_Line1(">>Pompa 2   ");
								    	 LCD_Send_String_On_Line2(" Pompa 3  ");

								    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
								    	     	  {
								    	     		  degisken2=2;
								    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

								    	     	  }
								    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
								    	 		    			    	     	  {
								    	 		    			    	     		  degisken2=0;
								    	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

								    	 		    			    	     	  }
								    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
								    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    			    		    		  LCD_Send_String_On_Line1("     POMPA 2");
								    			    		    		  HAL_Delay(1000);
								    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    			    		 pompa2_ayar();
								    			    	 }
								    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
								    	 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    	 		    	     	  	    	 																				 					Genel_Ekran_Ayar();
								    	 		    	     	  	    	 																				 					                                          }
								}
		if(degisken2==3){
								    	 LCD_Send_String_On_Line1(" Pompa 3   ");
								    	 LCD_Send_String_On_Line2(">>Pompa 4  ");

								    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
								    	     	  {
								    	     		  degisken2=0;
								    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

								    	     	  }
								    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
								    	 		    			    	     	  {
								    	 		    			    	     		  degisken2=6;
								    	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

								    	 		    			    	     	  }
								    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
								    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    			    		    		  LCD_Send_String_On_Line1("     POMPA 4");
								    			    		    		  HAL_Delay(1000);
								    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    			    		 pompa4_ayar();
								    			    	 }
								    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
								    	 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
								    	 		    	     	  	    	 																				 					Genel_Ekran_Ayar();
								    	 		    	     	  	    	 																				 					                                          }
								}
		if(degisken2==6){
										    	 LCD_Send_String_On_Line1(">>Pompa 3   ");
										    	 LCD_Send_String_On_Line2(" Pompa 4  ");

										    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1  )
										    	     	  {
										    	     		  degisken2=3;
										    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										    	     	  }
										    	 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1  )
										    	 		    			    	     	  {
										    	 		    			    	     		  degisken2=5;
										    	 		    			    	     		  LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										    	 		    			    	     	  }
										    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){
										    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
										    			    		    		  LCD_Send_String_On_Line1("     POMPA 3");
										    			    		    		  HAL_Delay(1000);
										    			    		 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
										    			    		 pompa3_ayar();
										    			    	 }
										    	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
										    	 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
										    	 		    	     	  	    	 																				 					Genel_Ekran_Ayar();
										    	 		    	     	  	    	 																				 					                                          }
										}










		}
}

void pompa1_ayar(){
	char snum[50];
	 data=Flash_Read(0x08020000);
		 		 	                         for(int i=0;i<=12;i++){

		 		 	    	 								 		  read[i]=data[i];
		 		 	    	 								 	  }


		 		 	    	 				 p1_ml=read[0];
		 		 	    	 				 p1_tkrr=read[1];
		 		 	    	 				 p1_saat=read[2];
		 		 	    	 				 Flash_Write(0x08020000,read,12);

	while(1){



		if(degisken3==0)
		{


			         LCD_Send_String_On_Line1(">Gun/Ml  1/");
					 LCD_Send_String_On_Line2("Gun/Tkrr 1/");

					 itoa((p1_ml), snum, 10);
					 HD44780_SetCursor(11,0);
					 HD44780_PrintStr(snum);



					itoa((p1_tkrr), snum, 10);
					HD44780_SetCursor(11,1);
					HD44780_PrintStr(snum);


				    if((p1_ml==10 || p1_ml==100 || p1_ml==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p1_ml=p1_ml-1;veri[0]=p1_ml;Flash_Write(0x08020000,veri,12);}

				    firsttime =HAL_GetTick();

				    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){

					 p1_ml=p1_ml+1;
					 veri[0]=p1_ml;


					 }


					 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p1_ml>0 ){p1_ml=p1_ml-1;veri[0]=p1_ml;}
//					 Flash_Write(0x08020000,veri,12);


					 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){



						 Flash_Write(0x08020000,veri,12);
						 degisken3=1;
						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

					 }
                   	 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){



                   								              Flash_Write(0x08020000,veri,12);
					 		    	     	  	    	 		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
					 		    	     	  	    	 		Ayar_Pompa();
	                                                           }
		}
		if(degisken3==1)
				{
			          data=Flash_Read(0x08020000);
					 		 	                                             for(int i=0;i<=12;i++){

					 		 	    	 								 		  read[i]=data[i];
					 		 	    	 								 	  }

					         LCD_Send_String_On_Line1("Gun/Ml  1/");
							 LCD_Send_String_On_Line2(">Gun/Tkrr 1/");

							 itoa((p1_ml), snum, 10);
							 HD44780_SetCursor(10,0);
							 HD44780_PrintStr(snum);



							itoa((p1_tkrr), snum, 10);
							HD44780_SetCursor(12,1);
							HD44780_PrintStr(snum);

							if((p1_tkrr==10 || p1_tkrr==100 || p1_tkrr==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p1_tkrr=p1_tkrr-1;veri[1]=p1_tkrr;Flash_Write(0x08020000,veri,12);}
							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1)
							 {
							 p1_tkrr=p1_tkrr+1;
							 veri[1]=p1_tkrr;
							 Flash_Write(0x08020000,veri,12);
							 }

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p1_tkrr>0 ){p1_tkrr=p1_tkrr-1;veri[1]=p1_tkrr;
							 Flash_Write(0x08020000,veri,12);
							 }

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){

								 degisken3=2;
								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 }
							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){

							 								 degisken3=0;
							 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 							 }


							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){


												 		    	     	  	    	 		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 		    	     	  		    	     	  	    	 		Ayar_Pompa(); 	  	    	 																				 					Ayar_Pompa();
										 					                                          }

				}
		if(degisken3==2)
						{
							         LCD_Send_String_On_Line1("Gun/Tkrr 1/");
									 LCD_Send_String_On_Line2("> Bsl/Saat 17.31");

									 itoa((p1_tkrr), snum, 10);
									 HD44780_SetCursor(11,0);
									 HD44780_PrintStr(snum);



//									itoa((p1_tkrr), snum, 10);    saat eklenince ekleneck
//									HD44780_SetCursor(14,1);
//									HD44780_PrintStr(snum);

//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p1_tkrr=p1_tkrr+1;veri[1]=p1_tkrr;Flash_Write(0x080E0000,veri,12);}
//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1){p1_tkrr=p1_tkrr-1;veri[1]=p1_tkrr;Flash_Write(0x080E0000,veri,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
										 degisken3=0;
										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 }
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
									 								 degisken3=3;
									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 							 }
									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
														 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 		    	     	  	    	 																				 					Ayar_Pompa();
														 		    	     	  	    	 																				 					                                          }



						}

		if(degisken3==3)
						{
							         LCD_Send_String_On_Line1(">Gun/Tkrr 1/");
									 LCD_Send_String_On_Line2("Bsl/Saat 17.31");

									 itoa((p1_tkrr), snum, 10);
									 HD44780_SetCursor(12,0);
									 HD44780_PrintStr(snum);



//									itoa((p1_tkrr), snum, 10);  saat eklenecek
//									HD44780_SetCursor(14,1);
//									HD44780_PrintStr(snum);


										if((p1_tkrr==10 || p1_tkrr==100 || p1_tkrr==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p1_tkrr=p1_tkrr-1;veri[1]=p1_tkrr;Flash_Write(0x08020000,veri,12);}
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p1_tkrr=p1_tkrr+1;veri[1]=p1_tkrr;Flash_Write(0x08020000,veri,12);}
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p1_tkrr>0){p1_tkrr=p1_tkrr-1;veri[1]=p1_tkrr;Flash_Write(0x08020000,veri,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
										 degisken3=2;
										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 }

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
									 								 degisken3=0;
									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 							 }

									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
														 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 		    	     	  	    	 																				 					Ayar_Pompa();
														 		    	     	  	    	 																				 					                                          }

						}



	}



}

 void pompa2_ayar(){
	 char snum2[50];
	 data2=Flash_Read2(0x08040000);
	 		 	                         for(int i=0;i<=12;i++){

	 		 	    	 								 		  read2[i]=data2[i];
	 		 	    	 								 	  }


	 		 	    	 				p2_ml=read2[0];
	 		 	    	 				 p2_tkrr=read2[1];
	 		 	    	 				 Flash_Write2(0x08040000,read2,12);


	while(1){

		if(degisken4==0)
		{

			         LCD_Send_String_On_Line1(">Gun/Ml  1/");
					 LCD_Send_String_On_Line2("Gun/Tkrr 1/");

					 itoa((p2_ml), snum2, 10);
					 HD44780_SetCursor(11,0);
					 HD44780_PrintStr(snum2);



					itoa((p2_tkrr), snum2, 10);
					HD44780_SetCursor(11,1);
					HD44780_PrintStr(snum2);

					 if((p2_ml==10 || p2_ml==100 || p2_ml==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p2_ml=p2_ml-1;veri2[0]=p2_ml;Flash_Write2(0x08040000,veri2,12);}
					 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1)
					 {
						 p2_ml=p2_ml+1;
						 veri2[0]=p2_ml;
				     }
					 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p2_ml>0 )
					 {p2_ml=p2_ml-1;
					 veri2[0]=p2_ml;
					 }

					 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
						 degisken4=1;
						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
					 }
					 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
						                                                        Flash_Write2(0x08040000,veri2,12);
						 				 		    	     	  	    		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
										 		    	     	  	    	 	Ayar_Pompa();
							 }


		}

		if(degisken4==1)
				{
					         LCD_Send_String_On_Line1("Gun/Ml  1/");
							 LCD_Send_String_On_Line2(">Gun/Tkrr 1/");

							 itoa((p2_ml), snum2, 10);
							 HD44780_SetCursor(10,0);
							 HD44780_PrintStr(snum2);



							itoa((p2_tkrr), snum2, 10);
							HD44780_SetCursor(12,1);
							HD44780_PrintStr(snum2);

							if((p2_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p2_ml=p2_ml-1;veri2[0]=p2_ml;Flash_Write2(0x08040000,veri2,12);}

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p2_tkrr=p2_tkrr+1;veri2[1]=p2_tkrr;Flash_Write2(0x08040000,veri2,12);}
							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p2_tkrr>0 ){p2_tkrr=p2_tkrr-1;veri2[1]=p2_tkrr;Flash_Write2(0x08040000,veri2,12);}

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
								 degisken4=2;
								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 }
							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
							 								 degisken4=0;
							 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 							 }

							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
												 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 		    	     	  	    	 																				 					Ayar_Pompa();
												 		    	     	  	    	 																				 					                                          }

				}
		if(degisken4==2)
						{
							         LCD_Send_String_On_Line1("Gun/Tkrr 1/");
									 LCD_Send_String_On_Line2("> Bsl/Saat 17.31");

									 itoa((p2_tkrr), snum2, 10);
									 HD44780_SetCursor(11,0);
									 HD44780_PrintStr(snum2);



//									itoa((p1_tkrr), snum, 10);    saat eklenince ekleneck
//									HD44780_SetCursor(14,1);
//									HD44780_PrintStr(snum);

//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p1_tkrr=p1_tkrr+1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}
//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1){p1_tkrr=p1_tkrr-1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
										 degisken4=0;
										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 }
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
									 								 degisken4=3;
									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 							 }
									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
														 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 		    	     	  	    	 																				 					Ayar_Pompa();
														 		    	     	  	    	 																				 					                                          }


						}

		if(degisken4==3)
						{
							         LCD_Send_String_On_Line1(">Gun/Tkrr 1/");
									 LCD_Send_String_On_Line2("Bsl/Saat 17.31");

									 itoa((p2_tkrr), snum2, 10);
									 HD44780_SetCursor(12,0);
									 HD44780_PrintStr(snum2);



//									itoa((p1_tkrr), snum, 10);  saat eklenecek
//									HD44780_SetCursor(14,1);
//									HD44780_PrintStr(snum);
									 if((p2_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p2_ml=p2_ml-1;veri2[0]=p2_ml;Flash_Write2(0x08040000,veri2,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p2_tkrr=p2_tkrr+1;veri2[1]=p2_tkrr;Flash_Write2(0x08040000,veri2,12);}
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p2_tkrr>0){p2_tkrr=p2_tkrr-1;veri2[1]=p2_tkrr;Flash_Write2(0x08040000,veri2,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
										 degisken4=2;
										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 }

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
									 								 degisken4=0;
									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 							 }

									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
														 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 		    	     	  	    	 																				 					Ayar_Pompa();
														 		    	     	  	    	 																				 					                                          }
						}



	}



}

 void pompa3_ayar(){
	 char snum3[50];
		 data3=Flash_Read3(0x08060000);
		 		 	                         for(int i=0;i<=12;i++){

		 		 	    	 								 		  read3[i]=data3[i];
		 		 	    	 								 	  }


		 		 	    	 				p3_ml=read3[0];
		 		 	    	 				 p3_tkrr=read3[1];
		 		 	    	 				 Flash_Write3(0x08060000,read3,12);

	while(1){
		if(degisken5==0)
				{

					         LCD_Send_String_On_Line1(">Gun/Ml  1/");
							 LCD_Send_String_On_Line2("Gun/Tkrr 1/");

							 itoa((p3_ml), snum3, 10);
							 HD44780_SetCursor(11,0);
							 HD44780_PrintStr(snum3);



							itoa((p3_tkrr), snum3, 10);
							HD44780_SetCursor(11,1);
							HD44780_PrintStr(snum3);

							if((p3_ml==10 || p3_ml==100 || p3_ml==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p3_ml=p3_ml-1;veri3[0]=p3_ml;Flash_Write3(0x08060000,veri3,12);}

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1)
							 {p3_ml=p3_ml+1;
							 veri3[0]=p3_ml;
							 }
							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p3_ml>0 )
							 {p3_ml=p3_ml-1;
							 veri3[0]=p3_ml;
							 }

							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
								 Flash_Write3(0x08060000,veri3,12);
								 degisken5=1;
								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 }
							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
								                    Flash_Write3(0x08060000,veri3,12);
							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
							 					    Ayar_Pompa();
							 					                                          }



				}

				if(degisken5==1)
						{
							         LCD_Send_String_On_Line1("Gun/Ml  1/");
									 LCD_Send_String_On_Line2(">Gun/Tkrr 1/");

									 itoa((p3_ml), snum3, 10);
									 HD44780_SetCursor(10,0);
									 HD44780_PrintStr(snum3);



									itoa((p3_tkrr), snum3, 10);
									HD44780_SetCursor(12,1);
									HD44780_PrintStr(snum3);
									if((p3_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p3_ml=p3_ml-1;veri3[1]=p3_ml;Flash_Write3(0x08060000,veri3,12);}


									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p3_tkrr=p3_tkrr+1;veri3[1]=p3_tkrr;Flash_Write3(0x08060000,veri3,12);}
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p3_tkrr>0 ){p3_tkrr=p3_tkrr-1;veri3[1]=p3_tkrr;Flash_Write3(0x08060000,veri3,12);}

									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
										 degisken5=2;
										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 }
									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
									 								 degisken5=0;
									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 							 }
									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){

														 		    	     	  	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 		    	     	  	  	Ayar_Pompa();
														 		    	     	  	    	 																				 					                                          }


						}
				if(degisken5==2)
								{
									         LCD_Send_String_On_Line1("Gun/Tkrr 1/");
											 LCD_Send_String_On_Line2("> Bsl/Saat 17.31");

											 itoa((p3_tkrr), snum3, 10);
											 HD44780_SetCursor(11,0);
											 HD44780_PrintStr(snum3);



		//									itoa((p1_tkrr), snum, 10);    saat eklenince ekleneck
		//									HD44780_SetCursor(14,1);
		//									HD44780_PrintStr(snum);

		//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p1_tkrr=p1_tkrr+1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}
		//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1){p1_tkrr=p1_tkrr-1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken5=0;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
											 								 degisken5=3;
											 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 							 }
										}

				 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){

									 		    	     	  	    	 									LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
									 		    	     	  	    	 									Ayar_Pompa();
									 		    	     	  	    	 																				 					                                          }
								}

				if(degisken5==3)
								{
									         LCD_Send_String_On_Line1(">Gun/Tkrr 1/");
											 LCD_Send_String_On_Line2("Bsl/Saat 17.31");

											 itoa((p3_tkrr), snum3, 10);
											 HD44780_SetCursor(12,0);
											 HD44780_PrintStr(snum3);



		//									itoa((p1_tkrr), snum, 10);  saat eklenecek
		//									HD44780_SetCursor(14,1);
		//									HD44780_PrintStr(snum);
											 if((p3_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p3_ml=p3_ml-1;veri3[1]=p3_ml;Flash_Write3(0x08060000,veri3,12);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p3_tkrr=p3_tkrr+1;veri3[1]=p3_tkrr;Flash_Write3(0x08060000,veri3,12);}
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p3_tkrr>0){p3_tkrr=p3_tkrr-1;veri3[1]=p3_tkrr;Flash_Write3(0x08060000,veri3,12);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken5=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
											 								 degisken5=0;
											 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 							 }



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																 		    	     	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 		    	     	Ayar_Pompa();
																 		    	     	  	    	 																				 					                                          }


	}
 }

 void pompa4_ayar(){
 	 char snum4[50];
 		 data4=Flash_Read4(0x08080000);
 		 		 	                         for(int i=0;i<=12;i++){

 		 		 	    	 								 		  read4[i]=data4[i];
 		 		 	    	 								 	  }


 		 		 	    	 				p4_ml=read4[0];
 		 		 	    	 				 p4_tkrr=read4[1];
 		 		 	    	 				 Flash_Write4(0x08080000,read4,12);

 	while(1){
 		if(degisken6==0)
 				{

 					         LCD_Send_String_On_Line1(">Gun/Ml  1/");
 							 LCD_Send_String_On_Line2("Gun/Tkrr 1/");

 							 itoa((p4_ml), snum4, 10);
 							 HD44780_SetCursor(11,0);
 							 HD44780_PrintStr(snum4);



 							itoa((p4_tkrr), snum4, 10);
 							HD44780_SetCursor(11,1);
 							HD44780_PrintStr(snum4);

 							if((p4_ml==10 || p4_ml==100 || p4_ml==1000) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p4_ml=p4_ml-1;veri4[0]=p4_ml;Flash_Write4(0x08080000,veri4,12);}

 							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1)
 							 {
 							 p4_ml=p4_ml+1;
 							 veri4[0]=p4_ml;

 							 }
 							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p4_ml>0 )
 							 {
 								 p4_ml=p4_ml-1;
 								 veri4[0]=p4_ml;

 								}

 							 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
 								Flash_Write4(0x08080000,veri4,12);
 								 degisken6=1;
 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 							 }

 							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
 								                                                    Flash_Write4(0x08080000,veri4,12);
 												 		    	   				 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 												 		    	     	  	    	Ayar_Pompa();
 												 		     					             }

 				}

 				if(degisken6==1)
 						{
 							         LCD_Send_String_On_Line1("Gun/Ml  1/");
 									 LCD_Send_String_On_Line2(">Gun/Tkrr 1/");

 									 itoa((p4_ml), snum4, 10);
 									 HD44780_SetCursor(10,0);
 									 HD44780_PrintStr(snum4);



 									itoa((p4_tkrr), snum4, 10);
 									HD44780_SetCursor(12,1);
 									HD44780_PrintStr(snum4);

 									if((p3_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p4_ml=p4_ml-1;veri4[1]=p4_ml;Flash_Write4(0x08080000,veri4,12);}

 									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1)
 									 {
 										 p4_tkrr=p4_tkrr+1;
 									     veri4[1]=p4_tkrr;
 									    Flash_Write4(0x08080000,veri4,12);
 									     }
 									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p4_tkrr>0 )
 									 {
 										 p4_tkrr=p4_tkrr-1;
 										 veri4[1]=p4_tkrr;
 										Flash_Write4(0x08080000,veri4,12);
 								     }

 									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
 										 degisken6=2;
 										 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 									 }
 									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){

 									 								 degisken6=0;
 									 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 									 							 }

 									 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){

 																		 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 																			Ayar_Pompa();
 														 		    	         }

 						}
 				if(degisken6==2)
 								{
 									         LCD_Send_String_On_Line1("Gun/Tkrr 1/");
 											 LCD_Send_String_On_Line2("> Bsl/Saat 17.31");

 											 itoa((p4_tkrr), snum4, 10);
 											 HD44780_SetCursor(11,0);
 											 HD44780_PrintStr(snum4);



 		//									itoa((p1_tkrr), snum, 10);    saat eklenince ekleneck
 		//									HD44780_SetCursor(14,1);
 		//									HD44780_PrintStr(snum);

 		//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p1_tkrr=p1_tkrr+1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}
 		//									 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1){p1_tkrr=p1_tkrr-1;veri2[1]=p1_tkrr;Flash_Write(0x080E0000,veri2,12);}

 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
 												 degisken6=0;
 												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 											 }
 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
 											 								 degisken6=3;
 											 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 											 							 }


 											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
 																 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 																 		    	     	  	    	 																				 					Ayar_Pompa();
 																 		    	     	  	    	 																				 					                                          }
 								}

 				if(degisken6==3)
 								{
 									         LCD_Send_String_On_Line1(">Gun/Tkrr 1/");
 											 LCD_Send_String_On_Line2("Bsl/Saat 17.31");

 											 itoa((p4_tkrr), snum4, 10);
 											 HD44780_SetCursor(12,0);
 											 HD44780_PrintStr(snum4);



 		//									itoa((p1_tkrr), snum, 10);  saat eklenecek
 		//									HD44780_SetCursor(14,1);
 		//									HD44780_PrintStr(snum);

 											if((p4_ml==10 ) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);p4_ml=p4_ml-1;veri4[1]=p4_ml;Flash_Write4(0x08080000,veri4,12);}

 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1){p4_tkrr=p4_tkrr+1;veri4[1]=p4_tkrr;Flash_Write4(0x08080000,veri4,12);}
 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && p4_tkrr>0){p4_tkrr=p4_tkrr-1;veri4[1]=p4_tkrr;Flash_Write4(0x08080000,veri4,12);}

 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
 												 degisken6=2;
 												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 											 }

 											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
 											 								 degisken6=0;
 											 								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 											 							 }


 											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
 																 		    	     	  	    	 																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
 																 		    	     	  	    	 																				 					Ayar_Pompa();
 																 		    	     	  	    	 																				 					                                          }
 								}


 	}
  }



void pazartesi(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN


	 data5=Flash_Read5(0x080E0000);

			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }


			 		 	                       pazartesi_pompa1=read5[0];
			 		 	                       pazartesi_pompa2=read5[1];
			 		 	                       pazartesi_pompa3=read5[2];
			 		 	                       pazartesi_pompa4=read5[3];


		 		 	                       Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken9==0)
			{


		                                                                    data5=Flash_Read5(0x080E0000);
															 					for(int i=0;i<29;i++)
															 							 	{
															 							 	veri5[i]=data5[i];
															 							 	}



			if(pazartesi_pompa1==0 ){

				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa1=1;veri5[0]=pazartesi_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken9=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																														 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																														 					 	 Ayar_Gun();
																														 					                                          }


			}
			if(pazartesi_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa1=0;veri5[0]=pazartesi_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken9=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																	 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																	 					 	 Ayar_Gun();
																																	 					                                          }

						}


			}

	if(degisken9==1)
				{

				if(pazartesi_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa2=1;veri5[1]=pazartesi_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken9=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken9=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																															 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																															 					 	 Ayar_Gun();
																															 					                                          }
				}
				if(pazartesi_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa2=0;veri5[1]=pazartesi_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken9=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															degisken9=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																		 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																		 					 	 Ayar_Gun();
																																		 					                                          }
							}


				}



	if(degisken9==2)
					{

					if(pazartesi_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa3=1;veri5[2]=pazartesi_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken9=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																							 degisken9=4;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																											 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																											 					 	 Ayar_Gun();
																																											 					                                          }																					 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																														 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																														 					 	 Ayar_Gun();
																																														 					                                          }
					}
					if(pazartesi_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa3=0;veri5[2]=pazartesi_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken9=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																degisken9=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																																	 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																																	 					 	 Ayar_Gun();
																																																	 					                                          }
								}


					}
	if(degisken9==3)
						{

						if(pazartesi_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa4=1;veri5[3]=pazartesi_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken9=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																								 degisken9=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																	 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																	 					 	 Ayar_Gun();
																																	 					                                          }
						}
						if(pazartesi_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazartesi_pompa4=0;veri5[3]=pazartesi_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken9=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	degisken9=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																				 					 	 Ayar_Gun();
																																				 					                                          }

									}


						}


}
 }
void sali(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN


	 data5=Flash_Read5(0x080E0000);
			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }

			 		 	                       sali_pompa1=read5[4];
			 		 	                            sali_pompa2=read5[5];
			 		 	                            sali_pompa3=read5[6];
			 		 	                            sali_pompa4=read5[7];
		 		 	                       Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken10==0)
			{


		 data5=Flash_Read5(0x080E0000);
											 					for(int i=0;i<29;i++)
											 							 	{
											 							 	veri5[i]=data5[i];
											 							 	}



			if(sali_pompa1==0 ){


				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa1=1;veri5[4]=sali_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken10=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }
			}
			if(sali_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa1=0;veri5[4]=sali_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken10=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken10==1)
				{

				if(sali_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa2=1;veri5[5]=sali_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken10=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken10=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(sali_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa2=0;veri5[5]=sali_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken10=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken10=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																								 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								 					 	 Ayar_Gun();
																								 					                                          }
							}


				}



	if(degisken10==2)
					{

					if(sali_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa3=1;veri5[6]=sali_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken10=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken10=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																						 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 					 	 Ayar_Gun();
																						 					                                          }
					}
					if(sali_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa3=0;veri5[6]=sali_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken10=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken10=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken10==3)
						{

						if(sali_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa4=1;veri5[7]=sali_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken10=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken10=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(sali_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){sali_pompa4=0;veri5[7]=sali_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken10=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken10=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }
void carsamba(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN


	 data5=Flash_Read5(0x080E0000);
			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }


			 		 	                       carsamba_pompa1=read5[8];
			 		 	                       carsamba_pompa2=read5[9];
			 		 	                       carsamba_pompa3=read5[10];
			 		 	                       carsamba_pompa4=read5[11];
			 		 	                     pazartesi_pompa1=read5[0];
			 		 	                     			 		 	                       pazartesi_pompa2=read5[1];
			 		 	                     			 		 	                       pazartesi_pompa3=read5[2];
			 		 	                     			 		 	                       pazartesi_pompa4=read5[3];
		 		 	                           Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken11==0)
			{
				 data5=Flash_Read5(0x080E0000);
				 for(int i=0;i<29;i++)
				 											 							 	{
				 											 							 	veri5[i]=data5[i];
				 											 							 	}



			if(carsamba_pompa1==0 ){
				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa1=1;veri5[8]=carsamba_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken11=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }

			}
			if(carsamba_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa1=0;veri5[8]=carsamba_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken11=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken11==1)
				{

				if(carsamba_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa2=1;veri5[9]=carsamba_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken11=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken11=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(carsamba_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa2=0;veri5[9]=carsamba_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken11=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken11=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																								 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								 					 	 Ayar_Gun();
																								 					                                          }
							}


				}



	if(degisken11==2)
					{

					if(carsamba_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa3=1;veri5[10]=carsamba_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken11=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken11=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																						 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 					 	 Ayar_Gun();
																						 					                                          }
					}
					if(carsamba_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa3=0;veri5[10]=carsamba_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken11=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken11=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken11==3)
						{

						if(carsamba_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa4=1;veri5[11]=carsamba_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken11=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken11=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(carsamba_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){carsamba_pompa4=0;veri5[11]=carsamba_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken11=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken11=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }
void persembe(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN

	 data5=Flash_Read5(0x080E0000);
			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }


			 		 	                       persembe_pompa1=read5[12];
			 		 	                       persembe_pompa2=read5[13];
			 		 	                       persembe_pompa3=read5[14];
			 		 	                       persembe_pompa4=read5[15];
		 		 	                           Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken12==0)
			{
				 data5=Flash_Read5(0x080E0000);
				 for(int i=0;i<29;i++)
				 											 							 	{
				 											 							 	veri5[i]=data5[i];
				 											 							 	}



			if(persembe_pompa1==0 ){
				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa1=1;veri5[12]=persembe_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken12=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }

			}
			if(persembe_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa1=0;veri5[12]=persembe_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken12=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken12==1)
				{

				if(persembe_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa2=1;veri5[13]=persembe_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken12=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken12=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(persembe_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa2=0;veri5[13]=persembe_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken12=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken12=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																								 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								 					 	 Ayar_Gun();
																								 					                                          }
							}


				}



	if(degisken12==2)
					{

					if(persembe_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa3=1;veri5[14]=persembe_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken12=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken12=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																						 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 					 	 Ayar_Gun();
																						 					                                          }
					}
					if(persembe_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa3=0;veri5[14]=persembe_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken12=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken12=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken12==3)
						{

						if(persembe_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa4=1;veri5[15]=persembe_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken12=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken12=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(persembe_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){persembe_pompa4=0;veri5[15]=persembe_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken12=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken12=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }
void cuma(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN
	 data5=Flash_Read5(0x080E0000);

			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }


			 		 	                       cuma_pompa1=read5[16];
			 		 	                       cuma_pompa2=read5[17];
			 		 	                       cuma_pompa3=read5[18];
			 		 	                       cuma_pompa4=read5[19];
		 		 	                           Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken13==0)
			{
				 data5=Flash_Read5(0x080E0000);
				 for(int i=0;i<29;i++)
				 											 							 	{
				 											 							 	veri5[i]=data5[i];
				 											 							 	}



			if(cuma_pompa1==0 ){
				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa1=1;veri5[16]=cuma_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken13=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }

			}
			if(cuma_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa1=0;veri5[16]=cuma_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken13=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken13==1)
				{

				if(cuma_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa2=1;veri5[17]=cuma_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken13=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken13=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(cuma_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa2=0;veri5[17]=cuma_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken13=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken13=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																								 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								 					 	 Ayar_Gun();
																								 					                                          }
							}


				}



	if(degisken13==2)
					{

					if(cuma_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa3=1;veri5[18]=cuma_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken13=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken13=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																						 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 					 	 Ayar_Gun();
																						 					                                          }
					}
					if(cuma_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa3=0;veri5[18]=cuma_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken13=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken13=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken13==3)
						{

						if(cuma_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa4=1;veri5[19]=cuma_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken13=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken13=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(cuma_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cuma_pompa4=0;veri5[19]=cuma_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken13=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken13=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }
void cumartesi(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN
	 data5=Flash_Read5(0x080E0000);
			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }


			 		 	                      cumartesi_pompa1=read5[20];
			 		 	                      cumartesi_pompa2=read5[21];
			 		 	                      cumartesi_pompa3=read5[22];
			 		 	                      cumartesi_pompa4=read5[23];
		 		 	                           Flash_Write5(0x080E0000,read5,30);



while(1){
	if(degisken14==0)
			{
				 data5=Flash_Read5(0x080E0000);
				 for(int i=0;i<29;i++)
				 											 							 	{
				 											 							 	veri5[i]=data5[i];
				 											 							 	}



			if(cumartesi_pompa1==0 ){
				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa1=1;veri5[20]=cumartesi_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken14=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }

			}
			if(cumartesi_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa1=0;veri5[20]=cumartesi_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken14=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken14==1)
				{

				if(cumartesi_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa2=1;veri5[21]=cumartesi_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken14=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken14=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(cumartesi_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa2=0;veri5[21]=cumartesi_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken14=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken14=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}

							}

				 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
														 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 					 	 Ayar_Gun();
														 					                                          }
				}



	if(degisken14==2)
					{

					if(cumartesi_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa3=1;veri5[22]=cumartesi_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken14=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken14=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																																	 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																																	 					 	 Ayar_Gun();
																																	 					                                          }													 }

					}
					if(cumartesi_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa3=0;veri5[22]=cumartesi_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken14=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken14=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken14==3)
						{

						if(cumartesi_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa4=1;veri5[23]=cumartesi_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken14=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken14=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(cumartesi_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){cumartesi_pompa4=0;veri5[23]=cumartesi_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken14=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken14=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }
void pazar(){
// BURAYA SETLEYİP SIFIR YAPMAMIZ GEREK PAZARTESİ POMPA 1 DEĞERİ İÇİN

		                                      data5=Flash_Read5(0x080E0000);
			 		 	                         for(int i=0;i<30;i++){

			 		 	    	 								 		  read5[i]=data5[i];
			 		 	    	 								 	   }

			 		 	                       pazar_pompa1=read5[24];
     			 		 	                       pazar_pompa2=read5[25];
     			 		 	                       pazar_pompa3=read5[26];
     			 		 	                       pazar_pompa4=read5[27];

		 		 	                           Flash_Write5(0x080E0000,read5,30);




while(1){
	if(degisken15==0)
			{
				 data5=Flash_Read5(0x080E0000);
				 for(int i=0;i<29;i++)
				 											 							 	{
				 											 							 	veri5[i]=data5[i];
				 											 							 	}



			if(pazar_pompa1==0 ){
				LCD_Send_String_On_Line1(">>Pmp1 Pasif");
				LCD_Send_String_On_Line2("Pmp2");



										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa1=1;veri5[24]=pazar_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

										 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
											 degisken15=1;
											 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

										 }
										 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																				 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																				 					 	 Ayar_Gun();
																				 					                                          }

			}
			if(pazar_pompa1==1 ){
							LCD_Send_String_On_Line1(">>Pmp1 Aktif");
							LCD_Send_String_On_Line2("Pmp2");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa1=0;veri5[24]=pazar_pompa1;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken15=1;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

													 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}


			}

	if(degisken15==1)
				{

				if(pazar_pompa2==0 ){
					LCD_Send_String_On_Line1("Pmp1");
					LCD_Send_String_On_Line2(">>Pmp2 Pasif");



											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa2=1;veri5[25]=pazar_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
												 degisken15=2;
												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
											 }
											 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																						 degisken15=1;
																						 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 }
											 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																					 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																					 					 	 Ayar_Gun();
																					 					                                          }
				}
				if(pazar_pompa2==1 ){
								LCD_Send_String_On_Line1("Pmp1");
								LCD_Send_String_On_Line2(">>Pmp2 Aktif");



														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa2=0;veri5[25]=pazar_pompa2;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
															 degisken15=2;
															 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
														 }
														 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
															 degisken15=0;
															LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							}
														 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																								 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								 					 	 Ayar_Gun();
																								 					                                          }
							}


				}



	if(degisken15==2)
					{

					if(pazar_pompa3==0 ){
						LCD_Send_String_On_Line1(">>Pmp3 Pasif");
						LCD_Send_String_On_Line2("Pmp4 ");



												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa3=1;veri5[26]=pazar_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
													 degisken15=3;
													 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
												 }
												 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
													 degisken15=1;
																							 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 }
												 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																						 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																						 					 	 Ayar_Gun();
																						 					                                          }
					}
					if(pazar_pompa3==1 ){
									LCD_Send_String_On_Line1(">>Pmp3 Aktif");
									LCD_Send_String_On_Line2("Pmp4");



															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa3=0;veri5[26]=pazar_pompa3;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																 degisken15=3;
																 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
															 }
															 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																 degisken15=1;
																LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																								}
															 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																									 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									 					 	 Ayar_Gun();
																									 					                                          }
								}


					}
	if(degisken15==3)
						{

						if(pazar_pompa4==0 ){
							LCD_Send_String_On_Line1("Pmp3");
							LCD_Send_String_On_Line2(">>Pmp4 Pasif ");



													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa4=1;veri5[27]=pazar_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
														 degisken15=0;
														 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
													 }
													 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
														 degisken15=2;
																								 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 }
													 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																							 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																							 					 	 Ayar_Gun();
																							 					                                          }
						}
						if(pazar_pompa4==1 ){
										LCD_Send_String_On_Line1("Pmp3");
										LCD_Send_String_On_Line2(">>Pmp4 Aktif");



																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==1){pazar_pompa4=0;veri5[27]=pazar_pompa4;Flash_Write5(0x080E0000,veri5,28);LCD_Send_Cmd(LCD_CLEAR_DISPLAY);}

																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){
																	 degisken15=0;
																	 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																 }
																 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){
																	 degisken15=2;
																	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																									}
																 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
																										 					 	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
																										 					 	 Ayar_Gun();
																										 					                                          }
									}


						}


}
 }


void saat_ayarlar(){
	char snum[50];
	DS1302_Init();



	     while(1){
	    	 if(degisken16==0)
	    	 {
	    	 LCD_Send_String_On_Line1(">>Saat");
	    	 LCD_Send_String_On_Line2("Dakika");



	    	 					itoa((saat), snum, 10);
	    	 					HD44780_SetCursor(11,0);
	    	 					HD44780_PrintStr(snum);

	    	 					itoa((dakika), snum, 10);
	    	 						 HD44780_SetCursor(11,1);
	    	 						HD44780_PrintStr(snum);


	    	 						if((saat==10) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);saat=saat-1;}
	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1  && saat <24)
	    	 						{
	    	 							saat=saat+1;
	    	 						}
	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && saat>0 )
	    	 						 {
	    	 							saat=saat-1;
	    	 						 }
	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){

                                                         	 degisken16=1;
	    	 												 LCD_Send_Cmd(LCD_CLEAR_DISPLAY);

	    	 											 }
	    	 						 if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	    	 							         DS1302_Init();
	    	 								     setTimer.day=gun;
	    	 								     setTimer.isHourClock24=TRUE;
	    	 								     setTimer.isAm=FALSE;
	    	 								     setTimer.hour=saat;
	    	 								     setTimer.min=dakika;
	    	 								     setTimer.sec=0;
	    	 								      DS1302_SetTime_Struct(&setTimer);

	    	 																		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 																		 Genel_Ekran_Ayar();
	    	 																	  }
	    	 }

	    	 if(degisken16==1)
	    	 	    	 {
	    	 	    	 LCD_Send_String_On_Line1("Saat");
	    	 	    	 LCD_Send_String_On_Line2(">>Dakika");



	    	 	    	 					itoa((saat), snum, 10);
	    	 	    	 					HD44780_SetCursor(11,0);
	    	 	    	 					HD44780_PrintStr(snum);

	    	 	    	 					itoa((dakika), snum, 10);
	    	 	    	 						 HD44780_SetCursor(11,1);
	    	 	    	 						HD44780_PrintStr(snum);

	    	 	    	 						if((dakika==10) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);dakika=dakika-1;}
	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1  && dakika<60)
	    	 	    	 						{
	    	 	    	 							dakika=dakika+1;
	    	 	    	 						}
	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && dakika>0 )
	    	 	    	 						 {
	    	 	    	 							dakika=dakika-1;
	    	 	    	 						 }
	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){

	    	 	    	 						                                                degisken16=2;
	    	 	    	 							    	 									LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 							    	 								 }
	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){

	    	 	    	 													 					degisken16=0;
	    	 	    	 													 					LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 													 			   }
	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	    	 	    	 						  DS1302_Init();
	    	 	    	 							    	 								     setTimer.day=gun;
	    	 	    	 							    	 								     setTimer.isHourClock24=TRUE;
	    	 	    	 							    	 								     setTimer.isAm=FALSE;
	    	 	    	 							    	 								     setTimer.hour=saat;
	    	 	    	 							    	 								     setTimer.min=dakika;
	    	 	    	 							    	 								     setTimer.sec=0;
	    	 	    	 							    	 								      DS1302_SetTime_Struct(&setTimer);

	    	 	    	 							    	 																		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 							    	 																		 Genel_Ekran_Ayar();
	    	 	    	 							    	 																	  }
	    	 	    	 }
	    	 if(degisken16==2)
	    	 	    	 	    	 {
	    	 	    	 	    	 LCD_Send_String_On_Line1("Dakika");
	    	 	    	 	    	 LCD_Send_String_On_Line2(">>Gun");



	    	 	    	 	    	 					itoa((dakika), snum, 10);
	    	 	    	 	    	 					HD44780_SetCursor(11,0);
	    	 	    	 	    	 					HD44780_PrintStr(snum);

	    	 	    	 	    	 					itoa((gun), snum, 10);
	    	 	    	 	    	 						 HD44780_SetCursor(11,1);
	    	 	    	 	    	 						HD44780_PrintStr(snum);

	    	 	    	 	    	 						if((gun==10) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);gun=gun-1;}
	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1  && gun<7)
	    	 	    	 	    	 						{
	    	 	    	 	    	 							gun=gun+1;
	    	 	    	 	    	 						}
	    	 	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && gun>0 )
	    	 	    	 	    	 						 {
	    	 	    	 	    	 							gun=gun-1;
	    	 	    	 	    	 						 }
	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){

	    	 	    	 	    	 						                                                degisken16=0;
	    	 	    	 	    	 							    	 									LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 							    	 								 }
	    	 	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){

	    	 	    	 	    	 													 					degisken16=3;
	    	 	    	 	    	 													 					LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 													 			   }
	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	    	 	    	 	    	 						  DS1302_Init();
	    	 	    	 	    	 							    	 								     setTimer.day=gun;
	    	 	    	 	    	 							    	 								     setTimer.isHourClock24=TRUE;
	    	 	    	 	    	 							    	 								     setTimer.isAm=FALSE;
	    	 	    	 	    	 							    	 								     setTimer.hour=saat;
	    	 	    	 	    	 							    	 								     setTimer.min=dakika;
	    	 	    	 	    	 							    	 								     setTimer.sec=0;
	    	 	    	 	    	 							    	 								     DS1302_SetTime_Struct(&setTimer);

	    	 	    	 	    	 							    	 																		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 							    	 																		 Genel_Ekran_Ayar();
	    	 	    	 	    	 							    	 																	  }
	    	 	    	 	    	 }
	    	 if(degisken16==3)
	    	 	    	 	    	 	    	 {
	    	 	    	 	    	 	    	 LCD_Send_String_On_Line1(">>Dakika");
	    	 	    	 	    	 	    	 LCD_Send_String_On_Line2("Gun");



	    	 	    	 	    	 	    	 					itoa((dakika), snum, 10);
	    	 	    	 	    	 	    	 					HD44780_SetCursor(11,0);
	    	 	    	 	    	 	    	 					HD44780_PrintStr(snum);

	    	 	    	 	    	 	    	itoa((gun), snum, 10);
	    	 	    	 	    	 	    	 				    HD44780_SetCursor(11,1);
	    	 	    	 	    	 	    	 					HD44780_PrintStr(snum);

	    	 	    	 	    	 	    	 						if((dakika==10) &&  HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 ){LCD_Send_Cmd(LCD_CLEAR_DISPLAY);dakika=dakika-1;}
	    	 	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)==1  && dakika<60)
	    	 	    	 	    	 	    	 						{
	    	 	    	 	    	 	    	 						dakika=dakika+1;
	    	 	    	 	    	 	    	 						}
	    	 	    	 	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)==1 && dakika>0 )
	    	 	    	 	    	 	    	 						 {
	    	 	    	 	    	 	    	 							dakika=dakika-1;
	    	 	    	 	    	 	    	 						 }
	    	 	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==1){

	    	 	    	 	    	 	    	 						                                                degisken16=2;
	    	 	    	 	    	 	    	 							    	 									LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 	    	 							    	 								 }
	    	 	    	 	    	 	    	 						 if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1){

	    	 	    	 	    	 	    	 													 					degisken16=1;
	    	 	    	 	    	 	    	 													 					LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 	    	 													 			   }
	    	 	    	 	    	 	    	 						if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==1){
	    	 	    	 	    	 	    	 						  DS1302_Init();
	    	 	    	 	    	 	    	 							    	 								     setTimer.day=gun;
	    	 	    	 	    	 	    	 							    	 								     setTimer.isHourClock24=TRUE;
	    	 	    	 	    	 	    	 							    	 								     setTimer.isAm=FALSE;
	    	 	    	 	    	 	    	 							    	 								     setTimer.hour=saat;
	    	 	    	 	    	 	    	 							    	 								     setTimer.min=dakika;
	    	 	    	 	    	 	    	 							    	 								     setTimer.sec=0;
	    	 	    	 	    	 	    	 							    	 								      DS1302_SetTime_Struct(&setTimer);

	    	 	    	 	    	 	    	 							    	 																		LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	    	 	    	 	    	 	    	 							    	 																		 Genel_Ekran_Ayar();
	    	 	    	 	    	 	    	 							    	 																	  }
	    	 	    	 	    	 	    	 }
	     }

}


















void Flash_Write(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){

	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_5, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);


	}



	HAL_FLASH_Lock();


}
void Flash_Write2(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){


	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_6, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);


	}



	HAL_FLASH_Lock();


}
void Flash_Write3(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){

	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_7, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);


	}



	HAL_FLASH_Lock();


}
void Flash_Write4(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){

	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_8, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);


	}



	HAL_FLASH_Lock();


}
void Flash_Write5(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){

	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_11, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);
		HAL_Delay(10);


	}



	HAL_FLASH_Lock();


}
void Flash_Write6(uint32_t Flash_Address, uint32_t *Flash_Data,uint8_t leng){

	HAL_FLASH_Unlock();
	FLASH_Erase_Sector(FLASH_SECTOR_4, VOLTAGE_RANGE_3);

	for(int i=0;i<leng;i++){
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Flash_Address+(4*i),Flash_Data[i]);


	}



	HAL_FLASH_Lock();


}
uint32_t *Flash_Read(uint32_t Flash_Address){


	for(int i=0;i<6;i++){

		flash_datas[i]=Flash_Address+(4*i);
	}


return *flash_datas;



}
uint32_t *Flash_Read2(uint32_t Flash_Address){


	for(int i=0;i<6;i++){

		flash_datas[i]=Flash_Address+(4*i);
	}


return *flash_datas;



}
uint32_t *Flash_Read3(uint32_t Flash_Address){


	for(int i=0;i<6;i++){

		flash_datas[i]=Flash_Address+(4*i);
	}


return *flash_datas;



}
uint32_t *Flash_Read4(uint32_t Flash_Address){


	for(int i=0;i<6;i++){

		flash_datas[i]=Flash_Address+(4*i);
	}

	return *flash_datas;
}

uint32_t *Flash_Read5(uint32_t Flash_Address){


		for(int i=0;i<29;i++){

			flash_datas[i]=Flash_Address+(4*i);
		}



return *flash_datas;




}
