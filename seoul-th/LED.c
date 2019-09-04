#include <mega128.h>
#include <delay.h>

unsigned char fnd[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8, 0X80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

int i;

void increment()
{
   for(i=0;i<16;i++)
   {
         PORTC = fnd[i];
         delay_ms(1000);
         
   }
}

void decrement()
{
   for(i=15;i>=0;i--)
   {
       PORTC = fnd[i];
       delay_ms(1000);
       
   }
}

void even()
{
     for(i=0;i<16;i=i+2)
     {
           PORTC = fnd[i];
           delay_ms(1000);
           }
}

void odd()
{
      for(i=1;i<17;i=i+2)
      {
      PORTC = fnd[i];
      delay_ms(1000);
      }
}

void main(void)
{
   DDRB=0x00;
   PORTB=0x00;
   DDRC=0xFF;
   PORTC=0x00;
   DDRD=0xFF;
   PORTD=0x0F;
   PORTC=fnd[0];
   
   while (1)
       {
       if(PINB.0 == 0)    increment();
       
       else if(PINB.1 == 0)  decrement();
       
       else if(PINB.2 == 0)  even();
       
       else if(PINB.3 == 0) odd();
       
       else
         PORTC = fnd[0];
         
       }    
       }                           
