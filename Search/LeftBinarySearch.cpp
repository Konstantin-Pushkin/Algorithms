#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

u_int64_t leftBinarySearch(const std::vector<u_int64_t> &array, u_int64_t numSearch)
{
    if(array.empty())
    {
        return -2; //массив пустой
    }

    u_int64_t left = 0;
    u_int64_t right = array.size() - 1;
    while(left + 1 < right)
    {
        auto middle = left + (right - left) / 2; // или (left + right) / 2

        if(numSearch > array[middle])
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    if(array[left] == numSearch)
    {
        return left;
    }

    if(array[right] == numSearch)
    {
        return right;
    }

    return -1; // не найдено
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 13, 13, 7, 1, 28, 3, 5, 10, 11};
    std::ranges::sort(nums);
    cout << "Sorted array: ";
    for(const auto &num : nums)
    {
        cout << num << " ";
    }

    u_int64_t res = leftBinarySearch(nums, 13);
    cout << endl << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}