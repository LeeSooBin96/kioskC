#include <stdio.h>
// #include <conio.h>
// #include <Windows.h>
#include <termios.h>
#include <unistd.h>
typedef struct 
{
	char take[3];
}Shoplist; //주문 내역

char getch(void);

int main(void)
{
	puts("더벤티에 오신 것을 환영합니다."); //환영 메시지
	puts("아무키나 입력해주세요>"); //아무키나 입력하세요
	// _getch();
	getch();
	// system("cls");
	system("clear");
	//매장? 포장
	puts("매장 이용은 1번, 포장은 2번을 입력해주세요>");
	
	return 0;
}
char getch(void)
{
    char c;
	struct termios term;
    
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // non-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
    while (read(0, &c, sizeof(c)) > 0)
        return c;
}