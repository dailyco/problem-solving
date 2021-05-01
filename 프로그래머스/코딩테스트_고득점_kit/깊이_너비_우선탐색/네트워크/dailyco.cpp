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
vector<vector<int>> network_board;

void dfs(int i, int j, int n)
{
    network_board[i][j] = 0;
    for (int k = 0; k < n; k++)
        if (network_board[j][k] == 1)
            dfs(j, k, n);
}

int solution(int n, vector<vector<int>> computers)
{
    network_board = computers;
    int answer = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (network_board[i][j] == 1)
            {
                answer++;
                dfs(i, j, n);
            }

    return answer;
}