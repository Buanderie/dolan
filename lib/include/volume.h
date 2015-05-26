#pragma once

// Internal
#include "dolan_exceptions.h"

// C
#include <cstddef>

// STL
#include <iostream>

namespace dolan
{
    template <typename T>
    class Volume
    {
    public:

        Volume( std::size_t width, std::size_t height, std::size_t depth )
            :_width(width), _height(height), _depth(depth)
        {
            _totalExtent = _width * _height * _depth;

            if( _totalExtent == (T)0 )
            {
                throw dolan::VolumeException("Cannot create a volume of total size 0");
            }
            else
            {
                _rawData = new T[ _totalExtent ];
            }
        }

        virtual ~Volume(){}

    private:

        std::size_t _totalExtent;
        T*          _rawData;
        size_t      _width;
        size_t      _height;
        size_t      _depth;

    protected:

    };

    typedef Volume<float> Volumef;
}
