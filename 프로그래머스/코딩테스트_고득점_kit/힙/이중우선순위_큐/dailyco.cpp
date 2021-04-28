/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42628
블로그 링크 : https://dailyco.github.io/posts/double_priority_queue/
*/

#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int getNum(string str)
{
    int num;
    string str_num = str.substr(2);

    stringstream ssInt(str_num);
    ssInt >> num;

    return num;
}

vector<int> solution(vector<string> operations)
{
    multiset<int> pq;
    vector<int> answer;

    for (string op : operations)
    {
        if (op[0] == 'I')
            pq.insert(getNum(op));
        else if (op[0] == 'D' && pq.size())
        {
            if (op[2] == '-')
                pq.erase(pq.begin());
            else
                pq.erase(--pq.end());
        }
    }

    if (pq.empty())
        return {0, 0};
    return {*--pq.end(), *pq.begin()};
}