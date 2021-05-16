/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:50:00
문제 링크 : https://leetcode.com/contest/weekly-contest-196/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
블로그 링크 : https://dailyco.github.io/posts/smallest_number/
*/

class Solution
{
public:
    string minInteger(string num, int k)
    {
        string answer = "";
        int i = 0;

        string sorted_num = num;
        sort(sorted_num.begin(), sorted_num.end());

        while (k && num != "")
        {
            if (num.find(sorted_num[i]) <= k)
            {
                k -= num.find(sorted_num[i]);
                answer += sorted_num[i];
                num.erase(num.find(sorted_num[i]), 1);
                sorted_num.erase(i, 1);
                i = -1;
            }
            i++;
        }

        answer += num;

        return answer;
    }
};