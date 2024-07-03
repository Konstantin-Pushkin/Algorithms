#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void quickSort(std::vector<u_int64_t> &array, u_int64_t left, u_int64_t right)
{
    if(right == -1)
    {
        right = array.size() - 1;
    }

    if(left >= right)
    {
        return;
    }

    u_int64_t middle = array[(left + right) / 2];
    u_int64_t i = left;
    u_int64_t j = right;

    while(i <= j)
    {
        while(array[i] < middle)
        {
            i++;
        }

        while(array[j] > middle)
        {
            j--;
        }

        if(i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if(left < j)
    {
        quickSort(array, left, j);
    }

    if(i < right)
    {
        quickSort(array, i, right);
    }
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    cout << "Array before sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    quickSort(nums, 0, nums.size() - 1);
    cout << "Array after sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}