#include <mega32.h>
#include <delay.h>
//#include <cstdio>
const short JUMLAHLAMPU = 4;
short lampuSebelumnya[JUMLAHLAMPU] = {0,0,0,0};

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
void otomatis(void);
void manual(void);

void lampu1(int status) {
     switch (status) {
        case 0:
            PORTC.0 = 1;   
            PORTC.1 = 0;
            PORTC.2 = 0;
            lampuSebelumnya[0] = 0;
        break;
        
        case 1:
            PORTC.0 = 0;   
            PORTC.1 = 1;
            PORTC.2 = 0;
        break;
        
        case 2:
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

void ganti() {
    int i, ketemu, ubah;
    for (i = 0; i < JUMLAHLAMPU; i++) {
        if (lampuSebelumnya[i] == 1) { 
            ketemu = 1;
            ubah = i;
            break;
        }
    }
    if (ketemu == 1) {
        switch (ubah) {
            case 0:
                lampu1(1);
                delay_ms(1000);
                lampu1(0);
            break;
            case 1:
                lampu2(1);
                delay_ms(1000);
                lampu2(0);
            break;
            case 2:
                lampu3(1);
                delay_ms(1000);
                lampu3(0);
            break;
            case 3:
                lampu4(1);
                delay_ms(1000);
                lampu4(0);
            break;
        }
    }   
}
void main(void) {
    int mode = 0;
    init();
    
    while (1) {
        if (mode == 0) {
            otomatis();
        }
        else if (mode == 1) {
            manual();
        }
       
        mode = (mode == 1) ? 0 : 1; 
        
    }    
}

void manual(void)
{
    PORTD.7 = 1;
    PORTD.6 = 0;
    lampu1(0);
    lampu2(0);
    lampu3(0);
    lampu4(0);
    while (1)
          {
          // Place your code here
          if ((PINA&0b00010000) == 0) {
            break;
          }
         
        
           else if((PINA&0b00000001)== 0) { 
            ganti();
            delay_ms(1000);
            lampu1(2);

          }
          
          else if((PINA&0b00000010)== 0) {
            ganti();
            delay_ms(1000);
            lampu2(2);
          } 
          
          else if((PINA&0b00000100)== 0) {
            ganti();
            delay_ms(1000);
            lampu3(2);
          }
          
          else if((PINA&0b00001000)== 0) {
            ganti();
            delay_ms(1000);
            lampu4(2);
          }
         /* else {
            PORTC.0 = 0;
          }*/ 
          
    } //while
}// main

void otomatis(void) {
    int bruh = 0;
    PORTD.7 = 0;
    PORTD.6 = 1;
    
    lampu1(0);
    lampu2(0);
    lampu3(0);
    lampu4(0);
    while (1) {
        if ((PINA&0b00010000) == 0) {
            bruh = -1;
            break;
        }
        else if (bruh == 0) {
            delay_ms(1000);
            lampu1(2);
            delay_ms(3000);
            lampu1(0);
            bruh++;
        }
        else if (bruh == 1) {
            delay_ms(1000);
            lampu2(2);
            delay_ms(3000);
            lampu2(0);
            bruh++;
        }
        else if (bruh == 2) {
            delay_ms(1000);
            lampu3(2);
            delay_ms(3000);
            lampu3(0);
            bruh++;
        }
        else if (bruh == 3) {
            delay_ms(1000);
            lampu4(2);
            delay_ms(3000);
            lampu4(0);
            bruh = 0;
        }
        
    }  
             
}
