/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:20:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43164
블로그 링크 : https://dailyco.github.io/posts/travel_path/
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool dfs(string from, vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &cAnswer, vector<string> &answer, int cnt)
{
    cAnswer.push_back(from);
    if (cnt == tickets.size())
    {
        answer = cAnswer;
        return true;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == from && visited[i] == false)
        {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, visited, cAnswer, answer, cnt + 1);
            if (success)
                return true;
            visited[i] = false;
        }
    }

    cAnswer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer, temp;
    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visited, temp, answer, 0);

    return answer;
}