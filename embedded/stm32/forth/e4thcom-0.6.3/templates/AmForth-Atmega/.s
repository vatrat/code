\ MM-121229: A .s variant that prints the TOS as the last value.

: .s ( -- )
   sp0 sp@ - 2 ?do sp0 i - @ u. 2 +loop
;

