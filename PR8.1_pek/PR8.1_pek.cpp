
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool Check(const char* str, int i)
{
    if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0')
        return false;

    if ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
        (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A'))
        return true;

    return Check(str, i + 1);
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] == '\0')
    {
        *t = '\0';
        return dest;
    }

    if (str[i + 1] != '\0' && str[i + 2] != '\0' &&
        ((str[i] == 'O' && str[i + 1] == 'G' && str[i + 2] == 'O') ||
            (str[i] == 'A' && str[i + 1] == 'G' && str[i + 2] == 'A')))
    {
        *t++ = '*';
        *t++ = '*';

        return Change(dest, str, t, i + 3);
    }
    else
    {
        *t++ = str[i];

        return Change(dest, str, t, i + 1);
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains OGO or AGA: "
        << (Check(str, 0) ? "Yes" : "No") << endl;

    char* dest1 = new char[strlen(str) + 1];
    char* dest2;

    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;

    return 0;
}