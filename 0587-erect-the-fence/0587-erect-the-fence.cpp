class Solution
{
    public:
        int rotationangle(vector<int> A, vector<int> B, vector< int > C)
        {
           	//(x2-x1)(y3-y1)-(y2-y1)(x3-x1)
            return ((B[0] - A[0]) *(C[1] - A[1])) - ((B[1] - A[1]) *(C[0] - A[0]));
        }
    vector<vector < int>> outerTrees(vector<vector < int>> &trees)
    {
        //if the size is less than 3 that just return "trees"
        if (trees.size() <= 3)
        {
            return trees;
        }
        
        //sort the points 
        sort(trees.begin(), trees.end());
        
        //create a UpperHull vector
        vector<vector < int>> upperHull;
        
        //insert the 1st two starting element of trees in upperHull vector
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);
        
        for (int i = 2; i < trees.size(); i++)
        {
            int uhs = upperHull.size();
            //if the rotation angle is greater than zero then just pop out the point
            while (upperHull.size() >= 2 && rotationangle(upperHull[uhs - 2], upperHull[uhs - 1], trees[i]) > 0)
            {
                upperHull.pop_back();
                uhs--;
            }
            upperHull.push_back(trees[i]);
        }

        // do the same as we do for UpperHull, Create Lower Hull (insert the last two element of the trees)
        vector<vector < int>> lowerHull;
        lowerHull.push_back(trees[trees.size() - 1]);
        lowerHull.push_back(trees[trees.size() - 2]);

        for (int i = trees.size() - 3; i >= 0; --i)
        {
            int lhs = lowerHull.size();
            while (lowerHull.size() >= 2 && rotationangle(lowerHull[lhs - 2], lowerHull[lhs - 1], trees[i]) > 0)
            {
                lowerHull.pop_back();
                lhs--;
            }
            lowerHull.push_back(trees[i]);
        }
        
        //insert the lowerHull in the UpperHull vector (basically merging both the upperHull and LowerHull)
        upperHull.insert(upperHull.end(), lowerHull.begin(), lowerHull.end());
        
        //Remove Duplicates from the UpperHUll and return the UpperHull as the Answer vector
        sort(upperHull.begin(), upperHull.end());
        upperHull.erase(unique(upperHull.begin(), upperHull.end()), upperHull.end());
        return upperHull;
    }
};