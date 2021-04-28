/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:15:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42588
블로그 링크 : https://dailyco.github.io/posts/top/
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer;

    for (int i = heights.size() - 1; i >= 0; i--)
    {
        bool is_insert = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (heights[i] < heights[j])
            {
                is_insert = true;
                answer.insert(answer.begin(), j + 1);
                break;
            }
        }

        if (!is_insert)
            answer.insert(answer.begin(), 0);
    }
    return answer;
}