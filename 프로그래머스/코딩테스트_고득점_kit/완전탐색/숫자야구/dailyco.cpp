/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42841
블로그 링크 : https://dailyco.github.io/posts/numerical_baseball/
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball)
{
    int answer = 0;

    for (int i = 123; i < 988; i++)
    {
        bool is_answer = true;
        string num = to_string(i);

        if (num.find('0') != -1)
            continue;
        if (num[0] == num[1] || num[0] == num[2] || num[1] == num[2])
            continue;

        for (auto j : baseball)
        {
            string baseball_num = to_string(j[0]);
            int strike = 0, ball = 0;

            if (num[0] == baseball_num[0])
                strike++;
            if (num[1] == baseball_num[1])
                strike++;
            if (num[2] == baseball_num[2])
                strike++;

            if (baseball_num.find(num[0]) != -1)
                ball++;
            if (baseball_num.find(num[1]) != -1)
                ball++;
            if (baseball_num.find(num[2]) != -1)
                ball++;

            ball -= strike;

            if (j[1] != strike || j[2] != ball)
                is_answer = false;
        }

        if (is_answer)
            answer++;
    }

    return answer;
}