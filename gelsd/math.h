#ifndef MATH_HPP_20081118
#define MATH_HPP_20081118

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif


#include <boost/numeric/ublas/fwd.hpp>


namespace math {
    struct full_rank {};
    struct rank_deficient {};

    void least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::vector<double>& b, boost::numeric::ublas::vector<double>& x, full_rank);
    void least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::matrix<double>& B, boost::numeric::ublas::matrix<double>& X, full_rank);
    void least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::vector<double>& b, boost::numeric::ublas::vector<double>& x, rank_deficient);
    void least_squares(const boost::numeric::ublas::matrix<double>& A, const boost::numeric::ublas::matrix<double>& B, boost::numeric::ublas::matrix<double>& X, rank_deficient);
}


#endif