// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> l; // Contains all the leaders found in the array a
      
        if (n <= 0) {
            return l;
        }
        
        // The last element is always a leader 
        int max_leader = a[n - 1];
        l.push_back(max_leader);
        
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > max_leader) {
                l.insert(l.begin(), a[i]);
                max_leader = a[i];
            }
        }
        
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
