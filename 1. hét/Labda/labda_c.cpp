#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>

class Field {

public:
    
    const int MAX_X_COORDINATE = 160;
    const int MAX_Y_COORDINATE = 48;

};

class Ball {

public: 

    int x_jobbra = 0;
    int x_kozep = 0;

    int y_jobbra = 0;
    int y_kozep = 0;

};

int jobbra(int xyj, int mxy);
int kozep(int xyk, int mxy);
int setLabdaCoordinate(int yxj, int mxy, int yxk);


int main(void) {

    WINDOW *ablak;
    ablak = initscr();
    noecho();
    cbreak();
    nodelay(ablak, true);

    Field _field;
    Ball _ball;

    for(;;) {

        _ball.x_jobbra = jobbra(_ball.x_jobbra, _field.MAX_X_COORDINATE);     
        _ball.x_kozep = kozep(_ball.x_kozep, _field.MAX_X_COORDINATE);

        _ball.y_jobbra = jobbra(_ball.y_jobbra, _field.MAX_Y_COORDINATE);
        _ball.y_kozep = kozep(_ball.y_kozep, _field.MAX_Y_COORDINATE);
        
        clear();

        mvprintw(0,0,"--------------------------------------------------------------------------------");
        mvprintw(24,0,"--------------------------------------------------------------------------------");

        mvprintw(setLabdaCoordinate(_ball.y_jobbra, _field.MAX_Y_COORDINATE, _ball.y_kozep),
                 setLabdaCoordinate(_ball.x_jobbra, _field.MAX_X_COORDINATE, _ball.x_kozep), "O");

        refresh();
        usleep(150000);
    }

    return 0;
    
}

int jobbra(int xyj, int mxy) {
    
    return ((xyj - 1) % mxy);

}

int kozep(int xyk, int mxy) {

    return ((xyk + 1) % mxy);

}

int setLabdaCoordinate(int yxj, int mxy, int yxk) {
    return (abs (yxj + (mxy - yxk)) / 2 );

}

