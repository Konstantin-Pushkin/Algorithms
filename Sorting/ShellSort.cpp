#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void shellSort(std::vector<u_int64_t> &array)
{
    const u_int64_t len = array.size();
    u_int64_t step = len / 2;

    while(step > 0)
    {
        for(u_int64_t i = step; i < len; ++i)
        {
            u_int64_t temp = array[i];
            u_int64_t j;

            for(j = i; j >= step && array[j - step] > temp; j -= step)
            {
                array[j] = array[j - step];
            }
            array[j] = temp;
        }
        step /= 2;
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

    shellSort(nums);
    cout << "Array after sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}