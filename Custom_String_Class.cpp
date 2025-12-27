#include <iostream>
#include <cstring>

class MyString {
private:
    char *data;
    size_t len;

public:
    // Default constructor
    MyString() : data(nullptr), len(0) {}

    // Constructor from C-string
    MyString(const char *str) {
        if (str) {
            len = std::strlen(str);
            data = new char[len + 1];
            std::strcpy(data, str);
        } else {
            data = nullptr;
            len = 0;
        }
    }

    // Copy constructor
    MyString(const MyString &other) {
        len = other.len;
        data = new char[len + 1];
        std::strcpy(data, other.data);
    }

    // Move constructor
    MyString(MyString &&other) noexcept {
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }

    // Copy assignment
    MyString& operator=(const MyString &other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Move assignment
    MyString& operator=(MyString &&other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            len = other.len;
            other.data = nullptr;
            other.len = 0;
        }
        return *this;
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Length
    size_t length() const {
        return len;
    }

    // Indexing
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    // Concatenation
    MyString operator+(const MyString &rhs) const {
        MyString temp;
        temp.len = len + rhs.len;
        temp.data = new char[temp.len + 1];
        std::strcpy(temp.data, data);
        std::strcat(temp.data, rhs.data);
        return temp;
    }

    // Append
    MyString& operator+=(const MyString &rhs) {
        char *newData = new char[len + rhs.len + 1];
        std::strcpy(newData, data);
        std::strcat(newData, rhs.data);
        delete[] data;
        data = newData;
        len += rhs.len;
        return *this;
    }

    // Comparison
    bool operator==(const MyString &rhs) const {
        return std::strcmp(data, rhs.data) == 0;
    }

    bool operator<(const MyString &rhs) const {
        return std::strcmp(data, rhs.data) < 0;
    }

    // Substring
    MyString substr(size_t pos, size_t count) const {
        if (pos >= len) return MyString("");
        if (pos + count > len) count = len - pos;

        char *buf = new char[count + 1];
        std::strncpy(buf, data + pos, count);
        buf[count] = '\0';

        MyString result(buf);
        delete[] buf;
        return result;
    }

    // C-string access
    const char* c_str() const {
        return data;
    }

};

// Demo
int main() {
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1 + s2;

    std::cout << s3 << std::endl;
    std::cout << "Length: " << s3.length() << std::endl;

    MyString sub = s3.substr(6, 5);
    std::cout << "Substring: " << sub << std::endl;

    return 0;
}
