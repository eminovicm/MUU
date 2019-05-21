#include <at89c51rc2.h>    
#include <pin_disp.h>
#include <intrins.h>
#include <string.h>    
#define duzina 9

unsigned char data brojStotinki=0;
int brojSekundi=0;
unsigned char data brojPrekida=0;

char * ispravan_string = ">OK<";    
char * nije_ispravan_string = ">ERR<";
char str_unos[duzina];
char * pok_ispis;
int duzina_unosa=0;
int brojac_unos =0;

char* ispis_taster;
char* ispis_timer = "SEC:00";
char ispis_sec [5];
unsigned char promena = 0;        //1->javila se promena
unsigned char greska = 0;

unsigned char promena_0 = 0;    //0->nista; 1-> za ovu lampicu se javila promena 
unsigned char promena_1 = 0;
unsigned char promena_2 = 0;
unsigned char promena_3 = 0;
unsigned char promena_4 = 0;
unsigned char promena_5 = 0;
unsigned char promena_6 = 0;
unsigned char promena_7 = 0;    

unsigned char uklj_isklj0 = 0;    //0->upali; 1-> ugasi 
unsigned char uklj_isklj1 = 0;
unsigned char uklj_isklj2 = 0;
unsigned char uklj_isklj3 = 0;
unsigned char uklj_isklj4 = 0;
unsigned char uklj_isklj5 = 0;
unsigned char uklj_isklj6 = 0;
unsigned char uklj_isklj7 = 0;

unsigned char zapamti_stanje_0 = 1;    //0->upaljena ; 1-> ugasena; pamti stanje lapice
unsigned char zapamti_stanje_1 = 1;
unsigned char zapamti_stanje_2 = 1;
unsigned char zapamti_stanje_3 = 1;
unsigned char zapamti_stanje_4 = 1;
unsigned char zapamti_stanje_5 = 1;
unsigned char zapamti_stanje_6 = 1;
unsigned char zapamti_stanje_7 = 1;

//Funkcije
void inicijalizacija();    
void disp_cmd(unsigned char, unsigned char, unsigned char, unsigned char);
void init_disp();
void disp_char(char);
void disp_str(char *str);
void disp_clear();
void disp_newline();
void num2str(int broj, char* ispis_sec);
void reverse(char* string);
int sizeStr(char *str);
void delay_microsecond(void);
void delay_milisecond(void);

