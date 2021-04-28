/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42748
블로그 링크 : https://dailyco.github.io/posts/kth_number/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int a = 0; a < commands.size(); a++)
    {
        vector<int> cpVector;
        int i = commands[a][0];
        int j = commands[a][1];
        int k = commands[a][2];

        cpVector.assign((array.begin() + i - 1), (array.begin() + j));
        sort(cpVector.begin(), cpVector.end());
        answer.push_back(cpVector[k - 1]);
    }

    return answer;
}