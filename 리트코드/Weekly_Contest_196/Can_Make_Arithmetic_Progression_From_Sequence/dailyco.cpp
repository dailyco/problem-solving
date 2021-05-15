/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://leetcode.com/contest/weekly-contest-196/problems/can-make-arithmetic-progression-from-sequence/
블로그 링크 : https://dailyco.github.io/posts/equidistant_sequence/
*/

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] != diff)
                return false;
        }

        return true;
    }
};