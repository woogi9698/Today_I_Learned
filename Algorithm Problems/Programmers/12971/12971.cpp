#include <iostream>
#include <vector>
using namespace std;

int dp_max(vector<int> sticker, int start, int end);

int solution(vector<int> sticker)
{
    // 길이가 1인 경우 최댓값 : 그 스티커
    int answer = sticker[0];

    // [0, 마지막 인덱스 - 1] 까지에서의 최댓값 DP 
    answer = dp_max(sticker, 0, sticker.size() - 2);
    
    int score_idx0 = sticker[0]; sticker[0] = 0;
    // [1, 마지막 인덱스] 까지에서의 최댓값 DP
    int temp = dp_max(sticker, 1, sticker.size() - 1);
    sticker[0] = score_idx0;
    
    answer = (answer > temp) ? answer : temp;

    return answer;
}

int dp_max(vector<int> sticker, int start, int end) {
    int ret = 0;
    
    int max_m2 = 0;
    int max_m3 = 0;
    
     for (int i = start; i <= end; i++) {
        max_m2 = max_m3 = sticker[i];
        
        if (i - 2 >= 0) max_m2 += sticker[i - 2];
        if (i - 3 >= 0) max_m3 += sticker[i - 3];
        
        if (max_m2 > max_m3) sticker[i] = max_m2;
        else sticker[i] = max_m3;

    }
    
    ret = sticker[end];
    ret = (sticker[end - 1] > ret) ? sticker[end - 1] : ret;
    
    return ret;
}