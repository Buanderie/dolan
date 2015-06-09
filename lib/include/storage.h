#pragma once

#include <cstddef>

namespace dolan
{
    template< class T >
    class Storage
    {
    public:
        Storage( size_t size )
            :_size(size)
        {
            init();
        }

        virtual ~Storage()
        {
            destroy();
        }

        T& operator [] (const int idx)
        {
            // TODO: boundary check ?
            return _data[ idx ];
        }

    private:
        size_t _size;
        T* _data;

        void init()
        {
            _data = new T[ _size ];
        }

        void destroy()
        {
            delete[] _data;
        }

    protected:

    };
}
