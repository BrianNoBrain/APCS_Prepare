#include <bits/stdc++.h>
#define LL long long
using namespace std;

int n, l;
LL p[50010];

LL cut(int left, int right){
	if(right-left<=1) return 0;
	LL mid=(p[left]+p[right])/2, m=left;
	while(p[m]<mid) m++;
	if(p[m-1]-p[left] >= p[right]-p[m]) m--; //why mid-p[m-1]<=p[right]-mid didn't work? Why? 
	return p[right]-p[left]+cut(left,m)+cut(m,right);
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	freopen("D:/Brian/Documents/Developing Project/ch1/p_1_3/p_1_3_2.in", "r", stdin);
	cin>>n>>l;
	p[0]=0; p[n+1]=l;
	for(int i=1;i<=n;i++) cin>>p[i];
	cout<<cut(0, n+1)<<"\n";
	
	return 0;
}
