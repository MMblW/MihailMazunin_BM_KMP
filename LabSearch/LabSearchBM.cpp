#include <iostream>
#include <string>
using namespace std;
int BMSearch(string str, string substr)
{
    int StrSize, SubstrSize;
    StrSize = str.size();
    SubstrSize = substr.size();
    if (StrSize !=0 && SubstrSize != 0)
    {
        int pos;
        int ASCII[256];
        for(int i = 0; i < 256; i++)
        {
            ASCII[i] = SubstrSize;
        }
        for (int i = SubstrSize - 2; i >= 0; i--)
        {
            if (ASCII[int((unsigned char)substr[i])] == SubstrSize)
            {
                ASCII[int((unsigned char)substr[i])] = SubstrSize - i - 1;
            }
        }
        pos = SubstrSize - 1;
        while (pos < StrSize)
        {
            if (substr[SubstrSize - 1] != str[pos])
            {
                pos += ASCII[int((unsigned char)str[pos])];
            }
            else
            {
                for (int i = SubstrSize - 1; i >= 0; i--)
                {
                    if (substr[i] != str[pos - SubstrSize + i + 1])
                    {
                        pos += ASCII[int((unsigned char)str[pos - SubstrSize + i + 1])];
                        i = -1;
                    }
                    else
                    {
                        if (i == 0)
                        {
                            return pos - SubstrSize + 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    string str = "abbdkaabcd";
    string substr = "aabc";
    cout << "String: " << str << endl << "Substring: " << substr << endl;
    cout << BMSearch(str, substr);
}