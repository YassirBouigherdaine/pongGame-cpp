#pragma 





class Player
{
private:

	int currX , currY;
	int origin_X, origin_Y;

public:

	Player(int, int);

	int get_playerX_pos();

	int get_playerY_pos();

	// moving paddles

	void moveUp_paddle();
	void moveDown_paddle();
};

