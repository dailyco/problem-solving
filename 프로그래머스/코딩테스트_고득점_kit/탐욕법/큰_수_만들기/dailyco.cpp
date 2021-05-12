/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42883
블로그 링크 : https://dailyco.github.io/posts/creating_large_number/
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{

    while (k)
    {
        for (int i = 0; i < number.length(); i++)
        {
            if (i == number.length() - 1 || number[i] < number[i + 1])
            {
                number.erase(i, 1);
                k--;
                break;
            }
        }
    }

    return number;
}