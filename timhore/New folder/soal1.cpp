/*
55651
*/
#include <iostream>
#include <string>

using namespace std;

//char limited to alpha
bool is_upper(char c){
	if (c >= 'a' && c<= 'z')
		return false;
	else return true;
}

void print(int st){
	if (st == 0)
		cout << "none" << endl;
	else if (st == 1)
		cout << "chef" << endl;
	else if (st == 2)
		cout << "brother" << endl;
	else
		cout << "both" << endl;
}

int main (){
	int T, N, K ;
	
	cin >> T;
	for (int i =0; i< T; i++){
		cin >> N;
		cin >> K;
		string s;
		cin >> s;
		int uppercount = 0;
		for (int j =0; j< N; j++){
			if (is_upper(s[j])) uppercount ++;
		}
		
		int a, b;
	    int lowercount = s.size() - uppercount;
		
		a = (K - lowercount >=0) ? 2 : 0;
		b = (K - uppercount >=0) ? 1 : 0;
		
		print (a+b);
		
	}
	
	return 0;
}
