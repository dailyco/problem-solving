/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:50:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49189
블로그 링크 : https://dailyco.github.io/posts/furthest_node/
*/

#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    vector<bool> visited(n + 1, false);
    map<int, set<int>> graph;
    queue<int> q;
    int answer;

    for (auto e : edge)
    {
        graph[e[0]].insert(e[1]);
        graph[e[1]].insert(e[0]);
    }

    q.push(1);
    int cur_size = 1;
    while (q.size())
    {
        int i = q.front();
        q.pop();

        visited[i] = true;
        for (int node : graph[i])
        {
            if (visited[node] == false)
            {
                visited[node] = true;
                q.push(node);
            }
        }
        if (--cur_size == 0 && q.size() != 0)
        {
            answer = q.size();
            cur_size = q.size();
        }
    }

    return answer;
}