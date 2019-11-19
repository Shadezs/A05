//
// Created by shadesz on 11/19/19.
//

#ifndef A05_VECTOR_H
#define A05_VECTOR_H


class Vector {
    int size = 0;
    int capacity = 0;
    int * data = nullptr ;
public:
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

};


#endif //A05_VECTOR_H
