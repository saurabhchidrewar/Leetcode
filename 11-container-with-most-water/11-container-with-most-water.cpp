class Solution
{
    public:

        int maxArea(vector<int> &height)
        {
            int front = 0, rear = height.size() - 1, ans = 0, currentWaterLevel = 0;
            while (front < rear)
            {
                currentWaterLevel = (rear - front) *min(height[front], height[rear]);
                if (currentWaterLevel > ans)
                {
                    ans = currentWaterLevel;
                }
                if (height[front] < height[rear]) front++;
                else rear--;
            }
            return ans;
        }
};