#ifndef Magnum_Math_Tags_h
#define Magnum_Math_Tags_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015
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
 * @brief Tag type @ref Magnum::Math::ZeroInitT, @ref Magnum::Math::IdentityInitT, tag @ref Magnum::Math::ZeroInit, @ref Magnum::Math::IdentityInit
 */

namespace Magnum { namespace Math {

/**
@brief Zero initialization tag type

Used to distinguish construction with all elements set to zero.
@see @ref ZeroInit
*/
struct ZeroInitT {};

/**
@brief Identity initialization tag type

Used to distinguish construction with transformation set to identity.
@see @ref IdentityInit
*/
struct IdentityInitT {};

/**
@brief Zero initialization tag

Use for construction with all elements set to zero.
*/
constexpr ZeroInitT ZeroInit{};

/**
@brief Identity initialization tag

Use for construction with transformation set to identity.
*/
constexpr IdentityInitT IdentityInit{};

}}

#endif