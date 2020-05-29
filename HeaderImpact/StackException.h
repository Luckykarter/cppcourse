#pragma once
#include <exception>
using namespace std;
class StackException :
    public exception
{
private:
    const char * message;
public:
    StackException(const char* s) {
        message = s;
        const exception ex(message);
        throw ex;
    };
    const char* what() const throw() { return message; }
};

