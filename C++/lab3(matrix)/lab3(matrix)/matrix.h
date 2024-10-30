#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <algorithm>
//#include <fstream>
//#include <sstream>
#include <cstdlib>

class ArrayException
{
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
    int row; 
    int column; 
    std::vector<std::vector<float>> matrix;

public:
    Matrix() : row(0), column(0) {}
    Matrix(int ro, int col) : row(ro), column(col) {
        row = ro;
        column = col;
        for (int i = 0; i < ro; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < col; j++) {
                matrix[i].push_back(0);
            }
        }
    }
    

    Matrix(std::vector<std::vector<float>> matr) {

        for (int i = 0; i < matr.size(); i++) {
            if (matr[0].size() != matr[i].size()) {
                throw ArrayException("\nMatrix wrong vector sizes");
            }
        }
        row = matr.size();
        column = matr[0].size();
        matrix = matr;
    };

    void EnterMatrix()
    {
       float element;
       for (int i = 0; i < row; i++) {
       for (int j = 0; j < column; j++)
       {
            std::cin >> element;
            matrix[i][j] = element;
        }
      }
   };

    float trace() const {
        if (this->row == this->column) {
            float sum = 0;
            for (int i = 0; i < this->getrow(); i++) {
                sum += matrix[i][i];
            }
            return sum;
        }
        else {
            throw ArrayException("\nMatrix is not square");
        }
    }

    float frbnorm() const {
        float norm = 0;
        for (int i = 0; i < this->getcolumn(); i++) {
            for (int j = 0; j < this->getrow(); j++) {
                norm += this->matrix[i][j] * this->matrix[i][j];
            }
        }
        return sqrt(norm);
    }

    
     float determinant() const {
        if (this->row != this->column) {
            throw ArrayException("Determinant exists only on a square matrix");
        }
        else {
            Matrix temp(this->matrix);
            float d = 0, determinant = 1;
            int x = 0;
            for(int i = 0; i < temp.getrow(); i++){
                if (temp.matrix[i][i] == 0) {
                    for (int j = i + 1; j < temp.getrow(); j++) {
                        if (temp.matrix[j][i] != 0) {
                            x++;
                            for(int k = 0; k < temp.getrow(); k++)
                               std::swap(temp.matrix[j][k], temp.matrix[i][k]);
                            determinant *= (-1);
                            break;
                        }
                    }
                    if (x == 0) {

                        break;
                        determinant = 0;
                    }
                  }
                
                  for(int j = i + 1; j < temp.getcolumn(); j++){
                  d = (float)temp.matrix[j][i] / temp.matrix[i][i];
                  
                   for(int k = i; k < temp.getrow(); k++){
                     temp.matrix[j][k] = (float)temp.matrix[j][k] - (float)d * temp.matrix[i][k];
                   }
                  }
                 
            }
            for (int i = 0; i < temp.getrow(); i++)
            {
                determinant *= (float)temp.matrix[i][i];
  
            }
            return determinant;
       }
        
}



   
    Matrix Transpose() {

        std::vector<std::vector<float>> tmp;
        for (int i = 0; i < this->column; i++) {
            std::vector<float> temp;
            tmp.push_back(temp);
            for (int j = 0; j < this->row; j++) {
                tmp[i].push_back(this->matrix[j][i]);
            }
        }
        return Matrix(tmp);

    }
    

    int rank() {

        int rank, j, k, l;
        float r, e = 1E-3;
        std::vector<std::vector<float>> a = this->matrix;

        rank = 0; j = 0;
        while (rank < this->row && j < this->column) {
   
            r = 0.0;
            for (k = rank; k < this->row; ++k) {
                if (fabs(a[k][j]) > r) {
                    l = k;      
                    r = fabs(a[k][j]); 
                }
            }
            
            if (r <= e) {
               
                for (k = rank; k < this->row; ++k) {
                    a[k][j] = 0.0;
                }
                ++j;     
                continue; 
            }

            if (l != rank) {
                
                for (k = j; k < this->column; ++k) {
                    r = a[rank][k];
                    a[rank][k] = a[l][k];
                    a[l][k] = (-r); 
                }
            }

            for (k = rank + 1; k < this->row; ++k) {
                r = (-a[k][j] / a[rank][j]);

                a[k][j] = 0.0;
                for (l = j + 1; l < this->column; ++l) {
                    a[k][l] += r * a[rank][l];
                }
            }

            ++rank; ++j;   
        }

        return rank; 
    }

    Matrix inv()
    {

        if (this->row != this->column) {
            throw ArrayException("\nMatrix is not square, inversed matrix does not exist");
        }

        if (this->determinant() == 0) {
            throw ArrayException("\nMatrix is degenerated, inversed matrix does not exist");
        }

        std::vector<std::vector<float>> mtr = this->matrix; 
        std::vector<std::vector<float>> tmp; 

        int n = this->matrix.size();
        float num;
        for (int i = 0; i < n; i++) {
            std::vector<float> temp;
            tmp.push_back(temp);
            for (int j = 0; j < n; j++)
            {
                tmp[i].push_back(0.0);

                if (i == j)
                    tmp[i][j] = 1.0;
            }
        }// единичная матрица

        for (int k = 0; k < n; k++){
            num = mtr[k][k];

            for (int j = 0; j < n; j++){
                mtr[k][j] /= num;
                tmp[k][j] /= num;
            }

            for (int i = k + 1; i < n; i++)
            {
                num = mtr[i][k];

                for (int j = 0; j < n; j++){
                    mtr[i][j] -= mtr[k][j] * num;
                    tmp[i][j] -= tmp[k][j] * num;
                }
            }
        }

        for (int k = n - 1; k > 0; k--){
            for (int i = k - 1; i >= 0; i--)
            {
                num = mtr[i][k];

                for (int j = 0; j < n; j++)
                {
                    mtr[i][j] -= mtr[k][j] * num;
                    tmp[i][j] -= tmp[k][j] * num;

                }
            }
        }

        float e = 1E-3;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (fabs(tmp[i][j]) < e) {
                    tmp[i][j] = 0;
                }
            }
        }

        return Matrix(tmp);
    }



    friend Matrix operator+(const Matrix& a, const Matrix& b); 
    friend Matrix operator-(const Matrix& a, const Matrix& b); 
    friend Matrix operator*(const Matrix& a, const Matrix& b); 
    friend Matrix operator*(const Matrix& a, int n);
    friend Matrix adamar(const Matrix& tmp1, const Matrix& tmp2);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& mtr);
    int getrow() const { return this->row; }
    int getcolumn() const { return this->column; }
};

