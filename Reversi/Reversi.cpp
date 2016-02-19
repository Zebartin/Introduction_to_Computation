#include<iostream>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<graphics.h>

using namespace std;
MOUSEMSG m;
IMAGE img[20];
int black, white, player, x, y, X, Y, eva[8][8];
int board[8][8], saveBoard[60][8][8], cntOfSaving, cOST;
int dir[8][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 },
{ -1, -1 },{ 1, -1 },{ 1, 1 },{ -1, 1 } };

void load();
int options();
int chooseColor();
int newGame();
int hloadGame();
void forwardOrBackward(int, int);
inline void saveGame();
int quit();
void loadGame();
void printBoard(int);
void save();
int judgeAbleOnes(int);
int reverse(int, int, int);
int end();
void val();
int Evaluate();
int AlphaBeta(int, int, int, int);

//功能部分
void load()                 //加载图片，初始化窗格
{
	loadimage(&img[0], _T("..\\images\\welcome.jpg"));
	loadimage(&img[1], _T("..\\images\\options.jpg"));
	loadimage(&img[2], _T("..\\images\\game.jpg"));
	loadimage(&img[3], _T("..\\images\\choosecolor.jpg"));
	loadimage(&img[4], _T("..\\images\\load.jpg"));
	loadimage(&img[5], _T("..\\images\\new.jpg"));
	loadimage(&img[6], _T("..\\images\\quit.jpg"));
	loadimage(&img[7], _T("..\\images\\savesucceed.jpg"));
	loadimage(&img[8], _T("..\\images\\blank.bmp"));
	loadimage(&img[9], _T("..\\images\\black.bmp"));
	loadimage(&img[10], _T("..\\images\\white.bmp"));
	loadimage(&img[11], _T("..\\images\\move.jpg"));
	loadimage(&img[12], _T("..\\images\\blackJ.jpg"));
	loadimage(&img[13], _T("..\\images\\whiteJ.jpg"));
	loadimage(&img[14], _T("..\\images\\noBlack.jpg"));
	loadimage(&img[15], _T("..\\images\\noWhite.jpg"));
	loadimage(&img[16], _T("..\\images\\blackWin.jpg"));
	loadimage(&img[17], _T("..\\images\\whiteWin.jpg"));
	loadimage(&img[18], _T("..\\images\\draw.jpg"));
	initgraph(640, 480);
}
inline void save()       //临时保存，便于进退
{
	cOST = cntOfSaving;
	memcpy(saveBoard[cntOfSaving++], board, sizeof(board));
}
void saveGame()               //保存游戏，显示保存成功画面
{
	ofstream fout("board.txt");
	fout << player << "\n";
	for (int i = 0; i < 64; i++)
		fout << board[i / 8][i % 8] << " ";
	for (int i = 0; i < cntOfSaving; i++)
		for (int j = 0; j < 64; j++)
			fout << saveBoard[i][j / 8][j % 8] << " ";
	fout.close();
	putimage(0, 0, &img[7]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 265 && m.x < 365 && m.y > 270 && m.y < 305)
			{
				printBoard(-player);
				return;
			}
		}
	}
}
void loadGame()                 //复盘
{
	ifstream fin("board.txt");
	if (!fin)
		return;
	fin >> player;
	for (int i = 0; i < 64; i++)
		fin >> board[i / 8][i % 8];
	cntOfSaving = 0;
	while (!fin.eof())
	{
		for (int i = 0; i < 64; i++)
			fin >> saveBoard[cntOfSaving][i / 8][i % 8];
		cntOfSaving++;
	}
	cntOfSaving -= 2;
	fin.close();
}
void forwardOrBackward(int c, int i)         //进或退，于边界时不反应
{
	if (!(cntOfSaving - 1 == cOST && i == 1) && !(cntOfSaving == 0 && i == -1))
	{
		memcpy(board, saveBoard[(cntOfSaving += i) - 1], sizeof(board));
		printBoard(-c);
	}
}

