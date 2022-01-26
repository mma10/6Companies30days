/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &arr,int l,int r,int target,bool nonDec){
        while(l < r){
            int mid = l + (r-l) / 2;
            int num = arr.get(mid);
            if(num == target)
                return mid;
            if(nonDec){
                if(target < num)
                    r = mid;
                else
                    l = mid+1;
            }
            else{
                if(target < num)
                    l = mid+1;
                else
                    r = mid;
            }
        }
        if(arr.get(l) == target)
            return l;
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length(), l = 0, r = n-1, peak = -1;
        while(l < r){
            int mid = l + (r-l) / 2; 
            int num1 = arr.get(mid), num2 = arr.get(mid+1);               
            if(num1 < num2)
                l = mid+1;
            else
                r = mid;             
        }
        peak = l;
        
        int index1 = binarySearch(arr,0,peak-1,target,true);
        if(index1 != -1)
            return index1;
        int index2 = binarySearch(arr,peak,n-1,target,false);
        if(index2 != -1)
            return index2;
        return -1;
    }
};