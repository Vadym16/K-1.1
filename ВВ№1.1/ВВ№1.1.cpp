#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class Mass {
public:
	Mass(int S[], int n) {
		N = n;
		for (int i = 0; i < n; i++) {
			Sa[i] = S[i];
		}
	}

	int min_el() {

		int min_abs = 100, min_e, a;

		for (int i = 0; i < N; i++) {
			a = abs(Sa[i]);
			if (min_abs > a) {
				min_abs = a;
				min_e = i;
			}
		}
		return min_e;
	}

	int sum_abs() {
		int temp;
		double sum_a=0;
		for (int i = 0; i < N; i++) {
			if (Sa[i] < 0) {
				temp = i+1;
				break;
			}
		}
		while(temp < N){
			sum_a += abs(Sa[temp]);
			temp++;
		}
		return sum_a;
	}

	void sort() {
		int neg[100] = { 0 }, noneg[100] = {0};
		int n_count = 0, nn_count = 0, temp;
		for (int i=0; i < N; i++) {
			if (Sa[i] < 0 ) {
				neg[n_count++] = Sa[i];
			}
			else {
				noneg[nn_count++] = Sa[i];
			}
		}

		for (int i = 0; i < n_count - 1; i++) {
			for (int j = 0; j < n_count - i; j++) {
				if (neg[j] > neg[j + 1]) {
					temp = neg[j];
					neg[j] = neg[j + 1];
					neg[j + 1] = temp;
				}
			}
		}

		for (int i = 0; i < n_count; i++) {
			Sa[i] = neg[i];
		}
		for (int i = 0; i < nn_count; i++) {
			Sa[n_count + i] = noneg[i];
		}

		for (int i = 0; i < N; i++) {
			cout << Sa[i] << " ";
		}

	}
	void view(){
		for (int i = 0; i < N; i++) {
			cout << Sa[i] << " ";
		}
		cout << endl;
	}

private:

	int Sa[100];
	int N;

};



int main()
{
	setlocale(LC_ALL, "ukr");
	srand(time(NULL));

	int n, b;
	int S[100];
	cout << "Введіть кількість елементів "; cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) {
		S[i] = rand() % 20 - 10;
	}

	Mass arr(S, n);

	cout << "Початковий масив масив" << endl;
	arr.view();
	cout << "Виберіть дію" << endl;
	cout <<"1.Номер мінімального модуля числа: "<< endl;
	cout <<"2.Сума модулів після першого мінусового значення: "<< endl;
	cout <<"3.Масив упорядкованих негативних елементів які знаходяться зліва" << endl;
	cout << "4.Вихід з програми" << endl;

	do {
		cin >> b;
		switch (b) {
		case 1: cout << arr.min_el(); break;
		case 2: cout << arr.sum_abs(); break;
		case 3: arr.sort();  arr.view(); break;
		case 4: return 0;  break;
	}
	
	
	} while (true);
	


	return 0;
}


