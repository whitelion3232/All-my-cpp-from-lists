#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Book class to store book information
class Book {
private:
    std::string title;
    std::string author;
    int publicationYear;
    int numPages;

public:
    Book(const std::string& t, const std::string& a, int year, int pages)
        : title(t), author(a), publicationYear(year), numPages(pages) {}

    // Getters for book information
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    int getNumPages() const { return numPages; }

    // Function to display book information
    void displayInfo() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nPublication Year: "
            << publicationYear << "\nNumber of Pages: " << numPages << std::endl;
    }
};

// Library class to manage the collection of books
class Library {
private:
    std::vector<Book> books;

public:
    // Function to add a new book to the collection
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to display all books in the collection
    void displayAllBooks() const {
        for (const auto& book : books) {
            book.displayInfo();
            std::cout << "-------------------------" << std::endl;
        }
    }

    // Function to search for books based on title, author, or publication year
    void searchBooks(const std::string& keyword) const {
        for (const auto& book : books) {
            if (book.getTitle().find(keyword) != std::string::npos ||
                book.getAuthor().find(keyword) != std::string::npos ||
                std::to_string(book.getPublicationYear()).find(keyword) != std::string::npos) {
                book.displayInfo();
                std::cout << "-------------------------" << std::endl;
            }
        }
    }

    // Function to remove a book from the collection
    void removeBook(const std::string& title) {
        books.erase(std::remove_if(books.begin(), books.end(),
            [&title](const Book& book) { return book.getTitle() == title; }),
            books.end());
    }

    // Function to get statistics about the collection
    void displayStatistics() const {
        int totalBooks = books.size();
        int totalNumPages = 0;

        for (const auto& book : books) {
            totalNumPages += book.getNumPages();
        }

        std::cout << "Total number of books: " << totalBooks << std::endl;
        if (totalBooks > 0) {
            double averagePages = static_cast<double>(totalNumPages) / totalBooks;
            std::cout << "Average number of pages per book: " << averagePages << std::endl;
        }
    }

    // Function for file I/O to save and load book collection
    void saveBooksToFile(const std::string& filename) const {
        std::ofstream file(filename);

        if (file.is_open()) {
            for (const auto& book : books) {
                file << book.getTitle() << "," << book.getAuthor() << ","
                    << book.getPublicationYear() << "," << book.getNumPages() << "\n";
            }
            file.close();
            std::cout << "Books saved to file." << std::endl;
        }
        else {
            std::cerr << "Unable to open file for saving." << std::endl;
        }
    }

    void loadBooksFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string title, author;
                int year, pages;
                if (std::getline(ss, title, ',') && std::getline(ss, author, ',') &&
                    (ss >> year) && (ss.ignore() && (ss >> pages))) {
                    addBook(Book(title, author, year, pages));
                }
            }
            file.close();
            std::cout << "Books loaded from file." << std::endl;
        }
        else {
            std::cerr << "Unable to open file for loading." << std::endl;
        }
    }
};

int main() {
    Library library;

    // Sample books
    Book book1("The Catcher in the Rye", "J.D. Salinger", 1951, 224);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960, 281);
    Book book3("1984", "George Orwell", 1949, 328);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    int choice;
    std::string keyword, title;
    std::string filename = "books.txt";

    do {
        std::cout << "\nMenu:\n1. Add Book\n2. Display All Books\n3. Search Books\n"
            << "4. Remove Book\n5. Display Statistics\n6. Save Books to File\n"
            << "7. Load Books from File\n8. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Add Book
            std::string newTitle, newAuthor;
            int newYear, newPages;
            std::cin.ignore(); // Clear input buffer
            std::cout << "Enter Title: ";
            std::getline(std::cin, newTitle);
            std::cout << "Enter Author: ";
            std::getline(std::cin, newAuthor);
            std::cout << "Enter Publication Year: ";
            std::cin >> newYear;
            std::cout << "Enter Number of Pages: ";
            std::cin >> newPages;
            library.addBook(Book(newTitle, newAuthor, newYear, newPages));
            break;

        case 2:
            // Display All Books
            library.displayAllBooks();
            break;

        case 3:
            // Search Books
            std::cout << "Enter keyword to search: ";
            std::cin >> keyword;
            library.searchBooks(keyword);
            break;

        case 4:
            // Remove Book
            std::cout << "Enter the title of the book to remove: ";
            std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, title);
            library.removeBook(title);
            break;

        case 5:
            // Display Statistics
            library.displayStatistics();
            break;

        case 6:
            // Save Books to File
            library.saveBooksToFile(filename);
            break;

        case 7:
            // Load Books from File
            library.loadBooksFromFile(filename);
            break;

        case 8:
            // Exit
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}