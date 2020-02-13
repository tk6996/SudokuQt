    global isRow
    global isColumn
    global isBox
    global isSafe
    global randseqNum
    global fillDiagonal
    global solveSudoku
    global checkSolution
    global randompick
    global generateSoduku
    extern rand
    extern srand
    bits 64
    %define size 9
    %define sqsize 3
    section .text
isRow:;bool isRow(byte *board[rcx],byte row[rdx],byte number[r8])
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    mov rax , size
    mul dl
    add rcx , rax
    mov rdx , rcx
    add rdx , size
    loop_isRow:
        cmp byte[rcx] , r8b
        je exit1
        inc rcx
        cmp rcx , rdx
        jb loop_isRow
    jmp exit0

isColumn:;bool isColumn(byte *board[rcx],byte coloumn[rdx],byte number[r8])
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    add rcx , rdx
    mov rdx , rcx
    add rdx , size * size
    loop_isColumn:
        cmp byte[rcx] , r8b
        je exit1
        add rcx , size
        cmp rcx , rdx
        jb loop_isColumn
    jmp exit0

isBox:;bool isBox(byte *board[rcx],byte startRow[rdx],byte startCol[r8],byte number[r9])
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    mov rax , size
    mul dl
    add rcx , rax
    add rcx , r8
    mov rbx , rcx
    add rbx , size * sqsize
    loop_isBox_row:
        mov rdx , rcx
        add rdx , sqsize
        loop_isBox_col:
            cmp byte[rcx] , r9b
            je exit1
            inc rcx
            cmp rcx , rdx
            jb loop_isBox_col
        add rcx , size - sqsize
        cmp rcx , rbx
        jb loop_isBox_row
    jmp exit0

isSafe:;bool isSafe(byte *board[rcx],byte row[rdx],byte column[r8],byte number[r9])
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    push r8
    mov r8 , r9
    pop r9
    call isRow
    cmp rax , 1
    je exit0
    push rdx
    mov rdx , r9
    pop r9
    call isColumn
    cmp rax , 1
    je exit0
    push r8
    push rdx
    mov rax , r9
    mov rdx , r9
    mov rbx , sqsize
    div bl
    sub dl , ah
    pop r8
    mov rax , r8
    div bl
    mov al , ah
    sub r8b , al
    pop r9
    call isBox
    cmp rax , 1
    je exit0
    jmp exit1 ; safe
    
exit0:
    mov rax , 0
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbp
    ret

exit1:
    mov rax , 1
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbp
    ret

randseqNum:;void randseqNumNumber(byte *number[rcx])
    push rbp
    mov rbp , rsp
    mov rbx , size
    loop_randseqNum:
        push rcx
        call rand
        pop rcx
        div rbx
        dec rbx
        add rdx , rcx
        mov rax , rcx
        add rax , rbx
        mov r8b , byte[rdx]
        mov r9b , byte[rax]
        mov byte[rdx] , r9b
        mov byte[rax] , r8b
        cmp rbx , 1  
        jg loop_randseqNum
    pop rbp
    ret

fillDiagonal:;void fillDiagonal(byte *board[rcx])
    push rbp
    mov rbp , rsp
    push r11
    push r12
    push r13
    mov r11 , 0 ; int a = 0;
    loop_fillDiagonal:; do{
        mov r12 , 0; int b = 0;
         loop_fillDiagonal1:;do{
            mov r13 , 0;int c = 0;
            loop_fillDiagonal2:;do{
                push rcx
                call rand;int d = rand();
                pop rcx
                mov rdx , 0
                mov rbx , size
                div rbx ;d %= 9;
                inc rdx ;d += 1;
                mov r9 , rdx
                mov rdx , r11
                mov r8 , r11
                call isBox ;if(isBox(board,a,a,d))
                cmp rax , 1
                je loop_fillDiagonal2 ;continue;
                mov rdx ,r12
                add rdx , r11 ;int row = a + b;
                mov rbx , r13
                add rbx , r11 ;int col = a + c;
                mov rax , size
                mul rdx
                add rax , rbx
                add rax , rcx
                mov byte[rax] , r9b ;board[(row) * 9 + col] = d;
                inc r13 ;c++;
                cmp r13 , sqsize
                jb loop_fillDiagonal2 ;} while (c < 3);
            inc r12 ;b++;
            cmp r12 , sqsize
            jb loop_fillDiagonal1 ;} while (b < 3);
        add r11 , sqsize ;a+=3;
        cmp r11 , size
        jb loop_fillDiagonal ;} while (a < 9);
    pop r13
    pop r12
    pop r11
    pop rbp
    ret

