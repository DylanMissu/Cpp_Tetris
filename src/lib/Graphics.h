#pragma once

#include <string>

class Graphics {
    public:
        Graphics(const int width, const int height);
        void DrawGameBorder(int width, int height);
        void DrawPixel(int x, int y, int colorCode);
        void ClearRect(int x, int y, int width, int height);
        const int getWidth();
        const int getHeight();
        int *getBuffer();

    private:
        int *buffer;
        int gameWidth;
        int gameHeight;

};