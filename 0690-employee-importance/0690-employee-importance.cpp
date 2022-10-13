/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int, pair<int, vector<int>>> mp;
        
        for (auto c: employees) {
            int ID = c->id;
            int IM = c->importance;
            vector<int> SUB = c->subordinates;
            mp[ID] = {IM, SUB};
        }
        
        int imp = 0;
        queue <int> q;
        q.push(id);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            imp += mp[t].first;
            for (auto c: mp[t].second) {
                q.push(c);
            }
        }
        return imp;
    }
};