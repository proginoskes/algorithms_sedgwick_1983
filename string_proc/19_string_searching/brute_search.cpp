# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <algorithm>
# include <iostream>
# include <vector>

/*
    in this script we use a brute-search algorithm
    for finding a substring within a string

*/

void print_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    std::vector<int>::iterator iter;
    for(iter=begin; iter!=end; iter++){
        std::cout << *iter << " ";
    }
    std::cout<< "\n";
}

/*

i <- points in text
j <- points in pattern
as long as text[i] == pattern[j] both pointers are 
incremented. if j==pattern.length() we have our
match. If i and j point to mismatched chars,
then j is reset ot the beginning of the pattern
and i increments from where it was before the matching.

*/
int bruteSearch(std::string txt, std::string ptrn){
    //std::string::iterator iter_txt=txt.begin(), iter_ptrn=ptrn.begin();

    int iter_txt=0, iter_ptrn=0;

    do{
        if(txt[iter_txt] == ptrn[iter_ptrn]){
            iter_txt++;
            iter_ptrn++;
        } else {
            iter_txt = (iter_txt - iter_ptrn)+1;
            iter_ptrn = 0;
        }
    }while(iter_txt<txt.length()&&iter_ptrn<ptrn.length());

    if(iter_ptrn>=ptrn.length()) return iter_txt - iter_ptrn;

    return iter_txt;

}

// args: ./a.out n
int main(int argc, char **argv){
    
    srand (time(NULL));
    int result, correct_result;
    std::string str, substr;
    if(argc < 3){
        std::cout<<"provide format: <string> <substring>";
        return 0;
    }

    str = argv[1];
    substr = argv[2];
    
    result = bruteSearch(str,substr);
    correct_result = str.find(substr);
    std::cout<<"correct answer:\n" << correct_result << "\n";
    std::cout<<"your answer:\n" << result << "\n";
    std::cout<<"THESE RESULTS ARE ";
    if(result == correct_result){
        std::cout<<"EQUAL\n";
    }else{
        std::cout<<"NOT EQUAL\n";
    }
    return 0;
}
