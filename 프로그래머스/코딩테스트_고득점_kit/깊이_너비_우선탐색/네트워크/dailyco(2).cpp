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

int root[201];
int find(int node)
{
    if (root[node] == node)
        return node;
    return root[node] = find(root[node]);
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = n;
    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && computers[i][j] == 1)
            {
                int r1 = find(i + 1);
                int r2 = find(j + 1);
                if (r1 != r2)
                {
                    answer--;
                    if (r1 > r2)
                        root[i + 1] = root[j + 1];
                    else
                        root[j + 1] = root[i + 1];
                }
            }
        }
    }

    return answer;
}