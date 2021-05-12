/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:50:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49191
블로그 링크 : https://dailyco.github.io/posts/ranking/
*/

#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    map<int, set<int>> win;
    map<int, set<int>> defeat;
    int answer = 0;

    for (auto result : results)
    {
        win[result[0]].insert(result[1]);
        defeat[result[1]].insert(result[0]);
    }

    int count = n;
    while (--count)
    {
        for (int i = 1; i <= n; i++)
        {
            for (auto loser : win[i])
                win[i].insert(win[loser].begin(), win[loser].end());

            for (auto winner : defeat[i])
                defeat[i].insert(defeat[winner].begin(), defeat[winner].end());
        }
    }

    for (int i = 1; i <= n; i++)
        if (win[i].size() + defeat[i].size() == n - 1)
            answer++;

    return answer;
}