void main(void)
{
    inicijalizacija();
    init_disp();
    disp_str(ispis_timer);
        
    while(1){
//POLOCICA
        if (P0_0 == 0 && zapamti_stanje_0==0) //dugme 0
        {
            zapamti_stanje_0 = 1;
            P2_0=~P2_0;
            ispis_taster = "M0;OFF";
            promena = 1;
        }
        else if (P0_0 == 0 && zapamti_stanje_0==1){
            zapamti_stanje_0 = 0;
            P2_0=~P2_0;
            ispis_taster = "M0;ON";
            promena = 1;
        }
        if (P0_1 == 0 && zapamti_stanje_1==0)    //dugme 1
        {
            zapamti_stanje_1 = 1;
            P2_1=~P2_1;
            ispis_taster = "M1;OFF";
            promena = 1;
        }
        else if (P0_1 == 0 && zapamti_stanje_1==1){
            zapamti_stanje_1 = 0;
            P2_1=~P2_1;
            ispis_taster = "M1;ON";
            promena = 1;
        }
        if (P0_2 == 0 && zapamti_stanje_2==0)    //dugme 2
        {
             zapamti_stanje_2 = 1;
            P2_2=~P2_2;
            ispis_taster = "M2;OFF";
            promena = 1;
        }
        else if (P0_2 == 0 && zapamti_stanje_2==1){
             zapamti_stanje_2 = 0;
            P2_2=~P2_2;
            ispis_taster = "M2;ON";
            promena = 1;
        }
        if (P0_3 == 0 && zapamti_stanje_3==0) //dugme 3
        {
             zapamti_stanje_3 = 1;
            P2_3=~P2_3;
            ispis_taster = "M3;OFF";
            promena = 1;
        }
        else if (P0_3 == 0 && zapamti_stanje_3==1){
             zapamti_stanje_3 = 0;
            P2_3=~P2_3;
            ispis_taster = "M3;ON";
            promena = 1;
        }
        if (P0_4 == 0 && zapamti_stanje_4==0)    // dugme 4
        {
             zapamti_stanje_4 = 1;
            P2_4=~P2_4;
            ispis_taster = "M4;OFF";
            promena = 1;
        }
        else if (P0_4 == 0 && zapamti_stanje_4==1){
             zapamti_stanje_4 = 0;
            P2_4=~P2_4;
            ispis_taster = "M4;ON";
            promena = 1;
        }
        if (P0_5 == 0 && zapamti_stanje_5==0)     //dugme 5
        {
             zapamti_stanje_5 = 1;
            P2_5=~P2_5;
            ispis_taster = "M5;OFF";
            promena = 1;
        }
        else if (P0_5 == 0 && zapamti_stanje_5==1){
             zapamti_stanje_5 = 0;
            P2_5=~P2_5;
            ispis_taster = "M5;ON";
            promena = 1;
        }
        if (P0_6 == 0 && zapamti_stanje_6==0)    //dugme 6
        {
             zapamti_stanje_6 = 1;
            P2_6=~P2_6;
            ispis_taster = "M6;OFF";
            promena = 1;
        }
        else if (P0_6 == 0 && zapamti_stanje_6==1){
             zapamti_stanje_6 = 0;
            P2_6=~P2_6;
            ispis_taster = "M6;ON";
            promena = 1;
        }
        if (P0_7 == 0 && zapamti_stanje_7==0) //dugme 7
        {
             zapamti_stanje_7 = 1;
            P2_7=~P2_7;
            ispis_taster = "M7;OFF";
            promena = 1;
        }
        else if (P0_7 == 0 && zapamti_stanje_7==1){
             zapamti_stanje_7 = 0;
            P2_7=~P2_7;
            ispis_taster = "M7;ON";
            promena = 1;
        }

//PLOCICA KRAJ

//Serijska komunikacija        
        if (promena_0 == 1)    //Za lampicu 0 se javila promena
        {
            if (uklj_isklj0 == 0 && zapamti_stanje_0 ==  1 )    //Treba da se upali a ugasena je
            {
                P2_0=~P2_0;    //pali se lampica
                promena_0 = 0;    //gasi se zapamti_stanje_ pojavljivanja promene
                zapamti_stanje_0 = 0;    //pamti da je lampica upaljena
                ispis_taster = "M0;ON";
                promena = 1;
            }
            else if( uklj_isklj0 == 1 && zapamti_stanje_0 == 0)    //treba da se ugasi a upaljena je
            {
                P2_0=~P2_0;    
                promena_0 = 0;
                zapamti_stanje_0 = 1;
                ispis_taster = "M0;OFF";
                promena = 1;
            }
            //U ostalim slucajevima je naredba da se ukljuci (iskljuci) vec ukljucena (iskljucena) lampica
        }
        //lampica 1
        if (promena_1 == 1){
            if (uklj_isklj1 == 0 && zapamti_stanje_1 ==  1 ){
                P2_1=~P2_1;    
                promena_1 = 0;
                zapamti_stanje_1 = 0;
                ispis_taster = "M1;ON";
                promena = 1;
            }
            else if( uklj_isklj1 == 1 && zapamti_stanje_1 == 0){
                P2_1=~P2_1;    
                promena_1 = 0;
                zapamti_stanje_1 = 1;
                ispis_taster = "M1;OFF";
                promena = 1;
            }
        }
        //lampica 2
        if (promena_2 == 1)    {
            if (uklj_isklj2 == 0 && zapamti_stanje_2 ==  1 ){
                P2_2=~P2_2;    
                promena_2 = 0;
                zapamti_stanje_2 = 0;
                ispis_taster = "M2;ON";
                promena = 1;
            }
            else if( uklj_isklj2 == 1 && zapamti_stanje_2 == 0){
                P2_2=~P2_2;    
                promena_2 = 0;
                zapamti_stanje_2 = 1;
                ispis_taster = "M2;OFF";
                promena = 1;
            }
        }
        //lampica 3
        if (promena_3 == 1)    {
            if (uklj_isklj3 == 0 && zapamti_stanje_3 ==  1 ){
                P2_3=~P2_3;    
                promena_3 = 0;
                zapamti_stanje_3 = 0;
                ispis_taster = "M3;ON";
                promena = 1;
            }
            else if( uklj_isklj3 == 1 && zapamti_stanje_3 == 0){
                P2_3=~P2_3;    
                promena_3 = 0;
                zapamti_stanje_3 = 1;
                ispis_taster = "M3;OFF";
                promena = 1;
            }
        }
        //lampica 4
        if (promena_4 == 1){
            if (uklj_isklj4 == 0 && zapamti_stanje_4 ==  1 ){
                P2_4=~P2_4;    
                promena_4 = 0;
                zapamti_stanje_4 = 0;
                ispis_taster = "M4;ON";
                promena = 1;
            }
            else if( uklj_isklj4 == 1 && zapamti_stanje_4 == 0){
                P2_4=~P2_4;    
                promena_4 = 0;
                zapamti_stanje_4 = 1;
                ispis_taster = "M4;OFF";
                promena = 1;
            }
        }
        //lampica 5
        if (promena_5 == 1)    {
            if (uklj_isklj5 == 0 && zapamti_stanje_5 ==  1 ){
                P2_5=~P2_5;    
                promena_5 = 0;
                zapamti_stanje_5 = 0;
                ispis_taster = "M5;ON";
                promena = 1;
            }
            else if( uklj_isklj5 == 1 && zapamti_stanje_5 == 0)    {
                P2_5=~P2_5;    
                promena_5 = 0;
                zapamti_stanje_5 = 1;
                ispis_taster = "M5;OFF";
                promena = 1;
            }
        }
        //lampica 6
        if (promena_6 == 1)    {
            if (uklj_isklj6 == 0 && zapamti_stanje_6 ==  1 ){
                P2_6=~P2_6;    
                promena_6 = 0;
                zapamti_stanje_6 = 0;
                ispis_taster = "M6;ON";
                promena = 1;
            }
            else if( uklj_isklj6 == 1 && zapamti_stanje_6 == 0)    {
                P2_6=~P2_6;    
                promena_6 = 0;
                zapamti_stanje_6 = 1;
                ispis_taster = "M6;OFF";
                promena = 1;
            }
        }
        //lampica 7
        if (promena_7 == 1)    {
            if (uklj_isklj7 == 0 && zapamti_stanje_7 ==  1 ){
                P2_7=~P2_7;    
                promena_7 = 0;
                zapamti_stanje_7 = 0;
                ispis_taster = "M7;ON";
                promena = 1;
            }
            else if( uklj_isklj7 == 1 && zapamti_stanje_7 == 0)    {
                P2_7=~P2_7;    
                promena_7 = 0;
                zapamti_stanje_7 = 1;
                ispis_taster = "M7;OFF";
                promena = 1;
            }
        }
//Displej
        if (promena == 1){
            disp_clear();
            promena = 0;
            ispis_timer = "SEC:";
            disp_str(ispis_timer);
            num2str(brojSekundi, ispis_sec); 
            disp_str(ispis_sec);
            disp_newline();
            disp_str(ispis_taster);
        }
    }
}

