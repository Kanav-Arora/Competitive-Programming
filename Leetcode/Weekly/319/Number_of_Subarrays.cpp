
class Solution {
    public static int func_of_gcd(int num1  , int num2)
    {
        if(num2 == 0)
        {
            return num1;
        }
        
        return func_of_gcd(num2 , num1 % num2);
    }
    public int subarrayLCM(int[] nums, int k) {
        
        int counter = 0;
        for(int ptr_i = 0 ;  ptr_i < nums.length  ; ptr_i++)
        {
           int lcming = nums[ptr_i];
           for(int ptr_j = ptr_i ; ptr_j < nums.length ; ptr_j++)
           {
               lcming = (lcming * nums[ptr_j]) / func_of_gcd(lcming,nums[ptr_j]);
               if(lcming == k)
               {
                   counter++;
               }              
           }
        }
        
        return counter;
    }
}