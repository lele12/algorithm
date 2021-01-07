#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> find(vector<vector<int>>& edges, int s, vector<bool>&used){
    vector<int> re(edges.size(), -1);
    for (int i = 0; i < edges.size(); i++){
        if (used[i]){
            continue;
        }
        if (edges[i][0] == s){
            re[i] = 1;
        }else if(edges[i][1] == s){
            re[i] = 0;
        }
    }
    return re;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
    vector<int> ans;
    int min = edges.size() + 1;
    for (int i = 0; i < n; i++){
        vector<bool> used(edges.size(), false);
        queue<int> q;
        q.push(i);
        int height = 0;
        while(!q.empty()){
            int q_size = q.size();
            for (int k = 0; k < q_size; k++){
                int s = q.front();
                q.pop();
                vector<int> re = find(edges, s, used);
                for (int j = 0; j < re.size(); j++){
                    if (re[j] == -1){
                        continue;
                    }else{
                        q.push(edges[j][re[j]]);
                        used[j] = true;
                    }
                }
            }
            if (q_size > 0){
                height++;
            }
        }
        if (height < min){
            int ans_size = ans.size();
            for (int a = 0; a < ans_size; a++){
                ans.pop_back();
            };
            ans.push_back(i);
            min = height;
        }else if(height == min){
            ans.push_back(i);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    vector<int> ans = findMinHeightTrees(n, edges);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "  ";
    }
        system("pause");
    return 0;
}