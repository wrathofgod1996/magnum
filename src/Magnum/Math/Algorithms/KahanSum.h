#ifndef Magnum_Math_Algorithms_KahanSum_h
#define Magnum_Math_Algorithms_KahanSum_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015, 2016
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Function @ref Magnum::Math::Algorithms::kahanSum()
 */

#include <utility>

namespace Magnum { namespace Math { namespace Algorithms {

/**
@brief Kahan summation algorithm
@param[in] begin            Range begin
@param[in] end              Range end
@param[in] sum              Initial value for the sum
@param[in,out] compensation Floating-point roundoff error compensation value.
    If non-`nullptr`, value behind the pointer is used as initial compensation
    value and the resulting value is

Calculates a sum of a large range of floating-point numbers with roundoff error
compensation. Compared to for example `std::accumulate()` the algorithm
significantly reduces numerical error in the total. See Wikipedia for an
in-depth explanation: https://en.wikipedia.org/wiki/Kahan_summation_algorithm

Example with summation of a hundred million ones:
@code
std::vector<Float> data(100000000, 1.0f);
Float a = std::accumulate(data.begin(), data.end());            // 1.667e7f
Float b = Math::Algorithms::kahanSum(data.begin(), data.end()); // 1.000e8f
@endcode

If required, it is also possible to use this algorithm on non-contiguous ranges
or single values (for example when calculating sum of pixel values in an image
with some row padding or when the inputs are generated / converted from other
values):
@code
Containers::ArrayView<UnsignedByte> pixels;
Float sum = 0.0f, c = 0.0f;
for(UnsignedByte pixel: pixels) {
    Float value = Math::normalize<Float>(pixel);
    sum = Math::Algorithms::kahanSum(&value, &value + 1, sum, &c);
}
@endcode
*/
template<class Iterator, class T = typename std::decay<decltype(*std::declval<Iterator>())>::type> T kahanSum(Iterator begin, Iterator end, T sum = T(0), T* compensation = nullptr) {
    T c = compensation ? *compensation : T(0);
    for(Iterator it = begin; it != end; ++it) {
        const T y = *it - c;
        const T t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    if(compensation) *compensation = c;
    return sum;
}

}}}

#endif