#include "classPlayer.h"





Player::Player(int x_pos, int y_pos)
{
    currX = x_pos;
    currY = y_pos;

    origin_X = x_pos;
    origin_Y = y_pos;
}

int Player::get_playerX_pos()
{
    return currX;
}

int Player::get_playerY_pos()
{
    return currY;
}

void Player::moveUp_paddle()
{
    currY--;
}

void Player::moveDown_paddle()
{
    currY++;
}
