// Approch 2 : Using Deque - O(n)
class Solution
{
public:
    /* Story Points:
    1. When new element comes nums[i] make space for it(window size can't be
    greater than ķ)
    2. Now when nums[i] comes, there is no need to keep small elements in that window.
    Pop Them
    3. Now Push i in the deque-> for nums[i]
    4. If(i>=k-1), then deq.front() is our answer for that window.
    */
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            // Step 1: make space for nums[i]
            while (!deq.empty() && deq.front() <= i - k)
            {
                deq.pop_front(); //
            }
            // Step 2: Greater then nums[i]>deq.element
            while (!deq.empty() && nums[i] > nums[deq.back()])
            {
                deq.pop_back();
            }
            // Step-3
            deq.push_back(i);
            // window bana first and then bana hua hai ki nahi check
            if (i >= k - 1)
            {
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};