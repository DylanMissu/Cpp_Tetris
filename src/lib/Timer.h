#pragma once

class Timer
{
    public:
        Timer();
        int getElapsedMillis();
        void resetTimer();
        void setState(bool state);
        bool getState();

    private:
        int currentMillis();

    private:
        int millieSeconds;
        bool currentState;
};