#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;
    vector<int> deadline(n),profit(n);
    cout<<"Enter deadlines:\n";
    for(int i = 0; i < n; i++) {
        cin >> deadline[i];
    }
    cout<<"Enter profits:\n";
    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }
    vector<pair<int,int>> jobs;
    for(int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }
    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
    int maxDeadline=0;
    for (int i=0;i<n;i++) {
        maxDeadline=max(maxDeadline,deadline[i]);
    }
    vector<bool>slot(maxDeadline+1,false);
    int jobCount = 0;
    int totalProfit = 0;
    for (auto job:jobs) {
        for (int t=job.second;t>0;t--) {
            if (!slot[t]) {
                slot[t]=true;
                jobCount++;
                totalProfit+=job.first;
                break;
            }
        }
    }
    cout<<"\nMaximum jobs done:"<<jobCount<<endl;
    cout<<"Maximum profit earned:"<<totalProfit<<endl;

    return 0;
}
