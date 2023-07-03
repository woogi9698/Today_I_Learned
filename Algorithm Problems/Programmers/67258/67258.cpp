#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int inline getLen(int start, int end);
    
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    // [Squeeze Name Data]
    // 모든 보석의 이름을 key로 가지는 Hash Map "gemInfo" 생성
    unordered_map<string, int> gemInfo;
    for (int i=0; i<gems.size(); i++) {
        gemInfo[gems[i]] = 0;
    }
    
    int start = 0;
    int end = gems.size() - 1;
    int len = getLen(start, end);
    
    int cnt_gemkind = 0;
    int idx_start = -1;
    int idx_end = 0;
    
    // [Init : Find reasonable start point]
    // 모든 보석을 1개 이상 가지는 첫 구간 [idx_start = 0, idx_end] 탐색
    while(cnt_gemkind < gemInfo.size()) {
        if (gemInfo[gems[idx_end]] == 0) cnt_gemkind ++;
        gemInfo[gems[idx_end]] ++;
        idx_end ++;
    }
    idx_end --;
    
    // [Main Code : Two Pointer]
    while(idx_end < gems.size()) {
        // [idx_start] 특정 보석의 개수가 0개가 될 때 까지 idx_start를 뒤로 이동
        while(idx_start <= idx_end) {          
            idx_start ++;
            if(idx_end == gems.size()) break;
            
            gemInfo[gems[idx_start]] --;            
            if (gemInfo[gems[idx_start]] == 0) break;
        }
        // [idx_start, idx_end]의 길이가 기존에 알고 있던 최소길이보다 짧으면 정보 갱신
        int len_now = getLen(idx_start, idx_end);
        if (len > len_now) {
            len = len_now;
            start = idx_start;
            end = idx_end;
        }
        
        // [idx_end] 특정 보석의 개수가 0에서 1로 바뀔 때 까지 idx_end를 뒤로 이동
        while(idx_end < gems.size()) {
            idx_end ++;            
            if(idx_end == gems.size()) break;
            
            gemInfo[gems[idx_end]] ++;            
            if (gemInfo[gems[idx_end]] == 1) break;
        }
        
    }
    
    answer.push_back(start + 1);
    answer.push_back(end + 1);
    
    return answer;
}

int inline getLen(int start, int end) {
    return end - start + 1;
}