using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] answers) {
        // 수포자들의 패턴
        int[] p1 = { 1, 2, 3, 4, 5 };
        int[] p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
        int[] p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

        int[] scores = new int[3]; // 0: 1번, 1: 2번, 2: 3번

        for (int i = 0; i < answers.Length; i++)
        {
            if (answers[i] == p1[i % p1.Length]) scores[0]++;
            if (answers[i] == p2[i % p2.Length]) scores[1]++;
            if (answers[i] == p3[i % p3.Length]) scores[2]++;
        }

        // 최고 점수 찾기
        int maxScore = scores[0];
        if (scores[1] > maxScore) maxScore = scores[1];
        if (scores[2] > maxScore) maxScore = scores[2];

        // 최고 점수를 받은 사람들 모으기
        List<int> result = new List<int>();
        for (int i = 0; i < 3; i++)
        {
            if (scores[i] == maxScore)
                result.Add(i + 1); // 사람 번호는 1부터 시작
        }

        return result.ToArray();
    }
}
