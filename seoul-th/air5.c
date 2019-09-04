#include <mega128.h>
#include <delay.h>

#define SW1     	PINA.0     	// 시작 스위치(a접점, ++)
#define LS1     	PINA.1     	// 후진 감지용 리미트 스위치
#define LS2     	PINA.2     	// 전진 감지용 리미트 스위치

#define SOL1    	PORTC.0     	// 솔레노이드 1번
#define SOL2    	PORTC.1     	// 솔레노이드 2번



unsigned char temp[] =
           {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90};

void main(void)
{
	int i=0;
	DDRA=0x00;          	// PORTA INPUT 설정
	PORTA=0x00;         	// PORTA 초기화       
    
	DDRB=0xFF;          	// PORTB OUTPUT 설정
	PORTB=0x01;         	// PORTB 초기화

	DDRC=0xFF;          	// PORTC OUTPUT 설정
	PORTC=0xFD;         	// PORTC 초기화
    
	DDRD=0xFF;          	// PORTD OUTPUT 설정
	PORTD=0x00;         	// PORTD 초기화
    
    	PORTD = temp[0];     	// FND에 0표시
    
	while(1)
	{
		i = 0;
		while(SW1);
		do{
			while(LS1);     	// 피스톤 전진 감지
         //[주] ;이 없어도 No error이나 장비가 동작 안됨
			SOL1 = 0;       	// 피스톤 전진
			SOL2 = 1;
                        delay_ms(1000);
        
			while(LS2);     	// 피스톤 후진 감지
			SOL1 = 1;       	// 피스톤 후진
			SOL2 = 0; 
                        delay_ms(1000);

			i++;
			PORTD = temp[i];	// FND에 구동횟수 표시
		}while(i!=9);     		// 9회가 되면 멈춤
	}
}
