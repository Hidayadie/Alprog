#include <mega32.h>
#include <delay.h>
//#include <cstdio>
const short JUMLAHLAMPU = 4;
short lampuSebelumnya[JUMLAHLAMPU] = {0,0,0,0};

// FUNGSI INISIALISASI
void init(void) {
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
}

// KONSTRUKTOR
void otomatis(void);
void manual(void);

// FUNGSI" LAMPU
void lampu1(int status) {
     switch (status) {             // KODE STATUS 
        case 0:                    // MERAH
            PORTC.0 = 1;            
            PORTC.1 = 0;           
            PORTC.2 = 0;           
            lampuSebelumnya[0] = 0;
        break;
        
        case 1:                    // KUNING
            PORTC.0 = 0;   
            PORTC.1 = 1;
            PORTC.2 = 0;
        break;
        
        case 2:                    // HIJAU
            PORTC.0 = 0;   
            PORTC.1 = 0;
            PORTC.2 = 1;
            lampuSebelumnya[0] = 1;
        break;
    }
}

void lampu2(int status) {
    switch (status) {
        case 0:
            PORTC.3 = 1;   
            PORTC.4 = 0;
            PORTC.5 = 0;
            lampuSebelumnya[1] = 0;
        break;
        
        case 1:
            PORTC.3 = 0;   
            PORTC.4 = 1;
            PORTC.5 = 0;
        break;
        
        case 2:
            PORTC.3 = 0;   
            PORTC.4 = 0;
            PORTC.5 = 1;
            lampuSebelumnya[1] = 1;
        break;
    }
}

void lampu3(int status) {
    switch (status) {
        case 0:
            PORTD.0 = 1;   
            PORTD.1 = 0;
            PORTD.2 = 0;
            lampuSebelumnya[2] = 0;
        break;
        
        case 1:
            PORTD.0 = 0;   
            PORTD.1 = 1;
            PORTD.2 = 0;
        break;
        
        case 2:
            PORTD.0 = 0;   
            PORTD.1 = 0;
            PORTD.2 = 1;
            lampuSebelumnya[2] = 1;
        break;
    }
}

void lampu4(int status) {
    switch (status) {
        case 0:
            PORTD.3 = 1;   
            PORTD.4 = 0;
            PORTD.5 = 0;
            lampuSebelumnya[3] = 0;
        break;
        
        case 1:
            PORTD.3 = 0;   
            PORTD.4 = 1;
            PORTD.5 = 0;
        break;
        
        case 2:
            PORTD.3 = 0;   
            PORTD.4 = 0;
            PORTD.5 = 1;
            lampuSebelumnya[3] = 1;
        break;
    }
}


// FUNGSI GANTI WARNA BIAR JADI KUNING
void ganti() {
    int i, ketemu, ubah;
    for (i = 0; i < JUMLAHLAMPU; i++) { /* NGECEK 1 PER 1 */
        if (lampuSebelumnya[i] == 1) {  // KALO KETEMU...
            ketemu = 1;                 // kondisi ketemu menjadi 1 = true
            ubah = i;                   // dan nilai iterator disimpan
            break;                      // keluar dari loop for, jadi kalo
        }                               // ketemu langsung berhenti loop for
    }
    if (ketemu == 1) {                  // KALAU TADI ADA (TRUE)
        switch (ubah) {                 // cek lampu mana yang diubah
            case 0:                     /* LAMPU 1 */
                lampu1(1);              // lampu 1 -> kuning
                delay_ms(1000);         // delay 1 detik
                lampu1(0);              // lampu 1 -> merah
            break;
            case 1:                     /* LAMPU 2 */ 
                lampu2(1);              // lampu 2 -> kuning
                delay_ms(1000);         // delay 1 detik
                lampu2(0);              // lampu 2 -> merah
            break;
            case 2:                     /* LAMPU 3 */
                lampu3(1);              // lampu 3 -> kuning
                delay_ms(1000);         // delay 1 detik
                lampu3(0);              // lampu 3 -> merah
            break;
            case 3:                     /* LAMPU 4 */
                lampu4(1);              // lampu 4 -> kuning
                delay_ms(1000);         // delay 1 detik
                lampu4(0);              // lampu 4 -> merah
            break;
        }
    }   
}
/*
void tutt(void) {
    PORTC.7 = 0;
    delay_ms(500);
    PORTC.7 = 1;
    delay_ms(500);
    PORTC.7 = 0;
}
*/


        /****************/
        /*  KODE UTAMA  */
        /****************/


