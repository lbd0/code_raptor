using System.Linq;

public class Solution {
    public int[] solution(int[] arr) {
        int small = arr[0];
        for (int i = 0; i < arr.Length - 1; i++) {
            if (small > arr[i + 1]) {
                small = arr[i + 1];
            }
        }

        arr = arr.Where(x => x != small).ToArray();

       
        if (arr.Length == 0) {
            return new int[] { -1 };
        }

        return arr;
    }
}