#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void insertSort(std::vector<u_int64_t> &array)
{
    const u_int64_t lenArray = array.size();
    for(u_int64_t pos = 1; pos < lenArray; ++pos)
    {
        u_int64_t currentPos = pos;
        while(currentPos > 0 && array[currentPos] < array[currentPos - 1])
        {
            std::swap(array[currentPos], array[currentPos - 1]);
            currentPos--;
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

    insertSort(nums);
    cout << "Array after sorting: ";
    for(const auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}