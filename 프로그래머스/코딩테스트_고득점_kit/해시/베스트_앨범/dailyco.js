/*
작성자 : dailyco
문제 난이도: 중
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42579
블로그 링크 : https://dailyco.github.io/posts/best_album/
*/

function solution(genres, plays) {
  var genrePlay = genres.reduce((acc, cur, i) => {
    acc[cur] = (acc[cur] || 0) + plays[i];
    return acc;
  }, {});

  var genreCount = {};
  return plays
    .map((cur, i) => {
      var obj = {};
      obj.id = i;
      obj.play = cur;
      obj.genrePlay = genrePlay[genres[i]];
      return obj;
    })
    .sort(function (a, b) {
      if (a.genrePlay !== b.genrePlay) return b.genrePlay - a.genrePlay;
      if (a.play !== b.play) return b.play - a.play;
      return a.id - b.id;
    })
    .filter((cur) => {
      if (genreCount[cur.genrePlay] >= 2) return false;
      genreCount[cur.genrePlay] = (genreCount[cur.genrePlay] || 0) + 1;
      return true;
    })
    .map((cur) => cur.id);
}
