#include <iostream>
#include <vector>

void merge(std::vector<int>& nums, int left, int mid, int right) {
	std::vector<int> left_part(nums.begin() + left, nums.begin() + mid + 1);
	std::vector<int> right_part(nums.begin() + mid + 1, nums.begin() + right + 1);

	int left_pos = 0;
	int right_pos = 0;
	int nums_pos = left;
	while (left_pos < left_part.size() && right_pos < right_part.size()) {
		if (left_part[left_pos] < right_part[right_pos]) {
			nums[nums_pos++] = left_part[left_pos++];	
		} else {
			nums[nums_pos++] = right_part[right_pos++];	
		}
	}
	while (left_pos < left_part.size()) {
		nums[nums_pos++] = left_part[left_pos++];	
	}
	while (right_pos < right_part.size()) {
		nums[nums_pos++] = right_part[right_pos++];	
	}
}

void mergeSort(std::vector<int>& nums, int left, int right) {
	if (right - left + 1 == 1) { return; }
	int mid = left + (right - left) / 2;

	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

int main() {
	std::vector<int> nums {1,6, 3, 9, 6, 4, 0};
	mergeSort(nums, 0, nums.size() - 1);
	for (const auto& n : nums) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
	return 0;
}
