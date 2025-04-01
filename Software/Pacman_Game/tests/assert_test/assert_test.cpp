// #include <iostream>
// #include <cstdlib>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include "CppUTest/TestHarness.h"

// void functionThatAborts() {
//     std::abort(); // Simuliert einen Fehler
// }

// TEST_GROUP(AbortTests) {
//     void setup() {}
//     void teardown() {}
// };

// TEST(AbortTests, DetectAbort) {
//     pid_t pid = fork();
//     if (pid == 0) {
//         // Kindprozess
//         functionThatAborts();
//         exit(0); // Sollte nie erreicht werden
//     } else {
//         // Elternprozess
//         int status;
//         waitpid(pid, &status, 0);
//         CHECK(WIFSIGNALED(status)); // Überprüft, ob das Kind durch ein Signal beendet wurde
//         CHECK_EQUAL(SIGABRT, WTERMSIG(status)); // Überprüft, ob das Signal SIGABRT war
//     }
// }

#include <stdexcept>
#include "assert.h"
#include <iostream>
#include "CppUTest/TestHarness.h"

TEST_GROUP(assert_tests) {
    void setup() {}
    void teardown() {}
};

TEST(assert_tests, triggering_an_assert_shall_throw_an_exceptio_when_testing) {
    try {
        ASSERT(false);
    } catch (const std::runtime_error& e) {
        STRCMP_EQUAL("ASSERT triggered", e.what());
        std::cout << e.what() << std::endl;
    }
}