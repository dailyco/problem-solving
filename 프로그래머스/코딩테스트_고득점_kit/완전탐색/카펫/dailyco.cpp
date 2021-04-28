/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:10:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42842
블로그 링크 : https://dailyco.github.io/posts/carpet/
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red)
{
    int len = brown / 2 + 2;
    int w = len - 3;
    int h = 3;

    while (w * h != brown + red)
    {
        h++;
        w--;
    }

    return {w, h};
}