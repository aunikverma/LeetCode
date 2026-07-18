class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);

        int l = 0;
        int r = arr.size()-1;

        while(l<=r){

            int mid = (l+r)/2;

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) 
                return mid;

            else if(arr[mid]< arr[mid+1]) 
                l = mid+1;

            else 
                r = mid;
        }
        return -1;
}
};