public class Solution {
    public string solution(string s) {
 
        int center = 0;
        string result = "";
        center = s.Length/2;
        if(s.Length%2 == 0){
            result = s.Substring(center-1,2);
        }else{
            result = s.Substring(center,1);
        }
        
        return result;
    }
}
