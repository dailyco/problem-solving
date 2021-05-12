/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43236
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    int left = 1, right = distance, mid = 0;
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    while (left <= right)
    {
        int rm_rocks = 0;
        int prev = 0;

        mid = (left + right) / 2;
        for (int i = 0; i < rocks.size(); i++)
        {
            if (rocks[i] - prev < mid)
                rm_rocks++;
            else
                prev = rocks[i];
        }

        if (rm_rocks > n)
            right = mid - 1;
        else
        {
            answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}