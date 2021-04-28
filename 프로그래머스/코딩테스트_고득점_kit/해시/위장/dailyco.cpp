/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:20:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42578
블로그 링크 : https://dailyco.github.io/posts/camouflage/
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, vector<string>> clothes_map;
    int answer = 1;

    for (int i = 0; i < clothes.size(); i++)
        clothes_map[clothes[i][1]].push_back(clothes[i][0]);

    for (auto it = clothes_map.begin(); it != clothes_map.end(); it++)
        answer *= (it->second).size() + 1;

    return answer - 1;
}