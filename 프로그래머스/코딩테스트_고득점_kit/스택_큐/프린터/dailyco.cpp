/*
작성자 : dailyco
문제 난이도: 하
해결시간: 02:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42587
블로그 링크 : https://dailyco.github.io/posts/printer/
*/

#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(vector<int> priorities, int location)
{
    list<int> ps(priorities.begin(), priorities.end());
    int p = priorities[location];
    int max;
    int answer = 0;

    max = *max_element(ps.begin(), ps.end());
    while (true)
    {
        int front = ps.front();
        if (max != front)
        {
            ps.pop_front();
            ps.push_back(front);
        }
        else
        {
            ps.pop_front();
            answer++;

            if (location == 0)
                break;
            max = *max_element(ps.begin(), ps.end());
        }

        if (--location < 0)
            location = ps.size() - 1;
    }

    return answer;
}