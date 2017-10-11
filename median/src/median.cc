#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>

using namespace std;

template<typename T>
class WindowedMedian {
	typedef unsigned int size_type;
	typedef typename vector<T>::const_iterator vciterator;

	vector<T> sorted;
	deque<T> unsorted;

public:
	WindowedMedian(const size_type capacity) {
		if (capacity == 0) {
			throw invalid_argument("capacity cannot be negative: " + capacity);
		}
		sorted.reserve(capacity);
	}

	size_type size() const {
		return sorted.size();
	}

	size_type capacity() const {
		return sorted.capacity();
	}

	const T& median() const {
		if (sorted.size() == 0) {
			throw out_of_range("Window is empty");
		}
		return sorted[size() / 2];
	}

	size_type add(const T e) {
		// do we need to remove anything?
		if (size() == capacity()) {
			const T toRemove = unsorted.front();
			unsorted.pop_front();
			const auto range = equal_range(sorted.begin(), sorted.end(), toRemove);
			sorted.erase(range.first);
		}

		// Add new element to unsorted and sorted lists
		size_type iFinalPosition = 0;
		unsorted.push_back(e);
		vciterator itInsertion = sorted.begin();
		while (*itInsertion < e && itInsertion != sorted.end()) {
			itInsertion++;
			iFinalPosition++;
		}
		sorted.insert(itInsertion, e);

		return iFinalPosition;
	}

	void clear() {
		sorted.clear();
		unsorted.clear();
	}

	friend ostream& operator<<(ostream& os, const WindowedMedian& wm) {
		os << "WindowedMedian(sorted={";

		bool first = true;
		for (const auto i : wm.sorted) {
			if (first) {
				first = false;
			} else {
				os << " ";
			}
			os << i;
		}

		os << "}, median=" << wm.median() << ")";

		return os;
	}
};

int main(int argc, char* argv[]) {
	WindowedMedian<int> window(5);

	for (int i = 0; i < argc; i++) {
		const int n = atoi(argv[i]);

		// plain old insertion sort
		window.add(n);
		cout << "inserted " << n << ", " << window << endl;
	}
}
