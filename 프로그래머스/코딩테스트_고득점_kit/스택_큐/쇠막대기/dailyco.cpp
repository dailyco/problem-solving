/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:15:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42585
블로그 링크 : https://dailyco.github.io/posts/iron_bar/
*/

#include <string>
#include <vector>

using namespace std;

int solution(string arrangement)
{
    int pipe_count = 0;
    int answer = 0;

    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement[i] == '(')
        {
            if (arrangement[i + 1] == ')')
            {
                answer += pipe_count;
                i++;
            }
            else
                pipe_count++;
        }
        else if (arrangement[i] == ')')
        {
            answer++;
            pipe_count--;
        }
    }

    return answer;
}