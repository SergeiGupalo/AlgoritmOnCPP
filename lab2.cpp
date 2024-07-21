#include <iostream>
#include <ctime>
#include <queue>
#include <cmath>

using namespace std;

struct queue{
	static const int max_size = 3 * 5 + 50;
	int size = 3 * 5 + 50;
	int mas[max_size];
	int start = 0;
	int end = 0;
}f;

void zapolnen(){
	for( int i = 0; i < f.size; i++){
		f.mas[f.end++] = rand()%100 + 1;
	}
}

void gstore(int x){
	f.size++;
	f.mas[f.end++] = x;
}

int gretrive(){
	f.size--;
	return f.mas[f.start++];
}

bool prost(int n){
	if(n <= 1){
		return false;
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	srand(time(NULL));

	int d;
	int pst = 0;
	int npst = 0;
	char var;

	intro:
		cout << "Choose an action: " << endl;
		cout << "1 - Add a new item to the end of the list;" << endl;
		cout << "2 - Delete the first item;" << endl;
		cout << "3 - Fill the stack with random numbers from 1 to 100;" << endl;
		cout << "4 - Display queue elements that are prime numbers in the console;" << endl;
		cout << "5 - Display all values;" << endl;
		cout << "6 - Finish the job!" << endl;
		cout << "What to do? ";
		cin >> var;

		switch(var){
			case'1':
				if(f.size == f.max_size){
					cout << "The queue is full!" << endl;
					goto intro;
				}
				else{
					cout << "Enter the element you want to add: ";
					cin >> d;
					gstore(d);
					goto intro;
				}

			case'2':
				if(f.end == 0){
					cout << "Stack empty!" << endl;
					goto intro;
				}
				else{
					gretrive();
					goto intro;
				}

			case'3':
				zapolnen();
				cout << "Stack full!" << endl;
				goto intro;

			case'4':
				cout << "Simple elements = ";
				for(int i = 0; i < f.end + 1; i++){
					if(prost(f.mas[i])){
						cout <<" " << f.mas[i] << " ";
					}
				}
				cout << endl;
				goto intro;

			case'5':
				for(int i = f.start; i < f.end; i++){
					cout << " " << f.mas[i] << " ";
				}
				goto intro;

			case'6':
				return 0;

			default:
				goto intro;
		}
}
