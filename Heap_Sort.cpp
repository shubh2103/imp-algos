#include<iostream>
#include<math.h>

using namespace std;

class MinHeap {
  public:
    int * harr; // pointer to array of elements in heap
  int capacity; // maximum possible size of min heap
  int heap_size; // Current number of elements in min heap

  MinHeap(int cap) {
    heap_size = cap;
    capacity = cap;
    harr = new int[cap];
  }

  void printArray() {
    for (int i = 0; i < heap_size; i++)
      cout << harr[i] << " ";
    cout << endl;
  }

  int parent(int i) {
    return (i - 1) / 2;
  }

  int left(int i) {
    return (2 * i + 1);
  }

  int right(int i) {
    return (2 * i + 2);
  }
  int getMin() {
    return harr[0];
  }
  void MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
      smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
      smallest = r;
    if (smallest != i) {
      swap(harr[i], harr[smallest]);
      MinHeapify(smallest);
    }
  }
  // Method to remove minimum element (or root) from min heap
  int extractMin() {
    if (heap_size <= 0)
      return INT_MAX;
    if (heap_size == 1) {
      heap_size--;
      return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    //printArray();
    //cout <<"--"<<harr[0]<<"--";
    return root;
  }

  void getUnsortedArray() {
    cout << "Enter " << capacity << " no of elements to sort using HEAPSORT" << endl;
    for (int i = 0; i < capacity; i++)
      cin >> harr[i];
  }

  void heapSort() {
    int temp[capacity];
    for (int j = 0; j < capacity; j++) {
      //cout<<extractMin()<<" ";
      temp[j] = extractMin();
      cout << temp[j] << " ";
    }
  }

};

int main() {
  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s; // 5
  MinHeap obj(s);
  obj.getUnsortedArray(); // 7 4 3 9 8

  cout << "Unsorted Array :" << endl;
  obj.printArray();

  for (int i = s / 2 - 1; i >= 0; i--) {
    obj.MinHeapify(i);
  }

  //cout << "Heapified Array :"<<endl;
  //obj.printArray();

  cout << "Heap Sorted Array :" << endl;
  obj.heapSort();

}







/*



// in this we have to min heapify the array from n/2-1 to 0 rem this and then call heap_sort() function








int left(int i){
    return (2*i)+1;
}
int right(int i){
    return (2*i)+2;
}
int parent(int i){
    return (i-1)/2;
}


void min_heapify(int i , vector<int>&v){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    int heap_size = v.size();
    if(l<heap_size and v[l]<v[smallest]){
        smallest = l;
    }
    if(r<heap_size and v[r]<v[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        swap(v[i] , v[smallest]);
        min_heapify(smallest , v);
    }
}
int extract_min(vector<int>&v){
    if(v.size()==1){
        int res = v[0];
        v.pop_back();
        return res;
    }
    int res = v[0];
    v[0] = v.back();
    v.pop_back();
    min_heapify(0 , v);
    return res;
}

void heap_sort(vector<int>&v){
    vector<int>ans;
    while(v.size()>0){
        ans.push_back(extract_min(v));
    }
    for(auto i:ans){
        v.push_back(i);
    }
}









*/