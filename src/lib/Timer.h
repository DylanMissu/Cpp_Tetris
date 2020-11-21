#pragma once

class Timer
{
    public:
        Timer();
        int getElapsedMillis();
        void resetTimer();

    private:
        int currentMillis();

    private:
        int millieSeconds;
};