using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.Length];
        List<int> hall = new List<int>(); // 명예의 전당 점수들

        for (int i = 0; i < score.Length; i++)
        {
            hall.Add(score[i]);   // 오늘 점수 추가
            hall.Sort();          // 오름차순 정렬

            // 상위 k개만 남기기 (k개 초과하면 가장 낮은 점수 제거)
            if (hall.Count > k)
            {
                hall.RemoveAt(0);
            }

            // hall은 지금 "상위 k개 점수"만 가지고 있고,
            // 그 중 가장 작은 값이 명예의 전당 최하위 점수
            answer[i] = hall[0];
        }

        return answer;
    }
}
