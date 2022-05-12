# include <stdio.h>
# include <stdlib.h>
# include <iostream>

/* 
this is a program which finds the greatest 
common denominators of a command-line array of
numbers. It acts as a very simple "reduce" on 
all neighbors.

this version is non-recursive, but faster than
the naive implementation.

*/

int gcd(int u, int v){
    int t;
    while (v!=0){
        t = u % v;
        u = v;
        v = t;
    }
    return u;
}

int main(int argc, char** argv){
    int denom, i=2;
    while(i < argc){
        denom = gcd(std::stoi(argv[i-1]), std::stoi(argv[i]));
        std::cout << argv[i-1] << "," << argv[i]<< " gcd: " << denom << "\n";
        i++;
    }
    std::cout << "End of input" << "\n";
    return 0;
}