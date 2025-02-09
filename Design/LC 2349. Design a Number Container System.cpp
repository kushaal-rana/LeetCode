// Approach-1 (Using two maps : map of int, int and map of int, set)
// T.C : O(log(n))
// S.C : O(n)
class NumberContainers
{
public:
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers()
    {
        idxToNum.clear();
        numToIdx.clear();
        // our you can do nothing
    }

    void change(int index, int number)
    {
        if (idxToNum.count(index))
        { // O(1)
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index); // O(log(N))
            if (numToIdx[prevNum].empty())
            {
                numToIdx.erase(prevNum); // O(1)
            }
        }
        idxToNum[index] = number;
        numToIdx[number].insert(index); // O(longN)
    }

    int find(int number)
    {
        if (numToIdx.count(number))
        {                                     // O(1)
            return *numToIdx[number].begin(); // O(1)
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
