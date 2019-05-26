#include <iostream>
#include <string>
using namespace std;

class BigInteger;
 
// operators overloading
BigInteger operator+(const BigInteger& left, const BigInteger& right);
BigInteger operator-(const BigInteger& left, const BigInteger& right);
ostream& operator<<(ostream& out, const BigInteger& Bint);
 
class BigInteger {
public:
    BigInteger();
    explicit BigInteger(const string& number);
    BigInteger(const BigInteger& other);
    friend BigInteger operator+(const BigInteger& left,
                                const BigInteger& right);
    
    // promise left >= right
    friend BigInteger operator-(const BigInteger& left,
                                const BigInteger& right);
    friend ostream& operator<<(ostream& out, const BigInteger& Bint);
    ~BigInteger();
    BigInteger& operator=(const BigInteger& other){
        if(data_ != NULL)
            delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for(int i=0; i<size_; i++)
            data_[i] = other.data_[i];
    }
    BigInteger& operator=(int num){
        if(data_ != NULL)
            delete[] data_;
        if(num < 10){
            size_ = 1;
            data_ = new int[size_];
            data_[0] = num;
            return *this;
        }
        size_ = 2;
        data_ = new int[size_];
        data_[1] = num % 10;
        num /= 10;
        data_[0] = num % 10;
        return *this;
    }
 
private:
    int *data_;
    int size_;
};

BigInteger::BigInteger(){
    data_ = NULL;
    size_ = 0;
}
BigInteger::BigInteger(const string& number){
    size_ = number.length();
    data_ = new int[size_];
    for(int i=0; i<size_; i++)
        data_[i] = (int)(number[i]-'0');
}
BigInteger::BigInteger(const BigInteger& other){
    size_ = other.size_;
    data_ = new int[size_];
    for(int i=0; i<size_; i++)
        data_[i] = other.data_[i];
}
BigInteger::~BigInteger(){
    if(data_ != NULL)
        delete[] data_;
}

BigInteger operator+(const BigInteger& left, const BigInteger& right){
    int overflow = 0;
    int temp[100];
    int count = 0;
    int total = 0;
    const BigInteger* short_;
    const BigInteger* long_;
    if(left.size_ >= right.size_){
        short_ = &right;
        long_ = &left;
    }
    else{
        short_ = &left;
        long_ = &right;
    }
    for(int i=0; i<short_->size_; i++){
        total = short_->data_[short_->size_-i-1] + long_->data_[long_->size_-i-1] + overflow;
        if(total>=10){
            overflow = 1;
            temp[count] = total-10;
        }
        else{
            overflow = 0;
            temp[count] = total;
        }
        count++;
    }
    for(int i=short_->size_; i<long_->size_; i++){
        total = long_->data_[long_->size_-i-1] + overflow;
        if(total>=10){
            overflow = 1;
            temp[count] = total-10;
        }
        else{
            overflow = 0;
            temp[count] = total;
        }
        count++;
    }
    if(overflow == 1){
        temp[count] = 1;
        count++;
    }
    BigInteger total_;
    total_.size_ = count;
    total_.data_ = new int[total_.size_];
    for(int i=0; i<count; i++)
        total_.data_[i] = temp[count-i-1];
    return total_;
}
BigInteger operator-(const BigInteger& left, const BigInteger& right){
    int underflow = 0;
    int temp[100];
    int count = 0;
    int total = 0;
    for(int i=0; i<right.size_; i++){
        total = left.data_[left.size_-i-1] - right.data_[right.size_-i-1] - underflow;
        if(total<0){
            underflow = 1;
            temp[count] = total + 10;
        }
        else{
            underflow = 0;
            temp[count] = total;
        }
        count++;
    }
    for(int i=right.size_; i<left.size_-1; i++){
        total = left.data_[left.size_-i-1] - underflow;
        if(total<0){
            underflow = 1;
            temp[count] = total + 10;
        }
        else{
            underflow = 0;
            temp[count] = total;
        }
        count++;
    }
    total = left.data_[0] - underflow;
    if(total > 0){
        temp[count] = total;
        count++;
    }
    BigInteger total_;
    total_.size_ = count;
    total_.data_ = new int[total_.size_];
    for(int i=0; i<count; i++)
        total_.data_[i] = temp[count-i-1];
    return total_;
}
ostream& operator<<(ostream& out, const BigInteger& Bint){
    for(int i=0; i<Bint.size_; i++)
        out << Bint.data_[i];
    return out;
}

int main(){
    int m, n;
    while (cin >> m >> n){
        BigInteger temp[n+1];
        if(n == 0 || m == 0)
            break;
        if(n <= m){
            cout << n+1 << endl;
            continue;
        }
        for(int i=0; i<m; i++)
            temp[i] = i+1;
        for(int i=m; i<n+1; i++)
            temp[i] = temp[i-1] + temp[i-m];
        cout << temp[n] << endl;
    }
    system("pause");
    return 0;
}