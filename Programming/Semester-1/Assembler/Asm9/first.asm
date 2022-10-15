.586
.MODEL FLAT, C
.CODE
ASM_FUNC PROC C x : dword, mas : dword, rez : dword
mov esi, mas
mov ebx, [esi]
mov ecx, x
sub ecx, ebx
mov eax, ecx
mov ebx, [esi + 4]
mov ecx, x
sub ecx, ebx
imul eax, ecx
mov ebx, [esi + 8]
mov ecx, x
sub ecx, ebx
imul eax, ecx
mov ebx, [esi + 12]
mov ecx, x
sub ecx, ebx
imul eax, ecx
mov ebx, [esi + 16]
mov ecx, x
sub ecx, ebx
imul eax, ecx

ret
ASM_FUNC ENDP
END
