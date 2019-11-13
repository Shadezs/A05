#include <iostream>
#include <string>
#include <cstring>
#include <random>
struct Vector {
    int size = 0;
    int capacity = 0;
    int * data = nullptr ;
};
//prints data to user
void menudisplay();
void printardata(const Vector& k);
// Construct a Vector v with a default size 0.
void construct_vector ( Vector & v , int size1 = 0 , int initVal = 0) ;
// Destroy Vector v and return memory to the freestore ( heap ).
void destroy_vector ( Vector & v );
// ( optional ) Helper function to copy v.
// set the data poiter to new array 
void copy_data ( Vector & v );

// Returns pointer to the first element in Vector v.
int * data ( const Vector & v );
// Returns the number of elements in Vector v.
int size ( const Vector & v );
// Returns a reference to the element at location i in Vector v.
// ( optional ) Throws exception if out of bounds
int & at ( Vector & v , int i ) noexcept(false);
// Returns a reference to the last element in Vector v.
// ( optional ) Throws exception if Vector is empty
int & back ( const Vector & v ) noexcept(false);
// Returns the allocated storage for Vector v.
int capacity ( const Vector & v );
// Erases the elements of Vector v but does not change capacity .
void clear ( Vector & v );
// If Vector v is empty return true , else false .
bool empty ( const Vector & v );
// Returns a reference to the first element in the Vector .
// ( optional ) Throws exception if Vector is empty .
int & front ( const Vector & v ) noexcept(false);
// Deletes the last element of Vector v.
void pop_back ( Vector & v );
// Add element to the end of the Vector v.
void push_back ( Vector & v , int element );
// Resize Vector v. For details see provided links
void resize ( Vector & v , int newsize , int val );
// Increase capacity of Vector v. For details see provided links
void reserve ( Vector &v , int new_capacity );

void menudisplay();
void infomenu_display(Vector v);
void displayWrite(Vector a,int location,int user_input);

int main()
{
    int use1=0;
    int loc=0;
    int val=0;
    int user_input=0;
    Vector a,b,c;
    menudisplay();
    std::cin>>user_input;
while (user_input!=7) {
    switch (user_input) {
        case 0:
        case 1:
        case 2:

            std::cout << "What vector ,1A ,2B,3C";
            std::cin >> use1;
            std::cout << "\nwhat location: ";
            std::cin >> loc;
            std::cout << "\nAnd Value ";
            std::cin >> val;
            if (use1 == 1) {
                at(a, loc) = val;
            }
            if (use1 == 2) {
                at(b, loc) = val;
            }
            if (use1 == 3) {
                at(c, loc) = val;
            }
            break;
        case 3:
        case 4:
        case 5:
            std::cout << "What vector ";
            infomenu_display(a);
            break;
    }
    menudisplay();
    std::cin>>user_input;
}
    char y;


    return 0;
}

int size ( const Vector & v )
{
    return v.size;

}
int * data ( const Vector & v )
{
    int * ptrdata=&v.data[0];
    return ptrdata;

}

void construct_vector(Vector &v, int size1, int initVal) {
    v.size=size1;
    v.capacity=size1;
    v.data= new int[size1];
    for (int i = 0; i <size1 ; ++i)
    {
        v.data[i]=initVal;
    }

}
void push_back ( Vector & v , int element )
{

}
void destroy_vector ( Vector & v )
{
    v.size=0;
    v.capacity=0;
    delete[](v.data);
}

void clear ( Vector & v )
{
    v.size=0;
 

}

int capacity ( const Vector & v )
{
    return v.capacity;

}
void reserve ( Vector &v , int new_capacity )
{

  const int oldcap=capacity(v);
    v.capacity=new_capacity;
    int *tempdata;
    tempdata=new int [new_capacity];
    for (int i = 0; i < oldcap; i++) {/// this loop copies the date into the temp vector hold
        tempdata[i]=v.data[i];
    }
    v.data=nullptr;
    v.data=&tempdata;
    tempdata=nullptr;


}
int & at ( Vector & v , int i ) noexcept(false)
{
    if(i<size(v)) {
        int &temp = v.data[i];
        return temp;
    }
}
bool empty ( const Vector & v )
{
    bool t =false;
    if(data(v)== nullptr)
    {
        t=true;
    }
    return t;
}
void printardata(const Vector& k)
{
    std::cout << "\ndata is: ";
    for (int i = 0; i < size(k); ++i) {
        std::cout << *(data(k) + i) << " ";
    }

}
int & front ( const Vector & v )
{

    if(empty(v))
    {int&t =v.data[0];
        return t;
    }

}
void pop_back ( Vector & v )
{


}
int & back ( const Vector & v )
{
    int&temp =v.data[-1];
    return temp;
}
void resize ( Vector & v , int newsize , int val )
{

    const int sizev =size(v);
    int sizediff=sizev-newsize;
    int c=size(v);
    int *tempdata=new int[sizev];
    for (int i = 0; i < sizev; i++) {/// this loop copies the date into the temp vector hold
        tempdata[i]=v.data[i];
    }
    clear(v);
    v.size=newsize;
    v.data=&tempdata;
    for (int k = 0; k <sizediff ; k++) {  /// this loop fill the vector with the new value
        c+=k;
        v.data[c]=0;
    }
    tempdata=nullprt;


}
void menudisplay()
{

    std::cout<<"pick a num 1,Create vectore , 2 write to vector ,3 resize vector , 4 reserve vector space ,5 display info ,6 destroy vector  \n";

}
void infomenu_display(Vector v)
{
    std::cout<<"The size is : "<<size(v);
    std::cout<<"\nThe capacity is :"<<capacity(v);
    printardata(v);
}
void displayWrite(Vector a,int location,int user_input)
{
    at(a,location)=user_input;
}
