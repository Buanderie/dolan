#pragma once

// STL
#include <string>
#include <exception>

namespace dolan
{
    class VolumeException : public std::exception
    {
    public:
        VolumeException( const std::string& msg="")
            :_msg(msg)
        {

        }

        virtual ~VolumeException() throw ()
        {

        }

        virtual const char* what() const throw()
        {
            return _msg.c_str();
        }

    private:
        std::string _msg;

    protected:

    };
}
