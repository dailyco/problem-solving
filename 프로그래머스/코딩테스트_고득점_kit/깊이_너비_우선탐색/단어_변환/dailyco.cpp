/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43163
블로그 링크 : https://dailyco.github.io/posts/word_conversion/
*/

#include <string>
#include <vector>

using namespace std;

bool canChange(string prev, string next)
{
    bool diff = false;

    for (int i = 0; i < prev.length(); i++)
    {
        if (prev[i] != next[i])
        {
            if (diff)
                return false;
            else
                diff = true;
        }
    }

    return true;
}

int dfs(string begin, string target, vector<string> words)
{
    if (canChange(begin, target))
        return 1;

    int cAnswer, answer = 50;
    for (int i = 0; i < words.size(); i++)
    {
        if (canChange(begin, words[i]))
        {
            vector<string> words_cp = words;
            words_cp.erase(words_cp.begin() + i);
            cAnswer = dfs(words[i], target, words_cp);
            if (cAnswer != 0 && answer > cAnswer + 1)
                answer = cAnswer + 1;
        }
    }

    if (answer == 50)
        return 0;
    return answer;
}

int solution(string begin, string target, vector<string> words)
{
    return dfs(begin, target, words);
}