#pragma once

#include <string>

class Graphics {
    public:
        Graphics(const int width, const int height);
        void DrawGameBorder(int width, int height);
        void DrawPixel(int x, int y, std::string colorCode);
        std::string DrawBuffer();

    public:
        std::string red;
        std::string RED;
        std::string blue;
        std::string BLUE;
        std::string cyan;
        std::string CYAN;
        std::string green;
        std::string GREEN;
        std::string yellow;
        std::string YELLOW;

    private:
        std::string *buffer;
        int gameWidth;
        int gameHeight;

};