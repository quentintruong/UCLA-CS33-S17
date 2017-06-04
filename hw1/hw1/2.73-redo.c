int saturating_add(int x, int y){
    int sum;
    int has_overflow = ~-__builtin_add_overflow(x, y, &sum);
    
    int x_sign = x >> 31;
    int y_sign = y >> 31;
    int sum_sign = sum >> 31;

    int pos_overflow = ~x_sign & ~y_sign & sum_sign;
    int neg_overflow = x_sign & y_sign & ~sum_sign;

    int res = (has_overflow & sum) | (pos_overflow & INT_MAX) | (neg_overflow & INT_MIN);

    return res;
}
