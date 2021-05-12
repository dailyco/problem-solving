/*
작성자 : dailyco
문제 난이도: 중
해결시간: 01:00:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42579
블로그 링크 : https://dailyco.github.io/posts/best_album/
*/

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, int> genres_count;
    map<int, string> count_genres;
    map<string, vector<pair<int, int>>> genres_musics;
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++)
    {
        genres_count[genres[i]] += plays[i];
        genres_musics[genres[i]].push_back(make_pair(i, plays[i]));
    }

    for (auto it = genres_count.begin(); it != genres_count.end(); it++)
        count_genres[it->second] = it->first;

    for (auto it = genres_musics.begin(); it != genres_musics.end(); it++)
        sort(it->second.begin(), it->second.end(), compare);

    for (auto it = count_genres.rbegin(); it != count_genres.rend(); it++)
    {
        answer.push_back(genres_musics[it->second][0].first);
        if (genres_musics[it->second].size() > 1)
            answer.push_back(genres_musics[it->second][1].first);
    }

    return answer;
}