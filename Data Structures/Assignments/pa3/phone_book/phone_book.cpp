#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    // old version using a vector of Query is unnecessary: vector<Query> contacts;
	std::map<int, string> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // no need to check if we already have contact with such number
            // just direct access it, rewrite or add 
			contacts[queries[i].number]=queries[i].name;
        } else if (queries[i].type == "del") {
			std::map<int, string>::iterator it = contacts.find(queries[i].number);
			if (it!= contacts.end())
            contacts.erase(it);
                }
         else {
			std::map<int, string>::iterator it = contacts.find(queries[i].number);
			string response;
			if (it!= contacts.end())
			{
				response = it->second;
			}
			else
			{
				response = "not found";
            }
			result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
