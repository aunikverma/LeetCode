class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0; 
        int e = arr.size() - 1;
        if(arr.size() == 1) 
            return arr[0]; 
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(mid == 0 && arr[0] != arr[1]) return arr[mid];
            //base cases
            if(mid == e && arr[e] != arr[e - 1]) return arr[mid];
            //base cases
            if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) return arr[mid];
            if(mid % 2 == 0)//mid at even
            {
                if(arr[mid - 1] == arr[mid])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else//mid at odd
            {
                if(arr[mid - 1] == arr[mid])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }
       return -1; 
    }
};