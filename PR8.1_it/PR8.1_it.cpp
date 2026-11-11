
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

bool Check(const char* str)
{
    if (strlen(str) < 3)
        return false;

    for (int i = 0; str[i + 2] != '\0'; i++)
        if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
            return true;

    return false;
}

char* Change(char* str)
{
    size_t len = strlen(str);

    if (len < 3)
        return str;

    char* tmp = new char[len + 1];
    char* t = tmp;

    size_t i = 0;

    while (i < len)
    {
        if (i + 2 < len &&
            ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
                (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')))
        {
            *t++ = '*';
            *t++ = '*';
            i += 3;
        }
        else
        {
            *t++ = str[i++];
        }
    }

    *t = '\0';

    strcpy_s(str, len + 1, tmp);
    delete[] tmp;

    return str;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains OGO or AGA: "
        << (Check(str) ? "Yes" : "No") << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}