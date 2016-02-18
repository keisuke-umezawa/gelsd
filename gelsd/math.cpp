#include "math.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/vector.hpp>
#define BOOST_NUMERIC_BINDINGS_USE_CLAPACK
#include <boost/numeric/bindings/ublas/matrix.hpp>
#include <boost/numeric/bindings/lapack/driver/gels.hpp>
#include <boost/numeric/bindings/lapack/driver/gelsd.hpp>
#undef  BOOST_NUMERIC_BINDINGS_USE_CLAPACK


void math::least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::vector<double>& b, boost::numeric::ublas::vector<double>& x, math::full_rank rank)
{
    //BOOST_UBLAS_CHECK(A.size1() == b.size(), boost::numeric::ublas::external_logic());

    //boost::numeric::ublas::matrix<double> B(b.size(), 1), X;

    //boost::numeric::ublas::column(B, 0).assign(b);
    //least_squares(A, B, X, rank);

    //x = boost::numeric::ublas::column(X, 0);
}


void math::least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::matrix<double>& B, boost::numeric::ublas::matrix<double>& X, math::full_rank)
{
    //namespace ublas  = boost::numeric::ublas;
    //namespace lapack = boost::numeric::bindings::lapack;

    //BOOST_UBLAS_CHECK(A.size1() == B.size1(), ublas::external_logic());

    //ublas::matrix<double, ublas::column_major> CA(A), CX((std::max)(A.size1(), A.size2()), B.size2());
    //int                                        info;

    //ublas::project(CX, ublas::range(0, B.size1()), ublas::range(0, B.size2())).assign(B);

    //info = lapack::gels('N', CA, CX, lapack::optimal_workspace());
    //BOOST_UBLAS_CHECK(info == 0, ublas::internal_logic());

    //X = ublas::project(CX, ublas::range(0, A.size2()), ublas::range(0, B.size2()));
}


void math::least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::vector<double>& b, boost::numeric::ublas::vector<double>& x, math::rank_deficient rank)
{
    //BOOST_UBLAS_CHECK(A.size1() == b.size(), boost::numeric::ublas::external_logic());

    //boost::numeric::ublas::matrix<double> B(b.size(), 1), X;

    //boost::numeric::ublas::column(B, 0).assign(b);
    //least_squares(A, B, X, rank);

    //x = boost::numeric::ublas::column(X, 0);
}


void math::least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::matrix<double>& B, boost::numeric::ublas::matrix<double>& X, math::rank_deficient)
{
    namespace ublas  = boost::numeric::ublas;
    namespace lapack = boost::numeric::bindings::lapack;

    BOOST_UBLAS_CHECK(A.size1() == B.size1(), ublas::external_logic());

    ublas::matrix<double, ublas::column_major> CA(A), CX((std::max)(A.size1(), A.size2()), B.size2());
	const int n = boost::numeric::bindings::size_column(CA);
	boost::numeric::bindings::detail::array<double> s(n);
    int info = 0;
    int rank = 0;
    const int rcond = -1;

    ublas::project(CX, ublas::range(0, B.size1()), ublas::range(0, B.size2())).assign(B);

    lapack::optimal_workspace work;

    info = lapack::gelsd(CA, CX, s, rcond, rank, work);
    BOOST_UBLAS_CHECK(info == 0, ublas::internal_logic());

    X = ublas::project(CX, ublas::range(0, A.size2()), ublas::range(0, B.size2()));
}