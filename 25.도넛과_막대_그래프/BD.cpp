#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://school.programmers.co.kr/questions/71669 요기 참고했어요 ㅎㅎ

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    // 노드별 팬인, 팬아웃 개수 저장할 map.
    unordered_map<int, int> in, out;
    // 정점 저장할 set.
    unordered_set<int> nodes;
    
    // 정점 저장 및 노드별 팬인, 팬아웃 개수 저장.
    for(auto& e:edges)
    {
        in[e[0]];   // 0
        out[e[0]]++;
        in[e[1]]++;
        out[e[1]];  // 0
        
        nodes.insert(e[0]);
        nodes.insert(e[1]);
    }
    
    // 구해야 하는 것들.
    int line = 0, eight = 0, dou = 0, ver = 0;
    
    for(auto& n:nodes)
    {
        // 막대 그래프는 마지막 노드의 팬아웃이 0이 됨.
        if(out[n] == 0) line++;
        
        // 팬아웃이 2이면 8자 그래프일 수도 있고, 생성한 정점일 수도 있음.
        if(out[n] == 2)
        {
            // 8자 그래프는 팬인이 무조건 있음.
            if(in[n] > 0) eight++;
            else ver = n;
        }
        
        // 팬아웃이 2이상이면 생성한 정점임.
        if(out[n] > 2) ver = n;
    }
    
    // out[ver]는 생성한 정점에서 그래프가 뻗어나간 개수.
    // 그 중에 막대 그래프가 아니고, 8자 그래프가 아니면 도넛 그래프임.
    dou = out[ver] - line - eight;
    
    return {ver, dou, line, eight};
}
