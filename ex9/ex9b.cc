#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

bool isMatch(const char* text, const char* pattern);

int main()
{
    char text[51], pattern[51];
    cin >> text;
    cin >> pattern;
    if (isMatch(text, pattern))
        cout << "1" << endl;
    else
        cout << "0" << endl;

    return EXIT_SUCCESS;
}

bool isMatch(const char* text, const char* pattern)
{
    if (*text == '\0' && *pattern == '\0') return true;
    if (*pattern == '\0') return false;
    if (*text == '\0')
    {
        if (*pattern == '*') 
            return isMatch(text, pattern + 1);
        return false;
    }
    if (*pattern == *text || *pattern == '?')
        return isMatch(text + 1, pattern + 1);
    if (*pattern == '*')
        return isMatch(text + 1, pattern) || isMatch(text, pattern + 1);

    return false;
}