Matrix operator+(const Matrix& tmp1, const Matrix& tmp2) {
    if (tmp1.column != tmp2.column || tmp1.row != tmp2.row) {
        throw ArrayException("Matrix + Matrix: wrong sizes");
    }

    std::vector<std::vector<float>> mtr;

    for (int i = 0; i < tmp1.row; i++) {
        std::vector<float> temp;
        mtr.push_back(temp);
        for (int j = 0; j < tmp1.column; j++) {
            mtr[i].push_back(tmp1.matrix[i][j] + tmp2.matrix[i][j]);
        }
    }

    return Matrix(mtr);

}

Matrix operator-(const Matrix& tmp1, const Matrix& tmp2) {
    if (tmp1.column != tmp2.column || tmp1.row != tmp2.row) {
        throw ArrayException("Matrix + Matrix: wrong sizes");
    }

    std::vector<std::vector<float>> vectmp;

    for (int i = 0; i < tmp1.row; i++) {
        std::vector<float> temp;
        vectmp.push_back(temp);
        for (int j = 0; j < tmp1.column; j++) {
            vectmp[i].push_back(tmp1.matrix[i][j] - tmp2.matrix[i][j]);
        }
    }

    return Matrix(vectmp);

}

Matrix operator*(const Matrix& tmp1, const Matrix& tmp2) {
    if (tmp1.column != tmp2.row) {
        throw ArrayException("Matrix * Matrix: wrong sizes");
    }
    std::vector<std::vector<float>> vectmp;


    float tmpsum = 0;

    for (int i = 0; i < tmp1.row; i++) {
        std::vector<float> temp;
        vectmp.push_back(temp);
        for (int j = 0; j < tmp2.column; j++) {

            for (int k = 0; k < tmp1.column; k++) 
                    tmpsum += tmp1.matrix[i][k] * tmp2.matrix[k][j];
            vectmp[i].push_back(tmpsum);
            tmpsum = 0;
        }
    }
    return Matrix(vectmp);
}

