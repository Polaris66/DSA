#include <iostream>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		bool done = false;
		char a[3][3];
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cin>>a[i][j];
			}
		}
		
		if(!done && a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.'){
			cout<<a[0][0]<<endl;
			done = true;
		}
			
		if(!done && a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] != '.'){
			cout<<a[0][2]<<endl;
			done = true;
		}
				
		for(int i = 0; i < 3; i++){
			if(!done && a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '.'){
				cout<<a[i][0]<<endl;
				done = true;
			}
			if(!done && a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '.'){
				cout<<a[0][i]<<endl;
				done = true;
			}
		}
		
		if(!done){
			printf("DRAW\n");
		}
	}
}
