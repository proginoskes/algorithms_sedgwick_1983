#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include <algorithm>
# include <iostream>
# include <vector>

void print_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    std::vector<int>::iterator iter;
    for(iter=begin; iter!=end; iter++){
        std::cout << *iter << " ";
    }
    std::cout<< "\n";
}

void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    
    std::vector<int>::iterator iter_i, iter_j, min;
    for(iter_i=begin; iter_i!=end; iter_i++){
        min = iter_i;
        for(iter_j=iter_i+1; iter_j!=end;iter_j++){
            if(*iter_j<*min){
                min = iter_j;
            }
        }
        std::swap(*min, *iter_i);
    }

}

// args: ./a.out n
int main(int argc, char **argv){
    std::vector<int> arr, correctly_sorted_arr;
    srand (time(NULL));
    int iter,n;
    if(argc < 2){
        std::cout<<"specify number of elem in array";
        return 0;
    }

    n = std::stoi(argv[1]);
    for(iter=0; iter<n; iter++){
        arr.push_back(rand()% 256);
    }
    correctly_sorted_arr = arr;
    std::sort(correctly_sorted_arr.begin(),correctly_sorted_arr.end());
    selection_sort(arr.begin(), arr.end());
    std::cout<<"correct answer:\n";
    print_vector(correctly_sorted_arr.begin(),correctly_sorted_arr.end());
    std::cout<<"your answer:\n";
    print_vector(arr.begin(), arr.end());
    std::cout<<"THESE VECTORS ARE ";
    if(std::equal(correctly_sorted_arr.begin(),correctly_sorted_arr.end(),
    arr.begin(), arr.end())){
        std::cout<<"EQUAL\n";
    }else{
        std::cout<<"NOT EQUAL\n";
    }
    return 0;
}