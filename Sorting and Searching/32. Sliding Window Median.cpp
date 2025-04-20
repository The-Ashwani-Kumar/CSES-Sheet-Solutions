#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

long arraySize, windowSize;
long sequenceElements[200010];  // Array containing input sequence for median calculation
multiset<long> upperHalf;    // stores the larger half of elements
multiset<long> lowerHalf;    // stores the smaller half of elements

void insertNumber(long value) {
    /* Insertion Logic:
     * 1. If lowerHalf is empty, directly insert
     * 2. If value > current median, add to upperHalf
     * 3. If value <= current median, add to lowerHalf
     * 4. Rebalance sets if size conditions are violated
     */
    if (lowerHalf.empty()) {
        lowerHalf.insert(value);
        return;
    }

    long currentMedian = *lowerHalf.rbegin();
    if (currentMedian < value) {
        // Add to upper half and rebalance if needed
        upperHalf.insert(value);
        if (upperHalf.size() > windowSize / 2) {
            // Move smallest element from upper to lower half
            lowerHalf.insert(*upperHalf.begin());
            upperHalf.erase(upperHalf.begin());
        }
    } else {
        // Add to lower half and rebalance if needed
        lowerHalf.insert(value);
        if (lowerHalf.size() > (windowSize + 1) / 2) {
            // Move largest element from lower to upper half
            upperHalf.insert(*lowerHalf.rbegin());
            lowerHalf.erase(--lowerHalf.end());
        }
    }
}

void removeNumber(long value) {
    /* Removal Logic:
     * 1. Find and remove value from appropriate set
     * 2. Rebalance if lowerHalf becomes empty
     */
    if (upperHalf.find(value) != upperHalf.end()) 
        upperHalf.erase(upperHalf.find(value));
    else 
        lowerHalf.erase(lowerHalf.find(value));
    
    // If lowerHalf is empty after removal, move smallest element from upperHalf
    if (lowerHalf.empty() && !upperHalf.empty()) {
        lowerHalf.insert(*upperHalf.begin());
        upperHalf.erase(upperHalf.begin());
    }
}

int main() {
    cin >> arraySize >> windowSize;
    for (int i = 0; i < arraySize; i++) 
        cin >> sequenceElements[i];

    // Initialize first window
    lowerHalf.insert(sequenceElements[0]);
    for (int i = 1; i < windowSize; i++) 
        insertNumber(sequenceElements[i]);

    // Process each window and print median
    cout << *lowerHalf.rbegin() << " ";
    for (long i = windowSize; i < arraySize; i++) {
        if (windowSize == 1) {
            insertNumber(sequenceElements[i]);
            removeNumber(sequenceElements[i - windowSize]);
        } else {
            removeNumber(sequenceElements[i - windowSize]);
            insertNumber(sequenceElements[i]);
        }
        cout << *lowerHalf.rbegin() << " ";
    }
    cout << endl;
}