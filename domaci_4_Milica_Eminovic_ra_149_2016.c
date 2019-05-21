#include <at89c51rc2.h>

unsigned char pret_za_ivicu0,pret_za_ivicu1,pret_za_ivicu2,pret_za_ivicu3,pret_za_ivicu4,pret_za_ivicu5,pret_za_ivicu6,pret_za_ivicu7=1;
unsigned char tren_za_ivicu0,tren_za_ivicu1,tren_za_ivicu2,tren_za_ivicu3,tren_za_ivicu4,tren_za_ivicu5,tren_za_ivicu6,tren_za_ivicu7=1; 
unsigned char pret_za_deb0,pret_za_deb1,pret_za_deb2,pret_za_deb3,pret_za_deb4,pret_za_deb5,pret_za_deb6,pret_za_deb7=1;
unsigned char broj0 = 0, broj1 =0, broj2 = 0, broj3 = 0, broj4 = 0, broj5=0, broj6=0, broj7=0 ;
unsigned char pwm = 0;
unsigned char brojac0 = 21, brojac1 =21, brojac2 = 21, brojac3 = 21, brojac4 = 21, brojac5=21, brojac6=21, brojac7=21;
unsigned char br0, br1 , br2, br3, br4, br5, br6, br7  = 0;


void otklanjanje0 (void) {

	 if (pret_za_deb0==P0_0) {
	 
	   if (++broj0>100) {
	   
	   	  tren_za_ivicu0=pret_za_deb0;
	   }
	}
	  else {					   
		  
		   broj0=0;			  
	  }
	 pret_za_deb0= P0_0;
}

void otklanjanje1 (void) {

	 if (pret_za_deb1==P0_1) {
	 
	   if (++broj1>100) {
	   
	   	  tren_za_ivicu1=pret_za_deb1;
	   }
	}
	  else {					   
		  
		   broj1=0;			 
	  }
	 

	 pret_za_deb1= P0_1;
}
void otklanjanje2 (void) {

	 if (pret_za_deb2==P0_2) {
	 
	   if (++broj2>100) {
	   
	   	  tren_za_ivicu2=pret_za_deb2;
	   }
	}
	  else {					  
		  
		   broj2=0;			  
	  }
	 

	 pret_za_deb2= P0_2;
}
 void otklanjanje3 (void) {

	 if (pret_za_deb3==P0_3) {
	 
	   if (++broj3>100) {
	   
	   	  tren_za_ivicu3=pret_za_deb3;
	   }
	}
	  else {					   
		  
		   broj3=0;			  
	  }
	 

	 pret_za_deb3= P0_3;
}
void otklanjanje4 (void) {

	 if (pret_za_deb4==P0_4) {
	 
	   if (++broj4>100) {
	   
	   	  tren_za_ivicu4=pret_za_deb4;
	   }
	}
	  else {				
		  
		   broj4=0;			  
	  }
	 

	 pret_za_deb4= P0_4;
}
void otklanjanje5 (void) {

	 if (pret_za_deb5==P0_5) {
	 
	   if (++broj5>100) {
	   
	   	  tren_za_ivicu5=pret_za_deb5;
	   }
	}
	  else {					   
		  
		   broj5=0;			  	  
	  }
	 

	 pret_za_deb5= P0_5;
}
void otklanjanje6 (void) {

	 if (pret_za_deb6==P0_6) {
	 
	   if (++broj6>100) {
	   
	   	  tren_za_ivicu6=pret_za_deb6;
	   }
	}
	  else {					   
		  
		   broj6=0;			  
	  }
	 

	 pret_za_deb6= P0_6;
}
void otklanjanje7 (void) {

	 if (pret_za_deb7==P0_7) {
	 
	   if (++broj7>100) {
	   
	   	  tren_za_ivicu7=pret_za_deb7;
	   }
	}
	  else {					   
		  
		   broj7=0;			  
	  }
	 

	 pret_za_deb7= P0_7;
}
	
