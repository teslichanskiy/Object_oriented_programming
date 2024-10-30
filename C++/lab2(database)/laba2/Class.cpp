#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

const double EPS = 1E-9;

class ArrayException {
private:
    std::string m_error;
public:
    ArrayException(std::string error)
        : m_error(error)
    {
    }

    const char* getError() { return m_error.c_str(); }

};

class Matrix {
protected:
    int row, column;
    std::vector<std::vector<float>> matr;
public:
    Matrix(int ro, int col) : row(ro), column(col)
    {
        matr.resize(ro, std::vector<float>(col));
        for (int i = 0; i < ro; i++) {
            for (int j = 0; j < col; j++)
                matr[i][j] = 0;
        }
    }

    Matrix() {row = 0;column = 0;};

    Matrix(std::vector<std::vector<float>> len) {

        for (int i = 0; i < len.size(); i++) {
            if (len[i].size() != len[i+1].size()) {
                throw ArrayException("Matrix.cell(i, j): wrong vector sizes in Matrix");
            }
        }
        row = len.size();
        column = len[0].size();
        matr = len;
    };

    // сумма матриц
    Matrix operator+(const Matrix& tmp) {
        if (this->column != tmp.column || this->row != tmp.row) {
            throw ArrayException("Matrix + Matrix: wrong sizes");
        }

        std::vector<std::vector<float>> vectmp;

        for (int i = 0; i < this->row; i++) {
            std::vector<float> temp;
            vectmp.push_back(temp);
            for (int j = 0; j < this->column; j++) {
                vectmp[i].push_back(tmp.matr[i][j] + this->matr[i][j]);
            }
        }

        return Matrix(vectmp);

    }

    // вычитание матриц
    Matrix operator-(const Matrix& tmp) {
        if (this->column != tmp.column || this->row != tmp.row) {
            throw ArrayException("Matrix - Matrix: wrong sizes");
        }
        std::vector<std::vector<float>> vectmp;

        for (int i = 0; i < this->row; i++) {
            std::vector<float> temp;
            vectmp.push_back(temp);
            for (int j = 0; j < this->column; j++) {
                vectmp[i].push_back(tmp.matr[i][j] - this->matr[i][j]);
            }
        }
        return Matrix(vectmp);

    }

    // умножение матриц
    Matrix operator*(const Matrix& tmp) const {
        if (this->column != tmp.row) {
            throw ArrayException("Matrix * Matrix: wrong sizes");
        }
        std::vector<std::vector<float>> vectmp;

        float tmpsum = 0;

        for (int i = 0; i < this->row; i++) {
            std::vector<float> temp;
            vectmp.push_back(temp);
            for (int j = 0; j < tmp.column; j++) {

                for (int k = 0; k < this->column; k++) {
                    tmpsum += this->print(i, k) * tmp.print(k, j);
                }



                vectmp[i].push_back(tmpsum);
                tmpsum = 0;
            }
        }
        return Matrix(vectmp);
    }

    // умножение на число
    Matrix operator*(int num) {
        std::vector<std::vector<float>> tmpvec;

        for (int i = 0; i < this->row; i++) {
            std::vector<float> temp;
            tmpvec.push_back(temp);
            for (int j = 0; j < this->column; j++) {
                tmpvec[i].push_back(this->matr[i][j] * num);
            }


        }

        return Matrix(tmpvec);
    }

    int getstr() const {return this->row;}
    int getstolb() const {return this->column;}

    // проверка будет ли матрица квадратной
    bool issquare() const {
        if (this->getstr() == this->getstolb()) 
            return true;
        else 
            return false;
    };

    // след матрицы
    float trace() const {
        if (this->issquare()) {
            float sum = 0;
            for (int i = 0; i < this->getstr(); i++) {
                sum += this->print(i, i);
            }
            return sum;
        }
        else {
            throw ArrayException("Matrix must be squared");
        }
    }

    //определитель матрицы методом Гаусса

