//=================================================================================================
/*!
//  \file blazemark/armadillo/init/Row.h
//  \brief Header file for the Armadillo dense row vector initialization functions
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================

#ifndef _BLAZEMARK_ARMADILLO_INIT_ROW_H_
#define _BLAZEMARK_ARMADILLO_INIT_ROW_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <armadillo>
#include <blaze/util/Random.h>
#include <blazemark/system/Types.h>


namespace blazemark {

namespace armadillo {

//=================================================================================================
//
//  INITIALIZATION FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\name Armadillo initialization functions */
//@{
template< typename Type >
void init( ::arma::Row<Type>& v );
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Random initialization of the given row vector.
//
// \param v The row vector to be initialized.
// \return void
//
// This function initializes the given row vector with random values.
*/
template< typename Type >  // Data type of the vector
void init( ::arma::Row<Type>& v )
{
   const size_t N( v.n_elem );

   for( size_t i=0UL; i<N; ++i ) {
      v[i] = ::blaze::rand<Type>( 0, 10 );
   }
}
//*************************************************************************************************

} // namespace armadillo

} // namespace blazemark

#endif
