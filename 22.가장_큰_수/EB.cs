using System;
using System.Linq;

public class Solution {
    public string solution(int[] numbers) {
        // 1. 숫자들을 문자열 배열로 변환
        string[] arr = numbers.Select(n => n.ToString()).ToArray();

        // 2. 커스텀 정렬: (b + a)와 (a + b)를 비교해서 내림차순 정렬
        Array.Sort(arr, (a, b) => string.Compare(b + a, a + b, StringComparison.Ordinal));

        // 3. 가장 앞이 "0"이면 전부 0이라는 뜻이니 "0" 리턴 (예: [0,0,0])
        if (arr[0] == "0")
            return "0";

        // 4. 이어붙여서 반환
        return string.Join("", arr);
    }
}
//도움
