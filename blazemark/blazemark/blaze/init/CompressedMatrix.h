//=================================================================================================
/*!
//  \file blazemark/blaze/init/CompressedMatrix.h
//  \brief Header file for the Blaze compressed matrix initialization functions
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

#ifndef _BLAZEMARK_BLAZE_INIT_COMPRESSEDMATRIX_H_
#define _BLAZEMARK_BLAZE_INIT_COMPRESSEDMATRIX_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/CompressedMatrix.h>
#include <blaze/util/Random.h>
#include <blazemark/system/Types.h>
#include <blazemark/util/Indices.h>


namespace blazemark {

namespace blaze {

//=================================================================================================
//
//  INITIALIZATION FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\name Blaze initialization functions */
//@{
template< typename Type >
void init( ::blaze::CompressedMatrix<Type,::blaze::rowMajor>& m, size_t nonzeros );

template< typename Type >
void init( ::blaze::CompressedMatrix<Type,::blaze::columnMajor>& m, size_t nonzeros );
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Random initialization of the given row-major compressed matrix.
//
// \param m The row-major compressed matrix to be initialized.
// \param nonzeros The number of non-zero elements per row.
// \return void
//
// This function initializes the given row-major compressed matrix with random values.
// Each row will be filled with \a nonzeros non-zero elements, whose indices are randomly
// determined.
*/
template< typename Type >  // Data type of the matrix
void init( ::blaze::CompressedMatrix<Type,::blaze::rowMajor>& m, size_t nonzeros )
{
   const size_t M( m.rows()    );
   const size_t N( m.columns() );

   for( size_t i=0UL; i<M; ++i ) {
      m.reserve( i, nonzeros );
      ::blazemark::Indices indices( N, nonzeros );
      for( ::blazemark::Indices::Iterator it=indices.begin(); it!=indices.end(); ++it ) {
         m.append( i, *it, ::blaze::rand<Type>( 0, 10 ) );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Random initialization of the given column-major compressed matrix.
//
// \param m The column-major compressed matrix to be initialized.
// \param nonzeros The number of non-zero elements per column.
// \return void
//
// This function initializes the given column-major compressed matrix with random values.
// Each column will be filled with \a nonzeros non-zero elements, whose indices are randomly
// determined.
*/
template< typename Type >  // Data type of the matrix
void init( ::blaze::CompressedMatrix<Type,::blaze::columnMajor>& m, size_t nonzeros )
{
   const size_t M( m.rows()    );
   const size_t N( m.columns() );

   for( size_t j=0UL; j<N; ++j ) {
      m.reserve( j, nonzeros );
      ::blazemark::Indices indices( M, nonzeros );
      for( ::blazemark::Indices::Iterator it=indices.begin(); it!=indices.end(); ++it ) {
         m.append( *it, j, ::blaze::rand<Type>( 0, 10 ) );
      }
   }
}
//*************************************************************************************************

} // namespace blaze

} // namespace blazemark

#endif
