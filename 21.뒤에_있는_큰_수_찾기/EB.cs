using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] numbers) {
        int n = numbers.Length;
        int[] answer = new int[n];
        Array.Fill(answer, -1);           // 기본값 -1

        Stack<int> st = new Stack<int>(); // 인덱스를 담는 스택(단조 감소)

        for (int i = 0; i < n; i++) {
            // 현재 numbers[i]가 스택 꼭대기 인덱스의 값보다 크면,
            // 그 인덱스의 "다음 큰 수"가 현재 값임
            while (st.Count > 0 && numbers[st.Peek()] < numbers[i]) {
                int idx = st.Pop();
                answer[idx] = numbers[i];
            }
            st.Push(i);
        }

        // 스택에 남은 인덱스는 뒤에 더 큰 수가 없어서 -1 유지
        return answer;
    }
}



// using System;

// public class Solution {
//     public int[] solution(int[] numbers) {
//         int[] result = new int[numbers.Length];
        
//         result[numbers.Length-1] = -1;
//         for(int i = 0; i < numbers.Length-1 ; i++){
          
//            if(numbers[i] < numbers[i+1]) {result[i] = numbers[i+1];continue;}
//             else{
//                 result[i] = -1;
//                 int j = 2;
                
//                 while(i+j < numbers.Length){
//                     if(numbers[i] < numbers[i+j]){
//                         result[i] = numbers[i+j];                    
//                         break;
//                     }                    
//                     j++;                   
//                  }
//                 continue;
//             }
//         }
//         return result;
    
        
//     }
// }
