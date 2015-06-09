#pragma once

// Internal
#include "storage.h"

// C
#include <cstddef>

// C++
#include <memory>
#include <vector>

namespace dolan
{
    template< class T >
    class Tensor
    {
    public:
        Tensor( size_t s1, size_t s2, size_t s3, size_t s4 )
            :Tensor(std::vector<size_t>({s1, s2, s3, s4}))
        {}

        Tensor( size_t s1, size_t s2, size_t s3 )
            :Tensor<T>(std::vector<size_t>({s1, s2, s3}))
        {}

        Tensor( size_t s1, size_t s2 )
            :Tensor(std::vector<size_t>({s1, s2}))
        {}

        Tensor( size_t s1 )
            :Tensor(std::vector<size_t>({s1}))
        {}

        Tensor(std::vector<size_t> sizes)
            :_sizes(sizes), _dims(sizes.size()), _storageOffset(0)
        {
            init();
        }

        Tensor( std::vector<size_t> sizes, std::shared_ptr<dolan::Storage<T> > storage, size_t offset )
            :_sizes(sizes), _storage(storage), _storageOffset(offset)
        {
            init(false);
        }

        virtual ~Tensor()
        {
            _storage.reset();
        }

        Tensor<T> operator [] (size_t idx)
        {
            if( _sizes.size() > 1 )
            {
                std::vector< size_t > redSizes = _sizes;
                redSizes.erase( redSizes.begin() );
                size_t dimOffset = _sizes[1];
                for( size_t k = 2; k < _sizes.size(); ++k )
                {
                    dimOffset *= _sizes[k];
                }
                dimOffset *= idx;
                return Tensor<T>( redSizes, _storage, _storageOffset + dimOffset );
            }
            else
            {
                Tensor<T> sclr(1);
                return Tensor<T>( std::vector<size_t>({1}), _storage, _storageOffset + idx );
            }
        }

        T toScalar()
        {
            return (_storage.get())->operator []( _storageOffset );
        }

        Tensor<T>( const Tensor<T>& other )
        {
            _dims = other._dims;
            _sizes = other._sizes;
            _storage = other._storage;
            _storageOffset = other._storageOffset;
            init(false);
        }

        size_t sotrageOffset()
        {
            return _storageOffset;
        }

        std::vector<size_t> sizes()
        {
            return _sizes;
        }

    private:
        size_t                  _dims;
        std::vector< size_t >   _sizes;
        size_t                  _totalExtent;

        std::shared_ptr<dolan::Storage<T> > _storage;
        size_t                              _storageOffset;

        void init(bool initStorage=true)
        {
            if(initStorage)
                _storage = std::shared_ptr<dolan::Storage<T> >( new dolan::Storage<T>(_totalExtent) );

            size_t totalExtent = 0;
            if( _sizes.size() )
                totalExtent = _sizes[0];

            for( size_t k = 1; k < _sizes.size(); ++k )
            {
                totalExtent *= _sizes[k];
            }
            _totalExtent = totalExtent;
        }

    protected:

    };
}
