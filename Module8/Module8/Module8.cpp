#include <iostream>

class Book
{public:
    Book(std::string title,
        std::string author,
        std::string year,
        const char* ISBN) {
        _title = title;
        _author = author;
        _year = year;
        _ISBN = ISBN;
    }

    Book(const Book& other)
        : _title(other._title),
        _author(other._author),
        _year(other._year),
        _ISBN(other._ISBN)
    {
        std::cout << "copied\n";
    }

    ~Book() {
        std::cout << "deleted\n";
    }

    std::string getTitle() const {
        return _title;
    }
    std::string getAuthor() const {
        return _author;
    }
    std::string getYear() const {
        return _year;
    }
    std::string getISBN() const {
        return _ISBN;
    }

    void printinfo() {
        std::cout << "Name: " << getTitle()
            << ", Author: " << getAuthor()
            << ", Year: " << getYear()
            << ", Serial number: " << getISBN()
            << "\n";
    }

private:
    std::string _title;
    std::string _author;
    std::string _year;
    const char* _ISBN;
};

int main()
{
    std::cout << "Hello World!\n";
    Book DorianGray("The Picture of Doiran Gray", "Oscar Wilde", "1890", "1234567890123");
    Book PictureDorian(DorianGray);
    DorianGray.printinfo();
    PictureDorian.printinfo();
}