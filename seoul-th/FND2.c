#include <mega128.h>
#include <delay.h>

// FND 0~F배열 정의
unsigned char fnd[]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,
			0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned int j = 0;

void Display()			// 숫자 표시 함수
{
    	unsigned int i;
    	unsigned char v3, v2, v1, v0;
    
    	v3 = j/1000;		// 1000의 자리수
    	i = j%1000;
    
    	v2 = i/100;		// 100의 자리수
    	i %= 100;
    
    	v1 = i/10;		// 10의 자리수
    
    	v0 = i%10;		// 1의 자리수
    
    	PORTD = 0x08;		// 1의 자리 FND ON
    	PORTC = fnd[v0];	// 1의 자리수 표시
    	delay_ms(1);
    
    	PORTD = 0x04;		// 10의 자리 FND ON
    	PORTC = fnd[v1];	// 10의 자리수 표시 
    	delay_ms(1);
    
    	PORTD = 0x02;		// 100의 자리 FND ON
    	PORTC = fnd[v2];	// 100의 자리수 표시 
    	delay_ms(1);
    
     	PORTD = 0x01;		// 1000의 자리 FND ON
    	PORTC = fnd[v3];	// 1000의 자리수 표시 
    	delay_ms(1);
}

void main(void)
{
	unsigned int flag = 0;	// 상태 저장 변수 선언 및 초기화

	DDRB=0x00;		// PORTB INPUT 설정
	PORTB=0x00;		// PORTB 초기화

	DDRC=0xFF;		// PORTC OUTPUT 설정
	PORTC=0x00;		// PORTC 초기화
	DDRD=0xFF;		// PORTD OUTPUT 설정
	PORTD=0x00;		// PORTD 초기화

	while (1)
    	{
		if((PINB.0) == 0)		// 시작 스위치=0번 스위치
			flag = 1;		// 상태 변수를 1로 변경
  
  else if((PINB.1) == 0)   	// 정지 스위치=1번 스위치
			flag = 0;		// 상태 변수를 0으로 변경
                
		else
			Display();
                
		if(flag == 1)		// 상태 변수가 1이면
		{
			Display();	// FND에 숫자를 표시

                      if(j >= 9999)
                      {
                          flag = 0; //j=0;를 아래줄에 삽입하면 9999후                                              Reset
                      }
                      else
                      {
			j++;		// 카운트를 시작한다.
		       }
               }
	}
}            
