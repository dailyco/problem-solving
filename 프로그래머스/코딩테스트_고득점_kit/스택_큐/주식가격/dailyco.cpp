/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:25:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42584
블로그 링크 : https://dailyco.github.io/posts/stock_price/
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        int p = prices[i];
        int count = 0;

        for (int j = i; p <= prices[j] && j < prices.size() - 1; j++)
            count++;

        answer.push_back(count);
    }

    return answer;
}