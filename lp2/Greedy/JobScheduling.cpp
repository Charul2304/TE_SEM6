#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
    public:
    string id;
    int deadline;
    int profit;
    
    Job(string id,int deadline,int profit){
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};
bool compare(Job a,Job b){
    return a.profit>b.profit;
}
class Scheduling{
    public:
    vector<Job> jobs;
    int n;
    
    void input(){
        cout<<"Enter number of jobs : ";
        cin>>n;
        for(int i=0;i<n;i++){
            string id;
            int deadline,profit;
            cout<<"Enter id of job "<<i+1<<" : ";
            cin>>id;
            cout<<"Enter deadline of job "<<i+1<<" : ";
            cin>>deadline;
            cout<<"Enter profit of job "<<i+1<<" : ";
            cin>>profit;
            jobs.push_back(Job(id,deadline,profit));
        }
    }
    void jobschedule(){
        sort(jobs.begin(),jobs.end(),compare);
        int maxp=0;
        int maxd=0;
        for(int i=0;i<n;i++){
            maxd=max(maxd,jobs[i].deadline);
        }
        vector<string> slot(n,".");
        for(auto job:jobs){
            for(int j=job.deadline;j>=0;j--){
                if(slot[j]=="."){
                    slot[j]=job.id;
                    maxp+=job.profit;
                    break;
                }
            }
        }
        cout<<"Total Max Profit is : "<<maxp;
        cout<<"Jobs are scheduled as follow"<<endl;
        for(int i=0;i<n;i++){
            cout<<jobs[i].id<<" "<<jobs[i].deadline<<" "<<jobs[i].profit<<endl;
        }
    }
};
int main() {
    Scheduling obj;
    obj.input();
    
    obj.jobschedule();

    return 0;
}
