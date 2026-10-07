#include <iostream>

int& find_max(int arr[], int n)
{   
    int max{0};
    for (int i = 1; i < n; i++){
        if (arr[i] > arr[max]){
            max = i;
        }
    }
    return arr[max];
}

int main()
{
    int numbers[] = {4, -7, 12, 0, 9, -3};
    for (int& num : numbers){
        std::cout<<num<<' ';
        if(num < 0){
            num = -num;
        }
    }
    
    find_max(numbers, 6) = 0;
    
    std::cout<<"\n";
    for (int num : numbers){
        std::cout<<num<<' ';
    }
    return 0;
}