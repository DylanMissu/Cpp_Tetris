#pragma once

class Timer
{
    public:
        Timer();
        int getElapsedMillis();
        void resetTimer();
        void setState(bool state);
        bool interval(int milliseconds);
        bool getState();

    private:
        int currentMillis();

    private:
        int millieSeconds;
        bool currentState;
};