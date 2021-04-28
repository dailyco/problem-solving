/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42840
블로그 링크 : https://dailyco.github.io/posts/mock_test/
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer{1, 2, 3};
    vector<int> first{1, 2, 3, 4, 5};
    vector<int> second{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int one = 0, two = 0, three = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (first[i % first.size()] == answers[i])
            one++;
        if (second[i % second.size()] == answers[i])
            two++;
        if (third[i % third.size()] == answers[i])
            three++;
    }

    if (one < two || one < three)
        answer.erase(answer.begin());
    if (two < one || two < three)
        answer.erase(answer.end() - 2);
    if (three < one || three < two)
        answer.erase(answer.end() - 1);

    return answer;
}