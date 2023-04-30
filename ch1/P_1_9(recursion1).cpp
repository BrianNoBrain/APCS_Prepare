#include <bits/stdc++.h>
using namespace std;
#define LL long long

int solve(int n, int k, int p[]){
	if(k>=n){
		return 1;
	}
	int total=0;
	for(int i=0;i<n;i++){
		bool valid=true;
		for(int j=0;j<k;j++){
			if( k-j==abs(i-p[j]) || i==p[j] ){
				valid=false;
				break;
			}
		}
		if(valid){
			p[k]=i;
			total+=solve(n, k+1, p);
		}
	}
	return total;
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	int p[20];
	for(int i=1;i<12;i++) cout<<solve(i, 0, p)<<" ";
	cout<<"\n";
	return 0;
}
