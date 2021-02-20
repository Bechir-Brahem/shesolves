#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randomInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

string randomString(int n, char l, char r) {
    int len = r - l + 1;
    string res;
    for (int i = 1; i <= n; ++i)
        res += char(l + randomInt(0, len - 1));
    return res;
}

string generateString(int n) {
    string ret = randomString(n, 'A', 'Z');
    for (int i = 0; i < n; i++) {
        if (randomInt(0, 1) == 0) {
            ret[i] = tolower(ret[i]);
        }
    }
    return ret;
}
void solve(int i, fstream &in, ofstream &pc2, ofstream &print) {
    string display_name;
    getline(in, display_name);
    string password = generateString(6);
    pc2 << "1\tteam" << i << "\t" << display_name << "\t" << password
        << "\ttrue\ttrue\n";
    char line[200];
    char account[11];
    sprintf(account, "team%d", i);
    sprintf(line, "%-15s\t%-10s\t%s", display_name.c_str(), account,
            password.c_str());
    /* print << display_name << ": name = team" << i << "\tpassword = " <<
     * password */
    /*       << "\n"; */
    print << line << "\n";
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "arguments must be provided: file to read from, pc2 file then "
                "file to print"
             << endl;
        return 0;
    }
    fstream input(argv[1]);
    ofstream pc2(argv[2]);
    ofstream print(argv[3]);
    pc2 << "site\taccount\tdisplayname\tpassword\tpermdisplay\tpermlogin\n";
    char line[200];
    sprintf(line, "%-15s\t%-10s\t%s", "display name", "Name", "Password");
    print << line << "\n\n";
    int teams{};
    input >> teams;
    string str;
    getline(input, str);
    for (int i = 1; i <= teams; i++) {
        solve(i, input, pc2, print);
    }
    return 0;
}
