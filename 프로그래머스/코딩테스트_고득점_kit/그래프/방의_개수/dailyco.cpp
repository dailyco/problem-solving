/*
작성자 : dailyco
문제 난이도: 상
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/49190
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows)
{
    int cnt = 0;
    map<pair<int, int>, int> vertex_visited;
    map<pair<pair<int, int>, pair<int, int>>, int> edge_visited;

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int x = 0;
    int y = 0;
    vertex_visited[{x, y}] = 1;
    for (int i = 0; i < arrows.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int xpos = x + dx[arrows[i]];
            int ypos = y + dy[arrows[i]];

            if (vertex_visited[{xpos, ypos}] == 1)
            {
                if (edge_visited[{{x, y}, {xpos, ypos}}] == 0 || edge_visited[{{xpos, ypos}, {x, y}}] == 0)
                {
                    cnt++;
                }
            }

            vertex_visited[{xpos, ypos}] = 1;

            edge_visited[{{x, y}, {xpos, ypos}}] = 1;
            edge_visited[{{xpos, ypos}, {x, y}}] = 1;

            x = xpos;
            y = ypos;
        }
    }

    return cnt;
}