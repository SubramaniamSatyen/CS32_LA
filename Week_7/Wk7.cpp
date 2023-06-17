#include <vector>
#include <set>
#include <iostream>
using namespace std;

///Algorithm Analysis, Sorting
///Question 1
int randomSum(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (rand() % 2 == 1) {
                sum += 1;
            }
            for (int k = 0; k < j * i; k += j) {
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

    for (int i = 0; i < n; ++i) {
        for (int j = m; j > 0; j /= 2) {
            for (int jj = 0; jj < 50; jj++) {
                for (int k = w; k > 0; k -= 3) {
                    res += i * j + k;
                }
            }
        }
    }
    return res;
}

///Question 3
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) {
        int middle = left + (right - left) / 2;

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

///Question 4
int obfuscate(int a, int b) {
    vector<int> v;
    set<int> s;
    for (int i = 0; i < a; i++) {
        v.push_back(i);
        s.insert(i);
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

///Question 5
bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    if (n == 2) return true;
    for (int i = 3; (i * i) <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


///Question 6
//Table

///Question 7
int countNumOccurrences(const vector<string>& words, char c);

///Question 8
void sort(int a[], int n);

///Question 9
//Multiple choice

///Question 10
//Sort arrays