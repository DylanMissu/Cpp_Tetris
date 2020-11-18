#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

const int gameWidth = 24;
const int gameHeight = 12;

string buffer[gameWidth][gameHeight];

void DrawGameBorder(int width, int height) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1 || i == 0 || i == height - 1)
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
    DrawBuffer();
}