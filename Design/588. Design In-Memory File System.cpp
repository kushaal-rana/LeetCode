class FileSystem
{
public:
    struct fileNode
    {
        unordered_map<string, fileNode *> children; // if directory
        bool isFile;
        string content;
        fileNode()
        {
            isFile = false;
            content = "";
        }
    };
    fileNode *root;
    FileSystem()
    {
        root = new fileNode();
    }

    fileNode *goToPathFolder(string path)
    {
        fileNode *curr = root;
        stringstream ss(path);
        string folder;
        while (getline(ss, folder, '/'))
        {
            if (folder.size())
            {
                if (curr->children[folder] == NULL)
                {
                    curr->children[folder] = new fileNode();
                }
                curr = curr->children[folder];
            }
        }
        return curr;
    }

    vector<string> ls(string path)
    {
        fileNode *curr = goToPathFolder(path);
        if (curr->isFile)
        {
            return {path.substr(path.find_last_of('/') + 1)};
        }
        vector<string> res;
        for (auto &p : curr->children)
        {
            res.push_back(p.first);
        }
        sort(res.begin(), res.end());
        return res;
    }

    void mkdir(string path)
    {
        fileNode *curr = goToPathFolder(path);
    }

    void addContentToFile(string filePath, string content)
    {
        fileNode *curr = goToPathFolder(filePath);
        curr->content += content;
        curr->isFile = true;
    }

    string readContentFromFile(string filePath)
    {
        fileNode *curr = goToPathFolder(filePath);
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */