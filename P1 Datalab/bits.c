/*
 * CS:APP Data Lab
 *
 * <Quentin Truong 404782322>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;
    
    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc. Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */


int bang(int x) {
    //OR's the x and the two's-complement-negative and shifts it over 31. then takes the inverse of this. after shifting it over 31 bits and AND 1, 0 will be the only thing that ever returns 1 because of the inverse.
    return (~(x|(~x+1))>>31) & 1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //creates 32 bit long patterns for 01010101, 00110011, 00001111 and so on; then uses these patterns to extract and push over 1's from result sequentially. the last time you push it over, it will result in a number.
    int my85 = 85;
    int my51 = 51;
    int my15 = 15;
    int my255 = 255;
    int myhalf = 255;
    int res;
    
    my85 = my85<<16|85;
    my85 = my85<<8|my85;
    
    my51 = my51<<16|51;
    my51 = my51<<8|my51;
    
    my15 = my15<<16|15;
    my15 = my15<<8|my15;
    
    my255 = my255<<16|255;
    
    myhalf = myhalf<<8|255;
    
    res = (x&my85) + (x>>1&my85);
    res = (res&my51) + (res>>2&my51);
    res = (res&my15) + (res>>4&my15);
    res = (res&my255) + (res>>8&my255);
    res = (res&myhalf) + (res>>16&myhalf);
    return res;
}
/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    //if not the result of not x and not y, is equivalent to OR
    return ~(~x&~y);
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */




/*
 
 
 1
 11
 1111
 11111111
 1111111111111111
 0000000000000000000000111110000
 
 100001100001
 
 */
int bitRepeat(int x, int n) {
    //basically, create a mask to exclude the numbers you dont want. then apply this mask with the bitpattern repeatedly
    unsigned int apply;
    
    int mask = 1 << 31;
    mask = mask >> 32-n << 1;
    
    mask = ~mask;
    apply = x & mask;
    
    mask = mask;
    apply = ((apply<<n)&~mask) | apply;
    
    mask = mask<<n |mask;
    n = n<<1;
    apply = ((apply<<n)&~mask) | apply;
    
    mask = mask<<n |mask;
    n = n<<1;
    apply = ((apply<<n)&~mask) | apply;
    
    mask = mask<<n |mask;
    n = n<<1;
    apply = ((apply<<n)&~mask) | apply;
    
    mask = mask<<n |mask;
    n = n<<1;
    apply = ((apply<<n)&~mask) | apply;
    return apply;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    //shifts x using n to see if itll stay the same
    int shift = 33 + ~n;
    int myx = x << shift;
    myx = myx >> shift;
    return !(myx ^ x);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    //just extracts the bits by shifting the number by the proper number of bytes; uses a mask and shifting to exclude what you dont want.
    int shift = n << 3;
    int mask = ~(1 << 31 >> 23);
    int res = (x >> shift) & mask;
    return res;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    //adds the two numbers with a saturating add from hw1. determines whether lessthanorequal based on overflow
    int myx = ~x+1;
    
    int xMask = myx >>31;
    int yMask = y >> 31;
    
    int res = y+myx;
    int resMask = res >> 31;
    
    int posOverflowMask = ~xMask & ~yMask & resMask;
    int negOverflowMask = xMask & yMask & ~resMask;
    
    int overflowMask = posOverflowMask | negOverflowMask;
    
    return !!((~resMask & ~overflowMask) | posOverflowMask | !(myx^(1<<31)));
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    //takes the negative and the inverse, shifts them both by 31. if it both have a 1 in the least significant bit, than it must be positive because of the inverse
    int negx = ~x+1;
    int flipx = ~x;
    int shiftneg = negx >> 31;
    int flipneg = flipx >> 31;
    int neg = 1;
    
    return (shiftneg & neg) & (flipneg & neg);
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    //just uses a mask to shift the numbers, excluding the 1's that appear from arithmetic shift
    int myx = x;
    int xmask = ~0 << 31;
    xmask = ~(xmask >> n << 1);
    myx = myx >> n & xmask;
    return myx;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    //just takes 1 and shifts it over 31, giving you the two's complement min
    return 1<<31;
}
