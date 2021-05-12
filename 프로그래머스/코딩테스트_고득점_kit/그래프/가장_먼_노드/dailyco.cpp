/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:50:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49189
블로그 링크 : https://dailyco.github.io/posts/furthest_node/
*/

#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj_lst(n + 1, vector<int>());
    // map<int, set<int>> graph;
    int answer;

    for (auto e : edge)
    {
        adj_lst[e[0]].push_back(e[1]);
        adj_lst[e[1]].push_back(e[0]);
    }

        int cur_size = 1;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int i = q.front();
        q.pop();

        visited[i] = true;
        for (int node : adj_lst[i])
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