/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:50:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49191
블로그 링크 : https://dailyco.github.io/posts/ranking/
*/

#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1, false));

    for (vector<int> r : results)
        win[r[0]][r[1]] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (win[j][i] && win[i][k])
                    win[j][k] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (win[i][j] || win[j][i])
                cnt++;
        }

        if (cnt == n - 1)
            answer++;
    }

    return answer;
}