/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42577
블로그 링크 : https://dailyco.github.io/posts/telephone_directory/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i + 1].find(phone_book[i]) == 0)
            return false;
    }

    return true;
}