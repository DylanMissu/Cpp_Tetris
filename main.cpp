#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

const int gameWidth = 24;
const int gameHeight = 12;

string red = "\e[0;31m";
string RED = "\e[1;31m";
string blue = "\e[0;34m";
string BLUE = "\e[1;34m";
string cyan = "\e[0;36m";
string CYAN = "\e[1;36m";
string green = "\e[0;32m";
string GREEN = "\e[1;32m";
string yellow = "\e[0;33m";
string YELLOW = "\e[1;33m";

string buffer[gameWidth][gameHeight];

void DrawGameBorder(int width, int height) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1 || i == height - 1)
            {
                buffer[i][j] = "\xDB\xDB";
            }
            else
            {
                buffer[i][j] = "  ";
            }
        }
    }
}

void DrawPixel(int x, int y, string colorCode)
{
    buffer[x][y] = colorCode + "\xDB\xDB" + "\e[0m";
}

void DrawBuffer() 
{
    for (int i = 0; i < 22 + 2; i++)
    {
        for (int j = 0; j < 10 + 2; j++)
        {
            cout << buffer[i][j];
        }
        cout << endl;
    }
}

int main()
{
    DrawGameBorder(12, 24);
    DrawPixel(5,5, green);
    DrawBuffer();
}