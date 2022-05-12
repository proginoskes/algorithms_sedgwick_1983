# include <stdio.h>
# include <stdlib.h>
# include <iostream>

/* 
this is a program which finds the greatest 
common denominators of a command-line array of
numbers. It acts as a very simple "reduce" on 
all neighbors.

*/

int gcd(int u, int v){
    int t;
    if(u < v){
        t=u;
    } else {
        t=v;
    }
    while(u % t != 0 || v % t !=0){
        t = t-1;
    }
    return t;
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