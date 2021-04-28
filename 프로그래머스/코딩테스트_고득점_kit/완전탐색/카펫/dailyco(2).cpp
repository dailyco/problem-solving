/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42842
블로그 링크 : https://dailyco.github.io/posts/carpet/
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int red)
{
    for (int i = 1; i <= sqrt(2000000); i++)
    {
        int pow_num = pow(i, 2);

        if (pow_num == red)
        {
            if (brown == (pow((i + 2), 2) - red))
                return {i + 2, i + 2};
        }
        else if (pow_num >= red)
        {
            int sqrt_num = i - 1;

            while (1)
            {
                while (red % sqrt_num != 0)
                    sqrt_num--;
                if (brown == ((sqrt_num + 2) * ((red / sqrt_num) + 2) - red))
                    return {(red / sqrt_num) + 2, sqrt_num + 2};
                else
                    sqrt_num--;
            }
        }
    }
}