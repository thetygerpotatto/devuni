#include <iostream>
#include <string>
#include <chrono>

using std::string;
using std::cout;

string get_lcs_recursive(string a, string b);
string get_lcs_dinamic_prog(string a, string b);

int main (int argc, char *argv[]) {
    string a = string("ABBCAB");
    string b = string("ABCBAA");
    const auto start = std::chrono::steady_clock::now();
    string r = get_lcs_recursive(a, b);
    const auto finish = std::chrono::steady_clock::now();
    const std::chrono::duration<double> time {finish - start};
    cout << "funcion recursiva\n";
    cout << time.count() << "\n";
    cout << r << "\n";
    return 0;
}

string get_lcs_recursive(string a, string b) {
    if (a.size() == 0 || b.size() == 0) return "";
    
    if (a.end()[-1] == b.end()[-1]) {
        char end_a = a.end()[-1];
        char end_b = b.end()[-1];
        string result = get_lcs_recursive(a.substr(0, a.size()-1),
                                              b.substr(0, b.size()-1));
        result.push_back(end_a);
        return result;
    } else {
        string r1,r2;
        r1 = get_lcs_recursive(a.substr(0, a.size()-1), b);
        r2 = get_lcs_recursive(a, b.substr(0, b.size()-1));

        if (r1.size() > r2.size()) {
            return r1;
        } 
        else if(r2.size() > r1.size()) {
            return r2;
        } else {
            return r1;
        }

    }
}

string get_lcs_dinamic_prog(string a, string b) {
    //
    //a = ABBCAB
    //   A      
    //   B
    //   C
    //   B
    //   A
    //   A
    return "yes";
}
