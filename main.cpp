#include <iostream>
#include <conio.h>
#include <ctime>

//#include<cstdlib>
#include "Snake.h"
//for random func
#include<windows.h>
#include "Food.h"
//128
//macros =  one liner codes
//int sq(int x) { return x*x; }
//#define sq(x) x*x
//HEIGHT = i = how deep we are on the board = y axis
//WIDTH = j = x axis on a computer board
//initially 10,10 point
//snake moves faster in the vertical direction than the horizontal direction due to the property of console use a graphics lib to get rid of this

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

int score = 0;

//struct COORD (int X, Y);

//int x = 10, y = 10;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos =  food.get_pos();

    vector<COORD> snake_body = snake.get_body();

    cout << "SCORE : " << score << "\n\n";

    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j =0; j < WIDTH-2; j ++)
        {
            if(i == 0 || i == HEIGHT-1) cout << '#';
            else if(i == snake_pos.Y && j+1 == snake_pos.X) cout << '0';
            else if(i == food_pos.Y && j+1 == food_pos.X) cout << '@';
            else
            {
                bool isBodyPart = false;
                for(int k=0; k<snake_body.size()-1; k++)
                {
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart) cout << ' ';

            }
        }
        cout << "#\n";
    }
}

int main()
{
    score = 0;
    srand(time(NULL));

    food.gen_food();

    char game_over = false;
    while(!game_over)
    {
        board();

        if(kbhit())
        {
            switch(getch())
            {
                case 'w': snake.change_dir('u');break;
                case 'a': snake.change_dir('l');break;
                case 's': snake.change_dir('d');break;
                case 'd': snake.change_dir('r');break;
            }
        }

         if(snake.collided()) game_over = true;

        //snake.move_snake();

        if(snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score = score + 10;
        }


        //x++;//object moving to the right side
        //system("cls");
        snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0});
    }

    //FPS refresh rate -> OS

    // cout << "hello world\rasas";
    //takes cursor from the end of the line and puts it in the beginning
}
