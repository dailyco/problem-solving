/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42629
블로그 링크 : https://dailyco.github.io/posts/noodle_factory/
*/

#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
    priority_queue<int> pq;
    int answer = 0;
    int i = 0;

    while (k - stock > 0)
    {
        while (stock + 1 > dates[i])
        {
            pq.push(supplies[i]);
            i++;
        }

        stock += pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}