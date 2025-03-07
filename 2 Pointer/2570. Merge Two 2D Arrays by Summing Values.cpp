/*
Problem Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values
Approach 1: Map
Time Complexity: O(n+m)
Space Complexity: O(n+m)
*/
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mp;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i][0]] += nums1[i][1];
        }
        for (int i = 0; i < m; i++)
        {
            mp[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> result;
        for (auto it : mp)
        {
            result.push_back({it.first, it.second});
        }
        return result;
    }
};

/*
Approach 2: Two Pointer
Time Complexity: O(nlogn)
Space Complexity: O(n+m)
*/
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mp;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (nums1[i][0] == nums2[j][0])
            {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n)
        {
            result.push_back(nums1[i++]);
        }
        while (j < m)
        {
            result.push_back(nums2[j++]);
        }
        return result;
    }
};