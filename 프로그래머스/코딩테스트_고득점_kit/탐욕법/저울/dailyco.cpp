/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42886
블로그 링크 : https://dailyco.github.io/posts/balance/
*/

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> weight)
{
    int answer = 0;

    sort(weight.begin(), weight.end());
    for (int i = 0; i < weight.size(); i++)
    {
        if (answer + 1 < weight[i])
            break;
        answer += weight[i];
    }

    return answer + 1;
}