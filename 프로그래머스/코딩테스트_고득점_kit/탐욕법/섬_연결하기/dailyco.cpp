/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42861
블로그 링크 : https://dailyco.github.io/posts/connect_island/
*/

#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs)
{
    set<int> ccosts;
    int answer = 0;

    sort(costs.begin(), costs.end(), compare);
    ccosts.insert(costs[0][0]);
    ccosts.insert(costs[0][1]);
    answer += costs[0][2];

    while (ccosts.size() < n)
    {
        for (int i = 1; i < costs.size(); i++)
        {
            if (ccosts.find(costs[i][0]) != ccosts.end() && ccosts.find(costs[i][1]) != ccosts.end())
                continue;
            if (ccosts.find(costs[i][0]) != ccosts.end() || ccosts.find(costs[i][1]) != ccosts.end())
            {
                ccosts.insert(costs[i][0]);
                ccosts.insert(costs[i][1]);
                answer += costs[i][2];
                costs.erase(costs.begin() + i);
                break;
            }
        }
    }

    return answer;
}
