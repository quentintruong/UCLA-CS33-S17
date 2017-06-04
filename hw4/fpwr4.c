static float u2f(unsigned u) {
    return * (float*) &u;
}


float fpwr4(int x){
    unsigned exp, frac;
    unsigned u;
    
    if (x < -74){//2^-149
        exp = 0;
        frac = 0;
    }
    else if (x < -63){//2^-149; 4^-1 0100 0000; 4^-2 0001 0000; 23; 4^-62 2^-124; 0,00000000,0...23...1;
        exp = 0;
        frac = 1 << (149+2x);//1 * 2^-126 * 2^-23 = 2^-149
    }
    else if (x < 64){//2^-127; 4 000000100; 16 00010000
        exp = 2x+127;
        frac = 0;
    }
    else {//2^127
        exp = 255;
        frac = 0;
    }
    
    u = exp << 23 | frac;
    return u2f(u);
    
}
