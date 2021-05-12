/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42626
블로그 링크 : https://dailyco.github.io/posts/spicier/
*/

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    make_heap(scoville.begin(), scoville.end(), greater<int>());

    while (scoville.front() < K && scoville.size() >= 2)
    {
        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        int smallest1 = scoville.back();
        scoville.pop_back();

        pop_heap(scoville.begin(), scoville.end(), greater<int>());
        int smallest2 = scoville.back();
        scoville.pop_back();

        scoville.push_back(smallest1 + smallest2 * 2);
        push_heap(scoville.begin(), scoville.end(), greater<int>());

        answer++;
    }

    if (scoville.back() < K)
        return -1;
    return answer;
}