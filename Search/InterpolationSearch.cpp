#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;

u_int64_t interpolationSearch(const std::vector<u_int64_t> &array, size_t numSearch)
{
    if(array.empty())
    {
        return -2; // массив пустой
    }

    u_int64_t left = 0;
    u_int64_t right = array.size() - 1;
    while(array[left] <= numSearch && numSearch <= array[right] && array[left] != array[right])
    {
        if(array[left] == array[right])
        {
            break;
        }

        u_int64_t middle = left + ((right - left) * (numSearch - array[left])) / (array[right] - array[left]);
        if(array[middle] == numSearch)
        {
            return middle;
        }
        else if (array[middle] < numSearch)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    if(left < array.size() && array[left] == numSearch)
    {
        return left;
    }
    else
    {
        return -1; // не найдено
    }
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    std::ranges::sort(nums);
    u_int64_t res = interpolationSearch(nums, 13);
    cout << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}