/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:40:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/67257
블로그 링크 : https://dailyco.github.io/posts/formula_maximization/
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

void strtok_s(string str, string delimeter, vector<long long> &numbers, vector<char> &ops)
{
    long long number;
    string num = "";
    for (char c : str)
    {
        bool is_delimit = false;
        for (char d : delimeter)
        {
            if (c == d)
            {
                ops.push_back(d);
                istringstream(num) >> number;
                numbers.push_back(number);
                num = "";
                is_delimit = true;
                break;
            }
        }
        if (!is_delimit)
            num += c;
    }
    istringstream(num) >> number;
    numbers.push_back(number);
}

void Permutation(vector<vector<char>> &op_priorities, vector<char> &ops, int start, int end)
{
    if (start == end)
        op_priorities.push_back(ops);
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(ops[start], ops[i]);
            Permutation(op_priorities, ops, start + 1, end);
            swap(ops[start], ops[i]);
        }
    }
}

long long solution(string expression)
{
    vector<vector<char>> op_priorities;
    vector<char> ops;
    vector<long long> nums;
    long long answer = 0;

    strtok_s(expression, "*+-", nums, ops);
    vector<char> operands_kind(ops);

    for (int i = 0; i < operands_kind.size() - 1; i++)
    {
        for (int j = i + 1; j < operands_kind.size(); j++)
        {
            if (operands_kind[i] == operands_kind[j])
            {
                operands_kind.erase(operands_kind.begin() + j);
                j--;
            }
        }
    }

    Permutation(op_priorities, operands_kind, 0, 2);

    for (auto op_priority : op_priorities)
    {
        vector<long long> cp_nums(nums);
        vector<char> cp_ops(ops);
        for (char p : op_priority)
        {
            for (int i = 0; i < cp_ops.size(); i++)
            {
                if (cp_ops[i] == p)
                {
                    switch (p)
                    {
                    case '*':
                        cp_nums[i] *= cp_nums[i + 1];
                        break;
                    case '+':
                        cp_nums[i] += cp_nums[i + 1];
                        break;
                    case '-':
                        cp_nums[i] -= cp_nums[i + 1];
                        break;
                    default:
                        break;
                    }
                    cp_ops.erase(cp_ops.begin() + i);
                    cp_nums.erase(cp_nums.begin() + i + 1);
                    i--;
                }
            }
        }
        if (abs(cp_nums[0]) > answer)
            answer = abs(cp_nums[0]);
    }

    return answer;
}