void int_ser(void) interrupt 4
{
    if(RI) //Recieve interapt
    {
         RI=0;
        duzina_unosa++;
        greska = 0;
        str_unos[brojac_unos] = SBUF;
        brojac_unos=(brojac_unos+1)%duzina;

        if( SBUF == 0x3C ) //Ako je unet karakter '<'
        {     
             if(duzina_unosa < 7 || duzina_unosa > 8)     //Provera da li je dobar unos
                greska = 1;                 
            else if(str_unos[0] != 0x3E)    //<
                 greska = 1;                  
            else if(str_unos[1] != 0x4D)    //M
                 greska = 1; 
            else if (str_unos[2] < 0x30)    //manje od 0
                greska = 1;
            else if (str_unos[2] > 0x37)    //vece od 7
                greska = 1;
            else if (str_unos[3] != 0x3B)    //;
                 greska = 1;
            else if (str_unos[4] != 0x4F)    //O
                 greska = 1;
            else if (duzina_unosa == 7 && str_unos[5] != 0x4E)    //N
                 greska = 1;
            else if (duzina_unosa == 8 && str_unos[5] != 0x46)    //F
                 greska = 1;
            else if (duzina_unosa == 8 && str_unos[6] != 0x46)
                 greska = 1;
//Provera sta treba da se ispise     
            if (greska == 1)    //Ako nije dobar unos salje se error message
            {
                duzina_unosa = 0;
                brojac_unos=0;
                greska = 0;
                pok_ispis = nije_ispravan_string;
                SBUF = *pok_ispis;      //iniciranje slanja
            }
            else{                //Ako je dobar unos, salje se ok message
                duzina_unosa = 0;
                brojac_unos=0;
                pok_ispis = ispravan_string;
                SBUF = *pok_ispis;
//Pamti sta treba da uradi ako je dobar unos
                if (str_unos[2] == 0x30 )    //lampica 0
                {
                    if (str_unos[5] == 0x4E)    //N
                    {
                        promena_0 = 1;    //javila se promena
                        uklj_isklj0 = 0;    //treba da se upali
                    }
                    else{
                         promena_0 = 1;
                        uklj_isklj0 = 1;    //treba da se ugasi
                    }
                }                
                if (str_unos[2] == 0x31 )    //lampica 1
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_1 = 1;    
                        uklj_isklj1 = 0;    
                    }
                    else{
                         promena_1 = 1;
                        uklj_isklj1 = 1;    
                    }
                }            
                if (str_unos[2] == 0x32 )    //lampica 2
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_2 = 1;    
                        uklj_isklj2 = 0;    
                    }
                    else{
                         promena_2 = 1;
                        uklj_isklj2 = 1;    
                    }
                }
                
                if (str_unos[2] == 0x33 )    //lampica 3
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_3 = 1;    
                        uklj_isklj3 = 0;    
                    }
                    else{
                         promena_3 = 1;
                        uklj_isklj3 = 1;    
                    }
                }
                
                if (str_unos[2] == 0x34 )    //lampica 4
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_4 = 1;    
                        uklj_isklj4 = 0;    
                    }
                    else{
                         promena_4 = 1;
                        uklj_isklj4 = 1;    
                    }
                }
                
                if (str_unos[2] == 0x35 )    //lampica 5
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_5 = 1;    
                        uklj_isklj5 = 0;    
                    }
                    else{
                         promena_5 = 1;
                        uklj_isklj5 = 1;    
                    }
                }
                if (str_unos[2] == 0x36 )    //lampica 6
                {
                    if (str_unos[5] == 0x4E)    
                    {
                        promena_6 = 1;    
                        uklj_isklj6 = 0;    
                    }
                    else{
                         promena_6 = 1;
                        uklj_isklj6 = 1;    
                    }
                }    
                if (str_unos[2] == 0x37 )    //lampica 7
                {
                    if (str_unos[5] == 0x4E)
                    {
                        promena_7 = 1;    
                        uklj_isklj7 = 0;    
                    }
                    else{
                         promena_7 = 1;
                        uklj_isklj7 = 1;    
                    }
                }    
            }
        }        
    }
    if(TI){
         TI=0;
        if(*(++pok_ispis)!= '\0'){
            SBUF = *pok_ispis;
        }
    }    
}

