## Strategy
* **보석 종류**의 수를 센다
  * **Hash Map**(Unordered Map) Structure사용
* 어떠한 **인덱스 a 부터 보석을 담을 때, a보다 큰 어떠한 인덱스 b 까지 담아야만 한다**고 할 때 **인덱스 b의 가장 작은 값**을 구한다
  * **Two Pointer** Algorithm사용

## Used Data Structure
* Hash Map
    * What is Hash Map?
      * Here Will be linked soon.
    * Code Usage
        ```cpp
        #include <unordered_map>        // Need this header

        unordered_map<string, int> gemInfo;
        for (int i=0; i<gems.size(); i++) {
            gemInfo[gems[i]] = 0;
        }
        ```

## Used Algorithm
* Two Pointer
    * What is Two Pointer Algorithm?
        * Here Will be linked soon.
    * Code Usage
        ```cpp
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
        ```

## Someting Missed
* None

## Code Visibility Improvement
* 왼쪽 포인터의 탐색
    * Current Code
        ```cpp
        // initial condition : idx_start = 0; -- Wrong
        while(idx_start <= idx_end) {          
            idx_start ++;
            if(idx_end == gems.size()) break;
            
            gemInfo[gems[idx_start]] --;            
            if (gemInfo[gems[idx_start]] == 0) break;   // gems[idx_start] 부터 gems[end] 까지 담음
        }

        int len_now = getLen(idx_start, idx_end);
        if (len > len_now) {
            len = len_now;
            start = idx_start;
            end = idx_end;
        }
        ```
    * Past Code
        ```cpp
        // initial condition : idx_start = -1; -- Correct
        while(idx_start <= idx_end) {
            if(idx_start == gems.size()) break;

            gemInfo[gems[idx_start]] --;

            if (gemInfo[gems[idx_start]] == 0) {
                idx_start ++;
                break;                                  // gems[idx_start - 1] 부터 gems[end] 까지 담음
            }
        
            idx_start ++;
        }

        int len_now = getLen(idx_start - 1, idx_end);
        if (len > len_now) {
            len = len_now;
            start = idx_start - 1;
            end = idx_end;
        }
        ```

## 맺으며
* Two Pointer의 Pointer를 움직이는 While 문의 사용에 익숙해 질 필요가 있음