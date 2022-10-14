//
//#include <iostream>
//using namespace std;
//int main()
//{
//	int value;
//	cout << "Value: ";			
//	cin >> value;
//	int del = 2, result = 0;
//	if (value == 1)
//	{
//		cout << "Yes" << endl;
//		return 0;
//	}
//		_asm
//		{
//				mov eax, value	//fills eax with value
//				mov ebx, del	//fills ebx witn del
//		_for1:
//				mov edx, 0		//fills edx, 0
//				div ebx			//Divides eax by ebx
//				cmp edx, 0		//compares
//				je _end			//step if edx = 0 to _end 
//				inc ebx			//increases ebx by 1
//				mov eax, value	//fills eax with value
//				cmp ebx, eax	//compares
//				jl _for1		//step if ebx < eax to _for1
//				je end_1		//step if ebx=eax to end_1 
//		_END: MOV ecx, 1		//fills ecx with 1
//				mov result, ecx	//fills result with ecx
//				jmp _finish		//step to _finish
//		end_1: MOV ecx, 0		//fills ecx, 0
//				mov result, ecx	//fills result wiht ecx
//		_finish: nop			//empty command
//		}
//		if (result) cout << "No" << endl;
//		else cout << "Yes" << endl;
//		system("pause");
//		return 0;	
//}



//
//#include <iostream>
//using namespace std;
//void main()
//{
//int n = 0, res = 0;
//cin  >>n;
//_asm 
//{
//	mov ecx, n					// fills eñx with n
//	mov eax, 0					// fills eax with 0 
//	mov ebx, 1					// fills ebx with 1 
//	mov edx, 0					// fills edx with 0 
//	_for1:						
//		mov eax, 0				// fills eax with 0 
//		add eax, ebx			// eax += ebx
//		add eax, edx			// eax += edx
//		mov edx, ebx			// edx = ebx
//		mov ebx, eax			// ebx = eax
//		loop _for1				// repeat until ecx > 0
//		
//		mov res, eax			// fills res with eax 
//}
//cout << res<<"\n";
//system("pause");
//}



#include <iostream>
using namespace std;
void main() {

	int n, m, resn = 0, resm = 0, resnm = 0, res = 0;
	cin >> n;
	cin >> m;

	_asm {

		mov eax, 1
		mov ebx, 1

		mov ecx, n
		loop1 :
		imul ebx, eax
			inc eax
			loop loop1
			mov resn, ebx
			mov eax, 1
			mov ebx, 1
			mov ecx, m
			loop2 :

		imul ebx, eax
			inc eax
			loop loop2
			mov resm, ebx
			mov eax, 1
			mov ebx, 1
			mov ecx, n
			sub ecx, m
			loop3 :

		imul ebx, eax
			inc eax
			loop loop3
			mov resnm, ebx
	}
	cout << resn / resm / resnm << endl;
	system("pause");
}
