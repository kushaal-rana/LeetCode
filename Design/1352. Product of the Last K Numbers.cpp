// Approach 1: Simple Simulation Do as question says
// TC: O(k) for getProd
class ProductOfNumbers
{
public:
    vector<int> nums;
    ProductOfNumbers()
    {
        // TC = O(K) for get Prod
        nums.clear();
    }

    void add(int num)
    {
        nums.push_back(num); // O(1)
    }

    int getProduct(int k)
    {
        int n = nums.size();
        int prod = 1;
        // k nums ka prod not all n numbers
        for (int i = n - k; i < n; i++)
        { // O(k)
            prod *= nums[i];
        }
        return prod;
    }
};

// Follow Up Question can you solve in O(1) insted of O(k)
// Approach-2 (Follow up optimal in O(1))
// T.C : O(1) for both methods
// S.C : O(n) for the stream
class ProductOfNumbers
{
public:
    vector<int> cumProd; // cumulative prod store karenge
    int n;

    ProductOfNumbers()
    {
        cumProd.clear();
        n = 0;
    }

    void add(int num)
    {
        if (num == 0)
        {
            cumProd = {};
            n = 0;
        }
        else
        {
            if (cumProd.empty())
            {
                cumProd.push_back(num);
            }
            else
            {
                cumProd.push_back(cumProd[n - 1] * num);
            }
            n++; // increasing size by 1
        }
    }

    int getProduct(int k)
    {
        if (k > n)
        {
            return 0;
        }
        else if (k == n)
        {
            return cumProd[n - 1];
        }
        return cumProd[n - 1] / cumProd[n - k - 1];
    }
};