//选项部分
int options()           //选项界面
{
	putimage(0, 0, &img[1]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 200 && m.x < 300 && m.y > 300 && m.y < 325)
				return 1;
			if (m.x > 270 && m.x < 370 && m.y > 355 && m.y < 380)
				return 2;
			if (m.x > 340 && m.x < 440 && m.y > 410 && m.y < 435)
				return 3;
		}
	}
}
int hloadGame()            //游戏中途显示是否载入画面+选择
{
	cleardevice();
	putimage(0, 0, &img[4]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 190 && m.x < 280 && m.y > 270 && m.y < 310)
				return 1;
			if (m.x > 352 && m.x < 442 && m.y > 270 && m.y < 310)
				return 0;
		}
	}
}
int quit()                    //显示退出游戏画面+选择
{
	cleardevice();
	putimage(0, 0, &img[6]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 190 && m.x < 280 && m.y > 270 && m.y < 310)
				return 1;
			if (m.x > 352 && m.x < 442 && m.y > 270 && m.y < 310)
				return 0;
		}
	}
}
int end()                 //显示游戏正常结束画面+选择
{
	if (black > white)
		putimage(0, 0, &img[16]);
	else if (black < white)
		putimage(0, 0, &img[17]);
	else
		putimage(0, 0, &img[18]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 175 && m.x < 285 && m.y > 195 && m.y < 245)
				return 1;
			if (m.x > 255 && m.x < 365 && m.y > 245 && m.y < 295)
				return 2;
			if (m.x > 345 && m.x < 455 && m.y > 295 && m.y < 345)
				return 3;
		}
	}

}
int chooseColor()               //显示选择颜色画面+选择
{
	cleardevice();
	putimage(0, 0, &img[3]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 240 && m.x < 290 && m.y > 240 && m.y < 325)
				return 1;
			if (m.x > 350 && m.x < 400 && m.y > 240 && m.y < 325)
				return -1;
		}
	}
}
int newGame()                  //显示新开游戏画面+选择
{
	cleardevice();
	putimage(0, 0, &img[5]);
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 190 && m.x < 280 && m.y > 270 && m.y < 310)
				return 1;
			if (m.x > 352 && m.x < 442 && m.y > 270 && m.y < 310)
				return 0;
		}
	}
}

//棋盘部分
void printBoard(int c)            //画出棋盘，以及棋盘一旁的界面
{
	cleardevice();
	putimage(0, 0, &img[2]);
	int x, y;
	black = white = 0;
	judgeAbleOnes(-c);
	for (x = 0; x < 8; x++)
		for (y = 0; y < 8; y++)
			switch (board[x][y])
			{
			case 0:
				putimage(y * 50 + 20, x * 50 + 40, &img[8]);
				break;
			case 1:
				putimage(y * 50 + 20, x * 50 + 40, &img[9]);
				black++;
				break;
			case -1:
				putimage(y * 50 + 20, x * 50 + 40, &img[10]);
				white++;
				break;
			case 2:
				putimage(y * 50 + 20, x * 50 + 40, &img[11]);
				break;
			case 3:
				putimage(y * 50 + 20, x * 50 + 40, &img[12]);
				black++;
				break;
			case -3:
				putimage(y * 50 + 20, x * 50 + 40, &img[13]);
				white++;
				break;
			};
	setbkcolor(RGB(219, 149, 51));
	settextstyle(30, 11, _T("微软雅黑"));
	TCHAR s[3];
	settextcolor(WHITE);
	_stprintf_s(s, _T("%d"), black);
	outtextxy(550, 135, s);
	settextcolor(BLACK);
	_stprintf_s(s, _T("%d"), white);
	outtextxy(550, 205, s);
}
int judgeAbleOnes(int c)                 //判断可落子区，标记，并返回可落子数
{
	int i, f, n = 0, xp, yp;
	for (xp = 0; xp < 8; xp++)
		for (yp = 0; yp < 8; yp++)
			if (board[yp][xp] == 2)
				board[yp][xp] = 0;
	for (xp = 0; xp < 8; xp++)
		for (yp = 0; yp < 8; yp++)
			if (!board[yp][xp])
				for (i = 0; i < 8; i++)
				{
					int x, y;
					f = 0;
					x = xp + dir[i][0];
					y = yp + dir[i][1];
					while (x >= 0 && x < 8 && y >= 0 && y < 8 && board[y][x] != 0 && board[y][x] != 2)
					{
						if (board[y][x] == -c || board[y][x] == -c * 3)
						{
							f = 1;
							x += dir[i][0];
							y += dir[i][1];
						}
						else if (board[y][x] == c || board[y][x] == c * 3)
						{
							if (f)
							{
								board[yp][xp] = 2;
								n++;
							}
							break;
						}
					}
				}
	return n;
}
int reverse(int x, int y, int c)         //翻转颜色，返回翻转数
{
	int i, x1, y1, f1, f2, n = 0;
	for (i = 0; i < 8; i++)
	{
		f1 = 0, f2 = 0;
		x1 = x + dir[i][0];
		y1 = y + dir[i][1];
		while (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && board[y1][x1] != 0 && board[y1][x1] != 2)
		{
			if (board[y1][x1] == -c || board[y1][x1] == -c * 3)
			{
				f1 = 1;
				x1 += dir[i][0];
				y1 += dir[i][1];
			}
			else if (board[y1][x1] == c || board[y1][x1] == c * 3)
			{
				if (f1)
					f2 = 1;
				break;
			}
		}
		if (f2)
		{
			x1 = x + dir[i][0];
			y1 = y + dir[i][1];
			while (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8)
			{
				if (board[y1][x1] == -c || board[y1][x1] == -c * 3)
				{
					board[y1][x1] = c;
					n++;
					x1 += dir[i][0];
					y1 += dir[i][1];
				}
				else
					break;
			}
		}
	}
	return n;
}

