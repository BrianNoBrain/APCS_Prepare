#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, arr[30];
LL P=10009, cont=0;

void solve(int id, LL prod){
	if(id>=n){
		if(prod==1) cont++;
		return;
	}
	solve(id+1, (prod*arr[id]%P));
	solve(id+1, prod);
	return;
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	solve(0, 1);
	cout<<cont-1<<"\n";// -1 for empty subset
	
	return 0;
} 
