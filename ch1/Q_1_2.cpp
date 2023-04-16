#include<bits/stdc++.h>
using namespace std;

string token;

int solve(){
	
	int x, y, z;
	cin>>token;
	if(token=="f"){
		x = solve();
		return 2*x-3;
	}else if(token=="g"){
		x = solve();
		y = solve();
		return 2*x+y-7;
	}else if(token=="h"){
		x = solve();
		y = solve();
		z = solve();
		return 3*x-2*y+z;
	}else return stoi(token);
};

int main(){
	cout<<solve()<<"\n";
	return 0;
} 
