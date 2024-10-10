#include <iostream>
#include <memory>   // For std::shared_ptr
#include "libraries/pointers/shared_ptr/shared_ptr.h"

// Utility function to print shared_ptr details for std::shared_ptr
template<typename T>
void printStdSharedInfo(const std::shared_ptr<T>& ptr, const std::string& name)
{
    std::cout << name << " - Address: " << ptr.get() << ", Value: " << *ptr << ", Count: " << ptr.use_count() << std::endl;
}

// Utility function to print shared_ptr details for rsm::shared_ptr
template<typename T>
void printRsmSharedInfo(const rsm::shared_ptr<T>& ptr, const std::string& name)
{
    std::cout << name << " - Address: " << ptr.get() << ", Value: " << *ptr << ", Count: " << ptr.get_count() << std::endl;
}

int main()
{
    // Test 1: Creation and reference counting
    std::cout << "Test 1: Creation and reference counting\n";
    std::shared_ptr<int> stdPtr1 = std::make_shared<int>(10);
    rsm::shared_ptr<int> rsmPtr1 = rsm::make_shared<int>(10);
    printStdSharedInfo(stdPtr1, "stdPtr1");
    printRsmSharedInfo(rsmPtr1, "rsmPtr1");
    std::cout << std::endl;

    // Test 2: Copy construction and reference counting
    std::cout << "Test 2: Copy construction and reference counting\n";
    std::shared_ptr<int> stdPtr2 = stdPtr1;
    rsm::shared_ptr<int> rsmPtr2 = rsmPtr1;
    printStdSharedInfo(stdPtr2, "stdPtr2");
    printRsmSharedInfo(rsmPtr2, "rsmPtr2");
    std::cout << "After copy construction:\n";
    printStdSharedInfo(stdPtr1, "stdPtr1");
    printRsmSharedInfo(rsmPtr1, "rsmPtr1");
    std::cout << std::endl;

    // Test 3: Assignment and reference counting
    std::cout << "Test 3: Assignment and reference counting\n";
    std::shared_ptr<int> stdPtr3;
    rsm::shared_ptr<int> rsmPtr3;
    stdPtr3 = stdPtr1;
    rsmPtr3 = rsmPtr1;
    printStdSharedInfo(stdPtr3, "stdPtr3");
    printRsmSharedInfo(rsmPtr3, "rsmPtr3");
    std::cout << "After assignment:\n";
    printStdSharedInfo(stdPtr1, "stdPtr1");
    printRsmSharedInfo(rsmPtr1, "rsmPtr1");
    std::cout << std::endl;

    return 0;
}
