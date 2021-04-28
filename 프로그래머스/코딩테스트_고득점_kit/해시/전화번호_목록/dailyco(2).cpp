/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:10:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42577
블로그 링크 : https://dailyco.github.io/posts/telephone_directory/
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book)
{
    set<string> phone_numbers;

    for (int i = 0; i < phone_book.size(); i++)
    {
        phone_numbers.insert(phone_book[i]);
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        set<string>::iterator itup = phone_numbers.upper_bound(phone_book[i]);
        if (itup == phone_numbers.end())
            continue;
        if ((*itup).find(phone_book[i]) == 0)
            return false;
    }

    return true;
}