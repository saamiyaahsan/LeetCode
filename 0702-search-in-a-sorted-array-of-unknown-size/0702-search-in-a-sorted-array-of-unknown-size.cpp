/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
     
        int i,j,mid;
        
        i=0;
        j=9999;
        
        while(i <= j)
        {
            mid = (i+j)/2;
            
            if(reader.get(mid) == target)
            {
                return mid;
            }
            
            else if(reader.get(mid) > target)
            {
                j = mid-1;
            }
            
            else
            {
                i = mid + 1;
            }
        }
        
        return -1;
    }
};