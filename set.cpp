#include<iostream>
using namespace std;

class Set{

	int a[20];  //n is size
	public:
	int n;
		Set(){ n=0;} //default constructor to initialise n
		void Create();
		void Display();
		int Search(int x);
		void Union(Set A, Set B);
		void Intersect(Set A,Set B);
		
};

void Set::Create(){
	int x;
	cout<<"\n Enter number of elements: ";
	cin>>x;
	for(int i =0;i<x;i++){
		cout<<"\nEnter Element: ";
		cin>>a[n++];
	}	
}

void Set::Display(){
	for(int i =0;i<n;i++){
		cout<<a[i]<<" ";
	}
}


int Set::Search(int x){
	for(int i =0;i<n;i++){
		if(x==a[i]) return 1;
	}
	return 0;
}


void Set::Union(Set A,Set B){
	int i,x;
	for(i =0;i<A.n;i++){
		a[n++]= A.a[i];
	}
	for(i =0;i<B.n;i++){
		x = B.a[i];
		if(Search(x)==0){
		 a[n++]=x;
		 }	 
	}
}

void Set::Intersect(Set A, Set B){
	int x;
	int size;
		if(A.n>B.n) size = A.n;
		else size = B.n;
		
	for(int i =0; i< size;i++){
	x=B.a[i];
	if(A.Search(x)==1){
		a[n++]=x;	
		}
	}
}


int main(){
Set set;
Set A,B,C;
	int ch;

	while(true){
		cout<<"\n---Set Operations---\n 1.Add element \n 2.Display Set elements \n 3.Search in Set \n 4.Union of Two sets \n 5.Intersection \n 6.Exit \n\n Enter choice ";
		cin>>ch;
			switch(ch){

				case 1: 
						  set.Create(); break;

				case 2: 
						set.Display(); break;

				case 3: 
						cout<<"\n Enter key to be searched ";
						int key;
						cin>>key;

						if(set.Search(key)==1) cout<<"\n Found";
						else cout<<"\n Not found";

						break;
				
				case 4: A.n = B.n =  C.n =0;
						  cout<<"\n Enter elements in set A";
						  A.Create();
						  cout<<"\n Enter elements in set B";
						  B.Create();
						  C.Union(A,B);
						  C.Display();
						  break;
				case 5: A.n = B.n =  C.n =0;
						  cout<<"\n Enter elements in set A";
						  A.Create();
						  cout<<"\n Enter elements in set B";
						  B.Create();
						  C.Intersect(A,B);
						  C.Display();
						  break;
						  
						  
				case 6: exit(0); break;
				default: cout<<"\nInvalid choice!";
				break;
			}//switch case loop
		}//while loop
return 0;}