#include <bits/stdc++.h>
using namespace std;

int solve(){
	string token;
	cin>>token;
	if(token=="f"){
		return 2*solve()-1;
	}else if(token=="g"){
		return solve()+2*solve()-3;
	}
	else{
		return stoi(token);
	}
};

int main(){
	cout<<solve()<<"\n";
	return 0;
}
