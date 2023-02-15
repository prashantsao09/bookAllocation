#include<iostream>
using namespace std;

int BookAllo(int arr[] , int size , int students )
{
    int start =0 ; int ans=0;
    int sum =0 ;
    for (int i=0 ; i<size; i++)
    {
        sum+=arr[i];
    } 
    int end =sum;
    int mid = start=(end-start)/2;

    while(start<=end)
    {
        if ( isPossible(arr,size,students,mid) )
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }

        int mid = start=(end-start)/2;
    }
    return ans;
}

bool isPossible(int arr[] , int size , int students, int mid)
{
    int studentCount=0;
    int pageSum=0;

    for (int i=0; i<size ;i++)
    {
        if (pageSum + arr[i]<=mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;

            if(studentCount>students || arr[i] > mid) return false;
        }
        pageSum = arr[i];
    }
    return true;
}


int main()
{
    int arr[4] ={12,34,67,90};
    int size = 4;
    int students = 2;

    cout<<BookAllo(arr,size,students)<<endl;
    return 0;
}