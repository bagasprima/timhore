#include <iostream>
#include <string>

using namespace std;

int jumlah[4]; //0 = a, 1 = b, 2 = ab, 3 = ba

void insert_string(string& s){
    if (s == "a" || s == "aa")
        jumlah[0]++;
    else if (s == "b" || s == "bb")
        jumlah[1]++;
    else if (s == "ab")
        jumlah[2]++;
    else 
        jumlah[3]++;
}

void clear_jumlah(){
    for (auto& s : jumlah){
        s = 0;
    }
}

int countst(){
	int ct = 0;
	if (jumlah[2] >0 || jumlah[3] > 0){
		//count here
		int bigger, smaller;
		if(jumlah[2] >= jumlah [3]){
			bigger = 2;
			smaller = 3;
		}
		else{
			bigger = 3;
			smaller = 2;
		}
			
		
		jumlah[bigger]--;
		ct+=2;
		ct+=jumlah[smaller];
		if (jumlah[bigger] > jumlah[smaller])
		{
			int x = (jumlah[bigger] - jumlah[smaller]) *2;
			ct += x;
			ct+=jumlah[smaller];
		}
		else 
		{
			ct += jumlah[bigger];
		}
	}
	
	if (ct > 0)
		return ct;
	else {
		//hitung a sama b
		if (jumlah[0] > 0)
			ct++;
		if (jumlah[1] > 0)
			ct++;
		return ct;
	}
}

int main(){
    int T, n;
    string s;
    
    cin >> T;
    for (int i = 0; i< T; i++){
        clear_jumlah();
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> s;
            insert_string(s);
        }
        cout << countst() << endl;
    }
    return 0;
}
