/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:20:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42578
블로그 링크 : https://dailyco.github.io/posts/camouflage/
*/

function solution(clothes) {
  var obj = {};
  var answer = 1;

  for (let c of clothes) obj[c[1]] = (obj[c[1]] || 0) + 1;

  for (let key in obj) answer *= obj[key] + 1;

  return answer - 1;
}
