#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class rmDup
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
                it = nums.erase(it);
            }
        }
        return nums.size();
    }
    virtual void sortNums(vector<int> &nums) = 0;

  private:
    int currentNum;
};

class messrmDup : public rmDup
{
  public:
    void sortNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }
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
    messrmDup solution;
    rmDup *rmDupPtr = &solution;
    rmDupPtr->sortNums(nums);

    cout << "Total size is : " << rmDupPtr->removeDuplicates(nums) << endl;
    int i = 0;
    for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
    {
        cout << ++i << "th num is : " << *it << endl;
    }
    return 0;
}