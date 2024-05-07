#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
public:
    int id;
    int deadline;
    int profit;
    Job(int id, int deadline, int profit){
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool comp(Job a, Job b){
    return a.profit > b.profit;
}

class JobScheduling{
public:
    vector<Job> jobs;
    int numjobs;
    
    void input(){
        cout << "Enter the number of jobs: ";
        cin >> numjobs;
        
        for(int i = 0; i < numjobs; i++){
            int id, deadline, profit;
            cout << "Enter id of job " << i + 1 << " : ";
            cin >> id;
            cout << "Enter deadline of job " << i + 1 << " : ";
            cin >> deadline;
            cout << "Enter profit of job " << i + 1 << " : ";
            cin >> profit;
            jobs.push_back(Job(id, deadline, profit));
        }
    }
    
    void jobscheduling(){
        sort(jobs.begin(), jobs.end(), comp);
        int maxdeadline = 0;
        for(int i = 0; i < numjobs; i++){
            maxdeadline = max(maxdeadline, jobs[i].deadline);
        }
        vector<int> slots(maxdeadline + 1, -1);
        int totalprofit = 0;
        for(auto job : jobs){
            for(int j = job.deadline; j >= 0; j--){
                if(slots[j] == -1){ // If slot is empty
                    slots[j] = job.id;
                    totalprofit += job.profit;
                    break;
                }
            }
        }
        cout << "Scheduled Jobs:\n";
        for(int i = 0; i <= maxdeadline; i++){
            if(slots[i] != -1){
                cout << "Job with id " << slots[i] << " is scheduled with deadline " << i << endl;
            }
        }
        cout << "Total Profit: " << totalprofit << endl;
    }
};

int main() {
    JobScheduling obj;
    obj.input();
    cout << "Given Jobs:\n";
    cout << "Deadline\tProfit\n";
    for(const auto& job : obj.jobs){
        cout << job.deadline << "\t\t" << job.profit << endl;
    }
    obj.jobscheduling();

    return 0;
}
