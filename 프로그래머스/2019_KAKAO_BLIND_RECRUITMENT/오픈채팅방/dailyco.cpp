/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42888
블로그 링크 : https://dailyco.github.io/posts/openchatting/
*/

#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
    map<string, string> uid_name;
    vector<pair<string, string>> result_pair;
    vector<string> answer;

    for (auto r : record)
    {
        istringstream iss(r);
        string s1, s2, s3;

        getline(iss, s1, ' ');
        getline(iss, s2, ' ');
        getline(iss, s3, ' ');

        if (s1 == "Enter")
        {
            uid_name[s2] = s3;
            result_pair.push_back(make_pair(s2, "님이 들어왔습니다."));
        }
        else if (s1 == "Leave")
            result_pair.push_back(make_pair(s2, "님이 나갔습니다."));
        else if (s1 == "Change")
            uid_name[s2] = s3;
    }

    for (auto result : result_pair)
        answer.push_back(uid_name[result.first] + result.second);

    return answer;
}