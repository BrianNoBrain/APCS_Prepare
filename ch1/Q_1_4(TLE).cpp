#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, k, p[50005];

int cut(int left, int right, int layer){
	LL minpd=999999999999, minp=left+1;
	if( layer>k || (right-left+1)<3 ) return 0;
	for(int i=left+1;i<=right-1;i++){
		LL pdl=0, pdr=0;
		for(int j=left;j<i;j++){
			pdl+=p[j]*(i-j);
		}
		for(int j=i+1;j<=right;j++){
			pdr+=p[j]*(j-i);
		}
		if(abs(pdl-pdr)<minpd){
			minpd=abs(pdl-pdr);
			minp=i;
		}
	}
	
	return cut(left, minp-1, layer+1)+cut(minp+1, right, layer+1)+p[minp];	
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	freopen("D:/Brian/Documents/Developing Project/ch1/Q_1_4/Q_1_4_2.in", "r", stdin);
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	cout<<cut(0, n-1, 1)<<"\n";
	
	
	
} 
