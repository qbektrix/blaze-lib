//=================================================================================================
/*!
//  \file blazetest/mathtest/smatsmatadd/AliasingTest.h
//  \brief Header file for the sparse matrix/sparse matrix addition aliasing test
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

#ifndef _BLAZETEST_MATHTEST_SMATSMATADD_ALIASINGTEST_H_
#define _BLAZETEST_MATHTEST_SMATSMATADD_ALIASINGTEST_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <sstream>
#include <stdexcept>
#include <string>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/StaticMatrix.h>


namespace blazetest {

namespace mathtest {

namespace smatsmatadd {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class template for the sparse matrix/sparse matrix addition aliasing test.
//
// This class represents a test suite for all sparse matrix/sparse matrix addition aliasing tests.
// It performs a series of runtime tests to assure that all mathematical operations work correctly
// even in the presence of aliasing.
*/
class AliasingTest
{
 private:
   //**Type definitions****************************************************************************
   typedef blaze::CompressedMatrix<int,blaze::rowMajor>      SMat;   //!< Row-major sparse matrix type.
   typedef blaze::CompressedMatrix<int,blaze::columnMajor>   TSMat;  //!< Column-major sparse matrix type.
   typedef blaze::StaticMatrix<int,3UL,3UL,blaze::rowMajor>  RMat;   //!< Result row-major matrix type.
   //**********************************************************************************************

 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit AliasingTest();
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

 private:
   //**Test functions******************************************************************************
   /*!\name Test functions */
   //@{
   void testSMatSMatAdd  ();
   void testSMatTSMatAdd ();
   void testTSMatTSMatAdd();

   template< typename T1, typename T2 >
   void checkResult( const T1& computedResult, const T2& expectedResult );
   //@}
   //**********************************************************************************************

   //**Utility functions***************************************************************************
   /*!\name Utility functions */
   //@{
   void initialize();
   //@}
   //**********************************************************************************************

   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   SMat sA3x4_;    //!< The first row-major sparse matrix.
                   /*!< The \f$ 3 \times 4 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{4}{c}}
                        -1 & 0 & -2 & 0 \\
                         0 & 2 & -3 & 1 \\
                         0 & 1 &  2 & 2 \\
                        \end{array}\right)\f]. */
   SMat sB4x3_;    //!< The second row-major sparse matrix.
                   /*!< The \f$ 4 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        1 &  0 & -3 \\
                        0 & -1 &  0 \\
                        0 &  2 &  1 \\
                        2 &  1 & -2 \\
                        \end{array}\right)\f]. */
   SMat sC3x3_;    //!< The third row-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                         1 & 0 &  2 \\
                         0 & 3 & -1 \\
                        -1 & 0 &  2 \\
                        \end{array}\right)\f]. */
   SMat sD3x3_;    //!< The fourth row-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        0 & -1 &  0 \\
                        1 & -2 &  2 \\
                        0 &  0 & -3 \\
                        \end{array}\right)\f]. */
   SMat sE3x3_;    //!< The fifth row-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        2 &  0 &  0 \\
                        0 &  1 & -2 \\
                        1 &  0 &  0 \\
                        \end{array}\right)\f]. */
   TSMat tsA3x4_;  //!< The first column-major sparse matrix.
                   /*!< The \f$ 3 \times 4 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{4}{c}}
                        -1 & 0 & -2 & 0 \\
                         0 & 2 & -3 & 1 \\
                         0 & 1 &  2 & 2 \\
                        \end{array}\right)\f]. */
   TSMat tsB4x3_;  //!< The second column-major sparse matrix.
                   /*!< The \f$ 4 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        1 &  0 & -3 \\
                        0 & -1 &  0 \\
                        0 &  2 &  1 \\
                        2 &  1 & -2 \\
                        \end{array}\right)\f]. */
   TSMat tsC3x3_;  //!< The third column-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                         1 & 0 &  2 \\
                         0 & 3 & -1 \\
                        -1 & 0 &  2 \\
                        \end{array}\right)\f]. */
   TSMat tsD3x3_;  //!< The fourth column-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        0 & -1 &  0 \\
                        1 & -2 &  2 \\
                        0 &  0 & -3 \\
                        \end{array}\right)\f]. */
   TSMat tsE3x3_;  //!< The fifth column-major sparse matrix.
                   /*!< The \f$ 3 \times 3 \f$ matrix is initialized as
                        \f[\left(\begin{array}{*{3}{c}}
                        2 &  0 &  0 \\
                        0 &  1 & -2 \\
                        1 &  0 &  0 \\
                        \end{array}\right)\f]. */
   RMat result_;   //!< The sparse matrix for the reference result.

   std::string test_;  //!< Label of the currently performed test.
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Checking and comparing the computed result.
//
// \param computedResult The computed result.
// \param expectedResult The expected result.
// \return void
// \exception std::runtime_error Incorrect result detected.
//
// This function is called after each test case to check and compare the computed result.
// In case the computed and the expected result differ in any way, a \a std::runtime_error
// exception is thrown.
*/
template< typename T1    // Matrix type of the computed result
        , typename T2 >  // Matrix type of the expected result
void AliasingTest::checkResult( const T1& computedResult, const T2& expectedResult )
{
   if( computedResult != expectedResult ) {
      std::ostringstream oss;
      oss.precision( 20 );
      oss << " Test : " << test_ << "\n"
          << " Error: Incorrect result detected\n"
          << " Details:\n"
          << "   Computed result:\n" << computedResult << "\n"
          << "   Expected result:\n" << expectedResult << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the sparse matrix/sparse matrix addition in the presence of aliasing.
//
// \return void
*/
void runTest()
{
   AliasingTest();
}
//*************************************************************************************************




//=================================================================================================
//
//  MACRO DEFINITIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the execution of the sparse matrix/sparse matrix addition aliasing test.
*/
#define RUN_SMATSMATADD_ALIASING_TEST \
   blazetest::mathtest::smatsmatadd::runTest()
/*! \endcond */
//*************************************************************************************************

} // namespace smatsmatadd

} // namespace mathtest

} // namespace blazetest

#endif
