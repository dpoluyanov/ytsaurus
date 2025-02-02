//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___TYPE_TRAITS_IS_FUNCTIONAL_H
#define _LIBCPP___TYPE_TRAITS_IS_FUNCTIONAL_H

#include <__config>
#include <__type_traits/integral_constant.h>
#include <__type_traits/is_const.h>
#include <__type_traits/is_reference.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

template <class _Tp> struct _LIBCPP_TEMPLATE_VIS is_function
    : public _BoolConstant<
#if defined(__clang__) && !defined(__CUDACC__)
    __is_function(_Tp)
#else
 !(is_reference<_Tp>::value || is_const<const _Tp>::value)
#endif
    > {};


#if _LIBCPP_STD_VER > 14
template <class _Tp>
inline constexpr bool is_function_v = is_function<_Tp>::value;
#endif

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___TYPE_TRAITS_IS_FUNCTIONAL_H
