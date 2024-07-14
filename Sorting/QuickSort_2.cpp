#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<u_int64_t> quickSort(const vector<u_int64_t> &array)
{
    const u_int64_t lenArray = array.size();
    if(lenArray < 2)
    {
        return array;
    }

    u_int64_t pivot = array[0]; // you can take any element
    vector<u_int64_t> less;
    vector<u_int64_t> greater;

    for(size_t t = 1; t != lenArray; ++t)
    {
        if(array[t] < pivot)
        {
            less.push_back(array[t]);
        }
        else
        {
            greater.push_back(array[t]);
        }
    }

    vector<u_int64_t> sortedLess = quickSort(less);
    vector<u_int64_t> sortedGreater = quickSort(greater);

    sortedLess.push_back(pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

    return sortedLess;
}

int main()
{
    vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    cout << "Array before sorting: ";
    for(const auto& val : nums)
    {
        cout << val << " ";
    }

    vector<u_int64_t> sortedNums = quickSort(nums);

    cout << std::endl << "Array after sorting: ";
    for(const auto &val : sortedNums)
    {
        cout << val << " ";
    }

    cout << std::endl;

    return EXIT_SUCCESS;
}