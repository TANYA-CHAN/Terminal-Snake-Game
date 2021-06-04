#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>
#define WIDTH 50
#define HEIGHT 25

using namespace std;

//pos -> head
//len
//direction
//velocity -> speed -> no. of characters at a time or pixels at a time etc

class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char dir;
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel);
          void grow();
          void move_snake(); //move the snake in particular direction
        void change_dir(char dir); //change direction of snake

        vector<COORD> get_body();

           bool collided();
        bool eaten(COORD food);

        COORD get_pos();//get the current position of the snake

};

#endif
