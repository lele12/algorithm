#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void backtracking(vector<string>& path, vector<string>& res, unordered_map <string, vector<pair<string, bool>>>& targets, int ticket_num){
    if (res.size() > 0){
        return;
    }
    if (path.size() == ticket_num + 1){
        res = path;
        return;
    }
    for (pair<string, bool>& ticket: targets[path.back()]){
        if (ticket.second){
            continue;
        }
        ticket.second = true;
        path.push_back(ticket.first);
        backtracking(path, res, targets, ticket_num);
        path.pop_back();
        ticket.second = false;
    }
}
bool cmp(const pair<string, bool>& a, const pair<string, bool>& b){
    return a.first < b.first;
}
vector<string> findItinerary(vector<vector<string>>& tickets){
    vector<string> path;
    path.push_back("JFK");
    vector<string> res;
    unordered_map <string, vector<pair<string, bool>>> targets;
    for (vector<string> ticket:tickets){
        targets[ticket[0]].push_back({ticket[1], false});
    }
    for (auto iter = targets.begin(); iter != targets.end(); iter++){
        sort((iter->second).begin(), (iter->second).end(), cmp);
    }
        vector<bool> used(tickets.size(), false);
    backtracking(path, res, targets, tickets.size());
    return res;
}

int main(){
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res = findItinerary(tickets);
    for (string ticket:res){
        cout << ticket << ' ';
    }
    system("pause");
    return 0;
}