void inicijalizacija()
{
    P2=0x00;
     CKCON0|=0x01;
    PCON &=0x7F;
    BDRCON |= 0x1C;
    SM0=0;
    SM1=1;
    BRL= 250;
    REN=1;
    ES=1;
    EA=0;//UKIDANJE GLOBALNE DOZVOLA PREKIDA
    TL0=56;//VRIJEDNOST ZA PRVO BROJANJE TAJMERA
    TH0=56;//RELOAD VRIJEDNOST
    TMOD=0x02;//GATE0=0(bit 3), C/T0=0 (bit 2), mod 2(biti 0-1)
    TR0=1;//DOZVOLA RADA TAJMERA 0
    ET0=1;//DOZVOLA PREKIDA TAJMERA 0
    EA=1;//GLOBALNA DOZVOLA PREKIDA
}

void disp_cmd(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4)
{
    LCD_RS = 0;
    LCD_EN = 1;
    LCD_D7 = b1;
    LCD_D6 = b2;
    LCD_D5 = b3;
    LCD_D4 = b4;
    LCD_EN = 0;
    _nop_();    
}

void init_disp()
{
    // P1 = 0xE0;
    // P3 = 0xF9;
    LCD_BL = 0;   
	delay_milisecond();
	disp_cmd(0,0,1,1);
	disp_cmd(0,0,1,1);
	delay_milisecond();
	disp_cmd(0,0,1,1);
	delay_microsecond();
	disp_cmd(0,0,1,0);
	disp_cmd(0,0,1,0);
	disp_cmd(1,0,0,0);
	delay_microsecond();
	disp_cmd(0,0,0,0);
	disp_cmd(1,1,1,1);
	delay_microsecond();
	disp_cmd(0,0,0,0);
	disp_cmd(0,0,0,1);
	delay_microsecond();
	disp_cmd(0,0,0,0);
	disp_cmd(0,1,1,0);
	delay_milisecond();	 
	LCD_BL = 1;
}

 void delay_milisecond(void){ 
	int i, j;
	for(i = 0; i < 250; i++){	 	
		for(j = 0; j < 200; j++){  		
		}
	}	
}

