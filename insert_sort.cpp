#include <iostream>
#include <vector>

std::vector<int> insertationSort(std::vector<int>& nums) {
	if (nums.size() < 2) { return nums; }
	for (int i = 1; i < nums.size(); i++) {
		int j = i - 1;
		while (j >= 0 && nums[j + 1] < nums[j]) {
			int tmp = nums[j + 1];
			nums[j + 1] = nums[j];
			nums[j] = tmp;
			j--;
		}
	}
	return nums;
}

int main()
{
	std::vector<int> data {1, 4, 2, 6, 5};
	auto result = insertationSort(data);
	for (const auto& n : result) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	return 0;
}
