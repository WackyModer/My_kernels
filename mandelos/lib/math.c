double power(double base, int exponent){
    double result = 1.0;

    if (exponent >= 0) {
        for(int i = 0; i < exponent; i++) {
            result *= base;
        }
    }else {
        for (int i = 0; i < -exponent; i++) {
            result /= base;
        }
    }
    return result;
}

double factorial(double n){
    double result = 1.0;

    while(n>1){
        result *= n;
        n--;
    }

    return result;
}

double sin(double x){
    double result = 0.0;
    int n;

    for(n = 0; n <= 20; n++) {
        double term = power(-1, n)* power(x, 2*n+1) / factorial(2*n+1);
        result += term;
    }
    return result;
}


double cos(double x){
    double result = 0.0;
    int n;

    for(n = 0; n <= 20; n++) {
        double term = power(-1, n)* power(x, 2*n) / factorial(2*n);
        result += term;
    }
    return result;
}