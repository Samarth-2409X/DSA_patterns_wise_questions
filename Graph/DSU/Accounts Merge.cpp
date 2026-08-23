class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); 
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
};



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> emailToAcc;

        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAcc.count(email)) {
                    dsu.Union(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        
        map<int, vector<string>> emailGroup;
        for (auto &it : emailToAcc) {
            string email = it.first;
            int accId = it.second;

            int leader = dsu.find(accId);
            emailGroup[leader].push_back(email);
        }

        
        vector<vector<string>> res;
        for (auto &it : emailGroup) {
            int accId = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> merged;
            merged.push_back(accounts[accId][0]); 
            merged.insert(merged.end(), emails.begin(), emails.end());

            res.push_back(merged);
        }

        return res;
    }
};
