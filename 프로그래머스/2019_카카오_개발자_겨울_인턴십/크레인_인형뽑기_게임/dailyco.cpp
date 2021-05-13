/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/64061
블로그 링크 : https://dailyco.github.io/posts/crane-machine_game/
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    vector<stack<int>> board_stack;
    int N = board.size();
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        stack<int> s;
        for (int j = N - 1; j >= 0; j--)
            if (board[j][i] != 0)
                s.push(board[j][i]);
        board_stack.push_back(s);
    }

    stack<int> basket;
    basket.push(-1);
    for (int idx : moves)
    {
        idx--;
        if (board_stack[idx].empty())
            continue;
        if (board_stack[idx].top() == basket.top())
        {
            answer += 2;
            board_stack[idx].pop();
            basket.pop();
        }
        else
        {
            basket.push(board_stack[idx].top());
            board_stack[idx].pop();
        }
    }

    return answer;
}