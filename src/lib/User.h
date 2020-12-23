#pragma once

#include <string>

class User
{
    public:
        std::string getUserName();
        void setUserName(std::string user);

    private:
        std::string username;

};