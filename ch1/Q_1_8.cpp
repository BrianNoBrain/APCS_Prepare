#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n, arr[30];
LL P, maxsum=0;

void solve(int id, LL sum){
	if(id>=n){
		if(sum<=P && sum>maxsum) maxsum=sum;
		return;
	}
	solve(id+1, sum+arr[id]);
	solve(id+1, sum);
}

int main(){
	ios::sync_with_stdio(),cin.tie();
	cin>>n>>P;
	for(int i=0;i<n;i++) cin>>arr[i];
	solve(0, 0);
	cout<<maxsum<<"\n";
	
	return 0;
}
