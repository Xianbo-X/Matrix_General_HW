#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int>::iterator it;
        currentNum = nums[0];
        for (it = nums.begin() + 1; it < nums.end();)
        {
            if (*it != currentNum)
            {
                currentNum = *it;
                it++;
            }
            else
            {
                it=nums.erase(it);
            }
        }
        return nums.size();
    }

  private:
    int currentNum;
};

int main()
{
    ifstream dataInFile("data.in");
    try
    {
        if (!dataInFile.is_open())
            throw - 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    vector<int> nums;
    nums.clear();
    int totalNums(0);
    dataInFile >> totalNums;
    for (int i = 0; i < totalNums; i++)
    {
        int x;
        dataInFile >> x;
        nums.push_back(x);
    }
    Solution removeDuplicate;
    cout << "Total size is : " << removeDuplicate.removeDuplicates(nums) << endl;
    int i = 0;
    for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
    {
        cout << ++i << "th num is : " << *it << endl;
    }
    return 0;
}