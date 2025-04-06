// Approach 1: Backtracking
// T.C : O(2^n) * L
// S.C : O(2^n) * L
class Solution
{
public:
    int finalAns;
    void subSet(int i, vector<int> &nums, vector<int> &result)
    {
        if (i >= nums.size())
        {
            if (result.size() > 0)
            {
                int ans = result[0];
                for (int j = 1; j < result.size(); j++)
                {
                    ans ^= result[j];
                }
                finalAns += ans;
            }
            return;
        }

        result.push_back(nums[i]);
        subSet(i + 1, nums, result);
        result.pop_back();
        subSet(i + 1, nums, result);
    }
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> result;
        finalAns = 0;
        subSet(0, nums, result);
        return finalAns;
    }
};

// Approach 2:  On the Fly calculation
// T.C : O(2^n)
// S.C : O(1)
class Solution
{
public:
    int subSet(int i, vector<int> &nums, int Xor)
    {
        if (i >= nums.size())
        {
            return Xor;
        }
        int include = subSet(i + 1, nums, nums[i] ^ Xor);
        int exclude = subSet(i + 1, nums, Xor);

        return include + exclude;
    }
    int subsetXORSum(vector<int> &nums)
    {
        int Xor = 0;
        return subSet(0, nums, Xor);
    }
};

/*
Approach 3: Bitwise Observation
Find Or of all Numbers and then Do Left Shift n-1 times.
*/
class Solution
{
public:
    int observationApproach(vector<int> &nums)
    {
        int result = 0;
        int n = nums.size();
        for (int &num : nums)
        {
            result |= num;
        }
        return result << (n - 1);
    }
    int subsetXORSum(vector<int> &nums)
    {
        int Xor = 0;
        // return subSet(0,nums,Xor);
        return observationApproach(nums);
    }
};
