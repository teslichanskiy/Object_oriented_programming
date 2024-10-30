#include "Header1.h"


int main()
{
    std::vector<std::vector<float>> a = { { 1, 4, 0 }, {0, 1, 0} };
    std::vector<float> b = { 1, 3, 2 };
    std::vector<float> b1 = { 3, 2, 1 };
    
    try {
        Matrix A(a);
        // std::cout << "Enter the amount of rows and columns of matrix:" << std::endl;
        // int r, c;
        // std::cin >> r;
         //std::cin >> c;
        // Matrix A(r, c);
        // std::cout << "Enter matrix:" << std::endl;
        // A.EnterMatrix();
         std::cout << "Matrix:\n" << A;
       //  std::cout << "One\n" << one(3);
        // std::cout << "Diagonal\n" << diagonal(3);
        // std::cout << "Upper\n" << upper(3);
        // std::cout << "Lower\n" << lower(3);
        // std::cout << "Symetric\n" << symetric(3);
        // std::cout << "A + A:\n" << A + A;
        // std::cout << "A - A:\n" << A - A;
        // std::cout << "A * A:\n" << A * A;
         //std::cout << "adamar :\n" << adamar(A, A);
        // std::cout << "\ndeterminant A:\n" << A.determinant();
        // std::cout << "\nA rank:\n" << A.rank();
         //std::cout << "\ninverse A:\n" << A.inv();
         std::cout << "\ntranspose A:\n" << A.Transpose();
        // std::cout << "\nFrobenius norm A:\n" << A.frbnorm();
         //std::cout << "\ntrace A:\n" << A.trace();
        // std::cout << "\nA * 5\n" << A * 5;
         std::cout << "\nCheck\n" << A * A.inv();
 
         Vector v1(b), v2(b1);

         std::cout << "\nAngle:\n" << angle(v1, v2);
         std::cout << "\nv1 + v2\n" << v1 + v2;
         std::cout << "\nv1*v2\n" << v1 * v2;
         std::cout << "\nEvklid norm v1\n" << v1.evklidnorm();
         std::cout << "\nNorm v1\n" << v1.maxnorm();

    
    }
    catch (ArrayException& ex) {
        std::cerr << "Exception: " << ex.getError() << std::endl;
        return -1;
    }
    return 0;
}
 