//AI部分
void val()                               //为估值表赋值
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if ((i == 0 && (j == 7 || j == 0)) || (i == 7 && (j == 7 || j == 0)))
				eva[i][j] = 100;
			else if (i == 0 || i == 7 || j == 0 || j == 7)
				if (i + j == 1 || i + j == 8 || i + j == 6 || i + j == 13)
					eva[i][j] = -50;
				else
					eva[i][j] = 20;
			else if ((i == 1 && j == 1) || (i == 1 && j == 6) || (i == 6 && j == 1) || (i == 6 && j == 6))
				eva[i][j] = -80;
			else if (i == 1 || i == 6 || j == 1 || j == 6)
				eva[i][j] = -30;
			else
				eva[i][j] = 5;
}
int Evaluate()                       //估值（包括对手可下棋子数）
{
	int a = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == player || board[i][j] == player * 3)
				a += eva[i][j] + 1;
			else if (board[i][j] == -player || board[i][j] == -player * 3)
				a -= eva[i][j] + 1;
	a += 5 * judgeAbleOnes(player);
	return a;
}
int AlphaBeta(int c, int depth, int alpha, int beta)   //搜索，深度5步
{
	int tempBoard[8][8], max = INT_MIN, val, tx, ty;
	if (depth == 0)
		return Evaluate();
	if(!judgeAbleOnes(c))
		if(!judgeAbleOnes(-c))
			return Evaluate();
		else
			return  -AlphaBeta(-c, depth - 1, -beta, -alpha);
	judgeAbleOnes(c);
	memcpy(tempBoard, board, sizeof(board));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (board[i][j] == 2)
			{
				board[i][j] = c;
				reverse(j, i, c);
				val = -AlphaBeta(-c, depth - 1, -beta, -alpha);
				memcpy(board, tempBoard, sizeof(board));
				if (val > max)
				{
					tx = j;
					ty = i;
					max = val;
				}
				if (max > alpha)
					alpha = max;
				if (max >= beta)
					break;
			}
	if (depth == 5)
	{
		X = tx;
		Y = ty;
	}
	return max;
}

