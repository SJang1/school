#include <mega128.h>
#include <delay.h>

unsigned char fnd[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xD8,
                        0X80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
int i;

void increment()		   	// 증가 카운트 함수
{
	for(i=0;i<16;i++)		// 0~15까지 카운트 증가
	{
		PORTC = fnd[i];	// FND 배열을 PORTC에 출력
		delay_ms(1000);	// 1초 딜레이
	}
}

void decrement()			// 감소 카운트 함수
{
	for(i=15;i>=0;i--)		// 15~0까지 카운트 감소
	{
		PORTC = fnd[i];	// FND 배열을 PORTC에 출력
		delay_ms(1000);	// 1초 딜레이
	}
}

void even()				// 짝수 카운트 함수
{
	for(i=0;i<16;i=i+2)		// 0~15까지 짝수 카운트
	{
		PORTC = fnd[i];	// FND 배열을 PORTC에 출력
		delay_ms(1000);	// 1초 딜레이
    	}
}

void odd()				// 홀수 카운트 함수
{
    	for(i=1;i<17;i=i+2)		// 1~16까지 홀수 카운트
    	{
		PORTC = fnd[i];	// FND 배열을 PORTC에 출력
		delay_ms(1000);	// 1초 딜레이
    	}
}

void main(void)
{
	DDRB=0x00;			// PORTB INPUT 설정
	PORTB=0x00;			// PORTB 초기화
	DDRC=0xFF;			// PORTC OUTPUT 설정
	PORTC=0x00;			// PORTC 초기화
	DDRD=0xFF;			// PORTD OUTPUT 설정
	PORTD=0x0F;			// PORTD 초기화
	PORTC = fnd[0];		// FND에 ‘0’ 출력

	while (1)
      	{
         if(PINB.0 == 0)       increment(); 	// 스위치 0을 누르면 증가                                                      
         else if(PINB.1 == 0)  decrement();  // 스위치 1을 누르면 감소                                                        
         else if(PINB.2 == 0)  even();  // 스위치 2을 누르면 짝수 함수                                                  
         else if(PINB.3 == 0)  odd();	// 스위치 3을 누르면 홀수 함수                                                  
         else
             PORTC = fnd[0];		// 아무것도 누르지 않으면 ‘0’                                                 
      	}
}
