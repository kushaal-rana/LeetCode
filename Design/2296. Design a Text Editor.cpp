class TextEditor
{
public:
    stack<int> left;
    stack<int> right;
    TextEditor()
    {
    }

    void addText(string text)
    {
        for (auto &t : text)
        {
            left.push(t);
        }
    }

    int deleteText(int k)
    {
        int count = 0;
        while (!left.empty() && k--)
        {
            left.pop();
            count++;
        }
        return count;
    }

    string cursorLeft(int k)
    {
        while (!left.empty() && k--)
        {
            right.push(left.top());
            left.pop();
        }
        // returning the last min(10, len) characters to the left of the cursor
        return cursorShiftString();
    }

    string cursorRight(int k)
    {
        while (!right.empty() && k--)
        {
            left.push(right.top());
            right.pop();
        }
        return cursorShiftString();
    }

    string cursorShiftString()
    {
        int size = left.size();
        int count = min(10, size);
        string ans = "";
        while (count--)
        {
            ans += left.top();
            left.pop();
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            left.push(ans[i]);
        }
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */