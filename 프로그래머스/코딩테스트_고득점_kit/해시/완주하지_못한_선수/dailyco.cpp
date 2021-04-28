/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42576
블로그 링크 : https://dailyco.github.io/posts/uncompleted-player/
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    multiset<string> names;

    for (int i = 0; i < completion.size(); i++)
        names.insert(completion[i]);

    for (int i = 0; i < participant.size(); i++)
    {
        multiset<string>::iterator item = names.find(participant[i]);

        if (item == names.end())
            return participant[i];
        else
            names.erase(item);
    }
}