solveSudoku:;bool solveSudoku(byte *board[rcx],byte *pattern[rdx],byte pos[r8]);
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    cmp r8 , size * size ; if(pos == 81)
    je exit1 ; return 1;
    mov rbx , rcx
    add rbx , r8 ;if(*(board + pos))
    cmp byte[rbx] , 0
    je solveSudoku_skip
    inc r8 ;++ pos ;
    call solveSudoku ;solveSudoku(board,pattern,pos);
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbp
    ret ;return 
    solveSudoku_skip:
        mov rsi , rdx ; byte *ptr = pattern;
        mov rdi , rsi ; byte *end = pattern + 9;
        add rdi , 9
        solveSudoku_loop:;do{
            push rdx
            push r8
            mov rdx , 0
            mov rax , r8
            mov rbx , size
            div rbx
            mov r8 , rdx
            mov rdx , rax
            movzx r9 , byte[rsi]
            call isSafe ;if(isSafe(board,pos/9,pos%9,*ptr))
            pop r8
            pop rdx
            cmp rax , 0
            je solveSudoku_skip1
            mov r11b , byte[rsi]
            mov byte[rcx+r8] , r11b ;board[pos] = *ptr;
            inc r8 ;++ pos ;
            push rsi
            push rdi
            call solveSudoku  ; if(solveSudoku(board,pattern,pos))
            pop rdi
            pop rsi
            cmp rax , 1
            je exit1 ; return 1;
            dec r8 ;-- pos ;
            solveSudoku_skip1: ;}
            inc rsi ;ptr++;
            cmp rsi , rdi
            jb solveSudoku_loop ;} while (ptr < end);
        mov byte[rcx+r8] , 0;board[pos] = 0;
        jmp exit0 ; return 0;

checkSolution: ;int checkSolution(byte *board[rcx],byte pos[rdx])
    push rbp
    mov rbp , rsp
    push rcx
    push rdx
    push r8
    push r9
    mov r10 , 0 ; int sol = 0;
    cmp rdx , size * size; if (pos == 81)
    je exit1;     return 1;
    mov rax , rcx
    add rax , rdx
    cmp byte[rax] , 0 ; if (*(board + pos))
    je checkSolution_skip; {
    inc rdx;     ++pos;
    call checkSolution;     return checkSolution(board, pos); }
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbp
    ret ;
    checkSolution_skip:
        mov r11 , 1; byte num = 1;
        checkSolution_loop:; do{
            push rdx
            mov rax , rdx
            mov rdx , 0
            mov rbx , size
            div rbx
            mov r8 , rdx
            mov rdx , rax
            mov r9 , r11
            push r10
            push r11
            call isSafe
            pop r11
            pop r10
            pop rdx
            cmp rax , 0
            je checkSolution_skip1;      if (isSafe(board, pos / 9, pos % 9, num)){
            mov rax , rcx
            add rax , rdx
            mov byte[rax] , r11b;         board[pos] = num;
            inc rdx;         ++pos;
            push r10
            push r11
            call checkSolution;         sol += checkSolution(board, pos);
            pop r11
            pop r10
            add r10 , rax
            dec rdx;         --pos;
            cmp r10 , 2;if(sol >= 2){
            jb checkSolution_skip1
            mov rax , rcx
            add rax , rdx
            mov byte[rax] , 0 ;board[pos] = 0;
            mov rax , r10; 
            pop r9
            pop r8
            pop rdx
            pop rcx
            pop rbp
            ret ;return sol;}
            ;}
            checkSolution_skip1:
            inc r11;           num++;
            cmp r11 , 10; } while (num < 10);
            jb checkSolution_loop
        mov rax , rcx
        add rax , rdx
        mov byte[rax] , 0; board[pos] = 0;
    mov rax , r10; 
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbp
    ret ;return sol;

randompick: ;int randompick(byte *board[rcx],int attemp[rdx]){
    push rbp
    push r10
    push r11
    push r12
    push r15
    mov rbp , rsp
    mov r10 , 0 ;int repeat = 0;
    mov r11 , 0 ;int round = 0;
    mov r15 , rdx
    ramdompick_loop:;do{
        push r11
        push r10
        push r15
        push rcx
        call rand ;int p = rand() % 81;
        pop rcx
        pop r15
        pop r10
        pop r11
        mov rbx , size * size
        mov rdx , 0
        div rbx
        add rdx , rcx
        cmp byte[rdx] , 0
        je ramdompick_loop ;if(board[p] == 0) continue;
        mov r12b , byte[rdx] ; int x = board[p];
        mov byte[rdx] , 0 ;board[p] = 0;
        push r12
        push r10
        push r11
        push rdx
        mov rdx , 0
        call checkSolution
        pop rdx
        pop r11
        pop r10
        pop r12
        inc r11;round++;
        cmp rax , 2;if(checkSolution(board,0) < 2){continue;}
        jb ramdompick_loop
        dec r11;round--;
        mov byte[rdx] , r12b;board[p] = x;
        inc r10;++repeat;
        cmp r10 , r15
        jb ramdompick_loop;} while (repeat < attemp);
    mov rax , r11;return round;}
    pop r15
    pop r12
    pop r11
    pop r10
    pop rbp
    ret

generateSoduku:;void generateSoduku(byte *board[rcx],int seed[rdx]){
    push rbp
    mov rbp , rsp
    push rcx
    mov rcx , rdx
    call srand ; srand(seed);
    mov rcx , seq
    call randseqNum; randseqNum(seq);
    mov rcx , qword[rsp]
    call fillDiagonal    ; fillDiagonal(board);
    mov rcx , qword[rsp]
    mov rdx , seq
    mov r8 , 0
    call solveSudoku; solveSudoku(board,seq,0);
    pop rcx
    pop rbp
    ret

    section .data
seq: db 1,2,3,4,5,6,7,8,9 ; byte seq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
