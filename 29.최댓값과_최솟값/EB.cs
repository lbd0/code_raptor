using System;

public class Solution {
    public string solution(string s) {

        string[] arr = s.Split(' ');  // 공백 기준 split

        int min = int.MaxValue;
        int max = int.MinValue;

        for (int i = 0; i < arr.Length; i++) {
            int num = int.Parse(arr[i]);  // 문자열 → 숫자 변환

            if (num < min) min = num;
            if (num > max) max = num;
        }

        return min + " " + max;  // "최솟값 최댓값"
    }
}
