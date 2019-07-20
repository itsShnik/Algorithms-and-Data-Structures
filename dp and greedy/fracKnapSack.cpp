#include <bits/stdc++.h>
using namespace std;

typedef struct _item{
	float wt, val;
}item;

bool custom(item i1, item i2){
	return (i1.val)/(i1.wt) > (i2.val)/(i2.wt);
}

void printItems(vector< pair<item, float> > vec){
	
	cout << "wt" << "		" << "val" << "		" << "frac" << endl;
	for(int i = 0; i< vec.size(); i++){
		cout << vec[i].first.wt << "		" << vec[i].first.val << "		" << vec[i].second << endl;
	}
}

void chooseItems(item items[], int n, float capacity){
	//sort the items in increasing val/weight
	sort(items, items + n, custom);
	//make a vector of pairs containing the item and its fraction
	vector< pair<item, float> > vec;
	int i = 0;
	float total_val = 0;
	while(capacity > 0){
		if(items[i].wt >= capacity){
			float frac = capacity/items[i].wt;
			total_val += items[i].val * frac;
			vec.push_back(make_pair(items[i], frac));
			capacity = 0;
		}else{
			total_val += items[i].val;
			vec.push_back(make_pair(items[i], 1.0));
			capacity -= items[i].wt;
			i++;
		}
	}
	cout << "The total max value is :" << total_val << endl;
	cout << "The chosen items are : " << endl;
	printItems(vec);
}

int main(){
	item items[] = {{40, 12.63}, {10, 13}, {200, 60}, {100, 45}, {25, 3.94}, {500, 120}, {97, 49}, {300, 123.5}, {19, 57.65}};
	float capacity = 1000.0;
	int n = sizeof(items)/sizeof(items[1]);
	chooseItems(items, n, capacity);
} 