// MEDIUM

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>frequency(10,0); // Creating Frequency array of size 10 and initialise it to 0 
        
        for(char i:num)frequency[i - '0']++; // Storing the frequency
        
        string s1 = "", s2 = ""; // Intiliasing two empty strings 
        
        for(int i = 9;i>=0;i--) // starting the loop in the reverse as we need to create largest palindrome number
        {
            // if the s1 and s2 string is empty and we add zero to it , it will have leading zeroes , which we explicitly do not want in our answer 
           
            if(i == 0 && s1.empty())
                continue;
           
            // if it has only one character as its frequency than we may or may not need it in our final answer as we can have at max only one character in our answer whose frequency is one or else we cannot create palindrome.
            
            while(frequency[i] > 1) 
            {
                // Inserting the characters in both the strings
                s1 += to_string(i);
                s2 += to_string(i);
                frequency[i] -= 2;
            }
        }
        
        //As above mentioned , we can have one value whose frequency is one in our final answer, so the trick is to add the lasrgest possible value available in the frequency array to get the largest possible palindrome
        
        for(int i = 9;i>=0;i--)
        {
            if(frequency[i]) 
            {
                s1 += to_string(i);
                break;
            }
        }
        
        // reverse the s2 string and concatenate it with the s1 and return it;
        
        reverse(s2.begin(),s2.end());
        
        return s1 + s2 ;
    }
};