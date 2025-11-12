using System;
using System.Linq;

public class Solution {
    public int[] solution(string s) {
        int transformCount = 0; // 변환 횟수
        int removedZeroCount = 0; // 제거된 0의 총 개수

        while (s != "1") {
            transformCount++;

            // 1️⃣ 0 제거
            int zeroCount = s.Count(ch => ch == '0');
            removedZeroCount += zeroCount;

            s = s.Replace("0", ""); // 모든 0 제거

            // 2️⃣ 남은 길이 → 2진 변환
            int len = s.Length;
            s = Convert.ToString(len, 2);
        }

        return new int[] { transformCount, removedZeroCount };
    }
}
