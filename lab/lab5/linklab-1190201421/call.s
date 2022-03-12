movl 0x4(%esp), %ecx
lea 0xe6a(%ecx), %ecx
push %ecx
lea -0xe4b(%ecx), %ecx
call *%ecx
pop %ecx
