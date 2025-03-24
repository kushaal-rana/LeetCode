class Solution
{
public:
    // Whenever you have to deal with intervals, always try to sort(either by start or end) and see if that helps
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int n = meetings.size();
        int daysOff = 0;
        sort(begin(meetings), end(meetings));
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            if (meetings[i][0] > end)
            {
                daysOff += meetings[i][0] - end - 1;
            }
            end = max(end, meetings[i][1]);
        }
        if (end < days)
        { // if 10 days and end is 6 then you have 4 more days
            daysOff += days - end;
        }
        return daysOff;
    }
};