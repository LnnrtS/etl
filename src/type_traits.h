///\file

/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
http://www.etlcpp.com

Copyright(c) 2014 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef __ETL_TYPE_TRAITS__
#define __ETL_TYPE_TRAITS__

#include <stddef.h>

#include "platform.h"
#include "nullptr.h"

#if defined(ETL_C11_TYPE_TRAITS_SUPPORTED)
  #include <type_traits>
#endif

///\defgroup type_traits type_traits
/// A set of type traits definitions for compilers that do not support the standard header.
/// \ingroup utilities

namespace etl
{
  /// integral_constant
  ///\ingroup type_traits
  template <typename T, const T VALUE>
  struct integral_constant
  {
    static const T value = VALUE;

    typedef T value_type;
    typedef integral_constant<T, VALUE> type;

    operator value_type() const
    {
       return value;
    }
  };

  /// integral_constant specialisations
  ///\ingroup type_traits
  typedef integral_constant<bool, false> false_type;
  typedef integral_constant<bool, true>  true_type;

  /// remove_reference
  ///\ingroup type_traits
  template <typename T> struct remove_reference { typedef T type; };
  template <typename T> struct remove_reference<T&> { typedef T type; };

  /// add_reference
  ///\ingroup type_traits
  template <typename T> struct add_reference { typedef T& type; };
  template <typename T> struct add_reference<T&> { typedef T& type; };

  /// remove_pointer
  ///\ingroup type_traits
  template <typename T> struct remove_pointer { typedef T type; };
  template <typename T> struct remove_pointer<T*> { typedef T type; };

  /// add_pointer
  ///\ingroup type_traits
  template <typename T> struct add_pointer { typedef typename remove_reference<T>::type* type; };

  /// is_const
  ///\ingroup type_traits
  template <typename T> struct is_const : false_type {};
  template <typename T> struct is_const<const T> : true_type {};
  template <typename T> struct is_const<const volatile T> : true_type {};

  /// remove_const
  ///\ingroup type_traits
  template <typename T> struct remove_const { typedef T type; };
  template <typename T> struct remove_const<const T> { typedef T type; };

  /// add_const
  ///\ingroup type_traits
  template <typename T> struct add_const { typedef const T type; };
  template <typename T> struct add_const<const T> { typedef const T type; };

  /// is_volatile
  ///\ingroup type_traits
  template <typename T> struct is_volatile : false_type {};
  template <typename T> struct is_volatile<volatile T> : true_type {};
  template <typename T> struct is_volatile<const volatile T> : true_type {};

  /// remove_volatile
  ///\ingroup type_traits
  template <typename T> struct remove_volatile { typedef T type; };
  template <typename T> struct remove_volatile<volatile T> { typedef T type; };

  /// add_volatile
  ///\ingroup type_traits
  template <typename T> struct add_volatile { typedef volatile T type; };
  template <typename T> struct add_volatile<volatile T> { typedef volatile T type; };

  /// remove_cv
  ///\ingroup type_traits
  template <typename T> struct remove_cv
  {
    typedef typename remove_volatile<typename remove_const<T>::type>::type type;
  };

  /// add_cv
  ///\ingroup type_traits
  template <typename T> struct add_cv
  {
    typedef typename add_volatile<typename add_const<T>::type>::type type;
  };

  /// is_integral
  ///\ingroup type_traits
  template <typename T> struct is_integral : false_type {};
  template <> struct is_integral<bool> : true_type {};
  template <> struct is_integral<char> : true_type {};
  template <> struct is_integral<unsigned char> : true_type {};
  template <> struct is_integral<signed char> : true_type {};
  template <> struct is_integral<wchar_t> : true_type {};
  template <> struct is_integral<short> : true_type {};
  template <> struct is_integral<unsigned short> : true_type {};
  template <> struct is_integral<int> : true_type {};
  template <> struct is_integral<unsigned int> : true_type {};
  template <> struct is_integral<long> : true_type {};
  template <> struct is_integral<unsigned long> : true_type {};
  template <> struct is_integral<long long> : true_type {};
  template <> struct is_integral<unsigned long long> : true_type {};
  template <typename T> struct is_integral<const T> : is_integral<T> {};
  template <typename T> struct is_integral<volatile T> : is_integral<T> {};
  template <typename T> struct is_integral<const volatile T> : is_integral<T> {};


