/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43105
블로그 링크 : https://dailyco.github.io/posts/integer_triangle/
*/

#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    for (int i = triangle.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (triangle[i][j] + triangle[i + 1][j] >= triangle[i][j] + triangle[i + 1][j + 1])
                triangle[i][j] += triangle[i + 1][j];
            else
                triangle[i][j] += triangle[i + 1][j + 1];
        }
    }

    return triangle[0][0];
}