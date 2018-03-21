#include <bits/stdc++.h>

using namespace std;

using std::string;
typedef unsigned long long ull;
typedef long long ll;

const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;

struct Data {
  string pattern, text;
};

Data read_input() {
  Data data;
  std::cin >> data.pattern >> data.text;
  return data;
}

void print_occurrences(const std::vector<int> &output) {

  for (size_t i = 0; i < output.size(); ++i)
    std::cout << output[i] << " ";
  std::cout << "\n";
}

unsigned hashxx(const string &s) {
  long long ret = 0;
  for (int i = 0; i < s.size(); i++) {
    ret = ret * PRIME_BASE + s[i];
    ret %= PRIME_MOD;
  }
  return ret;
}

vector<int> rabin_karp(const string &needle, const string &haystack) {
  long long hash1 = hashxx(needle);
  long long hash2 = 0;
  long long power = 1;
  vector<int> res;

  for (int i = 0; i < needle.size(); i++)
    power = (power * PRIME_BASE) % PRIME_MOD;

  for (int i = 0; i < haystack.size(); i++) {
    hash2 = hash2 * PRIME_BASE + haystack[i];
    hash2 %= PRIME_MOD;

    if (i >= needle.size()) {
      hash2 -= power * haystack[i - needle.size()] % PRIME_MOD;
      if (hash2 < 0)
        hash2 += PRIME_MOD;
    }
    if (i >= needle.size() - 1 && hash1 == hash2) {
      res.push_back(i - (needle.size() - 1));
    }
  }

  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // print_occurrences(get_occurrences(read_input()));
  // print_occurrences(RabinKarp(read_input()));
  string x, x2;
  cin >> x >> x2;
  print_occurrences(rabin_karp(x, x2));

  return 0;
}