Matrix operator*(const Matrix& tmp, int num) {
    std::vector<std::vector<float>> tmpvec;

    for (int i = 0; i < tmp.row; i++) {
        std::vector<float> temp;
        tmpvec.push_back(temp);
        for (int j = 0; j < tmp.column; j++) {
            tmpvec[i].push_back(tmp.matrix[i][j] * num);
        }
    }
    return Matrix(tmpvec);
}


std::ostream& operator<<(std::ostream& out, const Matrix& mtr){
    for (int i = 0;i < mtr.row;i++) {
        for (int j = 0;j < mtr.column - 1;j++) 
            out << mtr.matrix[i][j] << std::setfill(' ') << std::setw(10);
        out << mtr.matrix[i][mtr.column - 1];
        out << std::endl;
    }
    return out;
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
            vectmp[i].push_back(tmp1.matrix[i][j] * tmp2.matrix[i][j]);
        }
    }

    return Matrix(vectmp);
}

class one : public Matrix 
{
public:
    one(int a) {
        row = a;
        column = a;

        for (int i = 0; i < a; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < a; j++) {
                if (i == j) 
                    matrix[i].push_back(1);
                else 
                    matrix[i].push_back(0);
               
            }
        }
    };

};

class diagonal : public Matrix {
public:
    diagonal(int x) {
        row = x;
        column = x;
        for (int i = 0; i < x; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < x; j++) {
                if (i == j) {
                    float a = (float)(rand() % 1000) / 100;
                    matrix[i].push_back(a);
                }
                else {
                    matrix[i].push_back(0);
                }
            }
        }

    };

};


class upper : public Matrix {
public:
    upper(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < c; j++) {
                if (j >= i) {
                    float a = (float)(rand() % 1000) / 100;
                    matrix[i].push_back(a);
                }
                else {
                    matrix[i].push_back(0);
                }
            }
        }
    };
};

class lower : public Matrix {
public:
    lower(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < c; j++) {
                if (i >= j) {
                    float a = (float)(rand() % 1000) / 100;
                    matrix[i].push_back(a);
                }
                else {
                    matrix[i].push_back(0);
                }
            }
        }
    };
};


class symetric : public Matrix {
public:
    symetric(int c) {
        row = c;
        column = c;
        for (int i = 0; i < c; i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            for (int j = 0; j < c; j++) {
                if (j >= i) {
                    float a = (float)(rand() % 1000) / 100;
                    matrix[i].push_back(a);
                }
                else {
                    matrix[i].push_back(this->matrix[j][i]); 
                }
            }
        }
    };
};

class Vector : public Matrix {
public:
    Vector() { row = 0, column = 0; };
    Vector(std::vector<float> vector) {
        row = vector.size();
        column = 1;

        for (int i = 0; i < vector.size(); i++) {
            std::vector<float> tmp;
            matrix.push_back(tmp);
            matrix[i].push_back(vector[i]);
        }

    }


    float evklidnorm() {
        return sqrt(*this * *this);
    }

    float maxnorm() {
        float max = 0;
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->column; j++) {
                if (abs(this->matrix[i][j]) > max) {
                    max = abs(this->matrix[i][j]);
                }
            }
        }
        return max;
    }
    friend float operator*(const Vector& tmp1, const Vector& tmp2);
    friend float angle(Vector& v1, Vector& v2);
};

float operator*(const Vector& tmp1, const Vector& tmp2) {
    if (tmp1.row != tmp2.row) {
        throw ArrayException("vector * vector: wrong sizes");
    }

    float sum = 0;

    for (int i = 0; i < tmp1.row; i++) {
        sum += tmp1.matrix[i][0] * tmp2.matrix[i][0];
    }

    return sum;

}

float angle(Vector& v1, Vector& v2) {

    return  acos((v1 * v2) / (v1.evklidnorm() * v2.evklidnorm()));

}
