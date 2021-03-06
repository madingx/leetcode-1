// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Hao Chen
// Date   : 2014-07-22
//
// Version: v2.0
// Modification: add a new method in C++
// Author : Mading
// Date   : 2019-02-26
/********************************************************************************** 
* 
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
* You may assume nums1 and nums2 cannot be both empty.

* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0

* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2 + 3)/2 = 2.5
*               
**********************************************************************************/

#include <stdio.h>

//new solution
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        if (nums1.empty()) return nums2[k - 1];
        if (nums2.empty()) return nums1[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min((int)nums1.size(), k / 2), j = min((int)nums2.size(), k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
//new solution 2 //https://blog.csdn.net/qq_28466517/article/details/79810809
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> temp=nums1;
            nums1=nums2;
            nums2=temp;
        }
        int m=nums1.size(),n=nums2.size();
        int imin=0,imax=m;
        int leftmax,rightmin;
        while (imin<=imax)
        {
            int i=(imin+imax)/2;
            int j=(m+n+1)/2-i;
            if(i>0&&nums1[i-1]>nums2[j])//j<n
                imax=i-1;//decrease i
            else if(i<m&&nums1[i]<nums2[j-1])//j>0
                imin=i+1;//increase i
            else{
                if(i==0)
                    leftmax=nums2[j-1];
                else if(j==0)
                    leftmax=nums1[i-1];
                else
                    leftmax=max(nums1[i-1],nums2[j-1]);

                if((m+n)%2==1)
                    return leftmax;

                if(i==m)
                    rightmin=nums2[j];
                else if(j==n)
                    rightmin=nums1[i];
                else
                    rightmin=min(nums1[i],nums2[j]);

                return (leftmax+rightmin)/2.0;
            }
        }
        return leftmax;
    }

/*********************************old solution,not sure*******************************************/
// Classical binary search algorithm, but slightly different
// if cannot find the key, return the position where can insert the key 
int binarySearch(int A[], int low, int high, int key){
    while(low<=high){
        int mid = low + (high - low)/2;
        if (key == A[mid]) return mid;
        if (key > A[mid]){
            low = mid + 1;
        }else {
            high = mid -1;
        }
    }
    return low;
}

//Notes:
// I feel the following methods is quite complicated, it should have a better high clear and readable solution
double findMedianSortedArrayHelper(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB) {

    // Take the A[middle], search its position in B array
    int mid = lowA + (highA - lowA)/2;
    int pos = binarySearch(B, lowB, highB, A[mid]);
    int num = mid + pos;
    // If the A[middle] in B is B's middle place, then we can have the result
    if (num == (m+n)/2){
        // If two arrays total length is odd, just simply return the A[mid]
        // Why not return the B[pos] instead ? 
        //   suppose A={ 1,3,5 } B={ 2,4 }, then mid=1, pos=1
        //   suppose A={ 3,5 }   B={1,2,4}, then mid=0, pos=2
        //   suppose A={ 1,3,4,5 }   B={2}, then mid=1, pos=1
        // You can see, the `pos` is the place A[mid] can be inserted, so return A[mid]
        if ((m+n)%2==1){
            return A[mid];
        }
        
        // If tow arrys total length is even, then we have to find the next one.
        int next;

        // If both `mid` and `pos` are not the first postion.
        // Then, find max(A[mid-1], B[pos-1]). 
        // Because the `mid` is the second middle number, we need to find the first middle number
        // Be careful about the edge case
        if (mid>0 && pos>0){ 
            next = A[mid-1]>B[pos-1] ? A[mid-1] : B[pos-1];
        }else if(pos>0){
            next = B[pos-1];
        }else if(mid>0){
            next = A[mid-1];
        }
        
        return (A[mid] + next)/2.0;
    }
    // if A[mid] is in the left middle place of the whole two arrays
    //
    //         A(len=16)        B(len=10)
    //     [................] [...........]
    //            ^             ^
    //           mid=7         pos=1
    //
    //  move the `low` pointer to the "middle" position, do next iteration.
    if (num < (m+n)/2){
        lowA = mid + 1;
        lowB = pos; 
        if ( highA - lowA > highB - lowB ) {
            return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
        }
        return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
    }
    // if A[mid] is in the right middle place of the whole two arrays
    if (num > (m+n)/2) {
        highA = mid - 1;
        highB = pos-1;
        if ( highA - lowA > highB - lowB ) {
            return findMedianSortedArrayHelper(A, m, B, n, lowA, highA, lowB, highB);
        }
        return findMedianSortedArrayHelper(B, n, A, m, lowB, highB, lowA, highA);
    }

}

double findMedianSortedArrays(int A[], int m, int B[], int n) {

    //checking the edge cases
    if ( m==0 && n==0 ) return 0.0;

    //if the length of array is odd, return the middle one
    //if the length of array is even, return the average of the middle two numbers
    if ( m==0 ) return n%2==1 ? B[n/2] : (B[n/2-1] + B[n/2])/2.0;
    if ( n==0 ) return m%2==1 ? A[m/2] : (A[m/2-1] + A[m/2])/2.0;
    
    
    //let the longer array be A, and the shoter array be B
    if ( m > n ){
        return findMedianSortedArrayHelper(A, m, B, n, 0, m-1, 0, n-1);
    }
        
    return findMedianSortedArrayHelper(B, n, A, m, 0, n-1, 0, m-1);
}


int main()
{
    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a12)/sizeof(a12[0]);
    n2 = sizeof(a22)/sizeof(a22[0]);

    printf("Median is 11 = %f\n", findMedianSortedArrays(a12, n1, a22, n2));

    int b1[] = {1 };
    int b2[] = {2,3,4};
 
    n1 = sizeof(b1)/sizeof(b1[0]);
    n2 = sizeof(b2)/sizeof(b2[0]);

    printf("Median is 2.5 = %f\n", findMedianSortedArrays(b1, n1, b2, n2));
    return 0;
}
