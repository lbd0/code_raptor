using System;

public class Solution {
    public int[,] solution(int[,] arr1, int[,] arr2) {

        int n = arr1.GetLength(0); // arr1 행
        int m = arr1.GetLength(1); // arr1 열 = arr2 행
        int k = arr2.GetLength(1); // arr2 열

        int[,] answer = new int[n, k];

        // 행렬 곱
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int sum = 0;
                for (int t = 0; t < m; t++) {
                    sum += arr1[i, t] * arr2[t, j];
                }
                answer[i, j] = sum;
            }
        }

        return answer;
    }
}
