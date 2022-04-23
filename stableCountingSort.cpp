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