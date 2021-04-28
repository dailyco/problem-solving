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
    list<int> trucks_on_bridge(bridge_length, 0);
    int total_weight = 0;
    int answer = 0;

    while (trucks_on_bridge.size())
    {
        total_weight -= trucks_on_bridge.front();
        trucks_on_bridge.pop_front();
        answer++;

        if (truck_weights.size())
        {
            if (truck_weights[0] + total_weight > weight)
            {
                trucks_on_bridge.push_back(0);
            }
            else
            {
                trucks_on_bridge.push_back(truck_weights[0]);
                total_weight += truck_weights[0];
                truck_weights.erase(truck_weights.begin());
            }
        }
    }

    return answer;
}