/**
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
// TC: O(V+E);
class Solution
{
private:
    string getHostName1(string &url)
    {
        // cout<<"Url: "<< url<<endl;
        int start = url.find("//") + 2; // this gives the starting index of //
        // cout<<start<<" start\n";
        int end = url.find('/', start); // this finds the next start index of / starting from index start=7
        // cout<<end<<" End\n";
        if (end == string::npos)
        {
            // cout<<"host name is "<<url.substr(start, end-start);
            return url.substr(start);
        }
        return url.substr(start, end - start);
    }
    string getHostName(string &url)
    {
        stringstream ss(url);
        string protocol, hostname;
        // Split the URl by '/'
        getline(ss, protocol, '/'); // https:
        getline(ss, protocol, '/'); // "//"
        getline(ss, hostname, '/'); // news.yahoo.com

        return hostname;
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        unordered_set<string> visited;
        queue<string> q;
        vector<string> result;

        string hostName = getHostName(startUrl);

        q.push(startUrl);
        visited.insert(startUrl);

        while (!q.empty())
        {
            string url = q.front();
            q.pop();
            result.push_back(url);

            // get Next Urls
            vector<string> urls = htmlParser.getUrls(url);
            for (string &nextUrl : urls)
            {
                if (visited.count(nextUrl) == 0 && getHostName(nextUrl) == hostName)
                {
                    q.push(nextUrl);
                    visited.insert(nextUrl);
                }
            }
        }
        return result;
    }
};