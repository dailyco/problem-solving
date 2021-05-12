/*
작성자 : dailyco
문제 난이도: 하
해결시간: 01:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42746
블로그 링크 : https://dailyco.github.io/posts/largest_number/
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
    string a = to_string(i);
    string b = to_string(j);

    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);
    for (auto n : numbers)
        answer += to_string(n);

    if (answer.at(0) == '0')
        return "0";
    return answer;
}