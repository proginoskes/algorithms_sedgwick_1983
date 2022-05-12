# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <sstream>
# include <vector>

# define MAX_N 100

/* 
this is a program which adds two polynomials
*/

std::vector<int> parse_poly(std::string poly, char delim){
    std::vector<int> internal_vector;
    std::stringstream stream(poly);
    std::string temp;

    while(getline(stream, temp, delim)){
        internal_vector.push_back(stoi(temp));
    }

    return internal_vector;
}

// p and q should be equal length
std::vector<int> polyadd(std::vector<int> p, std::vector<int> q){
    int iter;
    std::vector<int> r = {};
    for(iter=0; iter<p.size(); iter++){
        r.push_back(p.at(iter) + q.at(iter));
    }
    return r;
}

/*
    argc: max 3
    argv: 1 -> first polynomial "p"
          2 -> second polynomial "q"
    argument format is:
    ./a.out "1 2 3 4 5" "6 3 2 5 6"
*/
int main(int argc, char** argv){

    int iter;
    std::vector<int> p_consts, q_consts, r_consts;

    if(argc !=3){
        std::cout << "wrong num args: " << argc << ", should be 3\n"; 
        return -1;
    }
    std::string p_str(argv[1]);
    std::string q_str(argv[2]);

    p_consts = parse_poly(p_str, ' ');
    q_consts = parse_poly(q_str, ' ');

    while(p_consts.size() < q_consts.size()){
        p_consts.push_back(0);
    }
    while(p_consts.size() > q_consts.size()){
        q_consts.push_back(0);
    }

    r_consts = polyadd(p_consts, q_consts);
    std::cout<< "polysum of p and q: ";
    for(iter=0; iter<r_consts.size(); iter++){
        std::cout<< r_consts.at(iter) <<" ";
    }

    std::cout<<"\n";


    return 0;
}