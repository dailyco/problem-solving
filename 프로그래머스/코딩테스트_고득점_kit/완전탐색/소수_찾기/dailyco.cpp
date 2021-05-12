/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42839
블로그 링크 : https://dailyco.github.io/posts/find_prime_number/
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool make_prime(string numbers, int prime_number)
{
    while (prime_number)
    {
        int pos = numbers.find(prime_number % 10 + 48);
        if (pos == -1)
            return false;
        else
        {
            numbers.erase(pos, 1);
            prime_number /= 10;
        }
    }

    return true;
}

bool is_prime(int prime)
{
    int prime_sqrt = sqrt(prime);

    for (int i = 3; i <= prime_sqrt; i++)
        if (prime % i == 0)
            return false;

    return true;
}

int solution(string numbers)
{
    int answer = 0;

    if (numbers.find(50) != -1)
        answer++;
    if (numbers.find(51) != -1)
        answer++;
    for (int i = 6; i <= 9999999; i += 6)
    {
        if (is_prime(i + 1) && make_prime(numbers, i + 1))
            answer++;
        if (is_prime(i - 1) && make_prime(numbers, i - 1))
            answer++;
    }

    return answer;
}