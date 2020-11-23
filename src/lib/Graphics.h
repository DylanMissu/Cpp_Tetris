#pragma once

#include <string>

class Graphics {
    public:
        Graphics(const int width, const int height);
        void ClearRect(int x, int y, int width, int height);
        void DrawPixel(int x, int y, int colorCode);
        void DrawGameBorder(int width, int height);
        const int getHeight();
        const int getWidth();
        int *getBakedBuffer();
        int *getBuffer();
        void clearAll();
        void bake();

    public:
        bool hasBlockAt(int x, int y);

    private:
        int *buffer;
        int *bakedBuffer;
        int gameWidth;
        int gameHeight;

};