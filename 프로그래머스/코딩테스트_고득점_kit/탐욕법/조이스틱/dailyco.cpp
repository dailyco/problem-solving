/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42860
블로그 링크 : https://dailyco.github.io/posts/joystick/
*/

#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int idx = 0;
    bool endBack = false;
    int answer = 0;

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != 'A')
        {
            if (name[i] == 78)
                answer += 13;
            else if (name[i] > 78)
                answer += 91 - name[i];
            else
                answer += name[i] - 65;

            if (i - idx > idx + 1)
            {
                endBack = true;
                answer += idx + 1;
            }
            else
                answer += i - idx;
            idx = i;
        }
    }

    if (endBack)
        answer += name.length() - idx - 1;

    return answer;
}