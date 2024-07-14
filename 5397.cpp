#include <iostream>
#include <string.h>
#include <list>
using namespace std;

int main()
{

    int a;
    cin >> a;

    char s[1000000] = {0};

    for (int i = 0; i < a; i++)
    {

        // acbc0
        //   i
        list<char> stack;
        list<char>::iterator cursor = stack.end();

        cin >> s;
        int len = strlen(s);
        for (int j = 0; j < len; j++)
        {
            if (s[j] == '<')
            {
                if (cursor != stack.begin())
                {
                    cursor--;
                }
            }
            else if (s[j] == '>')
            {
                if (cursor != stack.end())
                {
                    cursor++;
                }
            }
            else if (s[j] == '-')
            {
                if (cursor != stack.begin())
                {
                    cursor = stack.erase(--cursor);
                }
            }
            else
            {
                stack.insert(cursor, s[j]);
            }
        }

        cursor = stack.begin();
        while(cursor != stack.end()){
            cout<<*cursor++;
        }
        cout<<endl;
    }
}