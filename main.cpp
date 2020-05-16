#include <iostream>
using namespace std;

class Piece
{
    char player;
    int column, row;
    bool isKing;

    void init_possible_coordinates(int arr[][2], int rows, int cols = 2)
    {
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                arr[i][j] = -1;
    }

    public:
        Piece(){}
        Piece(char player, int row, int column, bool isKing = false)
        {
            this -> player = player;
            this -> column = column;
            this -> row = row;
            this -> isKing = isKing;
        }

        void getVals()
        {
            cout << "player: " << player << endl;
            cout << "column: " << column << endl;
            cout << "row: " << row << endl;
            cout << "isKing: " << isKing << endl;
        }

        int *posibleMoves(int board[8][8], int x, int y)
        {   

            int forward_diagonal_right[] = {row + 1, column + 1};
            int forward_diagonal_left[] = {row + 1, column - 1};
            if(!isKing)
            {   
                static int possible_coordinates[2][2];
                if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] == ' ')
                {
                    possible_coordinates[0][0] = forward_diagonal_right[0];
                    possible_coordinates[0][1] = forward_diagonal_right[1];
                }

                else if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] != player)
                {
                    forward_diagonal_right[0]++;
                    forward_diagonal_right[1]++;
                    if(board[forward_diagonal_right[0]][forward_diagonal_right[1]] == ' ')
                    {
                        possible_coordinates[0][0] = forward_diagonal_right[0];
                        possible_coordinates[0][1] = forward_diagonal_right[1];
                    }
                }

                if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] == ' ')
                {
                    possible_coordinates[1][0] = forward_diagonal_left[0];
                    possible_coordinates[1][1] = forward_diagonal_left[1];
                }

                else if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] != player)
                {
                    forward_diagonal_left[0]++;
                    forward_diagonal_left[1]--;
                    if(board[forward_diagonal_left[0]][forward_diagonal_left[1]] == ' ')
                    {
                        possible_coordinates[1][0] = forward_diagonal_left[0];
                        possible_coordinates[1][1] = forward_diagonal_left[1];
                    }
                }
                return *possible_coordinates;
            }
/*
            else
            {
                int possible_coordinates[4][2] = {{column + 1, row + 1},
                 {column - 1, row + 1}, {column, row + 1}, {column, row - 1}};
            } */

            
        }

};

class Position
{
    bool isDark, isKingMaker;
    char containingValue;

    public:
        Position(){}
        Position(bool isDark, int row)
        {
            this -> isDark = isDark;
            containingValue = ' ';

            if(row == 0 || row == 7)
                isKingMaker = true;
            else
                isKingMaker = false;
        }

        void setContainingValue(char x)
        {
            containingValue = x;
        }

        char getContainingValue()
        {
            return containingValue;
        }

        bool getIsKingMaker()
        {
            return isKingMaker;
        }

        bool getIsDark()
        {
            return isDark;
        }

        void getVals()
        {
            cout << "isDark: " << isDark << endl;
            cout << "isKingMaker: " << isKingMaker << endl;
        }

};

void game_init(char board[8][8]);
void board_init(Position board[8][8]);
void player_init(Piece [], Position board[8][8], char);
void renderBoard(Position board[8][8]);
void theGame();

int main()
{
    theGame();
    /*
    char arr[25][33];    //on x axis everything is multiplied by 3 and on y axis everything is multiplied by 4
    for (int i = 0;i <= 24;i++)
    {
        for (int j = 0;j <= 32;j++)
        {
            if (i % 3 == 0 || j % 4 == 0)
                arr[i][j] = '*';
            else
                arr[i][j] = ' ';
        }

    }
    for (int i = 0;i <= 24;i++)
    {
        for (int j = 0;j <= 32;j++)
        {

            cout << arr[i][j];

        }
        cout << endl;
    }
*/
    return 0;
}

void board_init(Position board[8][8])
{   
    bool isLastDark = false;
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            if(!isLastDark)
            {
                board[row][col] = Position(true, row);
                if(col != 7)
                    isLastDark = true;
            }
            else
            {
                board[row][col] = Position(false, row);
                if(col != 7)
                    isLastDark = false;
            }

        }
    }
}

void player_init(Piece pieces[], Position board[8][8], char player)
{   
    int piece_index = 0, max_row, row;

    if(player == 'R')
    {
        row = 0;
        max_row = 3;
    }

    else
    {
        row = 5;
        max_row = 8;
    }
    
    for(; row < max_row; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            if(board[row][col].getIsDark())
            {
                pieces[piece_index] = Piece(player, row, col);
                board[row][col].setContainingValue(player);
                piece_index++;
            }
        }
    }
}

void theGame()
{
    Position board[8][8];
    Piece red_pieces[12], white_pieces[12];
    bool gameCompelete = false, isPlayerOne = true;

    board_init(board);
    player_init(red_pieces, board, 'R');
    player_init(white_pieces, board, 'W');

    while(!gameCompelete)
    {
        if(isPlayerOne)
        {
            renderBoard(board);
            gameCompelete = true;
        }

        else
        {
            // To Be continued
        }
    }
}

void renderBoard(Position board[8][8])
{
    for(int i = 0; i < 11; i++)
        cout << "---";

    cout << endl;
    for(int row = 0; row < 8; row++)
    {   
        for(int col = 0; col < 8; col++)
        {
            if(col == 0)
            {
                cout << "| " << board[row][col].getContainingValue() << " | ";
            }
            else
            {
                cout << board[row][col].getContainingValue() << " | ";
            }            
        }

        cout << endl;
        for(int i = 0; i < 11; i++)
            cout << "---";
        cout << endl;
    }
}

