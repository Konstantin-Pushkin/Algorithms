#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

u_int64_t binarySearch(const std::vector<u_int64_t> &array, u_int64_t numSearch)
{
    if(array.empty())
    {
        return -2; //массив пустой
    }

    u_int64_t left = 0;
    u_int64_t right = array.size() - 1;
    while(left <= right)
    {
        auto middle = left + (right - left) / 2; // или (left + right) / 2
        if(array[middle] == numSearch)
        {
            return middle;
        }

        if(numSearch > array[middle])
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1; // не найдено
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    std::ranges::sort(nums);
    cout << "Sorted array: ";
    for(const auto &num : nums)
    {
        cout << num << " ";
    }

    u_int64_t res = binarySearch(nums, 13);
    cout << endl << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}