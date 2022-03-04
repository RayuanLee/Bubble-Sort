//
//  main.cpp
//  CIS Assignment #6 (bubble sort)
//
//  Created by rayuan lee on 2/22/17.
//  Copyright © 2017 rayuan lee. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include<ctime>

using namespace std;

//we name the class here. In this class we will keep the functions of each piece to solve this problem.
class ArrayPlace
{
public:
    // Here i have created a memory location for 3 different types of data. Now we have places to store a value for the array, for place and for the input.
    int array[1000];
    int place = -1;
    int input;
    
    
    //There is a method where we create a variable to hold the function to address a random number.
    void RandomNumber()
    {
        //This code alone makes the array more random. So that if we search th same number twice the position will not be the same.
        srand (time(NULL));
        
        for(int i=0;i<1000;i++){
            array[i] = (rand()%1000)+1;
        }
    }
    //We make the user input a word.
    void NumberEntry()
    {
        cout<< "Enter a number to search from 1-1000: "<<endl;
        cin >> input;
    }
    
    //Here is our binary search.
    void BinarySearch()
    {
        // we create a new set of memory to store some data.
        int low=0;
        int high = 999;
        int mid;
        
        //we say that while the low value can not be biger than r. We make a variable to hold a math equation between low and r.
        while (low <= high){

            int mid = low + (high-low)/2;
                
            if (array[mid] == input) {place= mid;  break;}
            
            if (array[mid] < input) low = mid + 1;
            
            else high = mid - 1;
        }
        if (place == -1){
            cout<< "Number "<<input<< " does not exist in the array."<<endl;
            
        }
        else
            cout<< "Number "<<input<< " does exist in the array at pos "<< place << endl;
            };
    
    //In this sort we make, a new value and see if it is bigger or smaller than the number then move the value into a new space of memory.
    void BubbleSort()
    {
        for (int i=0; i<1000; i++)
        {
            for (int j=0; j<999; j++)
            {
                if (array[j]>array[j+1])
                {
                    int temp = array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
    }
};

int main()
{
    clock_t start = clock();
    
    ArrayPlace ai;
    ai.RandomNumber();
    cout<<endl;
    
    ai.BubbleSort();
    cout<<endl;
    
    ai.NumberEntry();
    cout<< endl;
    
    ai.BinarySearch();
    cout<<endl;
    
    clock_t end = clock();
    clock_t duration = (end - start);
    cout << "Elapsed Time: "<<duration <<" seconds" <<endl;
    
    
    return 0;
}
