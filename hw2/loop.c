long loop(long x, int n){
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask<<n){
        result |= x&mask;
    }
    return result;
}
/*
 A.
 x is in %rdi
 n is in %cl
 result is in %rax
 mask is in &rdx
 
 B.
 initial result is 0
 initial mask is 1
 
 C.
 mask != 0
 
 D.
 mask = mask<<n
 
 E.
 result |= x&mask;
 
 F.
 see above
*/
