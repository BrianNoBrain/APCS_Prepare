#include <bits/stdc++.h>
using namespace std;

int m, n, arr[15][15], mincost=2E9;

void solve(int xl, int xr, int yl, int yr, int totalcost){
	if(xl==xr||yl==yr){
		if(totalcost<mincost) mincost=totalcost;
		return;
	}
	
	int zerocost=0, onecost=0;
	for(int i=yl;i<=yr;i++){
		if(arr[xl][i]==0)  zerocost++;
		else onecost++;
	}
	solve(xl+1, xr, yl, yr, totalcost+min(zerocost, onecost));
	
	zerocost=0, onecost=0;
	for(int i=yl;i<=yr;i++){
		if(arr[xr][i]==0)  zerocost++;
		else onecost++;
	}
	solve(xl, xr-1, yl, yr, totalcost+min(zerocost, onecost));
	
	zerocost=0, onecost=0;
	for(int i=xl;i<=xr;i++){
		if(arr[i][yl]==0)  zerocost++;
		else onecost++;
	}
	solve(xl, xr, yl+1, yr, totalcost+min(zerocost, onecost));
	
	zerocost=0, onecost=0;
	for(int i=xl;i<=xr;i++){
		if(arr[i][yr]==0)  zerocost++;
		else onecost++;
	}
	solve(xl, xr, yl, yr-1, totalcost+min(zerocost, onecost));
	return;
};

int main(){
	ios::sync_with_stdio(), cin.tie();
	cin>>m>>n;
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
	solve(0, m-1, 0, n-1, 0);
	cout<<mincost<<"\n";
	return 0;
} 
