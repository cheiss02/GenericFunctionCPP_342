#include <iostream>
#include <vector>
using namespace std;
class Person {
	public: 
		string name;
		int age;
		
	Person(){
	}
	
	Person(string name_, int age_){
		this->name=name_;
		this->age=age_;
	}
	
	friend ostream & operator << (ostream &out,Person &per){
		out<<"("<<per.name<<","<<per.age<<")";
	}
	
	bool operator>(Person p) { //ascending order per name
		return (name > p.name)? true: false;
	}
	
	bool operator<(Person p){//descending order per age
		if(age<= p.age){
			if(age==p.age){
				return name > p.name;
			}else{
				return (age< p.age)? true: false;
			}
		}
		return false;
	}	
};

template <class T>
void exchange(T &data1, T &data2){
	T aux;
	aux=data1;
	data1=data2;
	data2=aux;
}

template<class T> 
void shortF(T array,int sizef,bool inverse=false) { 
	bool result;
	for(int i=0; i<sizef-1; i++){
		for(int j=i+1; j<sizef; j++){
			result= inverse? array[i]<array[j]:array[i]>array[j];
			if(result){
				exchange(array[i],array[j]);
			}
		}
	}
};

template<class T> 
void showF(T array, int sizef){
	for(int i=0; i<sizef; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main() { // =====================
	float numbers[] = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
	Person people[]={Person("Hal",20), Person("Susann",31),Person("Dwight",19),Person("Kassandra", 21),Person("Lawrence", 25),
	Person("Cindy", 22), Person("Cory", 27),Person("Mac", 19),Person("Romana", 27),Person("Doretha", 32),Person("Danna", 20),
	Person("Zara", 23),Person("Rosalyn", 26),Person("Risa", 24),Person("Benny", 28),Person("Juan", 33),Person("Natalie", 25)};
	int tNumbers=12;
	int tPeople=17;
  	
  	cout<<"Order numbers in ascending order"<<endl;
	shortF(numbers,tNumbers);
	showF(numbers,tNumbers);
	
	cout<<"\n\nOrder people in alphabetical order (lexicographically) per name"<<endl;
	shortF(people,tPeople);
	showF(people,tPeople);
	
	cout<<"\n\nOrder people in descending order per age, where a person with the same age shoulf be ordered alphabetical by name (lexicographically)"<<endl;
	shortF(people,tPeople,true);
	showF(people,tPeople);
	return 0;
}
