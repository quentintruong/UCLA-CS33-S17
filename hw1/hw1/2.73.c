int saturating_add(int x, int y){//only works if x and y are already in the range
    int sum = x + y;
    
    int w = sizeof(int)<<3 -1;
    int x_sign = x>>w;
    int y_sign = y>>w;
    int sum_sign = sum>>31;//sign should match x or y
    
    int pos_overflow = ~x_sign & ~y_sign & sum_sign;//is -1 if sum >2147483647
    int neg_overflow = x_sign & y_sign & ~sum_sign;//is -1 if sum < 2147483648
    int has_overflow = pos_overflow | neg_overflow;//is -1 if overflow
    
    return (INT_MAX & pos_overflow) | (INT_MIN & neg_overflow) | (sum & ~has_overflow);
}
