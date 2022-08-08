//Hackerearth-campers

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int parent[N];
int size[N];
multiset<int> sizes;

void updateSizes(int n1,int n2) {
    sizes.erase(sizes.find(size[n1]));  //erasing only 1 occurence
    sizes.erase(sizes.find(size[n2]));
    sizes.insert(size[n1]+size[n2]);
}

void make(int node) {
	parent[node]=node;
	size[node]=1;
	sizes.insert(1);
}
int find(int node) {
	if(node==parent[node]) {
		return node;
	}
	return parent[node]=find(parent[node]);
}
void Union(int n1,int n2) {
	int p1=find(n1);
	int p2=find(n2);
	if(size[n1]<=size[n2]) {
       parent[p1]=p2;
       updateSizes(p1,p2);         //Perform this before size updation
	   size[p2]+=size[p1];
	}
	else {
		parent[p2]=p1;
		updateSizes(p1,p2);
		size[p1]+=size[p2];
	}
}
int main() {
	int num;
	int q;
	cin>>num>>q;
	for(int i=0;i<num;i++) {
		make(i);
	}
	while(q--) {
		int x;int y;
		cin>>x>>y;
		x--;
		y--;
		Union(x,y);
		if(sizes.size()==1) {
		    cout<<"0"<<endl;
		}
		else{
		    int val1=*(sizes.begin());
		    int val2=*(--sizes.end());
		    cout<<val2-val1<<endl;
		}
	}
	return 0;
}
