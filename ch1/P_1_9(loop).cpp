#include <bits/stdc++.h>
using namespace std;
#define LL long long

int solve(int n){
	int p[20], total=0;
	for(int i=0;i<n;i++) p[i]=i;
	do{
		bool valid=true;
		for(int i=0;i<n;i++) {
			if(!valid) break;
			for(int j=i+1;j<n;j++){
				if( abs(p[i]-p[j])==j-i ){
					valid=false;
					break;
				}
			}
		}
		if(valid) total++;
	}while(next_permutation(p, p+n));
	return total;
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	for(int i=1;i<12;i++) cout<<solve(i)<<" ";
	cout<<"\n";
	return 0;
}
