section .data
    hello db "Hello, Holberton",10  ; The string to print with a newline character (10)

section .text
    global main
    extern printf

main:
    ; Prepare arguments for printf
    mov rdi, hello  ; Address of the format string
    xor rax, rax   ; Clear RAX register (no floating-point args)
    call printf    ; Call the printf function

    ; Exit the program
    mov rax, 60     ; syscall number for exit
    xor rdi, rdi    ; status = 0
    syscall

