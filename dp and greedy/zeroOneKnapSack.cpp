#include <bits/stdc++.h>
using namespace std;

typedef struct _item{
	int wt, val;
}item;

void chooseItems(vector<item> items, int capacity){
	int tab[items.size() + 1][capacity];
	for(int i = 0; i <= items.size(); i++){
		for(int j = 0; j <= capacity; j++){
			 if(i == 0 || j == 0){
			 	tab[i][j] = 0;
			 }else if(items[i - 1].wt <= j){
			 	tab[i][j] = max(tab[i - 1][j], tab[i - 1][j - items[i - 1].wt] + items[i - 1].val);
			 }else{
			 	tab[i][j] = tab[i - 1][j];
			 }
		}
	}
	/*
	for(int i = 0; i<= items.size(); i++){
		for(int j = 0; j <= capacity; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;	
	}
	*/
	cout << "The max value is " << tab[items.size()][capacity];
}

int main(){
	vector<item> items{{10, 60}, {20, 100}, {30, 120}, {40, 170}};
	int capacity = 50;
	chooseItems(items, capacity);
}