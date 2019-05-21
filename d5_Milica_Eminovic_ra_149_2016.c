#include<at89c51rc2.h>

#define duzina 9 //(max 8 +1)

char str_unos[duzina];
char * poruka_OK= ">OK<";
char * poruka_ERR= ">ERR<";


int duzina_unosa=0;
int brojac_unos=0;

 char *p_ispis;

unsigned char greska=0;

 unsigned char promena_0=0;			 // nema promene stanja->0, promena->1
 unsigned char promena_1=0;
 unsigned char promena_2=0;
 unsigned char promena_3=0;
 unsigned char promena_4=0;
 unsigned char promena_5=0;
 unsigned char promena_6=0;
 unsigned char promena_7=0;


 unsigned char 	uklj_isklj_0=0;		  // 1->iskljuci, 0->ukljuci
 unsigned char 	uklj_isklj_1=0;
 unsigned char 	uklj_isklj_2=0;
 unsigned char 	uklj_isklj_3=0;
 unsigned char 	uklj_isklj_4=0;
 unsigned char 	uklj_isklj_5=0;
 unsigned char 	uklj_isklj_6=0;
 unsigned char 	uklj_isklj_7=0;

 unsigned char zapamti_0=1;	  			// zapamti stanje lampice, 1-> iskljucena, 0->ukljucena
 unsigned char zapamti_1=1;	
 unsigned char zapamti_2=1;	
 unsigned char zapamti_3=1;	
 unsigned char zapamti_4=1;
 unsigned char zapamti_5=1;
 unsigned char zapamti_6=1;	
 unsigned char zapamti_7=1;
 




void init();

