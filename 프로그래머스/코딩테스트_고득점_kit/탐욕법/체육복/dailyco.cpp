/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42862
블로그 링크 : https://dailyco.github.io/posts/gym_suit/
*/

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int wear = n - lost.size();

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                wear++;
                break;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] - 1 == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                wear++;
                break;
            }

            if (lost[i] + 1 == reserve[j])
            {
                lost[i] = -1;
                reserve[j] = -1;
                wear++;
                break;
            }
        }
    }
    return wear;
}