  /// is_signed
  ///\ingroup type_traits
  template <typename T> struct is_signed : false_type {};
  template <> struct is_signed<char> : integral_constant<bool, (char(255) < 0)> {};
  template <> struct is_signed<wchar_t> : public etl::integral_constant<bool, static_cast<bool>(wchar_t(-1) < wchar_t(0))> {};
  template <> struct is_signed<signed char> : true_type {};
  template <> struct is_signed<short> : true_type {};
  template <> struct is_signed<int> : true_type {};
  template <> struct is_signed<long> : true_type {};
  template <> struct is_signed<long long> : true_type {};
  template <> struct is_signed<float> : true_type{};
  template <> struct is_signed<double> : true_type{};
  template <> struct is_signed<long double> : true_type{};
  template <typename T> struct is_signed<const T> : is_signed<T> {};
  template <typename T> struct is_signed<volatile T> : is_signed<T> {};
  template <typename T> struct is_signed<const volatile T> : is_signed<T> {};

  /// is_unsigned
  ///\ingroup type_traits
  template <typename T> struct is_unsigned : false_type {};
  template <> struct is_unsigned<bool> : true_type {};
  template <> struct is_unsigned<char> : integral_constant<bool, (char(255) > 0)> {};
  template <> struct is_unsigned<unsigned char> : true_type {};
  template <> struct is_unsigned<wchar_t> : public etl::integral_constant<bool, (wchar_t(-1) > wchar_t(0))> {};
  template <> struct is_unsigned<unsigned short> : true_type {};
  template <> struct is_unsigned<unsigned int> : true_type {};
  template <> struct is_unsigned<unsigned long> : true_type {};
  template <> struct is_unsigned<unsigned long long> : true_type {};
  template <typename T> struct is_unsigned<const T> : is_unsigned<T> {};
  template <typename T> struct is_unsigned<volatile T> : is_unsigned<T> {};
  template <typename T> struct is_unsigned<const volatile T> : is_unsigned<T> {};

  /// is_floating_point
  ///\ingroup type_traits
  template <typename T> struct is_floating_point : false_type {};
  template <> struct is_floating_point<float> : true_type {};
  template <> struct is_floating_point<double> : true_type {};
  template <> struct is_floating_point<long double> : true_type {};
  template <typename T> struct is_floating_point<const T> : is_floating_point<T> {};
  template <typename T> struct is_floating_point<volatile T> : is_floating_point<T> {};
  template <typename T> struct is_floating_point<const volatile T> : is_floating_point<T> {};

  /// is_same
  ///\ingroup type_traits
  template <typename T1, typename T2> struct is_same : public false_type {};
  template <typename T> struct is_same<T, T> : public true_type {};

  /// is_void
  ///\ingroup type_traits
  template<typename T> struct is_void : false_type {};
  template<> struct is_void<void> : true_type {};

  /// is_arithmetic
  ///\ingroup type_traits
  template<typename T> struct is_arithmetic : integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value> {};

  /// is_fundamental
  ///\ingroup type_traits
  template <typename T> struct is_fundamental : integral_constant<bool, is_arithmetic<T>::value ||
                                                                        is_void<T>::value  ||
                                                                        is_same<std::nullptr_t,
                                                                  typename remove_cv<T>::type>::value> {};

  /// is_compound
  ///\ingroup type_traits
  template <typename T> struct is_compound : integral_constant<bool, !is_fundamental<T>::value> {};

