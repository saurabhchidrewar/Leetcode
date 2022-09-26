class Solution
{
    public:
        int wateringPlants(vector<int> &plants, int capacity)
        {
            int steps = 0, original = capacity;
            for (int i = 0; i < plants.size(); i++)
            {
                if (plants[i] > capacity) {
                    steps += 2 * i;
                    capacity = original;
                }
                capacity -= plants[i];
                steps++;
                // cout << steps << " " << capacity << endl;
            }
            return steps;
        }
};