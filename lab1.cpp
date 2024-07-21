#include <iostream>
#include <ctime>

using namespace std;

int index = 1;

struct stack{
	static const int size = 3 * 5 + 50;
	int mas[size];
}s,p,np;

void zapol(){
	for(int i = 0; i < s.size; i++){
		index++;
		s.mas[i] = rand()%100+1;
	}
}

void push(int x){
	index++;
	s.mas[index] = x;
}

int pop(){
	return s.mas[index--];
}

int back(){
	return s.mas[index];
}

int size(){
	return index+1;
}

int main(){

	int d;
	char N;
	int par = 0;
	int nepar = 0;

	intro:
		cout << "Choose an action with a folder: " << endl;
		cout << "1 - Add a new item to the end of the stack;" << endl;
		cout << "2 - Remove item from stack;" << endl;
		cout << "3 - Learn the meaning of the last element;" << endl;
		cout << "4 - Find out the number of items in the stack;" << endl;
		cout << "5 - Fill the stack with random numbers from 1 to 100;" << endl;
		cout << "6 - Stack output to the screen;" << endl;
		cout << "7 - Display the even and odd stack element in the console;" << endl;
		cout << "8 - Finish work!" << endl;
		cout << "Your option: ";
		cin >> N;

		switch(N){
			case'1':
				if(index+1 == s.size){
					cout << "The stack is full!";
					goto intro;
				}
				else{
					cout << "Enter which item to add: ";
					cin >> d;
					push(d);
					goto intro;
				}

			case'2':
				if(index==1){
					cout << "The stack is empty!" << endl;
					goto intro;
				}
				else{
					pop();
					goto intro;
				}
			case'3':
				if(index==1){
					cout << "The stack is empty!" << endl;
					goto intro;
				}
				else{
					cout << "The last element of the stack = " << back() << endl;
					goto intro;
				}
			case'4':
				if(index== 1){
					cout << "The stack is empty!" << endl;
					goto intro;
				}
				else{
					cout << "Number of stack elements!" << size() << endl;
					goto intro;
				}
			case'5':
				zapol();
				cout << "Stack full!" << endl;
				goto intro;
			case'6':
				for(int i = 0; i < index + 1; i++){
					cout << s.mas[i] << " ";
				}
				cout << endl;
				goto intro;
			case'7':
				for(int i = 0; i < index +1; i++){
					if(s.mas[i] % 2 == 0){
						p.mas[par] = s.mas[i];
						par++;
					}
					else{
						np.mas[nepar] = s.mas[i];
						nepar++;
					}
				}
				cout << "Paired elements = ";
				for(int i = 0; i < par; i++){
					cout << p.mas[i] << " ";
				}
				cout << endl;
				cout << "Odd elements = ";
				for(int i = 0; i < nepar; i++){
					cout << np.mas[i] << " ";
				}
				cout << endl;
				goto intro;
			case'8':
				return 0;
			default:
				goto intro;
		}
}
