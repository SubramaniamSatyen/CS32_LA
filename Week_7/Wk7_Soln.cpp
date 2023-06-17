#include <vector>
#include <set>
#include <iostream>
using namespace std;

///Algorithm Analysis, Sorting
///Question 1
int randomSum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {                           // 1 ^ 2 + 2 ^ 2 + … + (n - 1) ^ 2 is O(n ^ 3)
            for (int j = 0; j < i; j++) {                   // O(i ^ 2)
                    if (rand() % 2 == 1) {
                        sum += 1;
                    }
                for (int k = 0; k < j * i; k += j) {        // O(i)
                        if (rand() % 2 == 2) {
                            sum += 1;
                        }
                }
            }
    }
    return sum;
}

///Question 2
int operationFoo(int n, int m, int w) {
    int res = 0;

    for (int i = 0; i < n; ++i) { // the outer loop runs n iterations
        for (int j = m; j > 0; j /= 2) { // every time this loop is entered, this loop runs log2(m) iterations
            for (int jj = 0; jj < 50; jj++) { // every time this loop is entered, it runs 50 iterations, which is constant, or O(1)
                for (int k = w; k > 0; k -= 3) { // every time this loop  is entered, it runs ⅓ * w iterations, or O(w)
                    res += i * j + k; // this line runs in total n*log(m)*w
                }
            }
        }
    }
    return res;
}

///Question 3
// At start, left = 0 and right = length of array - 1
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) { // Iteration stops when left > right
        int middle = left + (right - left) / 2;

        // If the exact match is not found
        // Either left or right will be assigned value of middle
        // So next time in iteration, the new left and right pair
        // interval is half of the original interval
        if (arr[middle] == x)
            return middle;
        else if (arr[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
int main()
{
    int arr[] = { 2, 3, 4, 10, 40, 60, 80 };
    int x = 60;
    int index = binarySearch(arr, 0, 6, x);
    if (index == -1) {
        cout << x << " doesn't exist in array." << endl;
    }
    else {
        cout << x << " is at " << index << " position." << endl;
    }
}

//We get O(log(n))

///Question 4
int obfuscate(int a, int b) {
    vector<int> v;
    set<int> s;
    for (int i = 0; i < a; i++) {
        v.push_back(i);
        s.insert(i); // each insert is O(log(size of set))
    }
    v.clear();

    int total = 0;
    if (!s.empty()) {
        for (int x = a; x < b; x++) {
            for (int y = b; y > 0; y--) {
                total += (x + y);
            }
        }
    }
    return v.size() + s.size() + total;
}

//We get O(a*log(a) + b * (b - a))

///Question 5
bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    if (n == 2) return true;
    for (int i = 3; (i * i) <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//We get O(sqrt(n))


///Question 6
//Table

///Question 7
int countNumOccurrences(const vector<string>& words, char c) {
    int count = 0;
    for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++) {
        const string& word = *it;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == c) {
                ++count;
            }
        }
    }
    return count;
}

//We get O(N * K)

///Question 8
void sort(int a[], int n) {
    int counts[100] = {};  // Count occurrences of each integer.
    for (int i = 0; i < n; i++)
        counts[a[i] - 1]++;

    // Add that many of each integer to the array in order.
    int j = 0;
    for (int i = 0; i < 100; i++)
        for (; counts[i] > 0; counts[i]--)
            a[j++] = i + 1;
}

///Question 9
//Insertion sort

///Question 10
// a) -> {3, 6, 21, 45, 8, 10, 12, 15}
// b) -> {1, 2, 4, 5, 8}
// c) -> {-44, -4, 0, 2, 1, 3, 8, 19}