#include <math.h>

unsigned int str2num(char* String) 
{
	unsigned int i=0;
	unsigned int duzinaStr=0;
	unsigned char pomocniString[8];
	unsigned int stepenHex=0;
	unsigned int broj=0;
	unsigned int stepenBin=0;
	unsigned m=0;
	unsigned b=0;
	unsigned stepenDec=0;

	while(*String!='\0')
	{
		duzinaStr++;
		String++;
	}
	String=String-duzinaStr;

	if(String[0]=='H')
 	{
 		for(i=0;i<duzinaStr;i++)  
  		{
			pomocniString[i]=String[i+1];
		} 
		pomocniString[(duzinaStr-1)]='\0';

		stepenHex=duzinaStr-2;
  		
		for(i=0; pomocniString[i]!='\0'; i++)  
     	{
	          if(pomocniString[i]>='0' && pomocniString[i]<='9')
	          {	
		            m = pomocniString[i] - 48;
	          }
	         else if(pomocniString[i]>='A' && pomocniString[i]<='F')
	          {
	               m = pomocniString[i] - 65 + 10;
	          }
	         broj=broj + m * pow(16, stepenHex);
	         stepenHex--;
    	}
 	}


	else if(String[0]=='b')
	{
		for(i=0;i<duzinaStr;i++) 
  		{
			pomocniString[i]=String[i+1];
		} 
		pomocniString[(duzinaStr)]='\0';
		stepenBin=duzinaStr-2;
		for(i=0;i<(duzinaStr-1);i++)
  		{
			if(pomocniString[i]=='1')
   			{
     			b=b+pow(2,stepenBin);
			}
   		stepenBin--; 
  		}
  		broj=b;
  	}


 	else
 	{
		for(i=0;i<duzinaStr;i++) 
  		{
			pomocniString[i]=String[i];
		} 
  		for(i=0;i<duzinaStr;i++)
  		{
   			broj=broj+(pomocniString[i]-48)*pow(10,(duzinaStr-1-i));
  		}
 	}
return broj;
}

char* num2str(int broj)
{   
	unsigned int i=0;
	unsigned int j=0;
	unsigned int ostatak=0;
	char str[15];
	char pom[10];
	char* pom2=pom;	
	do{
		ostatak=broj%10;
		broj=(broj/10);
		*pom2=ostatak+48;
		pom2++;
		i++;
	}while(broj!=0);
		*pom2='\0';

	while(i>0)
	{
	pom2--;
	str[j]=*pom2;
	++j;
	--i;
	}
	str[j]='\0';
	return str;
				
}

void izracunaj(char* op1, char* op2,char* rez, char operant) 
{

	int prviBroj=0;
	int drugiBroj=0;
	int rezultat=0;
	unsigned int i=0;
	unsigned int j=0;
	

	prviBroj=str2num(op1);
	drugiBroj=str2num(op2);


	 switch (operant)
	 {
	  case '+':
	  		rezultat=prviBroj+drugiBroj;
	 		break;
	  case '/':
	  		rezultat=prviBroj/drugiBroj;
	  		break;
	  case '*':
	  		rezultat=prviBroj*drugiBroj;
	  		break;
	  default:
	  		break;
	 }
	rez=num2str(rezultat);
}


void main()
{
	unsigned char* a="H3";
	unsigned char* b="b101";
	unsigned char* rez1; 
	unsigned char* c="12";
	unsigned char* d="10";
	unsigned char* rez2;
	unsigned char* e="50";
	unsigned char* f="10";
	unsigned char* rez3;
/*	unsigned char* g="b011";
	unsigned char* h="b101";
	unsigned char* rez4;
	unsigned char* j="HA4";
	unsigned char* k="H4";
	unsigned char* rez5;
	unsigned char* l="HC5";
	unsigned char* z="H2A";
	unsigned char* rez6; */
/*	izracunaj(l,z,rez6,'/');
	izracunaj(j,k,rez5,'/');
	izracunaj(g,h,rez4,'+'); */
	izracunaj(a,b,rez1,'+');	
	izracunaj(c,d,rez2,'*');
	izracunaj(e,f,rez3,'/');

	/*unsigned char* l="HC5";
	unsigned char* z="H2A";
	unsigned char* rez6;
	izracunaj(l,z,rez6,'/');  */





}