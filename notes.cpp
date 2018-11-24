//Two pointer techniques:
//1. Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.
// Naive way 1: O(n^2)
bool isPairSum(A[], N, X)
{
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			if(A[i] + A[j] == X)
				return true;
			if (A[i]+A[j]>X)
				break;
		}
	}
	return false;
}

//way 2: O(n)
/*We take two pointers, one representing the first element and other representing the last element of the array, and then we add the values kept at both the pointers. If their sum is smaller than X then we shift the left pointer to right or if their sum is greater than X then we shift the right pointer to left, in order to get closer to the sum. We keep moving the pointers until we get the sum as X.*/
bool isPairSum(A[], N, X){
	//represents first pointer
	int i=0;
	//represents second pointer
	int j=N-1;
	while (i<j){
		if(A[i] + A[j] == X)
			return true;
		else if (A[i] + A[j] <X)
			i++;
		else 
			j--;
	}
	return false;
}
