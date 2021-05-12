/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:30:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42587
블로그 링크 : https://dailyco.github.io/posts/printer/
*/

function solution(priorities, location) {
  var answer = 0;

  while (priorities.length) {
    var J = priorities.shift();
    var isPrint = true;
    for (let i = 0; i < priorities.length; i++) {
      if (J < priorities[i]) {
        isPrint = false;
        break;
      }
    }

    if (isPrint) {
      answer++;
      if (location === 0) return answer;
      else location--;
    } else {
      if (location === 0) location = priorities.length;
      else location--;
      priorities.push(J);
    }
  }

  return answer;
}
