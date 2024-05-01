#include<iostream>
#include<cstdlib>
using namespace std;


class Hashing{

public:
	long int Hash_Table[10];

Hashing(){
for(int i =0;i<10;i++) Hash_Table[i]=-1;
}

long int read(){
	long int key;
	cout<<"\nEntre Mobile Number(Key): ";
	cin>>key;
	return key;	
}

void linear_probe(long int key){
	int index = key%10;

	if(Hash_Table[index]==-1){
		Hash_Table[index]=key;
	}

	else{
		while(Hash_Table[index]!= -1){
		index= (index +1)%10;
		}
		Hash_Table[index]=key;
	}
}

void quadratic_probe(long int key){
	int index = key%10;
	int i =1;

	if(Hash_Table[index]==-1){
		Hash_Table[index]=key;
	}
	else{ 
		while(Hash_Table[index]!= -1){
		index= (key + (i*i))%10;
		cout<<"**"<<index;
		i++;
		}
		Hash_Table[index]=key;
	}

}
void display(){
	for(int i=0;i<10;i++){
		cout<<Hash_Table[i]<<endl;
	}
}


};



int main(){

Hashing hash;

	int ch;
	int n;
	while(true){
	
	cout<<"\n 0.Enter Number of keys \n 1. Display List \n 2. Linear Probe \n 3. Quadratic Probe \n 59. Flush Hash Table\n 60. Exit \n\n\n Enter choice: ";
	cin>>ch;
	switch(ch){
		case 0: cin>>n;
		        break;
		case 1: hash.display();
			  break;
		case 2: for(int j =0;j<n;j++){
			  hash.linear_probe(hash.read());
			  }
			  break;
			  
		case 3: for(int j =0;j<n;j++){
		        hash.quadratic_probe(hash.read());
			  }
			  break;
		case 59: for(int k=0;k<10;k++){
				hash.Hash_Table[k]=-1;
				}
		case 60: exit(0);
				break;
		default: cout<<"Invalid input";
			   break;
		}
	}
	
return 0;
}