void main(void){

  init();

  while(1)
  {
		if(promena_0==1)    //promena stanja lampice 0
		 {
		 	if(uklj_isklj_0==0 && zapamti_0==1)	  //iskljucena-> ukljucuje se
			 {
			 	P2_0=~P2_0;  //	   lampica sija
				promena_0=0;  // iskljucuje se promena
				zapamti_0=0;	  // zapamti stanje lampice 
			  }
			 else if(uklj_isklj_0=1 && zapamti_1==0) //ukljucena->iskljucuje se
			  {
			  	P2_0=~P2_0;
				promena_0=0;
				zapamti_0=1;
			  }
			 }
		 

		if (promena_1==1)
		{
			if(uklj_isklj_1==0 && zapamti_1==1)
			{
				 P2_1=~P2_1;
				 promena_1=0;
				 zapamti_1=0;
			 }
		    else if(uklj_isklj_1==1 && zapamti_1==0)
			{
				 P2_1=~P2_1;
				 promena_1=0;
				 zapamti_1=1;
			}
			
	      }

		if (promena_2==1)
		{
			if(uklj_isklj_2==0 && zapamti_2==1)
			{
				 P2_2=~P2_2;
				 promena_2=0;
				 zapamti_2=0;
			}
		    else if(uklj_isklj_2==1 && zapamti_2==0)
			{
				 P2_2=~P2_2;
				 promena_2=0;
				 zapamti_2=1;
			}
			
	      }


		if (promena_3==1)
		{
			if(uklj_isklj_3==0 && zapamti_3==1)
			{
				 P2_3=~P2_3;
				 promena_3=0;
				 zapamti_3=0;
			}
		    else if(uklj_isklj_3==1 && zapamti_3==0)
			{
				 P2_3=~P2_3;
				 promena_3=0;
				 zapamti_3=1;
			}
		
	      }

		if (promena_4==1)
		{
			if(uklj_isklj_4==0 && zapamti_4==1)
			{
				 P2_4=~P2_4;
				 promena_4=0;
				 zapamti_4=0;
			 }
		    else if(uklj_isklj_4==1 && zapamti_4==0)
			{
				 P2_4=~P2_4;
				 promena_4=0;
				 zapamti_4=1;
			}
			
	      }

		if (promena_5==1)
		{
			if(uklj_isklj_5==0 && zapamti_5==1)
			{
				 P2_5=~P2_5;
				 promena_5=0;
				 zapamti_5=0;
			 }
		    else if(uklj_isklj_5==1 && zapamti_5==0)
			{
				 P2_5=~P2_5;
				 promena_5=0;
				 zapamti_5=1;
			
			}
	      }

		 if (promena_6==1)
		{
			if(uklj_isklj_6==0 && zapamti_6==1)
			{
				 P2_6=~P2_6;
				 promena_6=0;
				 zapamti_6=0;
			}
		    else if(uklj_isklj_6==1 && zapamti_6==0)
			{
				 P2_6=~P2_6;
				 promena_6=0;
				 zapamti_6=1;
			}
			
	      }

		 if (promena_7==1)
		{
			if(uklj_isklj_7==0 && zapamti_7==1)
			{
				 P2_7=~P2_7;
				 promena_7=0;
				 zapamti_7=0;
			 }
		    else if(uklj_isklj_7==1 && zapamti_7==0)
			{
				 P2_7=~P2_7;
				 promena_7=0;
				 zapamti_7=1;
			}
			
	      }
    }
}

  void int_serijske(void)interrupt 4{
    if(RI)
	 {
		RI=0;
		duzina_unosa++;
		greska=0;

		str_unos[brojac_unos]=SBUF;
		brojac_unos=(brojac_unos+1)%duzina;

		if(SBUF== 0X3C)						  // ako je unet '<'
		{
			if(duzina_unosa< 7 || duzina_unosa>8)  //  da li je dobra duzina, 7(on) ili  8(off) 
			{
			 	greska=1;   // ako je uneto manje od 7, a vise od 8 karaktera
			}

			else if(str_unos[0] != 0x3E)  // ako prvi znak nije '<'
			{
			    greska=1;
			}

			else if(str_unos[1] != 0x4D) 	// ako drugi znak nije 'M'
			{
				greska=1;
			}

			else if(str_unos[2]< 0x30)		// ako je manje od 0
			{ 
				greska=1;
			}
			else if(str_unos[2] > 0x37)		 // ako je vece od 7
			{
				greska=1;
			}

			else if(str_unos[3] != 0x3B) // ako je razicito od ';'
			{
				greska=1;
			}

			else if(str_unos[4] != 0x4F)	  //ako je razlicito od O
			{
				greska=1;
			}

			else if( duzina_unosa==7 && str_unos[5] != 0X4E) // ako je duzina unosa=7(on), a 6.karakter nije N
			{
				greska=1;
			}
			else if( duzina_unosa==8 && str_unos[5] != 0x46) // ako je duzina unosa=8(off), a 6.karakter nije F
			{ 
				greska=1;
			}

	    	else if( duzina_unosa==8 && str_unos[6] != 0x46) // ako je duzina unosa=8(off), a  7.karakter nije F
			{ 
				greska=1;
			}



				if(greska==1)			 // unos nije dobar->ERR
				{
				  duzina_unosa=0;
				  brojac_unos=0;
				  greska=0;
				  p_ispis=poruka_ERR;
				  SBUF=*p_ispis;
				}
														 
				else{					  //unos je dobar -> OK
					duzina_unosa=0;
					brojac_unos=0;
					p_ispis=poruka_OK;
					SBUF=*p_ispis;


					if(str_unos[2] == 0x30)		 // lampica 0
					   {	
					   		if(str_unos[5]==0x4E)	 //6.karakter je N-> ON
							{
								promena_0=1;	 //promena stanja
								uklj_isklj_0=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_0=1;
								uklj_isklj_0=0;	// treba ukljuciti lampicu

							}
						}


					 if(str_unos[2] == 0x31)		 // lampica 1
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_1=1;	 //promena stanja
								uklj_isklj_1=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_1=1;
								uklj_isklj_1=0;	// treba ukljuciti lampicu

							}
						}


					if(str_unos[2] == 0x32)		 // lampica 2
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_2=1;	 //promena stanja
								uklj_isklj_2=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_2=1;
								uklj_isklj_2=0;	// treba ukljuciti lampicu

							}
						}


					if(str_unos[2] == 0x33)		 // lampica 3
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_3=1;	 //promena stanja
								uklj_isklj_3=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_3=1;
								uklj_isklj_3=0;	// treba ukljuciti lampicu

							}
						}

					if(str_unos[2] == 0x34)		 // lampica 4
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_4=1;	 //promena stanja
								uklj_isklj_4=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_4=1;
								uklj_isklj_4=0;	// treba ukljuciti lampicu

							}
						}



					 if(str_unos[2] == 0x35)		 // lampica 5
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_5=1;	 //promena stanja
								uklj_isklj_5=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_5=1;
								uklj_isklj_5=0;	// treba ukljuciti lampicu

							}
						}
						
					 if(str_unos[2] == 0x36)		 // lampica 6
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_6=1;	 //promena stanja
								uklj_isklj_6=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_6=1;
								uklj_isklj_6=0;	// treba ukljuciti lampicu

							}
						}
						
					 if(str_unos[2] == 0x37)		 // lampica 7
					   {	
					   		if(str_unos[5]==0x46)	 //6.karakter je F-> OFF
							{
								promena_7=1;	 //promena stanja
								uklj_isklj_7=1;	 // treba iskljuciti lampicu
							}
							else				  // 6.karakter je N->ON
							{
								promena_7=1;
								uklj_isklj_7=0;	// treba ukljuciti lampicu

							}
						}			
  			}
 		 }
      }


	   if(TI)
	   {
	   		TI=0;

			if(*(++p_ispis)!= '\0')
			{	
				SBUF=*(p_ispis);
			}
		}

  }

  
void init(){	
	P2=0x00;
 	CKCON0|=0x01;
	PCON &=0x7F;
	BDRCON |= 0x1C;
	SM0=0;
	SM1=1;
	BRL= 250;
	REN=1;
	ES=1;
	EA=1;
}
