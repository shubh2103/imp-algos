# include <iostream>
using namespace std;
// counting sort sorting algorithm
void CountingSort(int input_array[],int s, int r)
{
	int output_array[s];
	int count_array[r];
	
	// initialize all elements to 0 in count array
	for(int i=0;i<r;i++)
		count_array[i]=0;
		
	// to take a count of all elements in the input array
	for(int i=0;i<s;i++)
		++count_array[input_array[i]];
	
	// cummulative count of count array to get the 
	// positions of elements to be stored in the output array
	for(int i=1;i<r;i++)
		count_array[i]=count_array[i]+count_array[i-1];
	
	// placing input array elements into output array in proper
	//  positions such that the result is a sorted array in ASC order
	for(int i=0;i<s;i++)
		output_array[--count_array[input_array[i]]] = input_array[i];
	
	// copy output array elements to input array
	for(int i=0;i<s;i++)
		input_array[i]=output_array[i];
}

int main()
{
	int size=0;
	int range = 10;
	cout<<"Enter Size of array: "<<endl;
	cin>>size;
	int myarray[size];
	cout<<"Enter "<<size<<" integers in any order in range of 0-9: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>myarray[i];
	}
	cout<<"Before Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	cout<<endl;
	CountingSort(myarray,size,range);  // counting sort called
	cout<<"After Sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<myarray[i]<<" ";
	}
	return 0;
}



/*
Working –
Step 1 – Take input array & range(no of unique integer values involved)
Step 2 – Create the output array of size same as input array. Create count array with size equal to the range & initialize values to 0.
Step 3 – Count each element in the input array and place the count at the appropriate index of the count array
Step 4 – Modify the count array by adding the previous counts(cumulative). The modified count array indicates the position of each object/element in the output array.
Step 5 – Output each object from the input array into the sorted output array followed by decreasing its count by 1.
Step 6 – Print the sorted output array.
*/




/*



void counting_sort(vector<int>&v){
    int n = v.size();
    int mx = *max_element(v.begin() , v.end());
    vector<int>count(mx+1 , 0);
    for(int i = 0 ; i<n ; i++){
        count[v[i]]++;
    }
    for(int i = 1 ; i<=mx ; i++){
        count[i]+=count[i-1];
    }
    vector<int>temp(n , 0);
    for(int i = 0 ; i<n ; i++){
        temp[--count[v[i]]]=v[i];
    }
    for(int i = 0 ; i<n ; i++){
        v[i]=temp[i];
    }
}




*/