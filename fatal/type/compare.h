/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef FATAL_INCLUDE_fatal_type_compare_h
#define FATAL_INCLUDE_fatal_type_compare_h

#include <type_traits>

#include <fatal/type/impl/compare.h>

namespace fatal {

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the EQUAL TO
 * comparison, figuratively `LHS` == `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `false`
 *  comparison_transform::equal<A, B>::value
 *
 *  // yields `false`
 *  comparison_transform::equal<B, A>::value
 *
 *  // yields `true`
 *  comparison_transform::equal<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using equal = std::integral_constant<bool, LHS::value == RHS::value>;

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the NOT EQUAL TO
 * comparison, figuratively `LHS` != `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `true`
 *  comparison_transform::not_equal<A, B>::value
 *
 *  // yields `true`
 *  comparison_transform::not_equal<B, A>::value
 *
 *  // yields `false`
 *  comparison_transform::not_equal<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using not_equal = std::integral_constant<bool, LHS::value != RHS::value>;

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the LESS THAN
 * comparison, figuratively `LHS` < `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `true`
 *  comparison_transform::less<A, B>::value
 *
 *  // yields `false`
 *  comparison_transform::less<B, A>::value
 *
 *  // yields `false`
 *  comparison_transform::less<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using less = std::integral_constant<bool, (LHS::value < RHS::value)>;

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the LESS THAN or
 * EQUAL TO comparison, figuratively `LHS` <= `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `true`
 *  comparison_transform::less_equal<A, B>::value
 *
 *  // yields `false`
 *  comparison_transform::less_equal<B, A>::value
 *
 *  // yields `true`
 *  comparison_transform::less_equal<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using less_equal = std::integral_constant<
  bool,
  (LHS::value <= RHS::value)
>;

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the GREATER THAN
 * comparison, figuratively `LHS` > `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `false`
 *  comparison_transform::greater<A, B>::value
 *
 *  // yields `true`
 *  comparison_transform::greater<B, A>::value
 *
 *  // yields `false`
 *  comparison_transform::greater<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using greater = std::integral_constant<bool, (LHS::value > RHS::value)>;

/**
 * Helper class similar to std::integral_constant for comparing two types
 * `LHS` and `RHS`. Its boolean value is the result of the GREATER THAN or
 * EQUAL TO comparison, figuratively `LHS` >= `RHS`.
 *
 * Example:
 *
 *  using A = std::integral_constant<int, 10>;
 *  using B = std::integral_constant<int, 20>;
 *
 *  // yields `false`
 *  comparison_transform::greater_equal<A, B>::value
 *
 *  // yields `true`
 *  comparison_transform::greater_equal<B, A>::value
 *
 *  // yields `true`
 *  comparison_transform::greater_equal<A, A>::value
 *
 * @author: Marcelo Juchem <marcelo@fb.com>
 */
template <typename LHS, typename RHS>
using greater_equal = std::integral_constant<
  bool,
  (LHS::value >= RHS::value)
>;

// TODO: DOCUMENT REQUIREMENTS OF PREDICATE
//         http://en.cppreference.com/w/cpp/concept/Compare
template <typename Less>
struct sequence_compare {
  template <typename LHS, typename RHS>
  using apply = impl_comp::sc<Less, LHS, RHS>;
};

} // namespace fatal {

#endif // FATAL_INCLUDE_fatal_type_compare_h
