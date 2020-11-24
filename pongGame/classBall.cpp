#include "classBall.h"





Ball::Ball(int x_pos, int y_pos)
{
    currX = x_pos;
    currY = y_pos;

    origin_X = x_pos;
    origin_Y = y_pos;

    direction = 0;                  // ball is not moving
}

int Ball::get_currX_pos()
{
    return currX;
}

int Ball::get_currY_pos()
{
    return currY;
}

void Ball::update_pos()
{
    currX = origin_X;
    currY = origin_Y;
}

int Ball::get_direction()
{
    return direction;
}


void Ball::turn_right()
{
    direction = 6;
}

void Ball::turn_upRight()
{
    direction = 5;
}
void Ball::turn_downRight()
{
    direction = 3;
}
void Ball::turn_left()
{
    direction = 1;
}
void Ball::turn_upLeft()
{
    direction = 4;
}
void Ball::turn_downLeft()
{
    direction = 2;
}


void Ball::generate_dir()
{
    direction = ((rand() % 6) +1);
}

int Ball::move_ball()
{
    switch (direction)
    {
    case 5 : currX++; currY--;

        break;

    case 6 : currX++;

        break;

    case 3 : currX++; currY++;

        break;

    case 4 : currX--; currY--;

        break;
    case 1: currX--;

        break;

    case 2:  currX--; currY++;

        break;

    case 0: 
        break;
    }
    
    return direction;
}
   