    float det() const {
        if (this->issquare() == false) {
            throw ArrayException("Matrix must be squared");
        }
        else {
            Matrix temp(this->matr);
            int n = temp.getstr();
            float d = 1;
            for (int i = 0; i < n; ++i) {
                int k = i;
                for (int j = i + 1; j < n; ++j)
                    if (abs(temp.print(j, i)) > abs(temp.print(k, i))) // поиск максимального элемента в столбце
                        k = j;
                if (abs(temp.print(k, i)) < EPS) { // если максимальный элемент в столбце очень мал, то определитель 0
                    d = 0;
                    break;
                }
                for (int j = 0; j < n; j++) { //  переставляем максимальную строку
                    // с максимальным по модулю элементом наверх
                    std::swap(temp.cell(i, j), temp.cell(k, j));
                }

                if (i != k) // меняем знак каждый раз когда переставляем строки
                    d = -d; // если максимальный элемент оказался в нужном месте, ничего не делаем
                d *= temp.cell(i, i); // умножаем det на элемент на главной диагонали
                for (int j = i + 1; j < n; ++j)
                    temp.cell(i, j) /= temp.cell(i, i); // делим элементы в строке на максимальный
                for (int j = 0; j < n; ++j)
                    if (j != i && abs(temp.cell(j, i)) > EPS)
                        for (int k = i + 1; k < n; ++k) {
                            temp.cell(j, k) -= temp.cell(i, k) * temp.cell(j, i);
                        }
            }
            return d;
        }
    }

    float fbnorm() const {
        float norm = 0;
        for (int i = 0; i < this->getstolb(); i++) {
            for (int j = 0; j < this->getstr(); j++) {
                norm += this->matr[i][j] * this->matr[i][j];
            }
        }
        return sqrt(norm);
    }

    Matrix T() {
        int strk1 = this->column;
        int stlb1 = this->row;
        std::vector<std::vector<float>> tmp;
        for (int j = 0; j < this->column; j++) {
            std::vector<float> temp;
            tmp.push_back(temp);
            for (int i = 0; i < this->row; i++) {
                tmp[j].push_back(this->cell(i, j));
            }
        }
        return Matrix(tmp);

    }
    friend Matrix operator*(int num, const Matrix& tmp);
    friend Matrix adamar(const Matrix& tmp1, const Matrix& tmp2);
    friend Matrix operator+(const Matrix& l, const Matrix& k);
    friend std::ostream& operator<<(std::ostream& om, const Matrix& m);
    friend Matrix operator-(const Matrix& l, const Matrix& k);
};



ostream& operator<<(ostream& om, const Matrix& m) // вывод матрицы
{
    for (int i = 0; i < m.r; i++)
    {
        for (int j = 0; j < m.c; j++)
            om << m.m[i][j] << " ";
        om << endl;
    }
    return om;
}

Matrix operator*(int num, const Matrix& tmp) {
    std::vector<std::vector<float>> tmpvec;

    for (int i = 0; i < tmp.row; i++) {
        std::vector<float> temp;
        tmpvec.push_back(temp);
        for (int j = 0; j < tmp.column; j++) {
            tmpvec[i].push_back(tmp.matr[i][j] * num);
        }
    }
    return Matrix(tmpvec);
}


Matrix adamar(const Matrix& tmp1, const Matrix& tmp2) {
    if (tmp1.column != tmp2.column || tmp1.row != tmp2.row) {
        throw ArrayException("Matrix adamar: wrong sizes");
    }
    std::vector<std::vector<float>> vectmp;

    for (int i = 0; i < tmp1.row; i++) {
        std::vector<float> temp;
        vectmp.push_back(temp);
        for (int j = 0; j < tmp1.column; j++) {
            vectmp[i].push_back(tmp1.matr[i][j] * tmp2.matr[i][j]);
        }
    }

    return Matrix(vectmp);
}




std::ostream& operator<< (std::ostream& out, const Matrix& mtr)
{
    float max = mtr.matr[0][0];
    float min = mtr.matr[0][0];
    int size = 0;



    size = 6;


    out.setf(std::ios::left);
    out << std::setprecision(6);
    if (mtr.row == 1) {
        out << "( ";
        for (int i = 0; i < mtr.column; i++) {
            out << std::setfill(' ') << std::setw(size);
            out << mtr.print(0, i) << " ";
        }
        out << ")\n";


    }

    else {

        out << "/ ";
        for (int i = 0; i < mtr.column; i++) {
            out << std::setfill(' ') << std::setw(size);
            out << mtr.print(0, i) << " ";
        }
        out << "\\ \n";

        for (int j = 1; j < mtr.row - 1; j++) {
            out << "| ";
            for (int i = 0; i < mtr.column; i++) {
                out << std::setfill(' ') << std::setw(size);
                out << mtr.print(j, i) << " ";
            }
            out << "|\n";
        }

        out << "\\ ";
        for (int i = 0; i < mtr.column; i++) {
            out << std::setfill(' ') << std::setw(size);
            out << mtr.print(mtr.row - 1, i) << " ";
        }
        out << "/ \n";

    }

    return out;

}




class Vector : public Matrix {
public:

    Vector() {
        column = 0;
        row = 0;
    };

