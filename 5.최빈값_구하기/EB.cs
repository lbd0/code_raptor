using System;

public class Solution {
    public int solution(int[] array) {
        int maxFrequency = 0;         // 최빈값의 빈도 수
        int modeValue = 0;            // 최빈값(가장 자주 등장한 숫자)
        int[] frequency;              // 숫자별 등장 횟수 저장용 배열
       
        int maxNumber = 0;            // 입력 배열에서 가장 큰 숫자 찾기
        for (int i = 0; i < array.Length; i++) {
            if (maxNumber < array[i]) {
                maxNumber = array[i];
            }
        }

        frequency = new int[maxNumber + 1];  // 숫자별 빈도 수 저장용 배열 생성
   
        for (int i = 0; i < array.Length; i++) {
            int number = array[i];
            frequency[number] += 1;
        }

        bool hasDuplicateMode = false;  // 최빈값 중복 여부 체크
        int mostFrequentNumber = 0;     // 최빈값 후보 저장

        //최빈값 찾기
        for (int i = 0; i < frequency.Length; i++) {
            if (frequency[i] > maxFrequency) {
                maxFrequency = frequency[i];
                mostFrequentNumber = i;
            }
        }

        // 최빈값이 여러 개 있는지 확인
        for (int i = 0; i < frequency.Length; i++) {
            if (mostFrequentNumber != i && frequency[i] == maxFrequency) {
                hasDuplicateMode = true;
            }
        }

        return hasDuplicateMode ? -1 : mostFrequentNumber;
    }
}