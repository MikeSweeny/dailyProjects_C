#pragma once
class BoardClass
{
public:
	BoardClass();
	~BoardClass();
	int numMoves;
	int board;

	void Board(): numMoves(0)
	{
		for (int row = 0; row < maxRows; ++row)
		{
			for (int col = 0; col < maxColumns; ++col)
			{
				board[row][col] = ' ';
			}
		}
	}
private:
	const int maxRows = 3;
	const int maxColumns = 3;
	const int fullBoard = 10;
};

