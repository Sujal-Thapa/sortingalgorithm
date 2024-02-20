#include<iostream>
#include<random>
using namespace std;
int main(){
    random_device rd;
    uniform_int_distribution d(1,99);
    vector <int> v;
    //pushing random value in vector v
    for(int i=0;i<100 ; i++){
        v.push_back(d(rd));
    }

    cout<<"before sorting the arrary"<<endl;

    for(int i=0; i<v.size();i++){
        cout<< v[i]<<"   ";
    }

    //sorting algorithm
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++)
        { 
            if(v[i]>v[j]){
                swap(v[i],v[j]);
            }
        }

    }
   

    cout<<endl<<"after sorting the array"<<endl;

      for(int i=0; i<v.size();i++){
        cout<< v[i]<<"   ";
    }


}