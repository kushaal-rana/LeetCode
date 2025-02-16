// Approach (Using Heap)
// T.C : Onlogn)
// S.C : O(n)
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums)); // Heapify - O(logn)
        // for(int i=0;i<n;i++){ //this is O(N)
        //     pq.push(nums[i]);
        // }
        int count = 0;

        while (!pq.empty())
        {
            if (pq.top() < k)
            {

                long smallest = pq.top(); // minimum
                pq.pop();

                long secondSmallest = pq.top(); // max
                pq.pop();
                long newNum = min(x, y) * 2LL + max(x, y);
                // min will alwasy be smallest and max will always be secondSmallest
                pq.push(smallest * 2L + secondSmallest);

                count++;
            }
            else
                break;
        }

        return count;
    }
};