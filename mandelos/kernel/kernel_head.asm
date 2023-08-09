[bits 32]
global krand
global ksleep
global ktimerstart
global ktimerend
[extern main]


[bits 32]

pmkernel:
;call a20_test ; tests to see if the a20 line is already enabled for us!

;screen size is 320x200 256 color
;https://wiki.osdev.org/Drawing_In_a_Linear_Framebuffer
push ebp
push dx
mov ebp, 0x0f

mov dl,[0x062D]
;mov dl, 0x80

;this is broken because
;it was made for 320x200
;with 256 colors (8 bit)

;I'm using  320x200
;with 24 bit colors
;8 bit r, g, b
mov [0xA0630], dl
mov [0xA0631], dl
mov [0xA0770], dl
mov [0xA0771], dl
mov [0xA062D], dl
pop dx
pop ebp

;function to enable a20 line with keyboard controller.
call enable_A20
call a20_test

in al,0xee
call a20_test

in al, 0x92
or al, 2
out 0x92, al

call a20_test

call main

jmp $



krand:
 
    push ebp
    mov  ebp, esp
    rdtsc;reads the processor's time-stamp counter into EDX:EAX.xor,we use only eax
    mov ebx,dword [ebp+8];start
    mov ecx,dword [ebp+12];end
    xor edx,edx
    sub ecx,ebx
    div ecx;div eax to ecx;quotient => EAX = 11 ;remainder => EDX = 3
    add edx,ebx
    mov eax,edx
    mov esp, ebp
    pop ebp
    ret



ksleep:
    push ebp
    mov  ebp, esp
    mov ecx,dword [ebp+8];start
    ;1000 microwami=1 miliwami
    imul ecx,1000
    lp:
    out 0x80,al; need 1 milisecond
    
    loop lp

    mov esp, ebp
    pop ebp
    ret


a20_test:
    pushad
    mov edi,0x112345  ;odd megabyte address.
    mov esi,0x012345  ;even megabyte address.
    mov [esi],esi     ;making sure that both addresses contain diffrent values.
    mov [edi],edi     ;(if A20 line is cleared the two pointers would point to the address 0x012345 that would contain 0x112345 (edi)) 
    cmpsd             ;compare addresses to see if the're equivalent.
    popad
    jne a20_on        ;if not equivalent , A20 line is set.
    ret               ;if equivalent , the A20 line is cleared.

a20_on:
    call main
    jmp $
    ret

;this uses the keyboard controller
enable_A20:
    call    a20wait
    mov     al,0xAD
    out     0x64,al
    call    a20wait
    mov     al,0xD0
    out     0x64,al
    call    a20wait2
    in      al,0x60
    push    eax
    call    a20wait
    mov     al,0xD1
    out     0x64,al 
    call    a20wait
    pop     eax
    or      al,2
    out     0x60,al 
    call    a20wait
    mov     al,0xAE
    out     0x64,al 
    call    a20wait
    ret
 
a20wait:
    in      al,0x64
    test    al,2
    jnz     a20wait
    ret
 
 
a20wait2:
    in      al,0x64
    test    al,1
    jz      a20wait2
    ret