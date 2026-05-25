#pragma once

#include <iostream>
#include <utility>

namespace EXP6
{

    template <typename T>
    class vec1
    {
    };

    template <typename T>
    class vec2
    {
    private:
        T *data_{};
        size_t size_{};
        size_t limit_{};

    public:
        vec2(size_t size = 6) : size_{}, limit_{size} { data_ = new T[size]; }

        ~vec2()
        {
            if (data_)
            {
                delete[] data_;
                data_ = nullptr;
            }
        }
    };

    extern int fLogMemory;       // Perform logging (0=no; nonzero=yes)?
    extern int cBlocksAllocated; // Count of blocks allocated.

    template <typename T>
    class vec3
    {
    private:
        T *data_{};
        size_t size_{};
        size_t limit_{};
        unsigned int id_{};

    public:
        static inline unsigned int seq_ = 0;

        unsigned int &id() { return id_; }

        // # TODO0 const version of id()

    public:
        vec3(size_t size = 6) : size_{}, limit_{size}
        {
            data_ = new T[size];
            // other initialization
        }

        // TODO1 copy constructor of vec3
        vec3(const vec3 & other):size_{other.size_},limit_(other.limit_){
            data_=new T[other.data_.size];
            std::memcpy(other,data_,other.data_.size);
        }
        // TODO2 copy assign for vec3, garding case of a=a
        void friend swap(vec3 A,vec3 B){
            std::swap(A.id_,B.id_);
            std::swap(A.size_,B.size_);
            std::swap(A.limit_,B.limit_);
            std::swap(A.data_,B.data_);
        }
        vec3 & operator=(const vec3 & other){
            vec3 tem(other);
            swap(tem,*this);
            return *this;
        }
        // TODO3 move construct for vec3
        vec3(vec3 &&other)noexcept
        :id_(other.id_),size_(other.size_),limit_(other.limit_),data_(other.data_)
        {
            other.data_=nullptr;
        }
        // TODO4 move assign for vec3, garding case of a=std::move(a)
        vec3 & operator=(vec3 && other)noexcept{
            if (&other==this){
                return *this;
            }
            this->id_=other.id_;
            this->data_=other.id_;
            this->limit_=other.limit_;
            this->size_=other.size_;
            other.data_=nullptr;
        } 
        // TODO5 destructor of vec3
        ~vec3(){
            if (data_){
                delete[] data_;
            }
        }
        // User-defined operator new & delete
        void *operator new(size_t stAllocateBlock)
        {
            static int fInOpNew = 0; // Guard flag

            if (fLogMemory && !fInOpNew)
            {
                fInOpNew = 1;
                std::clog << "Memory block " << ++cBlocksAllocated << " malloc "
                          << stAllocateBlock << "\n";
                fInOpNew = 0;
            }
            return malloc(stAllocateBlock);
        }

        void operator delete(void *pvMem)
        {
            static int fInOpDelete = 0; // Guard flag
            if (fLogMemory && !fInOpDelete)
            {
                fInOpDelete = 1;
                std::clog << "Memory block " << cBlocksAllocated-- << " free  \n";
                fInOpDelete = 0;
            }

            free(pvMem);
        }
        const vec3 & operator==(vec3 &other){
            if (id_==other.id_){
                return 1;
            }
            return 0;
        }
    };

    // TODO6 add operator==, using id() for comparing
    
} // namespace EXP6
