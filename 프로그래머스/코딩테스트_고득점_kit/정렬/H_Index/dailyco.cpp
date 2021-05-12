/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42747
블로그 링크 : https://dailyco.github.io/posts/h_index/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
        if (i + 1 > citations[i])
            return i;

    return citations.size();
}