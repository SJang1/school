#include <mega128.h>
#include <delay.h>

void main(void)
{
	DDRC=0xFF;	// PORTC OUTPUT 설정
	PORTC=0x00;	// PORTC 초기화

	DDRD=0xFF;	// PORTD OUTPUT 설정
	PORTD=0x08;	// PORTD 초기화

	while (1)
      	{
        	PORTC = 0xF9;		// 숫자 1
        	delay_ms(1000);		// 1초 딜레이
        
        	PORTC = 0x92;		// 숫자 5
        	delay_ms(1000);		// 1초 딜레이
        
        	PORTC = 0x90;		// 숫자 9
        	delay_ms(1000);		// 1초 딜레이
        
        	PORTC = 0x86;		// 숫자 E
        	delay_ms(1000);		// 1초 딜레이
      	}
}
