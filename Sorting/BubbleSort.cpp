#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void bubbleSort(std::vector<u_int64_t> &array)
{
    const u_int64_t len = array.size();
    for(u_int64_t i = 0; i < len - 1; ++i)
    {
        for(u_int64_t j = 0; j < len - i - 1; ++j)
        {
            if(array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
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

    bubbleSort(nums);
    cout << "Array after sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}