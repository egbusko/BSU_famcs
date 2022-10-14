//
////¹1
//#include <iostream>
//using namespace std; 
//void main()
//{
//	int m, n, b;
//	cout << "Enter 2 numers\n";
//	cin >> n >> m;  //b=m*m+n*n+m, all numbers are natural
//	_asm
//	{	mov eax, m		//fills eax with m
//		mov ebx, m		//fills ebx with m
//		mul m			//eax=eax*m
//		add ebx, eax	//ebx=ebx+eax
//		mov eax, n		//fills eax with n
//		mul n			//eax=eax*n
//		add ebx, eax	//ebx=ebx+eax
//		mov b, ebx		//fills b with ebx
//	}
//	cout <<b<<"\n";
//	system("pause");
//}


//
////¹2
//#include <iostream>
//using namespace std;
//void main()
//{
//	setlocale(LC_ALL, ".1251");
//	unsigned int a, b, c, min;
//	cout << "Enter three natural numbers:\n";
//	cin >> a >> b >> c;
//	_asm
//	{	mov eax, a		//eax=a
//		cmp eax, b		//compares
//		cmova eax, b	//(b<eax): eax=b
//		cmp eax, c		//compares
//		cmova eax, c	//(c<eax): eax=c
//		mov min, eax	//min=eax
//	}
//	cout << "\n---------------------------\n";
//	cout << "The smallest of the three natural numbers is: ";
//	cout << min << endl;
//	system("pause");
//
//}


//
////¹3
//#include <iostream>
//using namespace std;
//void main() {
//	int a, n, res;
//	cout << "Enter a number and a degree of this number\n";
//	cin >> a >> n;
//	n--;
//	_asm {
//		mov ecx, n
//		mov ebx, a
//		F : imul ebx, a
//			loop F
//
//			mov res, ebx
//	}
//	cout << "The result is ____ "<<res<<"\n";
//	system("pause");
//}



//¹4
#include <iostream>
using namespace std;
void main() 
{
	int a, n;
	cout << "Enter a number\n";
	cin>>a;
	_asm
	{
		mov eax, a		//put à into eax 
		mov ecx, 0		// put 0 into åñõ 
		mov ebx, 10		//put 10 into ebx
		mov edx, 0		//put 0 into edx
		N1:	xor edx, edx
			div ebx		//divide eax by 10, the integer part is written in eax
			inc ecx		// add 1 into åñõ 
			cmp eax, 0
			ja N1

		mov n, ecx
	}
	cout<<"There are "<<n<<" numbers in "<<a<<"\n";
	system("pause");
}
