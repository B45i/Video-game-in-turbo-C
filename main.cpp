#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	int x, y, padX, padY, dx = 5, dy = 5, r = 6;
	int fps = 1;

	int padW = 40;
	int padH = 10;

	int moveX = padW/2;

	int maxx = getmaxx()+1; // 639+1 = 640
	int maxy = getmaxy(); // 479

	printf("\n\n max x: %d, max y: %d", maxx, maxy);

	padX = maxx/2 - (padW/2);
	padY = maxy - padH;

	x = maxx/2;
	y = maxy - padH - r;

	circle(x, y, r);
	rectangle(padX, padY, padX+padW, padY+padH);
	getch();
	while(1) {
		cleardevice();
		//printf("X: %d, Y:%d\n", x, y);

		circle(x, y, r);
		rectangle(padX, padY, padX+padW, padY+padH);

		if(x+dx>maxx || x+dx<0) {
			dx = -dx;
		}
		if(y+dy>maxy || y+dy<0) {
			dy = -dy;
		}
		x += dx;
		y += dy;

		if(kbhit()){
			char c = getch();
			if(c == 'a') {
				if(padX-moveX >= 0) {
					padX -= moveX;
				}
			}
			else if(c == 'd') {
				if(padX+moveX <= maxx-padW) {
					padX += moveX;
				}
			}
		}

		delay(fps);
	}
 	getch();
	return 0;
}

