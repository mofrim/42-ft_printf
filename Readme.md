# readme for ft_printf

## TODOs

- [ ] unify way of commenting funcs. in header, or in source file?

## Progress

### 'd' and 'i'

- [x] minus
- [x] plus
- [x] zero
- [x] space
- [x] dot

### u

- [x] minus
- [x] plus
- [x] zero
- [x] space
- [x] dot



## a rule-set for printf conversions shall be defined!

1) any '-' invalidates any '0' and any ' '
2) you can wildly mix -, + and 0's. but, rule No.1, 0's will be ignored
   alongside -'s. still - and + will count!
3) after **any (positive) number** there can **only** be a single '.' and
   eventually **another number** but nothing else (except the conversion char)!
4) also the mighty '#' + conv_char cannot be after the 
5) so it seems, there can be any wild mix of the flags '+', '-', ' ', '#' and
   '0' ('+' and '#x' is a bit special..) followed by a number a dot and a
   number. that's it. so for example: "%+--  0#0 + -x" is perfectly valid
   **this means:** we can simply test valid compl_convs based on this ruleset!
6) the '#' rules:
    - only is supposed to work with 'x', 'X'

## fine grained rules for every flag

### zero rules

- [x] '-' present => ignore '0'
- [x] ' ' and '0' shall work together
- [x] '+' and '0' shall work together, but '+' overrides space anyway
- [x] '.' superceedes '0'

### prec rules

- [x] '-' is ignored
- [x] ' ' and '+' are respected
- [x] if width <= prec number is zero padded. if width > prec number including
      sign is ' ' padded until prec or sign
- [x] if '-' is given the width-padding happens to the right of the number


## conversions & flags i have to deal with

- conversions:
 • %c Prints a single character.
 • %s Prints a string (as defined by the common C convention).
 • %p The void * pointer argument has to be printed in hexadecimal format.
 • %d Prints a decimal (base 10) number.
 • %i Prints an integer in base 10.
 • %u Prints an unsigned decimal (base 10) number.
 • %x Prints a number in hexadecimal (base 16) lowercase format.
 • %X Prints a number in hexadecimal (base 16) uppercase format.

- flags:
 • Manage any combination of the following flags: ’-0.’ and the field minimum width
   under all conversions.
 • Manage all the following flags: ’# +’ (Yes, one of them is a space)

**Question** what is the meaning of '.' when there is no float conversion?

from manpage:
    the overall syntax for conversion specification is:
    %[$][flags][width][.precision][length modifier]conversion

## conversion notes:

* '-': overrides 0 if present, left justification in field boundary. this means
       everything right of number is filled with whitespaces. 
       **can have multiple '-'** but this does not have any effect.
* '0': if also '-' is given '0' is ignored. pads d, i, o, u, x, X, a, A, e, E,
       f, F, g, and G with zeros
* '.': usually this is for precision with floats... for i, u, x, X this also
       pads by zero even in the presence of '-'
* 'x' and 'X': can only convert up to unsigned int.
* width: there **must not** be any flag between the conversion specifier and the
         width.

so, '-.10d' works. '-010d' only left justifies without padding by zero.

so a algorithm for deciding if we have valid, usable flags would be:

1) check if first char after % is a '-'
2) if next few digits are a valid unsigned int 

...
