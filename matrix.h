#ifndef MATRIX_H
#define MATRIX_H

template <typename Type>
class Matrix
{
private:
    Type **data_{nullptr};
    unsigned height_;
    unsigned width_;
    Matrix<Type>& operator=(Matrix<Type> const& matrix);
public:
    Matrix(){}
    Matrix(unsigned height, unsigned width):height_(height),width_(width)
    {
        data_ = new Type *[height];
        for(unsigned i=0; i<height ; i++)
        {
            data_[i] = new Type [width];
        }
    }
    Matrix(const Matrix &matrix):height_(matrix.height()),width_(matrix.width())
    {
        data_ = new Type *[matrix.height()];
        for(unsigned i=0; i<matrix.height() ; i++)
        {
            data_[i] = new Type [matrix.width()];
        }
        for(unsigned h=0; h<height() ; h++)
        {
            for(unsigned w=0; w<width() ; w++)
            {
                data_[h][w]=matrix.data_[h][w];
            }
        }
    }

    unsigned width() const
    {
        return width_;
    }
    unsigned height() const
    {
        return height_;
    }

    Type *operator[](unsigned index)
    {
        return data_[index];
    }
    Type const *operator [](unsigned index) const
    {
        return data_[index];
    }

    ~Matrix()
    {
        for(unsigned i=0;i<height_; i++)
        {
            delete[]data_[i];
        }
        delete[]data_;
    }
};

#endif // MATRIX_H
