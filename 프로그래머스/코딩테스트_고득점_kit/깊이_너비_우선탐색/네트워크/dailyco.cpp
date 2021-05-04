/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43162
블로그 링크 : https://dailyco.github.io/posts/network/
*/

#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adj_list, vector<bool> &visited, int computer)
{
    if (visited[computer])
        return;

    visited[computer] = true;
    int s = adj_list[computer].size();
    for (int i = 0; i < s; i++)
        dfs(adj_list, visited, adj_list[computer][i]);
}

int solution(int n, vector<vector<int>> computers)
{
    vector<vector<int>> adj_list(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && computers[i][j] == 1)
            {
                adj_list[i + 1].push_back(j + 1);
                adj_list[j + 1].push_back(i + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            answer++;
            dfs(adj_list, visited, i);
        }
    }

    return answer;
}