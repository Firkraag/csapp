movl 8(%ebp), %eax
movl $0, %edx
divl 12(%ebp)
movl %eax, 4(%esp)
movl %edxl, (%esp)

