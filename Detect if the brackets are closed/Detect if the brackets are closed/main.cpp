//
//  main.cpp
//  Detect if the brackets are closed
//
//  Created by mac air on 8/30/19.
//  Copyright © 2019 mac air. All rights reserved.
//
//arkam assi
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool check(stack<string>&tag, string temp)
{
    for (int i = 0; temp[i] != NULL; i++)
    {
        
        if (temp[i] == '(' || temp[i] == '{' || temp[i] == '[')
        {
            
            string a;
            a = temp[i];
            tag.push(a);
        }
        if (temp[i] == ')' || temp[i] == '}' || temp[i] == ']')
        {
            if (tag.empty())return false;
            string a;
            a = temp[i];
            string g = tag.top();
            if (g[0] == '(')g[0] = g[0] + 1;
            if (g[0] == '{' || g[0] == '[')g[0] = g[0] + 2;
            
            if (g == a)
            {
                tag.pop();
            }
            else
                if (g != a)
                {
                    return false;
                    break;
                }
        }
    }
    return true;
}
//akram assi

int main()
{
    string temp = { "{}(()){([()])}" };
    stack<string> tag;
    if (check(tag,temp)&&tag.empty())
        cout << "True code, there is no error\n";
    else
        cout << "Invalid code, error found\n";
    return 0;
}
