#include "libraries/hash_table/hash_table.h"

#include <unordered_map>
#include <iostream>

using namespace rsm;

template <typename T>
bool hasItemInCommon(vector<T>& vec1, vector<T>& vec2)
{
    std::unordered_map<T, bool> tempMap;

    for(int idx = 0; idx < vec1.size(); idx++)
    {
        tempMap.insert({vec1[idx], true});
    }

    for(int idx = 0; idx < vec2.size(); idx++)
    {
        auto item = vec2[idx];
        if(tempMap[item])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(3);
    vec1.push_back(5);

    vector<int> vec2;
    vec2.push_back(2);
    vec2.push_back(4);
    vec2.push_back(5);

    std::cout << hasItemInCommon(vec1, vec2) << std::endl;

    return 0;
}
