#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::endl;

size_t blockInterpolationSearch(const std::vector<uint64_t> &array, const uint64_t numSearch) {
    const size_t lenArray = array.size();

    if (lenArray == 0) return SIZE_MAX;

    if (lenArray == 1) return (array[0] == numSearch) ? 0 : SIZE_MAX;

    size_t left = 0;
    size_t right = lenArray - 1;

    if (array[left] == array[right]) return (array[left] == numSearch) ? left : SIZE_MAX;

    if (numSearch < array[left] || numSearch > array[right]) return SIZE_MAX;

    size_t middle = left + static_cast<size_t>(
        (static_cast<double>(numSearch - array[left]) /
         static_cast<double>(array[right] - array[left])) *
        static_cast<double>(right - left)
    );

    if (middle >= lenArray) middle = lenArray - 1;

    if (array[middle] == numSearch) return middle;

    const size_t lenBlocks = static_cast<size_t>(std::sqrt(lenArray));
    if (lenBlocks == 0) {
        for (size_t i = 0; i < lenArray; ++i)
            if (array[i] == numSearch)
                return i;

        return SIZE_MAX;
    }

    if (array[middle] < numSearch) {
        left = middle + 1;
        right = std::min(left + lenBlocks - 1, lenArray - 1);

        while (right < lenArray - 1 && array[right] < numSearch) {
            left = right + 1;
            right = std::min(left + lenBlocks - 1, lenArray - 1);
        }
    } else {
        right = (middle > 0) ? middle - 1 : 0;
        left = (right >= lenBlocks - 1) ? right - lenBlocks + 1 : 0;

        while (left > 0 && array[left] > numSearch) {
            right = (left > 0) ? left - 1 : 0;
            left = (right >= lenBlocks - 1) ? right - lenBlocks + 1 : 0;
        }
    }

    for (size_t i = left; i <= right && i < lenArray; ++i)
        if (array[i] == numSearch)
            return i;

    return SIZE_MAX;
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    std::ranges::sort(nums);
    u_int64_t res = blockInterpolationSearch(nums, 13);
    cout << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}