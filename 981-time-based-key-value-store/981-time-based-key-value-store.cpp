class TimeMap {
    unordered_map <string, vector<pair<int, string>>> mp;
    
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int start = 0, end = mp[key].size()-1;
        string ans;
        while (start <= end) {
            int mid = start + (end - start)/2;
            int val = mp[key][mid].first;
            if (val <= timestamp) {
                ans = mp[key][mid].second;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */