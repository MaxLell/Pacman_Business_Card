#include <iostream>
#include <stdexcept>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "assert.h"

// Mock für ASSERT
void assert_failed(const char* condition,
                   const char* file, int line) {
  mock()
      .actualCall("assert_failed")
      .withParameter("condition", condition)
      .withParameter("file", file)
      .withParameter("line", line);
}