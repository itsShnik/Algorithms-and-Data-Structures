#include <bits/stdc++.h>
using namespace std;

typedef struct _job{
	int st, fi;
}job;

bool compareFi(job j1, job j2){
	return j1.fi < j2.fi;
}

void printJobs(int **c, job jobs[], int l, int r){
	
	
}

void scheduleJobsDP(job jobs[], int n){
	int tab[n][n] = {0};
	int **c;
	c = (int **)malloc(sizeof(int*) * n);
	for(int i = 0; i< n; i++){
		c[i] = (int *)malloc(sizeof(int) * n);
	}
	//sort the jobs in order of their finish time
	sort(jobs, jobs + n, compareFi);
	for(int i = 0; i < n; i++){
		for(int j = i + 2; j < n; j++){
			int max = INT_MIN, a;
			for(int k = i + 1; k < j; k++){
				if(jobs[k].st >= jobs[i].fi && jobs[k].fi <= jobs[j].st){
					a = tab[i][k] + tab[k][j] + 1;
				}else{
					a = tab[i][k] + tab[k][j];
				}
				if(max < a){
					max = a;
					c[i][j] = k;
				}
			}
			tab[i][j] = max;
		}
	}
	cout << "the max no. of jobs compatible are : " << tab[0][n -1] << endl;
	//printJobs(c, jobs, 0, n - 1);
	//cout << endl;
}

int main(){
	//first and the last job being dummy
	job jobs[] = {{0, 0},{1, 2}, {3, 9}, {4, 8}, {7, 16}, {5, 22}, {12, 34}, {11, 14}, {13, 19}, {15, 17}, {21, 24}, {INT_MAX, INT_MAX}};
	int n = sizeof(jobs)/ sizeof(jobs[1]);
	scheduleJobsDP(jobs, n);
}	