  /// is_array
  ///\ingroup type_traits
  template <typename T> struct is_array : false_type {};
  template <typename T> struct is_array<T[]> : true_type {};
  template <typename T, size_t MAXN> struct is_array<T[MAXN]> : true_type {};

  /// is_pointer
  ///\ingroup type_traits
  template <typename T> struct is_pointer : false_type {};
  template <typename T> struct is_pointer<T*> : true_type {};

  /// is_reference
  ///\ingroup type_traits
  template <typename T> struct is_reference : false_type {};
  template <typename T> struct is_reference<T&> : true_type {};

  /// is_pod
  ///\ingroup type_traits

#if defined(ETL_C11_TYPE_TRAITS_SUPPORTED)// && !defined(ETL_IN_UNIT_TEST)
  // For compilers that support C++11
  template <typename T> struct is_pod : std::is_pod<T> {};
#else
  /// For C++03, only fundamental and pointers types are recognised.
  template <typename T> struct is_pod : etl::integral_constant<bool, etl::is_fundamental<T>::value ||
                                                                     etl::is_pointer<T>::value> {};
#endif

#if defined(ETL_C11_TYPE_TRAITS_SUPPORTED) && defined(ETL_C11_TYPE_TRAITS_IS_TRIVIAL_SUPPORTED)// && !defined(ETL_IN_UNIT_TEST)
  /// is_trivially_constructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_constructible : std::is_trivially_constructible<T> {};

  /// is_trivially_copy_constructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_copy_constructible : std::is_trivially_copy_constructible<T> {};

  /// is_trivially_destructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_destructible : std::is_trivially_destructible<T> {};

  /// is_trivially_copy_assignable
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_copy_assignable : std::is_trivially_copy_assignable<T> {};
#else
  /// is_trivially_constructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_constructible : etl::is_pod<T> {};

  /// is_trivially_copy_constructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_copy_constructible : etl::is_pod<T> {};

  /// is_trivially_destructible
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_destructible : etl::is_pod<T> {};

  /// is_trivially_copy_assignable
  /// For C++03, only POD types are recognised.
  ///\ingroup type_traits
  template <typename T> struct is_trivially_copy_assignable : etl::is_pod<T> {};
#endif

  /// conditional
  ///\ingroup type_traits
  template <bool B, typename T, typename F>  struct conditional { typedef T type; };
  template <typename T, typename F> struct conditional<false, T, F> { typedef F type; };

  /// make_signed
  ///\ingroup type_traits
  template <typename T> struct make_signed { typedef  T type; };
  template <> struct make_signed<char> { typedef  signed char type; };
  template <> struct make_signed<unsigned char> { typedef  signed char type; };

  template <> struct make_signed<wchar_t>
  {
    typedef etl::conditional<sizeof(wchar_t) == sizeof(int16_t),
                                    int16_t,
                                    etl::conditional<sizeof(wchar_t) == sizeof(int32_t),
                                                            int32_t,
                                                            void>::type>::type type;
  };

  template <> struct make_signed<unsigned short> { typedef  short type; };
  template <> struct make_signed<unsigned int> { typedef int type; };
  template <> struct make_signed<unsigned long> { typedef  long type; };
  template <> struct make_signed<unsigned long long> { typedef long long type; };
  template <typename T> struct make_signed<const T> : add_const<typename make_signed<T>::type> {};
  template <typename T> struct make_signed<volatile T> : add_volatile<typename make_signed<T>::type> {};
  template <typename T> struct make_signed<const volatile T> : add_const<typename add_volatile<typename make_signed<T>::type>::type> {};

  /// make_unsigned
  ///\ingroup type_traits
  template <typename T> struct make_unsigned { typedef  T type; };
  template <> struct make_unsigned<char> { typedef unsigned char type; };
  template <> struct make_unsigned<signed char> { typedef unsigned char type; };
  template <> struct make_unsigned<short> { typedef unsigned short type; };

