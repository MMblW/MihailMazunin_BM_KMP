#include <iostream>
#include <string>
using namespace std;
void Prefix(string substr, int *arr)
{
    arr[0] = 0;
    int j = 0;
    int i = 1;
    while (i < substr.length())
    {
        if (substr[i] == substr[j])
        {
            arr[i] = j + i;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                arr[i] = 0;
                i++;
            }
            else
            {
                j = arr[j - 1];
            }
        }
    }
}
int KMPSearch(string substr, string str)
{
    int *arr = new int[substr.length()];
    Prefix(substr, arr);
    int i = 0, j = 0;
    while (i < str.length())
    {
        if (substr[j] == str[i])
        {
            i++;
            j++;
        }
        if (j == substr.length())
        {
            return i - substr.length();
        }
        else if (i < str.length() && substr[j] != str[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = arr[j - 1];
            }
        }
    }
    return -1;
}
int main()
{
    string str = "abcabceabcabcd";
    string substr = "abcd";
    cout << "String: " << str << endl << "Substring: " << substr << endl;
    cout << KMPSearch(substr, str);
}