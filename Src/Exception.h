#pragma once 

#include <string>

namespace todo
{
    class Exception
    {
    public:
        explicit Exception(const std::string& msg) : msg_(msg) { }
        const std::string& what() const { return msg_; }

    private:
        std::string msg_;
    };

}
