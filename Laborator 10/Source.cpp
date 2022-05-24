#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class CommandManager {
private:
	map<string, function<void(vector<string>)>>commands;
public:
	void add(string name, function<void(vector<string>)>fn);
	void run();
};
void CommandManager::add(string name, function<void(vector<string>)>fn) {
	commands[name] = fn;
}

void CommandManager::run() {
	string tmp;
	vector<string>args;
	while (true)
	{
		std::getline(std::cin, tmp);
		if (tmp == "stop")
			return;
		args.clear();
		auto ptr = strtok(&tmp[0], " ");
		while (ptr)
		{
			args.push_back(ptr);
			ptr = strtok(nullptr, " ");
		}
		if (args.empty())
		{
			
			continue;
		}
		auto it = commands.find(args[0]);
		if(it==commands.end())
		{
			printf("no command with that name");
			continue;
		}
		args.erase(args.begin());
		it->second(args);

	}
	struct MyFile {
		FILE* file;
		MyFile(FILE* file) :file(file) {
        }
		~MyFile() {
			fclose(file);
		}
	};
}
int main()
{
	CommandManager manager;
	unsigned number_of_errors = 0;
	auto ping = [](vector<string>args) { printf("pong!\n"); };
	manager.add("ping", ping);
	auto count = [](vector<string>args) {printf("counted %u args\n", static_cast<unsigned>(args.size())); };
	manager.add("count",count);
	auto append = [&number_of_errors](vector<string>args) {
		FILE* fisier = fopen(args[0].c_str(), "a");
		int ok = 1;
		if (fisier == nullptr) {
			number_of_errors++;
			ok = 0;
		}
		if (ok == 1)
			for (unsigned i = 1; i < args.size(); i++) {
				if (fprintf(fisier, "%s", args[i].c_str()) < 0)
				{
					number_of_errors++;
					break;
				}

			}
		if (ok == 1)
			fclose(fisier);
	};
	manager.add( "append",append);
	auto times = [k = 0](vector<string>args)mutable{
		k++;
		printf("times was called %d times\n", k);
	};
	manager.add("times", times);
	auto copy = [&number_of_errors](vector<string>args) {
		int ok1 = 1, ok2 = 1;
		FILE* source = fopen(args[0].c_str(), "rb");
		if (source == nullptr)
		{
			number_of_errors++;
			ok1 = 0;
		}
		FILE* destination = fopen(args[1].c_str(), "wb");
		if (destination == nullptr)
		{
			number_of_errors++;
			ok2 = 0;
		}
		char buffer[4096];
		while (true && ok1 == 1 && ok2 == 1)
		{
			int state = fread(buffer, sizeof(char), 4096, source);
			if (state == 0)
			{
				break;
			}
			if (ferror(source))
			{
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
	auto sort_size = [](vector<string>args) {
		sort(args.begin(), args.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
		auto print = [](const string& c) { printf("%s", c.c_str()); };
		for_each(args.begin(), args.end(), print);
		print("\n");
	};
	manager.add("sort_size", sort_size);
	manager.run();
	printf("number of errors: %u\ndone!\n", number_of_errors);
}