//游戏流程部分
int main()
{
	val();
	load();
	cleardevice();
	putimage(0, 0, &img[0]);
	_getch();

	int flag4 = 0, flag5 = 0;
	switch (options())
	{
	case 2:
		flag4 = 1;
		loadGame();
		printBoard(-player);
		if (black + white == 64 || (judgeAbleOnes(-player) == 0 && judgeAbleOnes(player) == 0))
			flag5 = 1;
	case 1:
	{
		while (1)
		{
			int flag2 = 0, flag6 = 0, temp;
			x = -1, X = -1;
			if (flag4)
			{
				temp = 1;
				flag4 = 0;
				for (int i = 0; i < 64; i++)
					if (board[i / 8][i % 8] == -player * 3)
					{
						Y = i / 8;
						X = i % 8;
					}
			}
			else
			{
				cntOfSaving = 0;
				memset(board, 0, sizeof(board));
				memset(saveBoard, 0, sizeof(saveBoard));
				board[3][3] = board[4][4] = -1;
				board[3][4] = board[4][3] = 1;
				temp = player = chooseColor();
			}
			printBoard(-player);
			do
			{
				int flag1 = 0, flag3 = 0;
				save();
				if (flag6)
				{
					flag6 = 0;
					if (board[y][x] == player * 3 && x != -1 && !(cntOfSaving == 1 && player == -1))
						board[y][x] = player;
				}
				printBoard(-player);
				if (temp == 1)
					if (judgeAbleOnes(player) || flag5)
						while (true)
						{
							m = GetMouseMsg();
							if (m.uMsg == WM_LBUTTONDOWN)
							{
								if (board[y][x] == player * 3 && x != -1 && !(cntOfSaving == 1 && player == -1))
									board[y][x] = player;
								x = (m.x - 20) / 50;
								y = (m.y - 40) / 50;
								if (board[y][x] == 2 && x >= 0 && x < 8 && y >= 0 && y < 8)
								{
									flag5 = 0;
									if (board[Y][X] == -player * 3 && cntOfSaving != 1 && X != -1)
										board[Y][X] = -player;
									board[y][x] = player * 3;
									reverse(x, y, player);
									printBoard(player);
									break;
								}
								else if (m.x >= 448 && m.x <= 523 && m.y >= 290 && m.y <= 324)
								{
									if (newGame())
									{
										flag5 = 0;
										flag1 = 1;
										break;
									}
									else
										printBoard(-player);
								}
								else if (m.x >= 537 && m.x <= 613 && m.y >= 290 && m.y <= 324)
									if (hloadGame())
									{
										loadGame();
										flag1 = 1;
										flag4 = 1;
										printBoard(-player);
										if (black + white == 64 || (judgeAbleOnes(-player) == 0 && judgeAbleOnes(player) == 0))
											flag5 = 1;
										break;
									}
									else
										printBoard(-player);
								else if (m.x >= 448 && m.x <= 523 && m.y >= 333 && m.y <= 367)
								{
									forwardOrBackward(player, -1);
									for (int i = 0; i < 64; i++)
										if (board[i / 8][i % 8] == -player * 3)
										{
											Y = i / 8;
											X = i % 8;
										}
										else if (board[i / 8][i % 8] == player * 3)
										{
											y = i / 8;
											x = i % 8;
										}
									if (player == -1 && cntOfSaving == 1)
										break;
								}
								else if (m.x >= 537 && m.x <= 613 && m.y >= 333 && m.y <= 367)
								{
									forwardOrBackward(player, 1);
									for (int i = 0; i < 64; i++)
										if (board[i / 8][i % 8] == -player * 3)
										{
											Y = i / 8;
											X = i % 8;
										}
								}
								else if (m.x >= 448 && m.x <= 523 && m.y >= 376 && m.y <= 410)
									saveGame();
								else if (m.x >= 537 && m.x <= 613 && m.y >= 376 && m.y <= 410)
								{
									int p = quit();
									if (p)
									{
										flag3 = 1;
										break;
									}
									else
										printBoard(-player);
								}
							}
						}
					else
					{
						x = -1;
						if (board[Y][X] == -player * 3 && cntOfSaving != 1 && X != -1)
							board[Y][X] = -player;
						if (black + white == 64 || judgeAbleOnes(-player) == 0)
							switch (end())
							{
							case 1: flag1 = 1; break;
							case 2: flag5 = 1; break;
							case 3: flag3 = 1; break;
							}
						else
						{
							putimage(0, 0, &img[(29 - player) / 2]);
							Sleep(1000);
							printBoard(-player);
						}
					}
				if (flag1)
				{
					flag2 = 1;
					break;
				}
				if (flag3)
					break;
				if (judgeAbleOnes(-player) || flag5)
				{
					AlphaBeta(-player, 5, INT_MIN, INT_MAX);
					Sleep(600);
					if (board[y][x] == player * 3 && x != -1 && !(cntOfSaving == 1 && player == -1))
						board[y][x] = player;
					if (!flag5)
					{
						board[Y][X] = -player * 3;
						reverse(X, Y, -player);
					}
				}
				else
				{
					flag6 = 1;
					if (black + white == 64 || judgeAbleOnes(player) == 0)
					{
						int p = end();
						if (p == 1)
						{
							flag2 = 1;
							break;
						}
						else if (p == 3)
							break;
						else
							flag5 = 1;
					}
					else
					{
						putimage(0, 0, &img[(29 + player) / 2]);
						Sleep(1000);
					}
				}
				temp = 1;
			} while (1);
			if (!flag2)
				break;
		}
	} break;
	case 3:
		break;
	}

	return 0;
}
