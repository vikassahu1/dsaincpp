#include <iostream>
#include <vector>
#include <string>
using namespace std;




// function to reverse a string
void reverseWords(vector<char> &s)
{
    vector<char> temp;
    int st;
    int j = 0;
    int e = s.size() - 1;

    // Last se check karega jaha index par ' ' milega waha se temp m store kr dega 
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            st = i;
            for (int j = st + 1; j <= e; j++)
            {
                temp.push_back(s[j]);
            }
            e = st - 1;
            temp.push_back(' ');
        }
    }

    // Bacha hua string print karne k lie 
    for (int j = 0; j <= e; j++)
            {
                temp.push_back(s[j]);
            }
    s = temp;

    // Print karne k lie 
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }cout<<endl;
}




// Maximum  occuring character in a string 
void maxChar(string s){
    int arr[26] = {0};

    // To count the maximum ocuurance character. 
    for (int i = 0; i < s.length(); i++)
    {
        char ch  = s[i];
        int number = 0;
        if (s[i]>='a' && s[i]<='z')
        {
            number = ch-'a';
        }
        else{
            number = ch-'A';
        }
        arr[number]++;
    }
    
    // To get character at maximum index. 
    int max = -1,i = 0,ans = 0;
    for (i; i < 26; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
            ans = i;
        }
    }
    char final = ans+'a';
    cout<<"Maximum occurance is "<<max<<endl;
    cout<<"Maximum occurance character is "<< final <<endl;
}





// Putting @40 in place of spaces in a string.
void Atforty(string &str){
    string copy="";

    int i=0;
    while (str[i]!='\0')
    {
        if (str[i]==' ')
        {
            copy.push_back('@');
            copy.push_back('4');
            copy.push_back('0');
        }
        else{
            copy.push_back(str[i]);
        }
        i++;
    }
    str = copy;
    cout<<str<<endl;
}




// Erasing substrings inside a string 
string removeSub(string str,string part){
    while (str.length()!=0 && str.find(part)<str.length())
        str.erase(str.find(part),part.length());
    return str;
}





// Checking any permutation of an string exists in other string or not 

bool checkEqual(int count1[26],int count2[26]){
    for (int i = 0; i < 26; i++)
    {
        if(count1[i]!=count2[i])
            return 0;
    }
    return 1;
}

bool chechPermutation(string s1,string s2){

    // Chracter count in array 
    int count1[26] ={0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    
    // Traverse s2 string in the window of size s1 length and compare 
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // running for the first window 
    while (i<windowSize && i<s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    if (checkEqual(count1,count2))
        return 1; 
    
    // Window ko aage process krna h 
    while (i<s2.length())
    {
        // new character k index ko ++ karna h 
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++; 

        // old character ko hatana h  
        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        if (checkEqual(count1,count2))
        return 1; 
    }
    return 0;
}

// Code to remove adjacent duplicates 
string removeAdjacentDuplicates(string s){
    int count=0;
    int n =0;
    while (count==0)
    {
        
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i]==s[i+1])
            {
                s.erase(i,2);
                count++;
            }
        }
        if (count==0)
        {
            break;
        }
        count=0;
        n++;
    }
    cout<<n<<endl;
    return s;
}

// Array for compressing the character array

void compressArray(vector<char> &arr){
    vector<char> count(26,0);
    vector<char> temp;

    // for counting the number 
    for(int i:arr){
        count[i-'a']++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (count[arr[i]-'a'] != -1)
        {
            temp.push_back(arr[i]);
            if (count[arr[i]-'a']!=1)
            {
                // Yaha par 48 plus lia taki ascii value se number match ho jaye 
                temp.push_back(count[arr[i]-'a'] + 48);
            }
        }
        count[arr[i]-'a'] = -1;
    }
    
    arr = temp;

    // to print
    for(char i:arr){
        cout<<i<<" ";
    }cout<<endl;
}

int main()
{
    // vector<char> a = {'i', 's', ' ', 'V'};
    // reverseWords(a);
    // string s = "Vggwweeiffktteeeessaaaaaaaaaaas";
    // maxChar(s);
    // Atforty(s);
    // cout<<removeSub(s,"as")<<endl;
    // cout<<removeAdjacentDuplicates(s)<<endl;

    vector<char> a = {'a', 'a', 'a','b','b','c','d','d'};
    compressArray(a);
    return 0;
}
