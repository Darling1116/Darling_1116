#pragma once
#define _CRT_SECURE_NO_WARNINGS

//方法三：使用二分查找，时间复杂度O(logN)
void test2_1(){
	int arr[] = { 3, 4, 5, 1, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	int mid = 0;  //存放最终的结果

	while (left < right){
		mid = (left + right) >> 1;
		if (arr[mid] > arr[right]){
			left = mid + 1;
		}
		else if (arr[mid] < arr[right]){
			right = mid;
		}
		else{
			right--;
		}
	}
	printf("min: %d\n", arr[left]);

	//while (left < right){
	//	if (left + 1 == right){
	//		mid = right;
	//		break;
	//	}
	//	int mid = (left + right) >> 1;
	//	if (arr[left] == arr[mid] && arr[mid] == arr[right]){
	//		int result = arr[left];
	//		for (int i = left+1; i < right; i++){
	//			if (arr[i] < result){
	//				result = arr[i];
	//			}
	//		}
	//		printf("min: %d\n", result);
	//		return;
	//	}
	//	if (arr[mid] > arr[left]){
	//		left = mid;
	//	}
	//	else if (arr[mid] < arr[right]){
	//		right = mid;
	//	}
	//}
	//printf("min: %d\n", arr[mid]);

}