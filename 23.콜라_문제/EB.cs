using System;

public class Solution {
    public int solution(int a, int b, int n) {      
        int answer = 0;
        while(n >= a){
           int cola = (n/a)*b; //콜라병 받는 수 
           answer += cola;
            
            n = cola +(n%a);    //받은 콜라 + 교환 못한 나머지 콜라 = 현 시점 가지고있는 콜라
        }
        
        return answer;
    }
}
