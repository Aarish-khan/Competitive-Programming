/*
Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Print the character in patt that is present at the minimum index in str. Print "No character present" (without quotes) if no character of patt is present in str.

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl
Output:
e
No character present
*/

int minIndexChar(string str, string patt)
{
    int str_size = str.size();
    int patt_size = patt.size();
    //extra space will be only 26 characters memory e.g constant extra space
    map<char,int> hmap;
    
    for(int i=0; i<str_size; ++i){
        
        if(hmap.find(str[i]) == hmap.end())
            hmap[str[i]] = i;
    }
    
    int min_idx = str_size+1;
    for(int i=0; i<patt_size; i++)
    {
        if(hmap.find(patt[i]) != hmap.end())
            min_idx = min(min_idx,hmap[patt[i]]);
    }
    if(min_idx == str_size+1)
        return -1;
    return min_idx;
    
}
