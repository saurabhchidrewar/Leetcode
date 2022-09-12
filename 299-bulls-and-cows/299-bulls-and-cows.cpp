class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map <int, int> mp;
        int a = 0, b = 0;
        for (int i = 0; i < secret.size(); i++){
            if (secret[i] != guess[i]) mp[secret[i]]++;    
        } 
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) a++;
            else if (mp.find(guess[i]) != mp.end() && mp[guess[i]] > 0)
            {
                mp[guess[i]]--;
                b++;
            }
        }
        string ans = to_string(a) + "A" + to_string(b) + "B";
        return ans;
    }
};

/*
"1123"
"0111"

1: 0, 2: 1, 3:1
a = 1
b = 1
*/