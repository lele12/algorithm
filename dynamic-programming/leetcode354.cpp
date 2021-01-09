#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp (const vector<int>& a, const vector<int>& b){
    if(a[0] > b[0]){
        return false;
    }else if(a[0] == b[0] && a[1] > b[1]){
        return false;
    }
    return true;
}

int maxEnvelopes(vector<vector<int>>& envelopes){
    // sort(envelopes.begin(), envelopes.end(), cmp);
    if(envelopes.size()==0){
        return 0;
    }
        sort(envelopes.begin(),envelopes.end(),[](const vector<int> &a,const vector<int> &b){
    if(a[0] > b[0]){
        return false;
    }else if(a[0] == b[0] && a[1] > b[1]){
        return false;
    }
    return true;
        });

    vector<int> memo(envelopes.size(), 1);
    for (int i = 1; i < envelopes.size(); i++){
        vector<int> s;
        for (int j = i - 1; j >= 0; j--){
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){

                s.push_back(memo[j]);
            }
        }
        int max_value = 0;
        for (int a = 0;a < s.size(); a++)
        {
            max_value = max(max_value, s[a]);
        }
        memo[i] = max_value + 1;
        
    }
    int max_value = 0;
    for (int a = 0;a < memo.size(); a++)
    {
        max_value = max(max_value, memo[a]);
    }
    return max_value;
}

int main(){
    vector<vector<int>> envelopes = {{10, 8}, {1, 12}, {6, 15}, {2, 18}};
    int re = maxEnvelopes(envelopes);
    cout << re;
    system("pause");
    return 0;
}