void InteraptT0 (void) interrupt 1 {
	 
	   ++br0;
	   ++br1; 
	   ++br2;
	   ++br3;
	   ++br4;
	   ++br5;
	   ++br6;
	   ++br7;

	if(++pwm>=20){
		br0 = 0;
		br1 = 0;
		br2 = 0;
		br3 = 0;
		br4 = 0;
		br5 = 0;
		br6 = 0;
		br7 = 0;
		pwm = 0;
		P0 = 0xff;
		otklanjanje0();
		otklanjanje1();
		otklanjanje2();
		otklanjanje3();
		otklanjanje4();
		otklanjanje5();
		otklanjanje6();
		otklanjanje7();
  }

    if(br0>brojac0) 
			P0_0 = 0;					
	     else 
			otklanjanje0();			   
     if(br1>brojac1)
			P0_1 = 0;				
	     else 
			otklanjanje2();			
	 if(br2>brojac2) 
			P0_2 = 0;			
	     else  
			otklanjanje3();
	 if(br3>brojac3) 
		    P0_3 = 0;				
	     else  
			otklanjanje3();	
	 if(br4>brojac4) 
				P0_4 = 0;			
	     else  
		    otklanjanje4();
	 if(br5>brojac5)
				P0_5 = 0;			
	       else 
		    otklanjanje5();
	 if(br6>brojac6)
	     		P0_6 = 0;			
	       else 
			otklanjanje6();
	 if(br7>brojac7) 
				P0_7 = 0;			
	       else 
			otklanjanje7();

 }
void main (void) {		   

   TMOD=0x02;
   TH0=26;
   TL0=26;
   TR0=1;
   ET0=1;
   EA=1;

   P2=0;   


   while (1)  {	

  
     if(pret_za_ivicu0!=tren_za_ivicu0)	  {
  
		if (pret_za_ivicu0==1 && tren_za_ivicu0==0)  {
		
		  	P2_0=~P2_0;
			if (brojac0 == 21){
						brojac0 = 2;
					}else{
						brojac0 = 21;
					}
            }
		    pret_za_ivicu0=tren_za_ivicu0;
	 	
		}
	if(pret_za_ivicu1!=tren_za_ivicu1)	  {
 			if (pret_za_ivicu1==1 && tren_za_ivicu1==0)  {
		
		  	P2_1=~P2_1;
				if (brojac1 == 21){
						brojac1 = 2;
					}else{
						brojac1 = 21;
					}
            }
				 pret_za_ivicu1=tren_za_ivicu1;
   }
   if(pret_za_ivicu2!=tren_za_ivicu2)	  {
		if (pret_za_ivicu2==1 && tren_za_ivicu2==0) {
		
		  	P2_2=~P2_2;
			if (brojac2 == 21){
						brojac2 = 2;
					}else{
						brojac2 = 21;
					}
            }
			pret_za_ivicu2=tren_za_ivicu2;
		}
	if(pret_za_ivicu3!=tren_za_ivicu3)	  {
			if (pret_za_ivicu3==1 && tren_za_ivicu3==0)  {
		
		  	P2_3=~P2_3;
			if (brojac3 == 21){
				brojac3 = 2;
					}else{
						brojac3 = 21;
					}
            }
			pret_za_ivicu3=tren_za_ivicu3;
		}
	 if(pret_za_ivicu4!=tren_za_ivicu4)	  {
			if (pret_za_ivicu0==4 && tren_za_ivicu4==0) {
		
		  	P2_4=~P2_4;
			if (brojac4 == 21){
				brojac4 = 2;
					}else{
						brojac4 = 21;
					}
            }
		    pret_za_ivicu4=tren_za_ivicu4;
		}
  if(pret_za_ivicu5!=tren_za_ivicu5)	  {
	 	if (pret_za_ivicu5==1 && tren_za_ivicu5==0)  {
		
		  	P2_5=~P2_5;	
		if (brojac5 == 21){
				brojac5 = 2;
					}else{
						brojac5 = 21;
					}
            }
		    pret_za_ivicu5=tren_za_ivicu5;	
		}

   if(pret_za_ivicu6!=tren_za_ivicu6)	  {
	 	if (pret_za_ivicu6==1 && tren_za_ivicu6==0){
		
		  	P2_6=~P2_6;
			if (brojac6 == 21){
				brojac6 = 2;
					}else{
						brojac6 = 21;
					}
            }
		pret_za_ivicu6=tren_za_ivicu6;
	}
  if(pret_za_ivicu7!=tren_za_ivicu7)	  {
			if (pret_za_ivicu7==1 && tren_za_ivicu7==0) {		
		  	P2_7=~P2_7;
			if (brojac7 == 21){
				brojac7 = 2;
					}else{
						brojac7 = 21;
					}
            }
	pret_za_ivicu7=tren_za_ivicu7;	
	
     }

   }	 
 
 }
 
