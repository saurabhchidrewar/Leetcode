class Solution
{
    public:
        int findMin(vector<int> &nums)
        {
            int start = 0, end = nums.size() - 1, n = nums.size();
            while (start <= end)
            {
                if (nums[start] <= nums[end])
                    return nums[start];
                int mid = start + (end - start) / 2;

                int next = (mid + 1) % n, prev = (mid + n - 1) % n;
                if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
                    return nums[mid];

                if (nums[mid] <= nums[end])
                    end = mid - 1;
                if (nums[mid] >= nums[start])
                    start = mid + 1;
            }
            return nums[start];
        }
};