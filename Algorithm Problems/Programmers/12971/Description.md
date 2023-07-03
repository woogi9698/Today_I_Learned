## Strategy
* 어떤 인덱스 idx에 대해서 idx 위치에 있는 스티커를 찢을 경우의 최댓값을 구한다

## Used Data Structure
* None

## Used Algorithm
* Dynamic Programming
    * What is Dynamic Programming?
        * Here Will be linked soon.
    * Code Usage
        ```cpp
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
        ```

## Someting Missed
* sticker 배열의 길이가 1일 경우 두 개 케이스로 나누는 전략의 코드가 전혀 작동하지 않음
    * Current Code
        ```cpp
        int solution(vector<int> sticker)
        {
            // 길이가 1인 경우 최댓값 : 그 스티커
            int answer = sticker[0];

            // [0, 마지막 인덱스 - 1] 까지에서의 최댓값 DP 
            answer = dp_max(sticker, 0, sticker.size() - 2);
        // 후략
        }
        ```
    * Past Code
        ```cpp
        int solution(vector<int> sticker)
        {
            int answer = 0;

            // [0, 마지막 인덱스 - 1] 까지에서의 최댓값 DP 
            answer = dp_max(sticker, 0, sticker.size() - 2);
        // 후략
        }
        ```

## Code Visibility Improvement
* None

## 맺으며
* Boundary Case에 대한 고려 습관화