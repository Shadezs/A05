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
void printardata(const Vector& k);
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
    construct_vector(a,25);
    std::cout <<"size of vector: "<<size(a)<<"\n";
    std::cout <<"capacity of the vector is: "<<capacity(a)<<"\n";
    printardata(a);
    std::cout<<"filling in the vector ";
    for (int i = 0; i <size(a) ; i++) {
        at(a,i)=i*3;
    }
    printardata(a);
    std::cout<<"\nreseving new capacity";
    reserve(a,35);
    std::cout<<"the Capacity of a is: "<<capacity(a);
    at(a,24)=152;
    at(a,15)=1001;
    at(a,19)=144;
    at(a,34)=125;
    at(a,5)=230;
    at(a,9)=1451;
    printardata(a);
    resize(a,50,26);
    std::cout<<"resizeing the vector ";
    std::cout<<"new vector \n";
    printardata(a);
    std::cout<<"The the size of the vector is: "<<size(a);
    std::cout<<"The capacity is "<<capacity(a);
    destroy_vector(a);
    std::cout<<"\ndestrying vector a";
    construct_vector(b,25);
    std::cout<<"\ncreating new vector b";
    printardata(b);
    std::cout<<"\nsetting data at vector b ";
    at(b,24)=15;
    at(b,15)=100;
    at(b,19)=145;
    printardata(b);
    construct_vector(c,10);
    at(c ,1)=152;
    std::cout<<"\ncreating new vector b";
    printardata(b);
    clear(b);
    if (empty(b))
    {
        std::cout<<"\nThe arr is empty";
    }else{
        std::cout<<"\nNot empty dude";
    }
    printardata(b);




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
void destroy_vector ( Vector & v )
{
    v.size=0;
    v.capacity=0;
    delete[](v.data);
}

void clear ( Vector & v )
{
    v.size=0;
    delete[](v.data);
    v.data= nullptr;

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
    tempdata=new int [oldcap];
    for (int i = 0; i < oldcap; i++) {/// this loop copies the date into the temp vector hold
        tempdata[i]=v.data[i];
    }
    clear(v);
    v.data= new int[new_capacity];
    for(int i=0;i<oldcap;i++)
    {
        v.data[i]=tempdata[i];
    }


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
    v.capacity=newsize;
    v.data=new int[newsize];
    for (int j = 0; j <sizev ; j++) { /// this loop fill the vector with the old datda
        v.data[j]=tempdata[j];
    }
    for (int k = 0; k <sizediff ; k++) {  /// this loop fill the vector with the new value
        c+=k;
        v.data[c]=0;
    }


}

