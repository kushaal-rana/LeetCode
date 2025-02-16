
// Approach-1 (Brute Force)
// T.C : O(n^2 * m), m = number of digits
// S.C : O(1)
class Solution
{
public:
    int getDigitSum(int num)
    {
        int sum = 0;

        while (num > 0)
        {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int> &nums)
    {
        int n = nums.size();
        int result = -1;

        for (int i = 0; i < n; i++)
        {
            int digitSumi = getDigitSum(nums[i]);

            for (int j = i + 1; j < n; j++)
            {
                int digitSumj = getDigitSum(nums[j]);

                if (digitSumi == digitSumj)
                {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }

        return result;
    }
};

// Approach-2 (Optimal using Map) can also use vector as mx ele is 81
// T.C : O(n*k), k = number of digits
class Solution
{
public:
    int digitSum(int num)
    { // O(k) if k is the len of digit
        int sum = 0;
        int N = num;
        while (num)
        {
            int last = num % 10;
            num = num / 10;
            sum += last;
        }
        return sum;
    }
    // TC: O(N*K), SC: O(N)
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxi = -1, currSum = 0;
        for (auto num : nums)
        { // O(N)
            int sum = digitSum(num);
            cout << sum << " ";
            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, mp[sum] + num);
            }
            mp[sum] = max(mp[sum], num); // bada wala number hi map mai rakho
        }
        for (auto it : mp)
        {
            cout << it.first << " " << it.second << endl;
        }
        return maxi;
    }
};
