using System;
using System.Text;

public class Solution {
    public string solution(int[] food) {
        StringBuilder left = new StringBuilder();

        // 왼쪽 부분 구성
        for (int i = 1; i < food.Length; i++) {
            int count = food[i] / 2; // 절반만 사용
            for (int j = 0; j < count; j++) {
                left.Append(i);
            }
        }

        // 전체 문자열 = 왼쪽 + 0 + (왼쪽 뒤집은 것)
        string leftStr = left.ToString();
        char[] rev = leftStr.ToCharArray();
        Array.Reverse(rev);
        string rightStr = new string(rev);

        return leftStr + "0" + rightStr;
    }
}
