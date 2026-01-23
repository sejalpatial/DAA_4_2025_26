#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int operations=0;
void complexRec(int n) {
   operations++;
   
   if (n <= 2) {   // 1 OPERATION
       
       return;
   }


   int p = n;
   operations++;
   while (p > 0) {   // O(n log n)
      operations++;
       vector<int> temp(n);
        operations++;
       for (int i = 0; i < n; i++) {
           operations++;
           temp[i] = i ^ p;
           operations++;
       }
       p >>= 1;
       operations++;
   }


   vector<int> small(n);
     operations++;
   for (int i = 0; i < n; i++) {
      operations++;
       small[i] = i * i;
         operations++;
   }


   if (n % 3 == 0) {  //O(n)
       reverse(small.begin(), small.end());
       operations+=n;
   } else {
       reverse(small.begin(), small.end());
        operations+=n;
   }

   //O(3T(N/2))
   complexRec(n / 2);  
   complexRec(n / 2);
   complexRec(n / 2);
   
}
//recurrence relation T(N)=3T(N/2)+O(N log N)
//CASE 1 OF MASTER THEOREM T.C. O(N ^ log_2 3)

