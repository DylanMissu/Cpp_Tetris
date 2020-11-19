#pragma once

#include <string>

class Graphics {
    public:
        Graphics(const int width, const int height);
        void DrawGameBorder(int width, int height);
        void DrawPixel(int x, int y, std::string colorCode);
        int getWidth();
        int getHeight();
        std::string DrawBuffer();

    private:
        std::string *buffer;
        int gameWidth;
        int gameHeight;
};