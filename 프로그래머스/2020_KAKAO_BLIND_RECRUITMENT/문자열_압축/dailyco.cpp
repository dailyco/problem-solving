/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60057
블로그 링크 : https://dailyco.github.io/posts/string_compression/
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = s.length();

    for (int i = 1; i < s.length() / 2 + 1; i++)
    {
        vector<string> string_set;

        for (int j = 0; j + i - 1 < s.length(); j += i)
            string_set.push_back(s.substr(j, i));
        string_set.push_back("");

        int length = s.length() % i;
        int count = 1;
        for (int j = 1; j < string_set.size(); j++)
        {
            if (string_set[j - 1] == string_set[j])
                count++;
            else if (count > 1)
            {
                length += i + to_string(count).length();
                count = 1;
            }
            else
                length += i;
        }

        if (length < answer)
            answer = length;
    }

    return answer;
}