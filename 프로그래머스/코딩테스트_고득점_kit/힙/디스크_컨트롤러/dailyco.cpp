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
    int disk_count = 0;

    sort(jobs.begin(), jobs.end());
    while (true)
    {
        if (!pq.size() && disk_count < jobs.size())
        {
            ms = jobs[disk_count][0];
            pq.push(make_pair(jobs[disk_count][1], jobs[disk_count][0]));
            disk_count++;
        }

        if (pq.size())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ms += p.first;
            answer += ms - p.second;
            while (disk_count < jobs.size() && ms >= jobs[disk_count][0])
            {
                pq.push(make_pair(jobs[disk_count][1], jobs[disk_count][0]));
                disk_count++;
            }
        }

        if (disk_count == jobs.size() && !pq.size())
            break;
    }

    return answer / disk_count;
}