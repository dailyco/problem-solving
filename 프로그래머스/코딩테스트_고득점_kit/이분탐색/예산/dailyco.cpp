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

bool is_ceiling(vector<int> budgets, int M, int ceiling)
{
    int total = 0;
    for (int budget : budgets)
    {
        if (budget > ceiling)
            total += ceiling;
        else
            total += budget;
    }

    return total > M ? false : true;
}

int solution(vector<int> budgets, int M)
{
    int left = 1, right = 100000;
    int mid = right / 2;
    int max = *max_element(budgets.begin(), budgets.end());

    while (left < right)
    {
        if (is_ceiling(budgets, M, mid))
        {
            if (mid >= max)
                return max;
            if (!is_ceiling(budgets, M, mid + 1))
                return mid;
            left = mid;
        }
        else
            right = mid;
        mid = (left + right) / 2;
    }

    return 0;
}