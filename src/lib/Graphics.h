#pragma once

#include <string>

class Graphics {
    public:
        Graphics(const int width, const int height);
        void DrawGameBorder(int width, int height);
        void DrawPixel(int x, int y, int colorCode);
        void ClearRect(int x, int y, int width, int height);
        int getWidth();
        int getHeight();
        std::string DrawBuffer();

    private:
        std::string *buffer;
        int gameWidth;
        int gameHeight;

    private:
        const std::string colors[9] = {
            "\e[0m", "\e[1;30m", "\e[1;31m",
            "\e[1;32m", "\e[1;33m", "\e[1;34m",
            "\e[1;35m", "\e[1;36m", "\e[1;37m"};
};