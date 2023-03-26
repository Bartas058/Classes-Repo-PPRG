#include <iostream>
#include <chrono>

using namespace std;

int symbolNewtona(int n, int k)
{
    if (k == n || k == 0)
        return 1;
    
    return symbolNewtona(n - 1, k - 1) + symbolNewtona(n - 1, k);
}

int algorytmEuklidesa(int a, int b)
{
    if (a == 0)
        return b;
    
    return algorytmEuklidesa(b % a, a);
}

int main()
{
	const int N = 42;
	int value1 = 0, value2 = 0;
	int a, b;
	a = 15;
	b = 5;

	//auto function1 = sumIterative;
	//auto function2 = sumRecursive;

	//auto function1 = factorialIterative;
	//auto function2 = factorialRecursive;

	auto function1 = symbolNewtona;
	auto function2 = algorytmEuklidesa;

	for (int i = 1; i < N; i++) {
		auto begin = chrono::high_resolution_clock::now();
		value1 = function1(a, b);
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin);

		cout << "Iter(" << i << ") = " << value1;
		cout << " time: " << elapsed.count() << " s";

		begin = chrono::high_resolution_clock::now();
		value2 = function2(a, b);
		end = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin);

		cout << " Rec(" << i << ") = " << value2;
		cout << " time: " << elapsed.count() << " s" << endl;

	a++;
	b++;
	
	}
	
	return 0;
    
}