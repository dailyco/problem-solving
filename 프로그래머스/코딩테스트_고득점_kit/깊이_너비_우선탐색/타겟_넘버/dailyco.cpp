/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:50:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/43165
블로그 링크 : https://dailyco.github.io/posts/target_number/
*/

#include <string>
#include <vector>

using namespace std;

int find_answer(vector<int> &numbers, int idx, int target, int sum)
{
    if (numbers.size() == idx)
    {
        if (sum == target)
            return 1;
        return 0;
    }
    else
    {
        return find_answer(numbers, idx + 1, target, sum + numbers[idx]) + find_answer(numbers, idx + 1, target, sum - numbers[idx]);
    }
}

int solution(vector<int> numbers, int target)
{
    return find_answer(numbers, 0, target, 0);
}