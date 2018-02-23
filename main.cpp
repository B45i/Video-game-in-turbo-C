#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
	int gdriver = DETECT, gmode, error;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
	int x, y, dx = 5, dy = 5, r = 5;
	int fps = 5;
	int padW = 36;
	int padH = 10;

	int maxx = getmaxx();
	int maxy = getmaxy() - r;

	int padX = (getmaxx()/2) - (padW/2);
	int padY = getmaxy() - padH;

	x = maxx/2;
	y = maxy;
	circle(x, y, r);
	while(1) {
		cleardevice();
		printf("X: %d, Y:%d\n", x, y);

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
				padX -= 15;
			}
			else if(c == 'd') {
				padX += 15;
			}
		}

		delay(fps);
	}
	getch();
	return 0;
}