    Vector(std::vector<float> vec) {
        row = vec.size();
        column = 1;

        for (int i = 0; i < vec.size(); i++) {
            std::vector<float> tmp;
            matr.push_back(tmp);
            matr[i].push_back(vec[i]);
        }

    }




    float operator*(const Vector& tmp) {
        if (this->row != tmp.row) {
            throw ArrayException("vector * vector: wrong sizes");
        }

        float sum = 0;

        for (int i = 0; i < this->row; i++) {
            sum += this->matr[i][0] * tmp.matr[i][0];
        }

        return sum;

    }


    Matrix operator*(const Matrix& tmp) {

        return Matrix(this->matr) * tmp;
    }




    float evklidnorm() {
        return sqrt(*this * *this);
    }



    float maxnorm() {
        float max = 0;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                if (abs(this->matr[i][j]) > max) {
                    max = abs(this->matr[i][j]);
                }
            }
        }
        return max;
    }



    friend float angle(Vector& v1, Vector& v2);


};

float angle(Vector& v1, Vector& v2) {

    return  acos((v1 * v2) / (v1.evklidnorm() * v2.evklidnorm()));


}




// написать подклассы для матриц указанных видов -  
//  верхняя и нижняя треугольные матрицы, симметричная матрица.


class One : public Matrix {
public:
    One(int a) {


        row = a;
        column = a;

        for (int i = 0; i < a; i++) {
            std::vector<float> tmp;
            matr.push_back(tmp);
            for (int j = 0; j < a; j++) {
                if (i == j) 
                    matr[i].push_back(1);
                else 
                    matr[i].push_back(0);
            }
        }
    };

};


class diagonal : public Matrix {
public:
    diagonal(std::vector<float> vec) {

        row = vec.size();
        column = vec.size();

        for (int i = 0; i < row; i++) {
            std::vector<float> tmp;
            matr.push_back(tmp);
            for (int j = 0; j < row; j++) {
                if (i == j) {
                    matr[i].push_back(vec[i]);
                }
                else {
                    matr[i].push_back(0);
                }
            }
        }
    };

    diagonal(Matrix mtr) {
        if (mtr.issquare() != true) {
            throw ArrayException("diagonal: matrix must be square");
        }
        for (int i = 0; i < mtr.getstr(); i++) {
            for (int j = 0; j < mtr.getstr(); j++) {
                if (i == j) {
                    matr[i].push_back(mtr.cell(i, j));
                }
                else {
                    matr[i].push_back(0);
                }
            }
        }
        row = mtr.getstr();
        column = row;
    }

};


class upper : public Matrix {
public:
    upper(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                if (j >= i) {
                    float a = (float)(rand() % 10000) / 1000;
                    matr[i].push_back(a);
                }
                else {
                    matr[i].push_back(0);
                }
            }
        }
    };

    float& cell(int i, int j) {
        if (i > j) {
            throw ArrayException("This value is constant");
        }
        else {
            return Matrix::cell(i, j);
        }

    }


};

class lower : public Matrix {
public:
    lower(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                if (i >= j) {
                    float a = (float)(rand() % 10000) / 1000;
                    matr[i].push_back(a);
                }
                else {
                    matr[i].push_back(0);
                }
            }
        }
    };

    float& cell(int i, int j) {
        if (j > i) {
            throw ArrayException("This value is constant");
        }
        else {
            return Matrix::cell(i, j);
        }

    }

};





class pair { // чисто для симметричной матрицы существует
    // чтобы в симметричной матрице менялись оба элемента всегда.
    // если это не нужно можно преобразовать симметричную к обычной матрице уже после генерации
public:
    float* a;
    float* b;
    pair(float* tmp1, float* tmp2) {
        a = tmp1;
        b = tmp2;
    }


    void operator= (const float num) {
        *a = num;
        *b = num;
    }

};



class simetric : public Matrix {
public:
    simetric(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            std::vector<float> tmp;
            matr.push_back(tmp);
            for (int j = 0; j < c; j++) {
                if (j >= i) {
                    float a = (float)(rand() % 10000) / 1000;
                    matr[i].push_back(a);
                }
                else {
                    matr[i].push_back(this->print(j, i)); // всегда сработает так как матрица заполняется построчно.
                    // то есть рандомится вся первая строка, вторая строка вся рандомится кроме одного числа которое берётся из первой строки
                    // в третьей строки уже 2 числа берутся из предыдущих строк а остальные рандомятся и так далее, ошибки никогда не возникнет.
                }
            }
        }
    };




    pair cell(int i, int j) {
        return pair(&Matrix::cell(i, j), &Matrix::cell(j, i));
    }



};