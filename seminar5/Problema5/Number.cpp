#include "Number.h"

Number::Number(const char* val, int b) :base_(b) {

	this->value_ = new char[strlen(val) + 1];
	strcpy(value_, val);
	digitsCount_ = 0;
	int len = strlen(val);
	for (auto i = 0; i < len; i++) {
		char c = val[i];
		int digit = (c >= 'A' && c <= 'F') ? (c - 'A' + 10) : (c - '0');
		if (digit >= b) {
			cout << "Invalid digit for base " << b << '\n';
			this->value_[0] = '0';
			this->value_[1] = NULL;
			return;
		}
		digitsCount_++;
	}

}



Number::~Number() {
	delete[] this->value_;
}


// copy constructor
Number::Number(const Number& other) {

    base_ = other.base_;
    digitsCount_ = other.digitsCount_;
    value_ = new char[digitsCount_];
    strncpy(value_, other.value_, digitsCount_);

}

// move constructor
Number::Number(Number&& other) {

    base_ = other.base_;
    digitsCount_ = other.digitsCount_;
    value_ = other.value_;
    other.value_ = nullptr;
    other.digitsCount_ = 0;

}

// copy assignment operator
Number& Number::operator=(const Number& other) {

    if (this != &other) {
        delete[] value_;
        value_ = new char[other.digitsCount_];
        copy(other.value_, other.value_ + other.digitsCount_, value_);
        base_ = other.base_;
        digitsCount_ = other.digitsCount_;
    }
    return *this;

}

// move assignment operator
Number& Number::operator=(Number&& other) {

    if (this != &other) {
        delete[] value_;
        value_ = other.value_;
        base_ = other.base_;
        digitsCount_ = other.digitsCount_;
        other.value_ = nullptr;
        other.base_ = 0;
        other.digitsCount_ = 0;
    }
    return *this;


}

// addition operator
Number operator+(const Number& a, const Number& b) {

    int base = max(a.base_, b.base_);
    char* result = new char[max(a.digitsCount_, b.digitsCount_) + 2];
    int carry = 0;

    int i = a.digitsCount_ - 1;
    int j = b.digitsCount_ - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry > 0) {

        int sum = carry;

        if (i >= 0) {

            sum += (a.value_[i] >= 'A' && a.value_[i] <= 'F') ? a.value_[i] - 'A' + 10 : a.value_[i] - '0';
            i--;

        }

        if (j >= 0) {

            sum += (b.value_[j] >= 'A' && b.value_[j] <= 'F') ? b.value_[j] - 'A' + 10 : b.value_[j] - '0';
            j--;

        }

        result[k] = (sum % base < 10) ? sum % base + '0' : sum % base - 10 + 'A';

        carry = sum / base;

        k++;

    }

    result[k] = '\0';
    reverse(result, result + k);

    Number res(result, base);

    delete[] result;

    return res;

}


// operator+=
Number& Number::operator+=(const Number& other) {
    int maxLength = std::max(digitsCount_, other.digitsCount_);
    int carry = 0;
    char* newValue = new char[maxLength + 1];
    int i = 0;
    for (; i < maxLength; ++i) {
        int a = i < digitsCount_ ? value_[digitsCount_ - i - 1] - '0' : 0;
        int b = i < other.digitsCount_ ? other.value_[other.digitsCount_ - i - 1] - '0' : 0;
        int sum = a + b + carry;
        carry = sum / base_;
        newValue[i] = sum % base_ + '0';
    }
    if (carry > 0) {
        newValue[i] = carry + '0';
        ++i;
    }
    delete[] value_;
    value_ = new char[i];
    std::copy(newValue, newValue + i, value_);
    digitsCount_ = i;
    delete[] newValue;
    return *this;
}

// subtraction operator
Number operator-(const Number& a, const Number& b) {

    int base = max(a.base_, b.base_);
    char* result = new char[max(a.digitsCount_, b.digitsCount_) + 2];
    int borrow = 0;

    int i = a.digitsCount_ - 1;
    int j = b.digitsCount_ - 1;
    int k = 0;

    while (i >= 0 || j >= 0) {

        int diff = borrow;

        if (i >= 0) {

            diff += (a.value_[i] >= 'A' && a.value_[i] <= 'F') ? a.value_[i] - 'A' + 10 : a.value_[i] - '0';
            i--;

        }

        if (j >= 0) {

            diff -= (b.value_[j] >= 'A' && b.value_[j] <= 'F') ? b.value_[j] - 'A' + 10 : b.value_[j] - '0';
            j--;

        }

        if (diff < 0) {

            diff += base;
            borrow = -1;

        }
        else
            borrow = 0;

        result[k] = (diff < 10) ? diff + '0' : diff - 10 + 'A';

        k++;

    }

    while (k > 1 && result[k - 1] == '0')
        k--;

    result[k] = '\0';

    reverse(result, result + k);

    Number res(result, base);

    delete[] result;

    return res;

}

