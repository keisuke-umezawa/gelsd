#include "math.h"
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>


#ifdef _MSC_VER
# pragma comment(lib, "libf2c.lib")
# pragma comment(lib, "BLAS.lib")
# pragma comment(lib, "clapack.lib")
#endif


int main()
{
    namespace ublas = boost::numeric::ublas;

    { // 過剰決定系(Overdetermined system)
        ublas::matrix<double> A(6, 2);
        ublas::matrix<double> B(6, 3), X;

        A(0, 0) = 0; A(0, 1) = +2;
        A(1, 0) = 2; A(1, 1) = -1;
        A(2, 0) = 2; A(2, 1) = -1;
        A(3, 0) = 0; A(3, 1) = +1.5;
        A(4, 0) = 2; A(4, 1) = -1;
        A(5, 0) = 2; A(5, 1) = -1;

        B(0, 0) = 1; B(0, 1) = +4; B(0, 2) = 1;
        B(1, 0) = 1; B(1, 1) = +1; B(1, 2) = 2;
        B(2, 0) = 1; B(2, 1) = -1; B(2, 2) = 1;
        B(3, 0) = 1; B(3, 1) = +3; B(3, 2) = 2;
        B(4, 0) = 1; B(4, 1) = +1; B(4, 2) = 1;
        B(5, 0) = 1; B(5, 1) = -1; B(5, 2) = 1;

        { // A がフルランク(Full rank)の場合
            math::least_squares(A, B, X, math::full_rank());

            // 以下結果の表示
            // 計算結果を http://publib.boulder.ibm.com/infocenter/clresctr/vxrx/topic/com.ibm.cluster.essl43.guideref.doc/am501_f10d032.html と比較してみましょう
            std::cout << X << std::endl;
        }

        { // A がランク落ち(Rank deficient)している可能性がある場合
            math::least_squares(A, B, X, math::rank_deficient());

            // 以下結果の表示
            // 計算結果を http://publib.boulder.ibm.com/infocenter/clresctr/vxrx/topic/com.ibm.cluster.essl43.guideref.doc/am501_f10d032.html と比較してみましょう
            std::cout << X << std::endl;
        }
    }

    { // 不定系(Underdetermined system)
        ublas::matrix<double> A(3, 4);
        ublas::matrix<double> B(3, 4), X;

        A(0, 0) = 0.5; A(0, 1) = +0.5; A(0, 2) = 0.5; A(0, 3) = +0.5;
        A(1, 0) = 0.5; A(1, 1) = -1.5; A(1, 2) = 0.5; A(1, 3) = -1.5;
        A(2, 0) = 1.0; A(2, 1) = +1.0; A(2, 2) = 0.0; A(2, 3) = +1.0;

        B(0, 0) = 1; B(0, 1) = +1; B(0, 2) = 1.0; B(0, 3) = 0;
        B(1, 0) = 1; B(1, 1) = -1; B(1, 2) = 2.5; B(1, 3) = 1;
        B(2, 0) = 1; B(2, 1) = +1; B(2, 2) = 3.0; B(2, 3) = 0;

        { // A がフルランク(Full rank)の場合
            math::least_squares(A, B, X, math::full_rank());

            // 以下結果の表示
            // 計算結果を http://publib.boulder.ibm.com/infocenter/clresctr/vxrx/topic/com.ibm.cluster.essl43.guideref.doc/am501_f10d034.html と比較してみましょう
            std::cout << X << std::endl;
        }

        { // A がランク落ち(Rank deficient)している可能性がある場合
            math::least_squares(A, B, X, math::rank_deficient());

            // 以下結果の表示
            // 計算結果を http://publib.boulder.ibm.com/infocenter/clresctr/vxrx/topic/com.ibm.cluster.essl43.guideref.doc/am501_f10d034.html と比較してみましょう
            std::cout << X << std::endl;
        }
    }

    return 0;
}