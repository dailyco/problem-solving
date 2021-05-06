/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43163
블로그 링크 : https://dailyco.github.io/posts/word_conversion/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 50;

bool IsChangeable(string from, string to)
{
    bool diff = false;

    for (int i = 0; i < from.length(); i++)
    {
        if (from[i] != to[i])
        {
            if (diff)
                return false;
            diff = true;
        }
    }

    return true;
}

int ChangeNumber(string from, string to, vector<string> &words, vector<bool> &used, int count)
{
    if (IsChangeable(from, to))
        return count + 1;

    for (int i = 0; i < words.size(); i++)
    {
        if (!used[i] && IsChangeable(from, words[i]))
        {
            used[i] = true;
            int c_answer = ChangeNumber(words[i], to, words, used, count + 1);
            if (c_answer != 0 && answer > c_answer)
                answer = c_answer;
            used[i] = false;
        }
    }

    return answer;
}

int solution(string begin, string target, vector<string> words)
{
    vector<bool> used(words.size(), false);

    if (find(words.begin(), words.end(), target) == words.end())
        return 0;

    return ChangeNumber(begin, target, words, used, 0);
}