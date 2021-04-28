/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42885
블로그 링크 : https://dailyco.github.io/posts/lifeboat/
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    for (int i = people.size() - 1, j = 0; i >= j; i--)
    {
        answer++;
        if (i == j)
            break;
        if (people[i] + people[j] <= limit)
            j++;
    }

    return answer;
}