  template <> struct make_unsigned<wchar_t>
  {
    typedef etl::conditional<sizeof(wchar_t) == sizeof(uint16_t),
                                    uint16_t,
                                    etl::conditional<sizeof(wchar_t) == sizeof(uint32_t),
                                                     uint32_t,
                                                     void>::type>::type type;
  };

  template <> struct make_unsigned<int> { typedef unsigned int type; };
  template <> struct make_unsigned<long> { typedef unsigned long type; };
  template <> struct make_unsigned<long long> { typedef unsigned long long type; };
  template <typename T> struct make_unsigned<const T> : add_const<typename make_unsigned<T>::type> {};
  template <typename T> struct make_unsigned<volatile T> : add_volatile<typename make_unsigned<T>::type> {};
  template <typename T> struct make_unsigned<const volatile T> : add_const<typename add_volatile<typename make_unsigned<T>::type>::type> {};

  /// enable_if
  ///\ingroup type_traits
  template <bool B, typename T = void> struct enable_if {};
  template <typename T> struct enable_if<true, T> { typedef T type; };

  /// extent
  ///\ingroup type_traits
  template <typename T, size_t MAXN = 0>
  struct extent : integral_constant<size_t, 0> {};

  template <typename T>
  struct extent<T[], 0> : integral_constant<size_t, 0> {};

  template <typename T, size_t MAXN>
  struct extent<T[], MAXN> : integral_constant<size_t, extent<T, MAXN - 1>::value> {};

  template <typename T, size_t MAXN>
  struct extent<T[MAXN], 0> : integral_constant<size_t, MAXN> {};

  template <typename T, size_t I, size_t MAXN>
  struct extent<T[I], MAXN> : integral_constant<size_t, extent<T, MAXN - 1>::value> {};

  /// remove_extent
  ///\ingroup type_traits
  template <typename T> struct remove_extent { typedef T type; };
  template <typename T> struct remove_extent<T[]> { typedef T type; };
  template <typename T, size_t MAXN> struct remove_extent<T[MAXN]> { typedef T type;};

  /// remove_all_extents
  ///\ingroup type_traits
  template <typename T> struct remove_all_extents { typedef T type;};
  template <typename T> struct remove_all_extents<T[]> { typedef typename remove_all_extents<T>::type type; };
  template <typename T, size_t MAXN> struct remove_all_extents<T[MAXN]> { typedef typename remove_all_extents<T>::type type; };

  /// rank
  ///\ingroup type_traits
  template <typename T>struct rank : integral_constant<size_t, 0> {};
  template <typename T> struct rank<T[]> : public integral_constant<size_t, rank<T>::value + 1> {};
  template <typename T, size_t MAXN> struct rank<T[MAXN]> : public integral_constant<size_t, rank<T>::value + 1> {};

  /// decay
  ///\ingroup type_traits
  template <typename T>
  struct decay
  {
    typedef typename etl::remove_reference<T>::type U;
    typedef typename etl::conditional<etl::is_array<U>::value,
                                      typename etl::remove_extent<U>::type*,
                                      typename etl::remove_cv<U>::type>::type type;
  };

  /// Alignment templates.
  /// These require compiler specific intrinsics.
  ///\ingroup type_traits
#if defined(ETL_C11_ALIGNOF_SUPPORTED)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(alignof(T))> {};
#elif defined(ETL_COMPILER_MICROSOFT)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__alignof(T))> {};
#elif defined(ETL_COMPILER_GCC)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__alignof__(T))> {};
#elif defined(ETL_COMPILER_KEIL)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__alignof__(T))> {};
#elif defined(ETL_COMPILER_IAR)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__ALIGNOF__(T))> {};
#elif defined(ETL_COMPILER_TI)
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__ALIGNOF__(T))> {};
#else
  // Best guess!
  template <typename T> struct alignment_of : integral_constant<size_t, size_t(__alignof__(T))> {};
#endif

  /// Specialisation of 'alignment_of' for 'void'.
  ///\ingroup type_traits
  template <> struct alignment_of<void> : integral_constant <size_t, 0>{};
}

#endif
