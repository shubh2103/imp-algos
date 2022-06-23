#include<bits/stdc++.h>
using namespace std;



/*    shell short      */

// void shell_short(vector<int>&v){
//     int n = v.size();
//     for(int gap = n/2 ; gap>0 ; gap = gap/2){
//         for(int j = gap ; j<n ; j++){
//             int temp = v[j];
//             int i = 0;
//             for(i = j ; i>=0 ; i-=gap){
//                 if(i-gap>=0 and v[i-gap]>temp){
//                     v[i] = v[i-gap];
//                 }
//                 else{
//                     break;
//                 }
//             }
//             v[i]=temp;
//         }
//     }
// }



/*   selection sort    */


// void selection_sort(vector<int>&v){
//     int n = v.size();
//     for(int i = 0 ; i<n ; i++){
//         int mn = i;
//         for(int j = i+1 ; j<n ; j++){
//             if(v[j]<v[mn]){
//                 mn = j;
//             }
//         }
//         int temp = v[i];
//         v[i] = v[mn];
//         v[mn] = temp;
//     }
// }



/*     bubble sort     */


// void bubble_sort(vector<int>&v){
//     int n = v.size();
//     for(int i = 0 ; i<n ; i++){
//         for(int j = 0 ; j<n-i-1 ; j++){
//             if(v[j]>v[j+1]){
//                 swap(v[j] , v[j+1]);
//             }
//         }
//     }
// }



/*  optimized bubble sort      */


// void optimized_bubble_sort(vector<int>&v){
//     int n = v.size();
//     for(int i = 0 ; i<n ; i++){
//         bool f = 1;
//         for(int j = 0 ; j<n-i-1 ; j++){
//             if(v[j]>v[j+1]){
//                 f = 0;
//                 swap(v[j] , v[j+1]);
//             }
//         }
//         if(f)break;
//     }
// }



/*   merge sort      */


// void merge(vector<int>&v , int l , int m , int r){
//     int i = l , j = m+1 , k = l;
//     vector<int>temp(v.size() , 0);// this can be declared outside also and used here;
//     while(i<=m and j<=r){
//         if(v[i]<=v[j]){
//             temp[k++]=v[i++];
//         }
//         else{
//             temp[k++]=v[j++];
//         }
//     }
//     while(i<=m){
//         temp[k++]=v[i++];
//     }
//     while(j<=r){
//         temp[k++]=v[j++];
//     }
//     for(int k = l ; k<=(r) ; k++){
//         v[k]=temp[k];
//     }
// }
// void merge_sort(vector<int>&v , int l , int r){
//     if(l<r){
//         int m = (l+r)/2;
//         merge_sort(v , l , m);
//         merge_sort(v , m+1 , r);
//         merge(v , l , m , r);
//     }
// }



/*    insertion sort     */



// void insertion_sort(vector<int>&v){
//     int n = v.size();
//     for(int i = 1 ; i<n ; i++){
//         int num = v[i];
//         int j = i-1;
//         while(j>=0 and v[j]>num){
//             v[j+1]=v[j];
//             j--;
//         }
//         v[j+1]=num;
//     }
// }




/*      counting   sort      */


// void counting_sort(vector<int>&v){
//     int n = v.size();
//     int mx = *max_element(v.begin() , v.end());
//     vector<int>count(mx+1 , 0);
//     for(int i = 0 ; i<n ; i++){
//         count[v[i]]++;
//     }
//     for(int i = 1 ; i<=mx ; i++){
//         count[i]+=count[i-1];
//     }
//     vector<int>temp(n , 0);
//     for(int i = 0 ; i<n ; i++){
//         temp[--count[v[i]]]=v[i];
//     }
//     for(int i = 0 ; i<n ; i++){
//         v[i]=temp[i];
//     }
// }






/*    radix sort    */


// void counting_sort(vector<int>&v , int d){
//     int n = v.size();
//     vector<int>count(10  , 0);
//     for(int i = 0 ; i<n ; i++){
//         count[(v[i]/d)%10]++;
//     }
//     for(int i = 1 ; i<10 ; i++){
//         count[i]+=count[i-1];
//     }
//     vector<int>temp(n , 0);
//     for(int i = n-1 ; i>=0 ; i--){
//         temp[--count[(v[i]/d)%10]]=v[i];
//     }
//     for(int i = 0 ; i<n ; i++){
//         v[i]=temp[i];
//     }
// }

// void radix_sort(vector<int>&v){
//     int n = v.size();
//     int mx = *max_element(v.begin() , v.end());
//     int d = 1;
//     while(mx>0){
//         counting_sort(v , d);
//         mx = mx/10;
//         d = d*10;
//     }
// }





/*     quick sort       */



// int partition(vector<int>&v , int l , int r){
//     int pivot = v[r];
//     int pidx = l;
//     // this for loop will segregate all less than and greater than pivot element.
//     for(int i = l ; i<r ; i++){
//         if(v[i]<pivot){
//             swap(v[i] , v[pidx]);
//             pidx++;
//         }
//     }
//     // now we will bring last element to correct pos;

//     int temp = v[pidx];
//     v[pidx]=pivot;
//     v[r]=temp;
//     return pidx;    
// }
// void quick_sort(vector<int>&v , int l , int r){
//     if(l<r){
//         int p = partition(v , l , r);
//         quick_sort(v , l , p-1);
//         quick_sort(v , p+1 , r);
//     }
// }







/*     heap sort       */




// in this we have to min heapify the array from n/2-1 to 0 rem this and then call heap_sort() function
 

// int left(int i){
//     return (2*i)+1;
// }
// int right(int i){
//     return (2*i)+2;
// }
// int parent(int i){
//     return (i-1)/2;
// }
// void min_heapify(int i , vector<int>&v){
//     int l = left(i);
//     int r = right(i);
//     int smallest = i;
//     int heap_size = v.size();
//     if(l<heap_size and v[l]<v[smallest]){
//         smallest = l;
//     }
//     if(r<heap_size and v[r]<v[smallest]){
//         smallest = r;
//     }
//     if(smallest!=i){
//         swap(v[i] , v[smallest]);
//         min_heapify(smallest , v);
//     }
// }

// int extract_min(vector<int>&v){
//     if(v.size()==1){
//         int res = v[0];
//         v.pop_back();
//         return res;
//     }
//     int res = v[0];
//     v[0] = v[v.size()-1];
//     v.pop_back();
//     min_heapify(0 , v);
//     return res;
// }

// void heap_sort(vector<int>&v){
//     vector<int>ans;
//     while(v.size()>0){
//         ans.push_back(extract_min(v));
//     }
//     for(auto i:ans){
//         v.push_back(i);
//     }
// }



int32_t main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    optimized_bubble_sort(v);
    for(int i = 0 ; i<n ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}