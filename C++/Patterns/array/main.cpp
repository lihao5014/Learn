#include "array.h"

int main()
{
	Array<int> arr(10);
	arr.display();
	arr.fill(5);
	cout<<arr<<endl;
	cout<<"arr[5] ="<<arr[5]<<endl;
	arr[5] = 7;
	cout<<arr<<endl;
	cout<<"arr.at(7) = "<<arr.at(7)<<endl;
	arr.at(7) = 9;
	arr.display();
	
	arr.reSize(8);
	arr.display();

	{
		Array<int> arr1(arr);
		arr1.display();
	}
	
	try{
		cout<<"arr[8] ="<<arr[8]<<endl;
	}catch(length_error &e){
		cout<<" exception: "<<e.what()<<endl;
	}
	
	return 0;
}