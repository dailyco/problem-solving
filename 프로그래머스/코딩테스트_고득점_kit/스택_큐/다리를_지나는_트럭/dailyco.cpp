/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42583
블로그 링크 : https://dailyco.github.io/posts/bridge_truck/
*/

#include <vector>
#include <list>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    list<int> lst(bridge_length, 0);
    int total_weight = 0;
    int answer = 0;

    while (lst.size())
    {
        total_weight -= lst.front();
        lst.pop_front();
        answer++;

        if (truck_weights.size())
        {
            if (truck_weights[0] + total_weight > weight)
            {
                lst.push_back(0);
            }
            else
            {
                lst.push_back(truck_weights[0]);
                total_weight += truck_weights[0];
                truck_weights.erase(truck_weights.begin());
            }
        }
    }

    return answer;
}