/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43237
블로그 링크 : https://dailyco.github.io/posts/buget/
*/

#include <algorithm>
#include <vector>

using namespace std;

bool IsCeiling(vector<int> &budgets, int M, int ceiling)
{
    int total = 0;
    for (int budget : budgets)
    {
        if (budget > ceiling)
            total += ceiling;
        else
            total += budget;
    }

    return total <= M;
}

int solution(vector<int> budgets, int M)
{
    int left = 1, right = 1e5, mid, answer;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (IsCeiling(budgets, M, mid))
        {
            left = mid + 1;
            answer = mid;
        }
        else
            right = mid - 1;

        return answer;
    }
}