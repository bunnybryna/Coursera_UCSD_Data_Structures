#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::cin;


struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector< std::list <string> > elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
//Prefixing the explicit keyword to the constructor prevents the compiler from using that constructor for implicit conversions
//https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {

        if (query.type == "check")
		{
			// use reverse order, because we append strings to the end
			if (elems[query.ind].size() != 0)
			{
				for (string& x: elems[query.ind]) std::cout << x << " ";
			}
			std::cout << "\n";
        }
		else
		{
			int hashNum = hash_func(query.s);
            std::list<string>::iterator it = std::find(elems[hashNum].begin(), elems[hashNum].end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems[hashNum].end());
            else if (query.type == "add")
			{
                // if not exists
				if (it == elems[hashNum].end())
					elems[hashNum].push_front(query.s);
            } else if (query.type == "del") {
                if (it != elems[hashNum].end())
                    elems[hashNum].erase(it);
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
		// need to initialize the vector first
		std::list<string> emptyList;
		for (int i = 0; i < bucket_count; ++i)
			elems.push_back(emptyList);
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