// less than operator
bool Number::operator<(const Number& other) const {
    if (base_ != other.base_) {
        return base_ < other.base_;
    }
    if (digitsCount_ != other.digitsCount_) {
        return digitsCount_ < other.digitsCount_;
    }
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        if (value_[i] != other.value_[i]) {
            return value_[i] < other.value_[i];
        }
    }
    return false;  // The two numbers are equal
}

// greater than operator
bool Number::operator>(const Number& other) const {
    if (base_ != other.base_) {
        return base_ > other.base_;
    }
    if (digitsCount_ != other.digitsCount_) {
        return digitsCount_ > other.digitsCount_;
    }
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        if (value_[i] != other.value_[i]) {
            return value_[i] > other.value_[i];
        }
    }
    return false; // The two numbers are equal
}

// less than or equal to operator
bool Number::operator<=(const Number& other) const {
    if (base_ != other.base_) {
        return base_ < other.base_;
    }
    if (digitsCount_ != other.digitsCount_) {
        return digitsCount_ < other.digitsCount_;
    }
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        if (value_[i] != other.value_[i]) {
            return value_[i] < other.value_[i];
        }
    }
    return true;  // The two numbers are equal or the current object is less than the other object
}

// greater than or equal to operator
bool Number::operator>=(const Number& other)const {
    if (base_ != other.base_) {
        return base_ > other.base_;
    }
    if (digitsCount_ != other.digitsCount_) {
        return digitsCount_ > other.digitsCount_;
    }
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        if (value_[i] != other.value_[i]) {
            return value_[i] > other.value_[i];
        }
    }
    return true; // The two numbers are equal or the current object is greater than the other object
}

// equal to operator
bool Number::operator==(const Number& other) const {
    if (base_ != other.base_ || digitsCount_ != other.digitsCount_) {
        return false;
    }
    for (int i = 0; i < digitsCount_; i++) {
        if (value_[i] != other.value_[i]) {
            return false;
        }
    }
    return true; // The two numbers are equal
}

// not equal to operator
bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

// index operator
char Number::operator[](int index) const {
    if (index < 0 || index >= digitsCount_) {
        return '\0';
    }
    return value_[digitsCount_ - index - 1];
}

// SwitchBase function
void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16) {
        // handle invalid argument here
        return;
    }
    if (base_ == newBase) {
        return;
    }

    // convert to decimal
    int decimalValue = 0;
    int baseMultiplier = 1;
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        decimalValue += baseMultiplier * (value_[i] - '0');
        baseMultiplier *= base_;
    }

    // convert to new base
    delete[] value_;
    base_ = newBase;
    value_ = new char[MAX_DIGITS + 1];
    int index = 0;
    while (decimalValue > 0) {
        value_[index] = decimalValue % newBase + '0';
        decimalValue /= newBase;
        index++;
    }
    value_[index] = '\0';
    digitsCount_ = index;
    reverse(value_, value_ + digitsCount_);
}

// Print function
void Number::Print()
{
    for (int i = 0; i < digitsCount_; i++) {
        cout << value_[i];
    }
    cout << endl;
}

// GetDigitsCount function
int Number::GetDigitsCount()const
{
    return digitsCount_;
}

// GetBase function
int Number::GetBase()const
{
    return base_;
}

//operator prefixare
Number Number::operator--(int) {
    Number temp(*this);
    --(*this);
    return temp;
}

//oparator postifixare
Number& Number::operator--() {
    if (digitsCount_ == 1 && value_[0] == '0') return *this; // Can't decrement 0
    int carry = -1;
    for (int i = digitsCount_ - 1; i >= 0; i--) {
        int digit = value_[i] - '0' + carry;
        if (digit < 0) {
            digit += base_;
            carry = -1;
        }
        else carry = 0;
        value_[i] = digit + '0';
        if (digit != 0) break; // No need to continue if there's no carry left
    }
    // Remove leading zeros
    int i = 0;
    while (i < digitsCount_ && value_[i] == '0') i++;
    if (i == digitsCount_) {
        // Result is 0, adjust the digits count and set the value to "0"
        digitsCount_ = 1;
        value_[0] = '0';
    }
    else {
        digitsCount_ -= i;
        memmove(value_, value_ + i, digitsCount_ + 1); // +1 for the null terminator
    }
    return *this;
}