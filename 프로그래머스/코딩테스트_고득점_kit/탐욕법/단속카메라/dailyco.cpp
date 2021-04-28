/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42884
블로그 링크 : https://dailyco.github.io/posts/control_camera/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;
    int min = 30000;

    sort(routes.begin(), routes.end());
    for (auto car : routes)
    {
        if (car[0] > min)
        {
            answer++;
            min = car[1];
        }
        else if (car[1] < min)
            min = car[1];
    }

    return answer;
}