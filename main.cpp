#include <iostream>
#include <string>
#include <cstring>
#include <random>
struct Vector {
    int size = 0;
    int capacity = 0;
    int * data = nullptr ;
};
// Construct a Vector v with a default size 0.
void construct_vector ( Vector & v , int size1 = 0 , int initVal = 0) ;
// Destroy Vector v and return memory to the freestore ( heap ).
void destroy_vector ( Vector & v );
// ( optional ) Helper function to copy v.
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


int main()
{
    Vector a,b,c;
    construct_vector(a,15,56);
    std::cout <<"size of vector: "<<size(a)<<"\n";
    for (int i = 0; i < size(a); ++i) {
        std::cout << "data is: " << *(data(a) + i) << " ";
    }
    char y;
    std::cin>> y;
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
