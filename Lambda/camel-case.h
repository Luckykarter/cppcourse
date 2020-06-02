#include <cctype>

class camel_case {
    char _last;
    char _sep = 0;
public:
    camel_case() : _last(0) {}
    camel_case(const char c) : _last(1), _sep(c) {}
    const char operator() (const char c);
};

const char camel_case::operator() (const char c) {
    if (c==' ') {
        _last = '.';
    }
    else
    _last = (!_last || isblank(_last)) ? toupper(c) : c;

    return _last;


}
