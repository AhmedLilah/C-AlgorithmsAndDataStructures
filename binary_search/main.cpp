#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"please enter the number of emplyee";
    cin>>num;

   int arr[num];
   for(int i=0;i<num;i++){
       cin>>arr[i];
   }
   int search;
   cout<<"please enter your search= ";
   cin>>search;
bool flag=false;
int index;
int first=0;
int last=num-1;
int midel= (first+last)/2;
while (!flag){
if(search==arr[midel]){
    flag=true;
    index=midel;
    break;
}else if (search>arr[midel]){
    first= midel+1;
    midel= (first+last)/2;
    continue;
}else if(search<midel){
    last=midel-1;
    midel= (first+last)/2;
    continue;
}else if(first>last){
    break;
}
}
if(flag){
    cout<<"i found and index = "<<index;
}

    return 0;
}

