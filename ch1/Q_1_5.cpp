#include <bits/stdc++.h>
using namespace std;

string s;
int n, id=0, sum;

void find(int siz){
	if(s[id]=='2'){
		id++;
		find(siz/2);
		find(siz/2);
		find(siz/2);
		find(siz/2);
	}else{
		sum+=siz*siz*(s[id]-'0');
		id++;
	}
	return;
};

int main(){
	ios::sync_with_stdio(),cin.tie();
	freopen("D:/Brian/Documents/Developing Project/ch1/Q_1_5/q_1_5_5.in", "r", stdin);
	cin>>s>>n;
	find(n);
	cout<<sum;
}
