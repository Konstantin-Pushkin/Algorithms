#include <iostream>
#include <vector>

using std::cout;
using std::endl;

u_int64_t linearSearch(const std::vector<u_int64_t> &array, size_t numSearch)
{
    if(array.empty())
    {
        return -2; // массив пустой
    }

    for(u_int64_t i = 0; i < array.size(); ++i)
    {
        if(array[i] == numSearch)
        {
            return i;
        }
    }

    return -1; // не найдено
}

int main()
{
    std::vector<u_int64_t> nums = {9, 4, 13, 7, 1, 28, 3, 5, 10, 11};
    u_int64_t res = linearSearch(nums, 13);
    cout << "The position of the number 13 is " << res << endl;

    return EXIT_SUCCESS;
}
