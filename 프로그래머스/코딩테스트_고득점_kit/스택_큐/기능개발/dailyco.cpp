/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:20:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
블로그 링크 : https://dailyco.github.io/posts/feature_development/
*/

#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    while (speeds.size())
    {
        int count = 1;
        int day = ceil((100 - progresses[0]) / (double)speeds[0]);

        progresses.erase(progresses.begin());
        speeds.erase(speeds.begin());

        while (speeds.size() && day >= ceil((100 - progresses[0]) / (double)speeds[0]))
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            count++;
        }

        answer.push_back(count);
    }

    return answer;
}