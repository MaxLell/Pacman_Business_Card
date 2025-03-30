#include <iostream>
#include "assert.h"

#include "CppUTest/TestHarness.h"


TEST_GROUP(dummy_test){
    void setup(){

    }
    void teardown()
    {
        // nothing much happening here
    }
};



template <std::size_t Rows, std::size_t Cols>
class MyClass {
    std::array<std::array<int, Cols>, Rows> arr; // 2D Array mit fester Größe
public:
    void printSize() { std::cout << "Rows: " << Rows << ", Cols: " << Cols << '\n'; }
};

TEST(dummy_test, dummy)
{
    

}


