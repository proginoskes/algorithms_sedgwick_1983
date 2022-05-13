# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <sstream>
# include <vector>

/*
    disclaimer: this is possibly more similar
    to the actual program laid out in the book
*/

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



// arguments: ./a.out seed max n
int main(int argc, char **argv){
    int seed, j=0, cfact, max, m1, n, *a, iter;

    seed = std::atoi(argv[1]);
    max = std::stoi(argv[2]);
    n = std::atoi(argv[3]);

    a = (int*)malloc(n * sizeof(int));
    a[0] = seed;

    // a number with one less digit than m
    cfact = max/10;
    // and also that ends in x21 with x even
    cfact /= 1000;
    cfact *= 1000;
    cfact += 621;

    while(m1 > 32768){
        m1 = m1 >> 1;
    }

    while(j < 55){
        j++;
        a[j] = (safe_mul(a[j-1],cfact, m1)+1) % max;
    }

    // still need to implement randomint.

    // this might actually end up working better in linear_congruential.cpp
    for(iter=0; iter<n; iter++){

    }
    

    free(a);
    return 0;
}