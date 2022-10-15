#include <iostream>
using namespace std;
extern "C" int ASM_FUNC(int x, int mas[5], int rez);
int main() {
	int x;
	int mas[5] = { 2,4,8,16,32 };
	int rez = 1;
	system("chcp 1251");
	system("cls");
	cout << "¬ведите x : ";
	cin >> x;
	cout << "(x-2)*(x-4)*(x-8)*(x-16)*(x-32)=" << ASM_FUNC(x, mas, rez);
	cin.get(); cin.get();
	return 0;
}
