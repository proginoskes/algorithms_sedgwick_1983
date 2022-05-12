# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <sstream>
# include <vector>

# define MAX_N 100

/* 
this is a program which performs calculations on two 
polynomials. a better version can be implemented using
a linked list
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
// adds two polynomial expressions
std::vector<int> polyadd(std::vector<int> p, std::vector<int> q){
    int iter;
    std::vector<int> r = {};
    for(iter=0; iter<p.size(); iter++){
        r.push_back(p.at(iter) + q.at(iter));
    }
    return r;
}

// multiplies two polynomial expressions
// does this in N^2 time
std::vector<int> polymul(std::vector<int> p, std::vector<int> q){
    int iter_i, iter_j;
    std::vector<int> r = {};
    for(iter_i=0; iter_i<2*p.size(); iter_i++){
        r.push_back(0);
    }
    for(iter_i=0; iter_i<p.size(); iter_i++){
        for(iter_j=0; iter_j<p.size(); iter_j++){
            r.at(iter_i + iter_j) = r.at(iter_i + iter_j) + p.at(iter_i)*q.at(iter_j);
        }
    }
    return r;
}

/*
    argc: max 3
    argv: 1 -> first polynomial "p"
          2 -> second polynomial "q"
    argument format is:
    ./a.out "1 2 3 4 5" "6 3 2 5 6" <0,1, for add, mul> 
    where the position in argv[1||2] is the degree
*/
int main(int argc, char** argv){

    int iter;
    std::vector<int> p_consts, q_consts, r_consts;
    std::string func;

    if(argc !=4){
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

    switch(std::stoi(argv[3])){
        case 0:
            r_consts = polyadd(p_consts, q_consts);
            func = "polysum";
            break;
        case 1:
            r_consts = polymul(p_consts, q_consts);
            func = "polyprod";
            break;
        default:
            r_consts = polyadd(p_consts, q_consts);
            func = "polysum";
            break;
    }
    

    std::cout<< func << " of p and q: ";
    for(iter=0; iter<r_consts.size(); iter++){
        std::cout<< r_consts.at(iter) <<" ";
    }

    std::cout<<"\n";


    return 0;
}