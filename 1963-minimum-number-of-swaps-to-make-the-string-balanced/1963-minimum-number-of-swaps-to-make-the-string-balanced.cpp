class Solution
{
    public:
        int minSwaps(string s)
        {
           	// Pattern
            int cnt = 0, st = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '[') st++;
                else
                {
                    if (!st) cnt++;
                    else st--;
                }
            }
           	// From pattern
            return (cnt + 1) / 2;
        }
};