# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <algorithm>
# include <iostream>
# include <vector>

/*
    in this script we establish a starting format for 
    testing future algorithms, possibly for the entire
    rest of the book. using stl functions allows us to
    test our results against reliable answers. 

    this script is a shell sort, and uses a random
    number generator with time as seed to generate 
    'n' random numbers. no runtime is calculated.

*/

void print_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    std::vector<int>::iterator iter;
    for(iter=begin; iter!=end; iter++){
        std::cout << *iter << " ";
    }
    std::cout<< "\n";
}

void shell_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    
    int gap, temp;
    std::vector<int>::iterator iter_i, iter_j;

    for(gap = (end-begin)/3; gap > 0; gap /=2){
        for(iter_i=begin+gap; iter_i!=end;iter_i++){
            temp = *iter_i;
            for(
                iter_j=iter_i;
                (iter_j-begin) >= gap && 
                    *(iter_j-gap) > temp; 
                iter_j -= gap){

                *iter_j = *(iter_j - gap);
            }
            *iter_j = temp;
        }
    }
}

/*

*/
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
    shell_sort(arr.begin(), arr.end());
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
