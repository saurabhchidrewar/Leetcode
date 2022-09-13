class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remBytes = 0;
        for (auto c: data) {
            if (remBytes == 0) {
                if ((c >> 7) == 0b0)
                    remBytes = 0;
                else if ((c >> 5) == 0b110) 
                    remBytes = 1;
                else if ((c >> 4) == 0b1110)
                    remBytes = 2;
                else if ((c >> 3) == 0b11110)
                    remBytes = 3;
                else
                    return false;
            } else {
                if ((c >> 6) == 0b10)
                    remBytes--;
                else
                    return false;
            }
        }
        
        if (remBytes) return false;
        return true;
    }
};