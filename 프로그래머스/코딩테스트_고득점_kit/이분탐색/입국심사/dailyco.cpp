/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43238
블로그 링크 : https://dailyco.github.io/posts/immigration/
*/

#include <vector>

using namespace std;

bool can_check(int n, vector<int> times, long long total_time)
{
    long long total = 0;

    for (int time : times)
        total += total_time / time;

    return n <= total;
}

long long solution(int n, vector<int> times)
{
    long long left = 1, right = 1000000000000000000;
    long long mid = right / 2;

    while (left < right)
    {
        if (can_check(n, times, mid))
        {
            if (!can_check(n, times, mid - 1))
                return mid;
            right = mid;
        }
        else
            left = mid;
        mid = (right + left) / 2;
    }

    return mid;
}