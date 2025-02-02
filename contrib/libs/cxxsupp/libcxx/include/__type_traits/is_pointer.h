//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___TYPE_TRAITS_IS_POINTER_H
#define _LIBCPP___TYPE_TRAITS_IS_POINTER_H

#include <__config>
#include <__type_traits/integral_constant.h>
#include <__type_traits/remove_cv.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

// Before AppleClang 12.0.5, __is_pointer didn't work for Objective-C types.
#if __has_keyword(__is_pointer) &&                                             \
    !(defined(_LIBCPP_APPLE_CLANG_VER) && _LIBCPP_APPLE_CLANG_VER < 1205) &&   \
    !defined(__CUDACC__)

template<class _Tp>
struct _LIBCPP_TEMPLATE_VIS is_pointer : _BoolConstant<__is_pointer(_Tp)> { };

#if _LIBCPP_STD_VER > 14
template <class _Tp>
inline constexpr bool is_pointer_v = __is_pointer(_Tp);
#endif

#else // __has_keyword(__is_pointer)

template <class _Tp> struct __libcpp_is_pointer       : public false_type {};
template <class _Tp> struct __libcpp_is_pointer<_Tp*> : public true_type {};

template <class _Tp> struct __libcpp_remove_objc_qualifiers { typedef _Tp type; };
#if defined(_LIBCPP_HAS_OBJC_ARC)
template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __strong> { typedef _Tp type; };
template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __weak> { typedef _Tp type; };
template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __autoreleasing> { typedef _Tp type; };
template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __unsafe_unretained> { typedef _Tp type; };
#endif

template <class _Tp> struct _LIBCPP_TEMPLATE_VIS is_pointer
    : public __libcpp_is_pointer<typename __libcpp_remove_objc_qualifiers<typename remove_cv<_Tp>::type>::type> {};

#if _LIBCPP_STD_VER > 14
template <class _Tp>
inline constexpr bool is_pointer_v = is_pointer<_Tp>::value;
#endif

#endif // __has_keyword(__is_pointer)

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___TYPE_TRAITS_IS_POINTER_H
