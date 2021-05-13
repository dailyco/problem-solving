/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60058
블로그 링크 : https://dailyco.github.io/posts/parenthesis_transformation/
*/

#include <string>
#include <vector>

using namespace std;

string MakeString(string w)
{
    int parenthesis = 0;
    string u = "", v = "";

    if (w == "")
        return "";

    int length = 0;
    for (auto c : w)
    {
        if (c == '(')
            parenthesis++;
        else if (c == ')')
            parenthesis--;
        length++;

        if (parenthesis == 0)
        {
            u = w.substr(0, length);
            if (length < w.length())
                v = w.substr(length);
            break;
        }
    }

    bool is_right_string = true;
    for (auto c : u)
    {
        if (c == '(')
            parenthesis++;
        else if (c == ')')
            parenthesis--;

        if (parenthesis < 0)
        {
            is_right_string = false;
            break;
        }
    }

    if (is_right_string)
        u += MakeString(v);
    else
    {
        string s = "(";
        s += MakeString(v) + ")";
        u.erase(u.begin());
        u.erase(u.end() - 1);
        for (auto c : u)
        {
            if (c == '(')
                s += ")";
            else if (c == ')')
                s += "(";
        }
        u = s;
    }

    return u;
}

string solution(string p)
{
    return MakeString(p);
}