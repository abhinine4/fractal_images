#include <iostream>
#include <vector>

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5};

    for(auto num : nums){
        std::cout << num << std::endl;
    }

    return 0;
}