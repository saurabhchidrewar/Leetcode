class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue <pair<int,int>> pq;
        int mp[26] {0};
        for (auto &c: s) mp[c - 'a']++;
        
        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0)
                pq.push({i, mp[i]});
        }
        string ans = "";
        while (!pq.empty()) {
            char t1 = (char)(pq.top().first + 'a');
            int f1 = pq.top().second;
            pq.pop();
            
            if (ans.size() == 0 || ans.back() != t1) {
                int times = min(f1, repeatLimit);
                for (int i = 0; i < times; i++) ans += t1;
                f1 -= times;
                if (f1) {
                    pq.push({t1 - 'a', f1});
                }
            } else {
                if (pq.size() == 0) break;
                char t2 = char(pq.top().first + 'a');
                int f2 = pq.top().second;
                pq.pop();
                
                ans += t2;
                f2--;
                if (f2) {
                    pq.push({t2 - 'a', f2});
                }
                pq.push({t1 - 'a',f1});
            }
        }
        return ans;
    }
};