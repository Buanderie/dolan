#pragma once

// C
#include <cstddef>

// STL
#include <vector>

namespace dolan
{
    template< class T >
    class Tensor
    {
    public:
        Tensor( size_t s1, size_t s2, size_t s3, size_t s4 )
            :Tensor({s1, s2, s3, s4})
        {}

        Tensor( size_t s1, size_t s2, size_t s3 )
            :Tensor({s1, s2, s3})
        {}

        Tensor( size_t s1, size_t s2 )
            :Tensor({s1, s2})
        {}

        Tensor( size_t s1 )
            :Tensor({s1})
        {}

        Tensor(std::vector<size_t> sizes)
        {
            _dims = sizes.size();
            size_t totalExtent = 0;

            if( sizes.size() )
                totalExtent = sizes[0];

            for( size_t k = 1; k < sizes.size(); ++k )
            {
                totalExtent *= sizes[k];
            }
        }

    private:
        size_t _dims;

    protected:

    };
}
