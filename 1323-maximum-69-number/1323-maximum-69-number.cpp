class Solution {
public:
    int maximum69Number (int num) {
        int t = num, i = 0, ans = -1;
        while (t > 0) {
            if (t % 10 == 6)
                ans = i;
            i++;
            t/=10;
        }
        if (ans != -1) return num + 3 * pow(10, ans);
        return num;
    }
};