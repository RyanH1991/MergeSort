#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct tripleVector {
  int year;
  string firstname;
  string lastname;
};

/*struct tripleVector* newTripleVector(){
    struct tripleVector* tripleVector = (struct tripleVector*)malloc(sizeof(struct tripleVector))
}*/

tripleVector make_tripleVector(int year, string first, string last){
    tripleVector cum = {year,first,last};
    return cum;
}
  
void print(vector<tripleVector> *penis) 
{ 
    /*for (int i=0;i<year.size();i++){
        cout << *(firstname.begin()+i) << " " << *(lastname.begin()+i) << " " << *(year.begin()+i) << endl;
    }*/
    for (int i=0;i<penis->size();i++){
        cout << (*penis)[i].firstname << " " << (*penis)[i].lastname << " " << (*penis)[i].year << endl;
    }
    cout << endl;
} 

void merge(vector<tripleVector> *penis, int low, int mid, int high){
    int leftVecSize = mid-low + 1;
    int rightVecSize = high - mid;

    vector<tripleVector> leftVec;
    vector<tripleVector> rightVec;

    for (int i = 0; i < leftVecSize; i++){
        leftVec.push_back((*penis)[low + i]);
    }

    for (int i = 0; i < rightVecSize; i++){
        rightVec.push_back((*penis)[mid + 1 + i]);
    }

    int leftVecIndex = 0;
    int rightVecIndex = 0;
    int mergedVecIndex = low;

    while (leftVecIndex < leftVecSize && rightVecIndex < rightVecSize){
        //add to here!
        if (leftVec[leftVecIndex].year < rightVec[rightVecIndex].year){
            (*penis)[mergedVecIndex] = leftVec[leftVecIndex];
            mergedVecIndex++;
            leftVecIndex++;
        }
        else if (leftVec[leftVecIndex].year == rightVec[rightVecIndex].year){
            if (leftVec[leftVecIndex].firstname.compare(rightVec[rightVecIndex].firstname) < 0){
                (*penis)[mergedVecIndex] = leftVec[leftVecIndex];
                mergedVecIndex++;
                leftVecIndex++;
            }
            else if(leftVec[leftVecIndex].firstname.compare(rightVec[rightVecIndex].firstname) == 0){
                if(leftVec[leftVecIndex].lastname.compare(rightVec[rightVecIndex].lastname) < 0){
                    (*penis)[mergedVecIndex] = leftVec[leftVecIndex];
                    mergedVecIndex++;
                    leftVecIndex++;
                }
            }
            else{
                (*penis)[mergedVecIndex] = rightVec[rightVecIndex];
                mergedVecIndex++;
                rightVecIndex++;
            }
        }
        else {
            (*penis)[mergedVecIndex] = rightVec[rightVecIndex];
            mergedVecIndex++;
            rightVecIndex++;
        }
    }

    while (leftVecIndex < leftVecSize){
        (*penis)[mergedVecIndex] = leftVec[leftVecIndex];
        mergedVecIndex++;
        leftVecIndex++;
    }
    while (rightVecIndex < rightVecSize){
        (*penis)[mergedVecIndex] = rightVec[rightVecIndex];
        mergedVecIndex++;
        rightVecIndex++;
    }
    print(penis);
}

void mergeSort(vector<tripleVector> *penis, int low, int high){
    if (high <= low){
        return;
    } 

    int midpoint = low + (high - low) / 2;

    mergeSort(penis, low, midpoint);
    mergeSort(penis, midpoint + 1, high);
    merge(penis, low, midpoint, high);
}


int main() {
    /*vector<int> year = {1,3,5,7,9,2,4,6,8,};  
    vector<string> firstname = {"mingming","emma", "c", "d", "e", "f", "g", "h", "i"};
    vector<string> lastname = {"feng","ziegellaub-eichler", "C","D","E","F","G","H","I"};*/
    vector<tripleVector> cream;
    vector<tripleVector> *penis = &cream;
    penis->push_back(make_tripleVector(2014,"mingming","feng"));
    penis->push_back(make_tripleVector(2014,"emma","ziegellaub-eichler"));
    penis->push_back(make_tripleVector(2014,"john","yu"));

    mergeSort(penis, 0, penis->size()-1);
    //print(penis);
    return 0;
}
