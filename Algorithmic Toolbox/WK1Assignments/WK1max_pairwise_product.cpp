#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  int max1 = 0;
  int max2 = 0;
  int maxs = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i)
  {
    // check n[i] for max1
    if (numbers[i] > max1)
    {
        // to swap max1 and max2
        maxs = max1;
        max1 = numbers[i];

        // if the old max1 is the second biggest number
        if (maxs>max2)
        {
            max2 = maxs;
        }
    }
    // when max1 doesn't change but max2 changes
    else if (numbers[i]>max2)
    {
        max2 = numbers[i];
    }
  }
  //cout << "max1="<< max1 <<", max2="<< max2<< ",maxs=" << maxs << "\n";
  // to fix an integer overflow bug
  // note that long long result = max1 * max won't work, have to define the type when multiplication happening
  long long result = (long long)max1 * max2;
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int>numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
