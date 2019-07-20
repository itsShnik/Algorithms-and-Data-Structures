#include <bits/stdc++.h>
using namespace std;

typedef struct _job{
	int st, fi;
}job;

bool compareFi(job j1, job j2){
	return j1.fi < j2.fi;
}

void printJobs(vector<job> set){
	for(int i = 0; i < set.size(); i++){
		cout << "(" << set[i].st << " , " << set[i].fi << ")" << endl;
	}
}

void scheduleJobsGreedy(job jobs[], int n){
	vector<job> finalSet;
	//sort the jobs in non decreasing order of time
	sort(jobs, jobs + n, compareFi);
	finalSet.push_back(jobs[0]);
	int i = 0;
	for(int j = 1; j < n; j++){
		if(jobs[j].st >= jobs[i].fi){
			finalSet.push_back(jobs[j]);
			i = j;
		}
	}
	cout << "The number of compatible jobs in the max sized set is " << finalSet.size() << endl;
	cout << "And the jobs in that set are:" << endl;
	printJobs(finalSet);
}

int main(){
	job jobs[] = {{1, 2}, {3, 9}, {4, 8}, {7, 16}, {5, 22}, {12, 34}, {11, 14}, {13, 19}, {15, 17}, {21, 24}};
	int n = sizeof(jobs)/ sizeof(jobs[1]);
	scheduleJobsGreedy(jobs, n);
}