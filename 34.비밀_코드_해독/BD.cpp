#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    // 모든 조합 찾아서 적용해 보기.
    for(int i=1; i<=n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
            for(int k=j+1; k<=n; ++k)
            {
                for(int l=k+1; l<=n; ++l)
                {
                    for(int m=l+1; m<=n; ++m)
                    {
                        bool present[101] = {false};
                        present[i] = present[j] = present[k] = present[l] = present[m] = true;
                        
                        int idx = 0;
                        for(idx=0; idx<q.size(); ++idx)
                        {
                            int cnt = 0;
                            
                            for(int x:q[idx])
                            {
                                if(present[x]) cnt++;
                            }
                            
                            if(cnt != ans[idx]) break;
                        }
                        
                        if(idx == q.size()) answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}
