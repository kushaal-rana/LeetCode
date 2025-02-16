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
        // O(N * 3logN)
        while (!pq.empty()) // O(N)
        {
            if (pq.top() < k)
            {

                long smallest = pq.top(); // minimum
                pq.pop();                 // O(logN)

                long secondSmallest = pq.top(); // max
                pq.pop();                       // O(logN)
                long newNum = min(x, y) * 2LL + max(x, y);
                // min will alwasy be smallest and max will always be secondSmallest
                pq.push(smallest * 2L + secondSmallest); // O(logN)

                count++;
            }
            else
                break;
        }

        return count;
    }
};