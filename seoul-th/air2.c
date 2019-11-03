#include <mega128.h>
#include <delay.h>

#define SW1     PINA.0    // 입력0 : 시작 스위치(a접점, ++)
#define SW2     PINA.1    // 입력1 : 정지 스위치(a접점, ++)
#define LS1     PINA.2  // 입력2 : 후진감지용 리미트 스위치(a접점, ++)
#define LS2     PINA.3  // 입력3 : 전진감지용 리미트 스위치(a접점, ++)

#define SOL1    PORTC.0     	// 출력0 : 전진 솔레노이드(+-)
#define SOL2    PORTC.1     	// 출력1 : 후진 솔레노이드(+-)


void main(void)
{
	DDRA=0x00;          	// PORTA INPUT 설정
	PORTA=0x00;         	// PORTA 초기화

	DDRC=0xFF;          	// PORTC OUTPUT 설정
	PORTC=0xFD;         	// PORTC 초기화
	while(1)
	{
		while(SW1);		// SW1이 눌려질 때까지 대기
  //[주] ;이 누락되면 메인 전원을 켜면 자동 왕복되며 정지SW도 안됨  
		do{
			while(LS1);    // 피스톤 후진 감지
			SOL1 = 0;     // 피스톤 전진
			SOL2 = 1;
			while(LS2);    // 피스톤 전진 감지
			SOL1 = 1;     // 피스톤 후진
			SOL2 = 0;
		}while(SW2);      	 // SW2가 눌려질 때까지 동작 반복
	}
}
