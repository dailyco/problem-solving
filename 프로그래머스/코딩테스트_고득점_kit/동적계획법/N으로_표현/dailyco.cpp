/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42895
블로그 링크 : https://dailyco.github.io/posts/express_with_N/
*/

#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(int N, int number)
{
    map<int, set<int>> c_values;
    int answer = 9;

    int n = 0;
    for (int i = 1; i <= 8; i++)
    {
        n = n * 10 + N;
        if (n == number)
            return i;
        c_values[i].insert(n);
    }

    c_values[1].insert(N);
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            if (i + j > 8)
                break;
            for (auto a = c_values[i].begin(); a != c_values[i].end(); a++)
            {
                for (auto b = c_values[j].begin(); b != c_values[j].end(); b++)
                {
                    if (*a + *b == number || *a - *b == number || *a * *b == number || (*b != 0 && *a / *b == number))
                    {
                        if (i + j < answer)
                            answer = i + j;
                    }
                    c_values[i + j].insert(*a + *b);
                    c_values[i + j].insert(*a - *b);
                    c_values[i + j].insert(*a * *b);
                    if (*b != 0)
                        c_values[i + j].insert(*a / *b);
                }
            }
        }
    }

    return answer == 9 ? -1 : answer;
}