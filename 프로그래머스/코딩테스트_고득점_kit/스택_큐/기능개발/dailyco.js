/*
작성자 : dailyco
문제 난이도: 하
해결시간: 00:20:00
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/42586
블로그 링크 : https://dailyco.github.io/posts/feature_development/
*/

function solution(progresses, speeds) {
  var answer = [];
  var deployDay = Math.ceil((100 - progresses.shift()) / speeds.shift());
  var workCount = 1;

  while (progresses.length) {
    var workDay = Math.ceil((100 - progresses.shift()) / speeds.shift());
    if (deployDay >= workDay) workCount++;
    else {
      answer.push(workCount);
      deployDay = workDay;
      workCount = 1;
    }
  }
  answer.push(workCount);
  return answer;
}
