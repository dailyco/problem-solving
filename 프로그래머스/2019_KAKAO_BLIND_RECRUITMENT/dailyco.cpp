/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42889
블로그 링크 : https://dailyco.github.io/posts/failure_rate/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<pair<int, double>> stage_frate;
    vector<int> answer;

    for (int i = 1; i <= N; i++)
    {
        double reach_player = 0;
        double nclear_player = 0;
        for (int j = 0; j < stages.size(); j++)
        {
            if (i <= stages[j])
                reach_player++;
            if (i == stages[j])
                nclear_player++;
        }

        stage_frate.push_back(
            make_pair(i, reach_player == 0 ? 0.0 : nclear_player / reach_player));
    }
    sort(stage_frate.begin(), stage_frate.end(), compare);

    for (auto s_f_pair : stage_frate)
        answer.push_back(s_f_pair.first);

    return answer;
}