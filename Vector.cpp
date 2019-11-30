//
// Created by shadesz on 11/19/19.
//

#include "Vector.h"
#include <string>
#include <iostream>

namespace cs52
{
    class Vector
    {
    public: Vector():_size(0),_capacity(0){}; //default constructor
        Vector(int sz, int init_val)
        {
            construct_vector(sz, init_val);
        } //overloaded constructor
        Vector( const Vector& other )
        {
            this->_size = other._size;
            this->_capacity = other._capacity;
            this->_data = other._data;
        } //copy constructor
        ~Vector(); //Destructor
        void construct_vector( int size1=0,int initVal) {
            _size = size1;
            _capacity = size1;
            _data = new int[size1];
            for (auto i = 0; i < size1; ++i)
            {
                _data[i] = initVal;
            }

        }

        int size()
        {
            const auto temp = _size;
            return temp;

        }
        int* data()
        {
            int* ptrdata = &_data[0];
            return ptrdata;

        }



        void push_back( int element)
        {
            int* tempdata;
            tempdata = new int[size() + 1];
            for (auto i = 0; i < size(); i++)
            {
                tempdata[i] = _data[i];
            }
            tempdata[size() + 1] = element;
            _size = _size + 1;
            _capacity = _capacity + 1;
            delete[](_data);
            _data = tempdata;
            tempdata = nullptr;


        }
        void destroy_vector()
        {
            _size = 0;
            _capacity = 0;
            delete[](_data);
        }

        void clear()
        {
            _size = 0;


        }

        int capacity()
        {
            return _capacity;

        }
        void reserve(int new_capacity)
        {

            const int oldcap = capacity();
            _capacity = new_capacity;
            int* tempdata;
            tempdata = new int[new_capacity];
            for (auto i = 0; i < oldcap; i++) {/// this loop copies the date into the temp vector hold
                tempdata[i] = _data[i];
            }
            _data = nullptr;
            _data = reinterpret_cast<int*>(&tempdata);
            tempdata = nullptr;


        }
        int& at(int i) noexcept(false)
        {
            if (i < size()) {
                int& temp = _data[i];
                return temp;
            }
        }
        bool empty()
        {
            bool t = false;
            if (data() == nullptr)
            {
                t = true;
            }
            return t;
        }
        void printardata()
        {
            std::cout << "\ndata is: ";
            for (int i = 0; i < size(); ++i) {
                std::cout << *(data() + i) << " ";
            }

        }
        int& front()
        {

            if (empty())
            {
                int& t = _data[0];
                return t;
            } else
                {
                std::cout<<"ree";
            }
        }
        void pop_back()
        {


        }
        int& back( )
        {
            int& temp = _data[size()];
            return temp;
        }
        void resize( int newsize, int val)
        {

            const int sizev = size();
            int sizediff = sizev - newsize;
            int c = size();
            int* tempdata = new int[sizev];
            for (int i = 0; i < sizev; i++) {/// this loop copies the date into the temp vector hold
                tempdata[i] = _data[i];
            }
            _data = nullptr;
            _size = newsize;
            _data = tempdata;
            for (int k = 0; k < sizediff; k++) {  /// this loop fill the vector with the new value
                c += k;
                _data[c] = 0;
            }
            tempdata = nullptr;


        }
        void menudisplay()
        {

            std::cout << "pick a num 1,Create vectore , 2 write to vector ,3 resize vector , 4 reserve vector space ,5 display info ,6 destroy vector  \n";

        }
        void infomenu_display()
        {
            std::cout << "\nThe capacity is :" << capacity();
            printardata();
        }
        void displayWrite( int location, int user_input)
        {
            at(location) = user_input;
        }
//Overloaded operators
        int& operator[] (int i)
        {
            return  at(i);

        }// [] array syntax
        Vector& operator=(const Vector& other)
        {
            this->_size =other._size;
            this->_capacity = other._capacity;
            this->_data =other._data;
            return *this;

        }// copy assignment
//Overloaded stream insertion operator
    private:
        int _size = 0;
        int _capacity = 0;
        int* _data = nullptr;


    };







}
