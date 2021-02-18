/* Use this file to generate multiple test files from a single file containing
 * all the tests, placing these files in current directory following the naming
 * format test{testnumber}.in.
 * Width of test number is calculated according to
 * total number of tests in the file containing all test cases.
 * for example for 100 tests, this program would produce files test001.in ->
 * test100.in.
 * for 10 tests, this program would produce files test01.in ->
 * test10.in.
 * Usage:generateTestFiles {path to file containing all tests}
 * {number of lines per test}
 * argument 2 is optional (default is 1)
 */
#include <bits/stdc++.h>

using namespace std;

int fileLength(fstream &f) {
    int ret{};
    string line;
    while (getline(f, line)) {
        ret++;
    }
    f.clear();
    f.seekg(f.beg);
    return ret;
}

int digitsNbr(int x) {
    if (x == 0) {
        return 1;
    }
    int ret{};
    while (x != 0) {
        ret++;
        x /= 10;
    }
    return ret;
}

class TestIncompleteError : public exception {
  public:
    const char *what() const throw() {
        return "Tests are incomplete, due to missing lines";
    }
};

istream &getTest(istream &in, int n, string &test) {
    test = "";
    for (int i = 0; i < n; i++) {
        string line;
        getline(in, line);
        /* if (!getline(in, line)) { */
        /*     throw TestIncompleteError(); */
        /* } */
        if (i != 0)
            test += '\n';
        test += line;
    }
    return in;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        const string inputFile = argv[1];
        fstream input{inputFile.c_str()};
        if (!input) {
            cout << "could not open file containing the tests" << endl;
            cout << "file name was " << inputFile << endl;
            exit(EXIT_FAILURE);
        }
        int lineNbr{};
        // check if user supplied the number of lines per test in the command
        // line arguments
        int linesPerTest{1};
        if (argc >= 3) {
            linesPerTest = atoi(argv[2]);
        }
        string line;
        int length = fileLength(input);
        if (length % linesPerTest != 0) {
            throw TestIncompleteError();
        }
        int width = digitsNbr(length / linesPerTest);
        while (getTest(input, linesPerTest, line)) {
            lineNbr++;
            stringstream format;
            format << "%0" << width << "d";
            char *testNumber = new char[width + 1];
            sprintf(testNumber, format.str().c_str(), lineNbr);
            char fileName[30];
            sprintf(fileName, "test%s.in", testNumber);
            /* cout << fileName << endl; */
            /* cout << line << endl; */
            ofstream testFile{fileName};
            testFile << line;
            testFile.close();
            delete[] testNumber;
        }
        input.close();
    } else {
        cout << "Please supply the input file" << endl;
    }
}
