#include <iostream>
#include <cpr/cpr.h>

static const int number = 6;

bool is_correct_answer (std::string answer, std::string* actions) {

    for (int i=0;i < number;++i) {
        if (answer == actions[i]) return true;
    }
    return false;
}

int main() {
    std::string actions[] = {"get", "post", "put", "delete", "patch", "exit"};
    std::string answer;

    do {
        std::cout << "\nEnter the type of request to the server 'httpbin.org':" << std::endl;
        for (int i = 0; i < number; ++i) {
            std::cout << "-" << actions[i] << std::endl;
        }
        std::cout << ">";

        do {
            std::cin >> answer;
            if (!(is_correct_answer(answer, actions))) std::cout << "Incorrect!Repeat.\n>";
        } while (!(is_correct_answer(answer, actions)));

        std::string url = "http://httpbin.org/" + answer;
        cpr::Response res;

        if (answer == actions[0]) {
            res = cpr::Get(cpr::Url(url));
            std::cout << res.text << std::endl << std::endl;
        } else if (answer == actions[1]) {
            res = cpr::Post(cpr::Url(url));
            std::cout << res.text << std::endl << std::endl;
        } else if (answer == actions[2]) {
            res = cpr::Put(cpr::Url(url));
            std::cout << res.text << std::endl << std::endl;
        } else if (answer == actions[3]) {
            res = cpr::Delete(cpr::Url(url));
            std::cout << res.text << std::endl << std::endl;
        } else if (answer == actions[4]) {
            res = cpr::Patch(cpr::Url(url));
            std::cout << res.text << std::endl << std::endl;
        }
    } while (answer != "exit");

    return 0;
}

