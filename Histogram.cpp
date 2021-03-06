#include <iostream>  
#include<string.h>  
using namespace std;


class Histogram
{
    public:
    int num_bins ;
    float *ptr ;
    Histogram(int n, float *p)
    {
        num_bins=n ;
        ptr = p ; // ptr points to the starting of array 
    }

void bin_values(float min,float max,int bin_size,int size,float array[],string output )
{
    float diff = max-min ;
    diff =diff/10.0 ;
    float bin_array[bin_size+1] ;
    bin_array[0]=min ;
    for(int i = 1 ; i<=bin_size ; i++) 
    {
        min = diff+min ;
        bin_array[i]=min ; 
        output=output+std::to_string(min)+"," ;
    } 

    output = output+" "+"-1"+" " ;
    int freq[bin_size+1] ;
    //set all to 0 in the start

    for(int i = 0 ; i<bin_size+1;i++)
    {
        freq[i]=0 ;
    }
    int j = 0 ;
    for(int i =0 ;i<size ; i++)
    {
       float a=*(ptr+i);
       int index = 0 ;

       for(int k = 0 ; k<=bin_size+1 ; k++)
       {
           float b = bin_array[k] ;
            if(a==b)
            {
                freq[index]=freq[index]+1 ;
                break ;
            }

            if(a>b)
            {
                index=index+1 ;
            }

            if(a<b)
            {
                index=index-1 ;
                freq[index]=freq[index]+1;
                break ;
            }

       }
    }
      
    for(int i =0 ; i<10;i++)
    {
        output=output+std::to_string(freq[i])+"," ;
    }

    output=output +" "+"-1" ;

    std::cout << output << endl ;
}


};