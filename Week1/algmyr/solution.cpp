#include <array>
#include <chrono>
#include <iostream>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

using namespace std;

// Just a handy timer utility that I like to use.
// Enable by defining TIME_IT or pass -DTIME_IT to the compiler.
struct TimeIt {
#ifdef TIME_IT
  string_view label;
  decltype(chrono::high_resolution_clock::now()) begin;
  TimeIt(string_view label = "") : label(label) {
    begin = chrono::high_resolution_clock::now();
  }
  ~TimeIt() {
    auto end = chrono::high_resolution_clock::now();
    auto duration =
        chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    cerr << duration << "ms elapsed [" << label << "]" << endl;
  }
#else
  TimeIt(string_view) {}
#endif
};

void Solve1(int n, int m, const vector<int>& steps,
            const vector<string>& strings) {
  // Not that much going on, allocate an array to hold all string results.
  // For every input modulo and string, jump along the result and append.
  //
  // Complexity is O(n log(m)).
  //
  // The log(m) comes from that the moduli are unique.
  // In the worst case we have {1, 2, ..., m}.
  // Which means we access n + n/2 + ... + n/m elements in the result.
  // This sum is n H_m where H_m is the mth Harmonic number, and H_m ~ log(m).
  TimeIt _("Solution 1 - Simple");

  vector<string> result(n + 1);

  for (int i = 0; i < m; ++i) {
    int step = steps[i];
    string s = strings[i];
    for (int j = step; j <= n; j += step) {
      result[j].append(s);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (result[i].empty())
      cout << i << '\n';
    else
      cout << result[i] << '\n';
  }
}

void Solve2(int n, int m, const vector<int>& steps,
            const vector<string>& strings) {
  // This is exactly the same approach as the first solution with one change,
  // here we work on blocks of numbers at a time.
  //
  // This has 2 big advantages:
  //   * Lower memory usage, we only have one block allocated at once
  //   * Better cache locality when jumping around the result
  //
  // This optimization is very similar to what you do when writing a segmented
  // sieve of Eratosthenes
  //   * You go through a block as usual
  //   * At the end of the block remember the offset that you end at for each
  //   modulo
  //   * At the next block start at that offset
  TimeIt _("Solution 2 - Segmented");
  ++n;  // Work with right-open interval [1, n)

  auto offsets = steps;
  constexpr int kBlockSize = 1 << 14;
  array<string, kBlockSize> block;

  // Lambda that handles one block.
  // This is broken out to not repeat logic for the last (truncated) block.
  auto handle = [&](int block_index, int block_len) {
    for (auto& b : block) b.clear();

    int block_start = block_index * kBlockSize;
    int block_end = block_start + block_len;

    // Build strings for every number in the block
    for (int i = 0; i < m; ++i) {
      int j = offsets[i];
      int step = steps[i];
      for (; j < block_end; j += step) {
        block[j % kBlockSize].append(strings[i]);
      }
      offsets[i] = j;
    }

    // Output for every number in the block
    for (int j = 0; j < block_len; ++j) {
      const auto& s = block[j];
      if (s.empty()) {
        int actual_number = block_start + j;
        if (actual_number != 0) cout << actual_number << '\n';
      } else {
        cout << s << '\n';
      }
    }
  };

  // Handle full blocks.
  int n_full_blocks = n / kBlockSize;
  for (int i = 0; i < n_full_blocks; ++i) {
    handle(i, kBlockSize);
  }
  // Handle the last (truncated) block.
  int n_remaining = n % kBlockSize;
  handle(n_full_blocks, n_remaining);
}

tuple<int, int, vector<int>, vector<string>> ReadInput() {
  TimeIt _("Input parsing");

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> steps;
  steps.reserve(m);
  vector<string> strings;
  strings.reserve(m);

  for (int i = 0; i < m; ++i) {
    int step;
    string s;
    cin >> step >> s;
    steps.push_back(step);
    strings.push_back(s);
  }

  return {n, m, move(step), move(strings)};
}

int main() {
  auto [n, m, steps, strings] = ReadInput();
  Solve1(n, m, steps, strings);
  Solve2(n, m, steps, strings);
}

