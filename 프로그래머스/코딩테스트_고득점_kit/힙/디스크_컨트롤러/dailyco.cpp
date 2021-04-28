/*
작성자 : dailyco
문제 난이도: 중
해결시간: 02:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42627
블로그 링크 : https://dailyco.github.io/posts/disk_controler/
*/

#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int answer = 0;
    int ms = 0;
    int i = 0;

    sort(jobs.begin(), jobs.end());
    while (true)
    {
        if (!pq.size() && i < jobs.size())
        {
            ms = jobs[i][0];
            pq.push(make_pair(jobs[i][1], jobs[i][0]));
            i++;
        }

        if (pq.size())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ms += p.first;
            answer += ms - p.second;
            while (i < jobs.size() && ms >= jobs[i][0])
            {
                pq.push(make_pair(jobs[i][1], jobs[i][0]));
                i++;
            }
        }

        if (i == jobs.size() && !pq.size())
            break;
    }

    return answer / i;
}