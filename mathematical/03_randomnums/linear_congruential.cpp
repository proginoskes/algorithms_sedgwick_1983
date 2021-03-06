# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <sstream>
# include <vector>


// this breaks the function up and then sums so
// as to prevent overflow when we multiply
// we can only represent ints less than 2^31
// so any terms of multiplication must be
// 2^15 or less
int safe_mul(int p, int q, int m1){
    int p1, p0, q1, q0;
    p1 = p / m1; p0 = p % m1;
    q1 = q / m1; q0 = q % m1;
    return (((p0*q1+p1*q0)%m1)*m1+ p0*q0);

}

// this has overflow!!
int * unsafe_lin_generate_seq(int seed, int max, int n){
    int iter, *a, cfact;
    a = (int *)malloc(n * sizeof(int));
    a[0] = seed;
    // a number with one less digit than m
    cfact = max/10;
    // and also that ends in x21 with x even
    cfact /= 1000;
    cfact *= 1000;
    cfact += 621;
    std::cout << "b:" << cfact<<"\n";

    for(iter=1; iter<n; iter++){
        a[iter] = (a[iter-1]*cfact + 1)%max;
    }
    return a;
}

int * better_safe_lin_generate_seq(int seed, int range, int max, int n){
    int iter, *a, cfact, m1=max;
    a = (int *)malloc(n * sizeof(int));
    a[0] = seed;
    // a number with one less digit than m
    cfact = max/10;
    // and also that ends in x21 with x even
    cfact /= 1000;
    cfact *= 1000;
    cfact += 621;
    std::cout << "b:" << cfact<<"\n";

    while(m1 > 32768){
        m1 = m1 >> 1;
    }

    for(iter=1; iter<n; iter++){
        a[iter] = ((safe_mul(a[iter-1],cfact, m1)%max) + 1)%max;
        // this version uses floats to get the ratio of
        // generated values to max and then multiplies by
        // a top-range value to remove the "counting up"
        // problem from before.
        // 
        a[iter] = (float(a[iter])/float(max))*float(range);
    }
    return a;
}

int * safe_lin_generate_seq(int seed, int max, int n){
    int iter, *a, cfact, m1=max;
    a = (int *)malloc(n * sizeof(int));
    a[0] = seed;
    // a number with one less digit than m
    cfact = max/10;
    // and also that ends in x21 with x even
    cfact /= 1000;
    cfact *= 1000;
    cfact += 621;
    std::cout << "b:" << cfact<<"\n";

    while(m1 > 32768){
        m1 = m1 >> 1;
    }

    for(iter=1; iter<n; iter++){
        a[iter] = ((safe_mul(a[iter-1],cfact, m1)%max) + 1)%max;
    }
    return a;
}


// argv: ./a.out seed max n mode
int main(int argc, char **argv){
    int *a, n, max, seed, iter, mode, range=0;

    seed = std::stoi(argv[1]);
    max = std::stoi(argv[2]);
    n = std::stoi(argv[3]);
    mode = std::stoi(argv[4]);
    
    switch(mode){
       case 1:
            range = std::stoi(argv[5]);
            a = better_safe_lin_generate_seq(seed,range,max,n);
            break;
       case 0:
            a = safe_lin_generate_seq(seed,max,n);
            break;
       default:
            a = unsafe_lin_generate_seq(seed, max, n);
            break;
    }

    
    std::cout<<"sequence: ";
    for(iter=0; iter<n; iter++){
        std::cout<< a[iter] << " ";
    }
    std::cout << "\n";

    free(a);
    return 0;

}