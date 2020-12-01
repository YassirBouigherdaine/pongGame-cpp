#include"game.h"





COORD cursor_origin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	cursor_origin.X = 0;
	cursor_origin.Y = 0;
	SetConsoleCursorPosition(console, cursor_origin);
}

const int width = 50, height = 25;
bool game_over = false;
int max_score = 10, score1 = 0, score2 = 0;

Ball* ball = new Ball(width / 2, height / 2);
Player* paddle1 = new Player(width - 4, (height / 2) - 1);
Player* paddle2 = new Player(1, (height / 2) - 1);


// game functions

void drawscreen()
{
	int ball_X = ball->get_currX_pos();
	int ball_Y = ball->get_currY_pos();

	int paddle1_X = paddle1->get_playerX_pos();
	int paddle1_Y = paddle1->get_playerY_pos();

	int paddle2_X = paddle2->get_playerX_pos();
	int paddle2_Y = paddle2->get_playerY_pos();

	std::cout << "\t\t PING PONG GAME\n\n";
	std::cout << "     Player 2 : "<<score2<<"\t\t Player 1 : "<<score1<<"\n\n";
	
	for (int i = 0; i < height; i++)
	{
		std::cout << "\xB1";

		for (int j = 0; j < width - 2; j++)
		{
			if (i == 0 || i == height - 1)
			{
				std::cout << "\xB1";
			}

			else if (i == ball_Y && j == ball_X)
			{
				std::cout << 'O';
			}

			// drawing paddle1

			else if (i == paddle1_Y && j == paddle1_X)
			{
				std::cout << "\xDB";
			}
			else if (i == paddle1_Y + 1 && j == paddle1_X)
			{
				std::cout << "\xDB";
			}
			else if (i == paddle1_Y + 2 && j == paddle1_X)
			{
				std::cout << "\xDB";
			}

			// drawing paddle2

			else if (i == paddle2_Y && j == paddle2_X)
			{
				std::cout << "\xDB";
			}
			else if (i == paddle2_Y + 1 && j == paddle2_X)
			{
				std::cout << "\xDB";
			}
			else if (i == paddle2_Y + 2 && j == paddle2_X)
			{
				std::cout << "\xDB";
			}

			else
			{
				std::cout << " ";
			}
		}

		std::cout << "\xB1" << std::endl;
	}

	std::cout << "\n   Player 1 : [A] to move up - [Z] to move down\n";
	std::cout << "   Player 2 : [W] to move up - [X] to move down\n";
	std::cout << "\n   Press [Q] to quit the game";
}


void input()
{
	int ball_X = ball->get_currX_pos();
	int ball_Y = ball->get_currY_pos();

	int paddle1_X = paddle1->get_playerX_pos();
	int paddle1_Y = paddle1->get_playerY_pos();

	int paddle2_X = paddle2->get_playerX_pos();
	int paddle2_Y = paddle2->get_playerY_pos();

	ball->move_ball();

	if (_kbhit())
	{
		// moving the ball when a button is pressed

		if (ball->get_direction() == 0)
		{
			ball->generate_dir();
		}

		switch (_getch())
		{
			// moving paddle1
		case 'a':

			if (paddle1_Y > 0)
			{
				paddle1->moveUp_paddle();
			}
			break;

		case 'z':

			if (paddle1_Y + 2 < height)
			{
				paddle1->moveDown_paddle();
			}

			break;

			// moving paddle2
		case 'w':

			if (paddle2_Y > 0)
			{
				paddle2->moveUp_paddle();
			}

			break;

		case 'x':

			if (paddle2_Y + 2 < height)
			{
				paddle2->moveDown_paddle();
			}
			break;

		case 'q': game_over = true;       // guit the game
		}
	}

	drawscreen();
}


void ball_collis()
{
	int ball_X = ball->get_currX_pos();
	int ball_Y = ball->get_currY_pos();

	int paddle1_X = paddle1->get_playerX_pos();
	int paddle1_Y = paddle1->get_playerY_pos();

	int paddle2_X = paddle2->get_playerX_pos();
	int paddle2_Y = paddle2->get_playerY_pos();

	// player can control ball direction by the part of paddle

	// collision with player1

	if (ball_X == paddle1_X - 1 && ball_Y == paddle1_Y )        // right part of paddle1
	{
		ball->turn_upLeft();
	}
	if (ball_X == paddle1_X - 1 && ball_Y == paddle1_Y+1)        // middle part of paddle1
	{
		ball->turn_left();
	}
	if (ball_X == paddle1_X - 1 && ball_Y == paddle1_Y+2)        // left part of paddle1
	{
		ball->turn_downLeft();
	}

	// collision with player2

	if (ball_X == paddle2_X + 1 && ball_Y == paddle2_Y)          // left part of paddle1
	{
		ball->turn_upRight();
	}
	if (ball_X == paddle2_X + 1 && ball_Y == paddle2_Y + 1)        // middle part of paddle1
	{
		ball->turn_right();
	}
	if (ball_X == paddle2_X + 1 && ball_Y == paddle2_Y + 2)        // right part of paddle1
	{
		ball->turn_downRight();
	}

	// collision with walls
	// top wall

	if (ball_Y == 1 && ball->get_direction() == 5)
	{
		ball->turn_downRight();
	}
	if (ball_Y == 1 && ball->get_direction() == 4)
	{
		ball->turn_downLeft();
	}
	
	// bottom wall

	if (ball_Y == height - 2 && ball->get_direction() == 3)
	{
		ball->turn_upRight();
	}
	if (ball_Y == height - 2 && ball->get_direction() == 2)
	{
		ball->turn_upLeft();
	}
	
	// right wall

	if (ball_X == width - 3)
	{
		score2++;

		ball->update_pos();
		
		ball->turn_left();
	}

	// left wall

	if (ball_X == 0)
	{
		score1++;

		ball->update_pos();
		
		ball->turn_right();
	}
}


void check_win()
{
	if (score1 == max_score)
	{
		std::cout << "\n Player 1 wins \n";
		game_over = true;
	}
	if (score2 == max_score)
	{
		std::cout << "\n Player 2 wins \n";
		game_over = true;
	}
}

void destroy()
{
	delete ball; 
	delete paddle1; 
	delete paddle2;
	
}

void run_game()
{
	srand((unsigned)time(NULL));

	drawscreen();

	while (!game_over)
	{
		SetConsoleCursorPosition(console, cursor_origin);

		input();

		ball_collis();

		check_win();
	}
	
	destroy();
}