void delay_microsecond(void){  
	int i;
	for(i = 0; i < 100; i++){  	
	}	   
}

void disp_char(char ch)
{
        LCD_RS = 1;
        LCD_EN = 1;
        LCD_D7 = ch&(0x01<<7);
        LCD_D6 = ch&(0x01<<6);
        LCD_D5 = ch&(0x01<<5);
        LCD_D4 = ch&(0x01<<4);
        LCD_EN = 0;
        _nop_();
        LCD_EN = 1;
        LCD_D7 = ch&(0x01<<3);
        LCD_D6 = ch&(0x01<<2);
        LCD_D5 = ch&(0x01<<1);
        LCD_D4 = ch&(0x01<<0);
        LCD_EN = 0;
        _nop_();
        delay_milisecond();
}

void disp_str(char* str)
{
    char* str1 = str;
    while(*(str1)){    
        disp_char(*(str1++));
        delay_milisecond();
    }
}

void disp_clear()
{
     disp_cmd(0,0,0,0);
    disp_cmd(0,0,0,1);
    delay_milisecond();
}

void disp_newline()
{
    disp_cmd(1,1,0,0);
    disp_cmd(0,0,0,0);
}

void Tajmer0 (void) interrupt 1 using 0 {
    if (++brojPrekida == 100) { // odbrojao 100*100us=10ms
        brojPrekida=0;//resetuje se brojac prekida
        if(++brojStotinki == 100) {//odbrojao sekundu
            brojStotinki=0;//postavlja se na 0 odbrojanih stotinki tekuce sekunde
            ++brojSekundi;
        }
    }
}

void num2str(int broj, char* ispis_sec)
{
    int temp, i=0;
    do{
        temp = broj % 10;
        broj = broj / 10;
        ispis_sec[i] = temp + '0';
        i++;
    }while (broj != 0);
    ispis_sec[i]='\0';
    reverse(ispis_sec);
}

void reverse(char* string)
{
    char temp;
    int size = sizeStr(string) - 1;
    int i, k;
    for(i = 0, k = size; i < size; i++, k--){
        temp = string[k];
        string[k] = string[i];
        string[i] = temp;
        if(k == (size / 2))    break;
    }
    return;
}

int sizeStr(char *str)
{
    int offset = 0;
    int size = 0;
    while (*(str + offset) != '\0'){
        ++size;
        ++offset;
    }
    return size;
}
