#pragma once
#include<Windows.h>




class Ball
{
private:

    int currX, currY;
    int origin_X, origin_Y;
    int direction;

public:

    Ball(int , int);

    int get_currX_pos();

    int get_currY_pos();

    void update_pos();                // set the ball in the middle of the game screen

    int get_direction();

    // change ball direction
    void turn_right();
   
    void turn_upRight();
   
    void turn_downRight();
   
    void turn_left();
    
    void turn_upLeft();
   
    void turn_downLeft();

    int move_ball();                // moving ball

    void generate_dir();            // generate ball direction
};

