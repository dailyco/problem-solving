/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:10:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42576
블로그 링크 : https://dailyco.github.io/posts/uncompleted-player/
*/

function solution(participant, completion) {
  var s = completion.length;

  participant.sort();
  completion.sort();

  for (let i = 0; i < s; i++)
    if (participant[i] != completion[i]) return participant[i];

  return participant[s];
}
