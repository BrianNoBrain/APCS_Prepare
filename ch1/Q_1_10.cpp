#include <bits/stdc++.h>
using namespace std;
#define LL long long

int n, maxscore, scorearr[15][15];

void solve(int n, int k, int p[], bool use[]){
	if(k>=n){
		int score=0;
		for(int i=0;i<n;i++) if(use[i]) score+=scorearr[i][p[i]];
		if(score>maxscore) maxscore=score;
		return;
	}
	// use k
	use[k]=1;
	// ( j, p[j] ) ( k, i )
	for(int i=0;i<n;i++){
		bool valid=true;
		for(int j=0;j<k;j++){
			if( use[j] && ( p[j]==i || k-j==abs(i-p[j]) ) ){
				valid=false;
				break;
			}
		}
		if(valid){	
			p[k]=i;
			solve(n, k+1, p, use);
		}
	}
	// don't use k
	use[k]=0;
	p[k]=n;
	solve(n, k+1, p, use);
	return;
}

int main(){
	ios::sync_with_stdio(), cin.tie();
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>scorearr[i][j];
	//for(int i=0;i<n;i++) for(int j=0;j<n;j++) cout<<scorearr[i][j]<<" ";
	int p[15];
	bool use[15];
	solve(n, 0, p, use);
	cout<<maxscore<<"\n";
	return 0;
}
