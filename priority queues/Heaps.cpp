//Implementation of binary heaps using arrays

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;


int insert(int heap[], int length, int key);

void printArray(int arr[], int length);

void buildHeap(int heap[], int length);

void downSift(int heap[], int length, int i);

int main(){
	cout << "First lets build a basic heap first" << endl;
	cout << "how many elements do you want to enter" << endl;
	int n, num;
	cin >> n;
	int heap[100] = {0}, length = n, A[n];
	for(int i = 1; i <= n; i++){
		cin >> heap[i];
	}
	buildHeap(heap, length);
	printArray(heap, length);

	int ch;

	printf("\n the heap is constructed, now what do you want to do?");
	printf("\n***********************\n");
	printf("*1.insert             *\n");
	printf("*2.findMax            *\n");
	printf("*3.extract max        *\n");
	printf("*4.display            *\n");
	printf("*5.exit               *\n");
	printf("***********************\n");
	while(cin >> ch)
	{
		switch(ch)
		{
			case 1:
				printf("\nenter the value:");
				scanf("%d",&num);
				length=insert(heap,length,num);
				break;
			case 2:
				//findMax(heap);
				break;
			case 3:
				//length=extractMax(heap,length);
				break;
			case 4:
				printArray(heap,length);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nwrong choice");
		}
	}
}

int insert(int heap[], int length, int num){
	length++;
	heap[length] = num;
	int ind = length;
	while(ind != 1 && heap[ind / 2] < heap[ind]){
		swap(heap[ind / 2], heap[ind]);
		ind /= 2;
	}
	return length;
}

void printArray(int arr[], int length){
	for(int i = 1; i<= length; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void buildHeap(int heap[], int length){
	for(int i = length / 2; i >=1; i--){
		downSift(heap, length, i);
	}
}

void downSift(int heap[], int length, int i){
	int l , r , lar_ind;
	l = 2 * i;
	r = l + 1;
	if(l <= length && heap[l] > heap[i]){
		lar_ind = l;
	}else{
		lar_ind = i;
	}
	if(r <= length && heap[r] > heap[lar_ind]){
		lar_ind = r;
	}

	if(lar_ind != i){
		swap(heap[lar_ind], heap[i]);
		downSift(heap, length, lar_ind);
	}
}