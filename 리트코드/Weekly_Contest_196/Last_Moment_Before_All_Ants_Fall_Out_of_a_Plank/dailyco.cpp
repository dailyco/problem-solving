/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://leetcode.com/contest/weekly-contest-196/problems/last-moment-before-all-ants-fall-out-of-a-plank/
블로그 링크 : https://dailyco.github.io/posts/falling_ant_from_plank/
*/

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int answer = 0;

        sort(left.begin(), left.end(), greater<int>());
        sort(right.begin(), right.end());

        if (left.size() != 0 && left.back() == 0)
            left.pop_back();
        if (right.size() != 0 && right.back() == n)
            right.pop_back();
        while (left.size() != 0 && right.size() != 0)
        {
            answer++;
            for (int i = 0; i < left.size(); i++)
                left[i]--;
            for (int i = 0; i < right.size(); i++)
                right[i]++;
            if (left.back() == 0)
                left.pop_back();
            if (right.back() == n)
                right.pop_back();
        }

        if (left.size() != 0)
            answer += left.front();
        else if (right.size() != 0)
            answer += n - right.front();

        return answer;
    }
};