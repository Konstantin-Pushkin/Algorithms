#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;

u_int64_t blockInterpolationSearch(const std::vector<u_int64_t> &array, size_t numSearch)
{
    const u_int64_t lenArray = array.size();
    if(lenArray == 0)
    {
        return -2;
    }

    u_int64_t left = 0;
    u_int64_t right = lenArray - 1;

    if(array[left] == array[right])
    {
        if(array[left] == numSearch)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }

    const u_int64_t middle = left + ((right - left) * (numSearch - array[left])) / (array[right] - array[left]);
    if(numSearch == middle)
    {
        return middle;
    }

    const auto lenBlocks = static_cast<int64_t>(std::sqrt(lenArray));

    if(numSearch > middle)
    {
        if(numSearch > array[middle])
        {
            left = middle + 1;
            right = middle + lenBlocks;
            while(right < lenArray && array[right - 1] < numSearch)
            {
                left = right;
                right += lenBlocks;
            }
        }

        if(right >= lenArray)
        {
            right = lenArray - 1;
        }

        for(u_int64_t t = left; t <= right; ++t)
        {
            if(array[t] == numSearch)
            {
                return t;
            }
        }
    }
    else
    {
        left = 0;
        right = middle - 1;
        while(right > 0 && array[right] >= numSearch)
        {
            left += lenBlocks;
            right -= lenBlocks;
        }

        for(u_int64_t t = left; t <= right; ++t)
        {
            if(array[t] == numSearch)
            {
                return t;
            }
        }
    }

    return -1;
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    std::ranges::sort(nums);
    u_int64_t res = blockInterpolationSearch(nums, 13);
    cout << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}