#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool if_terminating(size_t d) {
    while (d % 2 == 0) 
        d /= 2;
    while (d % 5 == 0)
        d /= 5;
    if (d == 1) return true;
    return false;
}

int main() {
    size_t d, rmd = 1, quo = 0, c = 0;
    std::vector<size_t> rmdvec, quovec;
    std::string res;
    std::cout << "1/";
    std::cin >> d;
    bool terminating = if_terminating(d);

    if (d <= 1) {
        std::cout << "Denominator must be greater than 1.\n";
        return 0;
    }

    while (!terminating) {
        rmdvec.push_back(rmd);
        quovec.push_back(quo);
        rmd *= 10;
        quo = (size_t)(rmd / d);
        rmd = rmd % d;
        if (rmd == 0) {
            quovec.push_back(quo);
            break;
        }
        auto it = std::find(rmdvec.begin(), rmdvec.end(), rmd);
        if (it != rmdvec.end()) {
            quovec.push_back(quo);
            c = (int)(it - rmdvec.begin()) + 1; // index starting from 0
            for (int i = 0; i < quovec.size(); i++) {
                if (i == c) res += "(";
                res += std::to_string(quovec[i]);
            }
            res += ")";
            break;
        }

    }

    while (terminating) {
        rmdvec.push_back(rmd);
        quovec.push_back(quo);
        rmd *= 10;
        quo = (size_t)(rmd / d);
        rmd = rmd % d;
        if (rmd == 0) {
            quovec.push_back(quo);
            for (auto&& item : quovec) {
                res += std::to_string(item);
            }
            break;
        }
    }

    res = "0." + res.substr(1);
    std::cout << "Decimal from: \n" << res << std::endl;

    return 0;
}
