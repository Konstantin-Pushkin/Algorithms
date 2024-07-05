#include <vector>
#include <iostream>

using std::cout;
using std::endl;

void mergeSort(std::vector<u_int64_t> &array, u_int64_t start, u_int64_t end)
{
    if(end - start < 2)
    {
        return;
    }

    u_int64_t middle = (start + end) / 2;
    mergeSort(array, start, middle);
    mergeSort(array, middle, end);

    std::vector<u_int64_t> resArr(end - start);
    u_int64_t left = start;
    u_int64_t right = middle;
    u_int64_t index = 0;

    while(left < middle && right < end)
    {
        if(array[left] <= array[right])
        {
            resArr[index++] = array[left++];
        }
        else
        {
            resArr[index++] = array[right++];
        }
    }

    while(left < middle)
    {
        resArr[index++] = array[left++];
    }

    while(right < end)
    {
        resArr[index++] = array[right++];
    }

    u_int64_t n = 0;
    u_int64_t *p = &array[n];
    for([[maybe_unused]] const auto &v: resArr)
    {
        std::copy(resArr.begin(), resArr.end(), p + start);
        n++;
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

    mergeSort(nums, 0, nums.size());
    cout << "Array after sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}