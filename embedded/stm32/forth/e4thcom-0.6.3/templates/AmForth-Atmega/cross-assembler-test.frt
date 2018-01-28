\ ----- Test for the AvrAsm cross-assembler for e4thcom  -----       MM-150406
\
\       derived from assembler-test.frt from amforth 5.1


only forth also

#require code

\xas warning off

\xas R24 equ TOSL  R25 equ TOSH

\xas : loadtos, TOSL Y+ ld, TOSH Y+ ld, ; \ define macro
\xas : savetos, -Y TOSH st, -Y TOSL st, ; \ from macros.asm

hex

code dup_ ( x -- x x )
     savetos, end-code   \ insert asm code
code drop_ ( x -- )
     loadtos, end-code

code ++_      \ ( x1 x2 x3 -- x4 ) 
  R14 2 ldi,   \ + +
  label>
  R16 Y+ ld,
  R17 Y+ ld,
  R24 R16 add,
  R25 R17 adc,
  R14 1 subi,
  <radr brne,
end-code

code demojmp1 \ demo jump + dup
  adr> 0 jmp,       \ -+
   label>           \  |  +>-+
         clc,       \  |  |  |
    adr> rjmp,      \  |  |  +-+
         nop,       \  |  |    |
    <labelr         \  |  |  +<+
    adr> brcc,      \  |  |  +-+
         nop,       \  |  |    |
  rot <labell       \  +> |    |
   swap <radr rjmp, \   '-+    |
    <labelb         \        <-+
         savetos,
end-code

code demojmp2 \ version with vector
  adr> 0 jmp,   0 >lbl \ addr->lbl[0]
   label>       1 >lbl
         clc,
    adr> rjmp,  2 >lbl
         nop,
    2 <lbl <labelr
    adr> brcc,  3 >lbl
         nop,
  0 <lbl <labell       \ lbl[0]->tos
   1 <lbl <radr rjmp,
    3 <lbl <labelb
         savetos,
end-code

2 3 4 ++_ .        \ 9   :
5 6 drop_ dup_ . . \ 5 5 :
7 demojmp1 . .     \ 7 7 :
8 demojmp2 . .     \ 8 8 :

\ end of file
