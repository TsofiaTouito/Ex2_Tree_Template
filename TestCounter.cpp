//tsofiatouito2@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

int main(int argc, char** argv) {
    doctest::Context context;

    // Apply command-line arguments to doctest context
    context.applyCommandLine(argc, argv);

    // Run the tests
    int test_result = context.run();

    // Check if any of the tests failed
    if (test_result == 0) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed. Total failures: " << test_result << std::endl;
    }

    // Important: check if the context should exit (for example, after --help flag)
    if (context.shouldExit()) {
        return test_result;  // Propagate the result of running the tests
    }

    return test_result;  // Return the result from doctest's run()
}
