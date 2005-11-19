// (C) Copyright 2005 Matthias Troyer 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef BOOST_SERIALIZATION_DETAIL_GET_DATA_HPP
#define BOOST_SERIALIZATION_DETAIL_GET_DATA_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#define STD _STLP_STD
#else
#define STD std
#endif


#include <vector>
#include <valarray>

namespace boost { namespace serialization { namespace detail {

template <class T, class Allocator>
T* get_data(STD::vector<T,Allocator>& v)
{
  return &(v[0]);
}


template <class T>
T* get_data(STD::valarray<T>& v)
{
  return &(v[0]);
}

template <class T, class Allocator>
const T* get_data(T const& v)
{
  return get_data(const_cast<T&>(v));
}

} } } //namespace boost::serialization::detail

#endif // BOOST_SERIALIZATION_DETAIL_GET_DATA_HPP