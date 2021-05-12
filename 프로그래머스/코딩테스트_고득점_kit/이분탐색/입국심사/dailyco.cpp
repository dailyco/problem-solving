/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43238
블로그 링크 : https://dailyco.github.io/posts/immigration/
*/

#include <vector>

using namespace std;

bool IsChecked(int n, vector<int> &times, long long total_time)
{
    long long total = 0;

    for (int time : times)
        total += total_time / time;

    return n <= total;
}

long long solution(int n, vector<int> times)
{
    long long min_m = 1, max_m = 1e9 * n, mid;
    long long answer = 1e18;

    while (min_m <= max_m)
    {
        mid = (min_m + max_m) / 2;

        if (IsChecked(n, times, mid))
        {
            max_m = mid - 1;
            if (answer > mid)
                answer = mid;
        }
        else
            min_m = mid + 1;
    }

    return answer;
}