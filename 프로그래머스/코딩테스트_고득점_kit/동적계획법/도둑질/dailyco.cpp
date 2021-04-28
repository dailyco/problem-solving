/*
작성자 : dailyco
문제 난이도: 상
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42897
블로그 링크 : https://dailyco.github.io/posts/stealing/
*/

#include <vector>

using namespace std;

int solution(vector<int> money)
{
    vector<int> include_first(money.size(), 0);
    vector<int> exclude_first(money.size(), 0);

    include_first[1] = money[0];
    for (int i = 1; i < money.size() - 1; i++)
    {
        if (include_first[i] > money[i] + include_first[i - 1])
            include_first[i + 1] = include_first[i];
        else
            include_first[i + 1] = money[i] + include_first[i - 1];
    }

    for (int i = 1; i < money.size(); i++)
    {
        if (i == 1)
            exclude_first[i] = money[i];
        else if (exclude_first[i - 1] > money[i] + exclude_first[i - 2])
            exclude_first[i] = exclude_first[i - 1];
        else
            exclude_first[i] = money[i] + exclude_first[i - 2];
    }

    return max(include_first[money.size() - 1], exclude_first[money.size() - 1]);
}