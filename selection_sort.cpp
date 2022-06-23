#include < iostream >
using namespace std;

void selectionSort(int arr[]) {
  for (int i = 0; i < 4; i++) {
    int min = i;

    for (int j = i + 1; j < 5; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

int main() {

  int myarr[5];
  cout << "Enter 5 integers in random order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarr[i];
  }

  cout << "UNSORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  cout << endl;

  selectionSort(myarr); // sorting actually happening

  cout << "SORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  return 0;
}




/*



void selection_sort(vector<int>&v){
    int n = v.size();
    for(int i = 0 ; i<n ; i++){
        int mn = i;
        for(int j = i+1 ; j<n ; j++){
            if(v[j]<v[mn]){
                mn = j;
            }
        }
        int temp = v[i];
        v[i] = v[mn];
        v[mn] = temp;
    }
}



*/