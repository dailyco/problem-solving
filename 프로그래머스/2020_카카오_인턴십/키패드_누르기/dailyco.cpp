/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/67256
블로그 링크 : https://dailyco.github.io/posts/push_keypad/
*/

#include <string>
#include <vector>

using namespace std;
const int R = 1, L = 0;

string solution(vector<int> numbers, string hand)
{
    int l_hand = 10, r_hand = 12;
    string answer = "";

    for (int num : numbers)
    {
        switch (num)
        {
        case 1:
        case 4:
        case 7:
            answer += "L";
            l_hand = num;
            break;
        case 3:
        case 6:
        case 9:
            answer += "R";
            r_hand = num;
            break;
        default:
            if (num == 0)
                num += 11;

            int left_dist = abs(num - l_hand);
            int right_dist = abs(num - r_hand);
            left_dist = (left_dist / 3) + (left_dist % 3);
            right_dist = (right_dist / 3) + (right_dist % 3);

            int cur_hand;
            if (left_dist == right_dist)
                cur_hand = hand == "right" ? R : L;
            else if (left_dist < right_dist)
                cur_hand = L;
            else
                cur_hand = R;

            if (cur_hand == R)
            {
                r_hand = num;
                answer += "R";
            }
            else
            {
                l_hand = num;
                answer += "L";
            }
        }
    }

    return answer;
}