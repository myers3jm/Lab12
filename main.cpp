#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <memory>

typedef std::chrono::high_resolution_clock Clock;

void insertionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int a = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > a) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = a;
	}
}

void mergeSort(int arr[], int start, int end) {
	// Base case
	if (start == end || start == end - 1) { // Size == 1 here
		return;
	}
	else {
		// Divide list into two
		int mid = start + (end - start) / 2;
		// Sort (recursive call)
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end); // TODO: Will cause errors for arrays of length 3 or less
		// Combine
		for (int j = start; j < end; j++) { // For all values from start to end
			// Find least
			int least{ arr[j] };
			int idx{ j };
			for (int i = j; i < end; i++) {
				if (arr[i] < least) {
					least = arr[i];
					idx = i;
				}
			}
			// Swap with front
			int temp = arr[j];
			arr[j] = arr[idx];
			arr[idx] = temp;
		}
	}
}

std::shared_ptr<int[]> countSort(int arr[], int n) {
	// Find max and min
	int min{ arr[0] };
	int max{ arr[0] };
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		else if (arr[i] > max) {
			max = arr[i];
		}
	}
	// Create array of counts
	//auto counts = std::make_shared<int[]>(max);
	std::shared_ptr<int[]> counts{ new int[max + 1]{} };

	// Count occurrences
	for (int i = 0; i < n; i++) {
		counts[arr[i]]++;
	}
	for (int i = 1; i < max + 1; i++) {
		counts[i] += counts[i - 1];
	}
	
	// Reinsertion
	std::shared_ptr<int[]> retArr{ new int[n] {} };
	for (int i = 0; i < n; i++) {
		int spot = counts[arr[i]];
		retArr[spot - 1] = arr[i];
		counts[arr[i]]--;
	}
	return retArr;
}

std::shared_ptr<int[]> stableCountSort(int arr[][], int n, int compIdx) {
	// Find max and min
	int min{ arr[0] };
	int max{ arr[0] };
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i][compIdx];
		}
		else if (arr[i] > max) {
			max = arr[i];
		}
	}
	// Create array of counts
	//auto counts = std::make_shared<int[]>(max);
	std::shared_ptr<int[]> counts{ new int[max + 1]{} };

	// Count occurrences
	for (int i = 0; i < n; i++) {
		counts[arr[i]]++;
	}
	for (int i = 1; i < max + 1; i++) {
		counts[i] += counts[i - 1];
	}

	// Reinsertion
	std::shared_ptr<int[]> retArr{ new int[n] {} };
	for (int i = 0; i < n; i++) {
		int spot = counts[arr[i]];
		retArr[spot - 1] = arr[i];
		counts[arr[i]]--;
	}
	return retArr;
}

void radixSort(int arr[], int n) {
	// Iterate over elements of the array
		// Find maximum length for an element
		// Convert all elements to arrays of length == max length, prefixing with zeroes where needed
	// For i = maximum length, i > 0, i--
		// Iterate over elements of the array
		// sort based on digit i of each element

	int maxLength{ 0 };
	for (int i = 0; i < n; i++) {

	}
}
int main() {

	// Declare arrays
	const int SIZE{ 10 };
	int arr[SIZE];

	int insertArr[SIZE];
	int mergeArr[SIZE];
	int countArr[SIZE];

	// Populate array with random values
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		int n = rand() % 20 + 1;
		arr[i] = n;
		insertArr[i] = n;
		mergeArr[i] = n;
		countArr[i] = n;
	}

	// Print unsorted array
	for (auto j : arr) {
		std::cout << j << " ";
	}
	std::cout << "\n";

	// Sort array
	/*int size = sizeof(insertArr) / sizeof(insertArr[0]);

	auto t1 = Clock::now();
	insertionSort(insertArr, size);
	auto t2 = Clock::now();

	std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds.\n";*/

	//mergeSort(mergeArr, 0, SIZE);
	//std::shared_ptr<int[]> idk = countSort(countArr, SIZE);


	// Print sorted array
	/*for (int j = 0; j < SIZE; j++) {
		std::cout << idk[j] << " ";
	}*/
	std::cout << "\n";


	return 0;
}