void main(void) {
    int mode = 0;                   /* START MODE: OTOMATIS */
    init();                         // jalanin kode inisialisasi 1x
    
    while (1) {                     // looping utama
        if (mode == 0) {            // cek mode lampu, jika 0
            otomatis();             // jalanin mode otomatis
        }
        else if (mode == 1) {       // cek mode lampu, jika 1
            manual();               // kalanin mode manual
        }
       
        mode = (mode == 1) ? 0 : 1; // cek, apakah mode isi nilainya 1... 
                                    // jika iya isinya 1,   ganti 0
    }                               // jika isinya bukan 1, ganti 1
}

void manual(void)
{
    PORTD.7 = 1;             // hidupin lampu mode manual   
    
    lampu1(0);               // semua lampu bewarna merah
    lampu2(0);
    lampu3(0);
    lampu4(0);
    while (1)                // looping utama
          {
          // Place your code here
          if ((PINA&0b00010000) == 0) {     /* TOMBOL MODE */
            //tutt();
            break;                          // keluar dari looping while
            
          }
         
        
           else if((PINA&0b00000001)== 0) { /* TOMBOL 1 */ 
            ganti();                        // ganti warna lampu sebelumnya
            delay_ms(1000);                 // delay 1 detik
            lampu1(2);                      // lampu 1 -> hijau

          }
          
          else if((PINA&0b00000010)== 0) {  /* TOMBOL 2 */
            ganti();                        // ganti warna lampu sebelumnya
            delay_ms(1000);                 // delay 1 detik
            lampu2(2);                      // lampu 2 -> hijau
          } 
          
          else if((PINA&0b00000100)== 0) {  /* TOMBOL 3 */
            ganti();                        // ganti warna lampu sebelumnya
            delay_ms(1000);                 // delay 1 detik
            lampu3(2);                      // lampu 3 -> hijau
          }
          
          else if((PINA&0b00001000)== 0) {  /* TOMBOL 4 */
            ganti();                        // ganti warna lampu sebelumnya
            delay_ms(1000);                 // delay 1 detik
            lampu4(2);                      // lampu 4 -> hijau
          }
          
    } //while 
    
    PORTD.7 = 0;             // Matikan lampu mode Manual
    delay_ms(2000);          // delay 2 detik
}// main

        /*********************/
        /*  FUNGSI OTOMATIS  */
        /*********************/

void otomatis(void) {
    int bruh = 0;               // :v tanya sendiri
    PORTD.6 = 1;                // hidupin lampu mode
    
    lampu1(0);                  // semua lampu merah
    lampu2(0);
    lampu3(0);
    lampu4(0);
    while (1) {                 // loop utama
        if ((PINA&0b00010000) == 0) { /* TOMBOL MODE */
            bruh = -1;                // rusak urutan nyala lampu, lalu
            //tutt();                 // keluar dari loop harus nunggu 
            break;                    // delay dibawahnya selesai
        }
        else if (bruh == 0) {         /* URUTAN PERTAMA */
            delay_ms(1000);           // delay 1 detik
            lampu1(2);                // lampu 1 -> hijau
            delay_ms(3000);           // delay 3 detik
            lampu1(0);                // lampu 1 -> merah
            bruh++;                   // urutan + 1
        }
        else if (bruh == 1) {         /* URUTAN KEDUA */
            delay_ms(1000);           // delay 1 deti
            lampu2(2);                // lampu 2 -> hijau
            delay_ms(3000);           // delay 3 detik
            lampu2(0);                // lampu 2 -> merah
            bruh++;                   // urutan + 1
        }
        else if (bruh == 2) {         /* URUTAN KETIGA */
            delay_ms(1000);           // delay 1 deti
            lampu3(2);                // lampu 3 -> hijau
            delay_ms(3000);           // delay 3 detik
            lampu3(0);                // lampu 3 -> merah
            bruh++;                   // urutan + 1
        }
        else if (bruh == 3) {         /* URUTAN KEEMPAT */
            delay_ms(1000);           // delay 1 deti
            lampu4(2);                // lampu 4 -> hijau
            delay_ms(3000);           // delay 3 detik
            lampu4(0);                // lampu 4 -> merah
            bruh = 0;                 // urutan reset mulai dari awal
        }
        
    }
    
    PORTD.6 = 0;             // matikan lampu mode Otomatis
    delay_ms(2000);          // delay 2 detik 
             
}
