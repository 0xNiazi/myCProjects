#include <ncurses.h>

void CreateBox(int startX,int startY,int len,int width,char * Message){
	WINDOW *textWin;
	textWin=newwin(len,width,startX,startY);
	box(textWin,0,0);
	mvwprintw(textWin,2,2,Message);
	wrefresh(textWin);
	delwin(textWin);
}

int main(){
	initscr();
	int x=10,y=10;
	int length=LINES,width=COLS;
	box(stdscr,0,0);
	mvprintw(x,y,"Hello Project");

	refresh();
	CreateBox(length/2-5,width/2-5,x,y*2,"THIS IS THE SAMPLE BOX");
	getch();
	endwin();
}
