movl 8(%ebp), %eax
sall $2, %eax
movl 12(%ebp), %ecx
sarl %cl, %eax
