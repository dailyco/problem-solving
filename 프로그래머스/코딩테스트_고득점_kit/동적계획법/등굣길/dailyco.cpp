/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42898
블로그 링크 : https://dailyco.github.io/posts/way_to-school/
*/

#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> mn(n + 1, vector<int>(m + 1, -1));

    mn[1][1] = 1;
    for (int i = 1; i < m + 1; i++)
        mn[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        mn[i][0] = 0;
    for (auto puddle : puddles)
        mn[puddle[1]][puddle[0]] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (mn[i][j] == -1)
                mn[i][j] = (mn[i - 1][j] + mn[i][j - 1]) % 1000000007;

    return mn[n][m];
}