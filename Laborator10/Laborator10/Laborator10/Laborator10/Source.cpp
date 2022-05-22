#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of
// {"a.jpg", "b.jpg"} no global(or statics!) variables allowed


class CommandManager {
  private:
    map<string, function<void(vector<string>)>> commands;

  public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at
    // https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}
void CommandManager::run() {
    string tmp;
    vector<string> args;

    while (true) {
        std::getline(std::cin, tmp);
        if (tmp == "stop") {
            return;
        }

        args.clear();
        auto ptr = strtok(&tmp[0], " ");
        while (ptr) {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty()) {
            // empty command, doing nothing
            continue;
        }

        auto it = commands.find(args[0]);
        if (it == commands.end()) {
            printf("no command with that name!\n");
            continue;
        }

        // remove the command name
        args.erase(args.begin());

        it->second(args);
    }
}
struct MyFile {
    FILE* file;

    MyFile(FILE* file) : file(file) {
    }

    ~MyFile() {
        fclose(file);
    }
};

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) { printf("counted %u args\n", static_cast<unsigned>(args.size())); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) {
        FILE* fisier = fopen(args[0].c_str(), "a");
        int ok       = 1;
        if (fisier == nullptr) {
            number_of_errors++;
            ok = 0;
        }
        if (ok==1)
        for (unsigned i = 1; i < args.size(); i++) {
            if (fprintf(fisier, "%s ", args[i].c_str()) < 0) {
                number_of_errors++;
                break;
            }
        }
        if (ok == 1)
            fclose(fisier);
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [k = 0](vector<string> args) mutable {
        k++;
        printf("times was called %d times\n", k);
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [&number_of_errors](vector<string> args) {
        int ok1 = 1, ok2 = 1;
        FILE* source = fopen(args[0].c_str(), "rb");
        if (source == nullptr) {
            number_of_errors++;
            ok1 = 0;
        }
        FILE* destination = fopen(args[1].c_str(), "wb");
        if (destination == nullptr) {
            number_of_errors++;
            ok2 = 0;
        }
        char buffer[4096];
        while (true && ok1==1 && ok2==1) {
            int state = fread(buffer, sizeof(char), 4096, source);
            if (state == 0)
                break;
            if (ferror(source)) {
                number_of_errors++;
                break;
            }
            int bytes = fwrite(buffer, 1, state, destination);
            if (bytes != state) {
                number_of_errors++;
                break;
            }
        }
        if (ok1 == 1)
            fclose(source);
        if (ok2 == 1)
            fclose(destination);
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args) {
        sort(args.begin(), args.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
        auto print = [](const string& c) { printf("%s ", c.c_str()); };
        for_each(args.begin(), args.end(), print);
        print("\n");
    };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like

    manager.run();
    printf("number of errors: %u\ndone!\n", number_of_errors);
}