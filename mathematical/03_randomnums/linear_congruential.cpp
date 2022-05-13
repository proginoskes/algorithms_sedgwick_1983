# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <sstream>
# include <vector>

int * lin_generate_seq(int seed, int max, int n){
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

// argv: ./a.out seed max n
int main(int argc, char **argv){
    int *a, n, max, seed, iter;

    seed = std::stoi(argv[1]);
    max = std::stoi(argv[2]);
    n = std::stoi(argv[3]);
    
    a = lin_generate_seq(seed, max, n);
    
    std::cout<<"sequence: ";
    for(iter=0; iter<n; iter++){
        std::cout<< a[iter] << " ";
    }
    std::cout << "\n";

    free(a);
    return 0;

}