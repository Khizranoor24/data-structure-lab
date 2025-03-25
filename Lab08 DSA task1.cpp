#include <iostream>
using namespace std;

class Book {
public:
    string title;
    double price;
    int edition;
    int pages;
    Book* next;
};

class BookStack {
private:
    Book* top;

public:
    BookStack() {
        top = NULL;
    }

   
    void push(string title, double price, int edition, int pages) {
        Book* newBook = new Book();
        newBook->title = title;
        newBook->price = price;
        newBook->edition = edition;
        newBook->pages = pages;
        newBook->next = top;
        top = newBook;
        cout << "Book pushed: " << title << endl;
    }

  
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty! No book to pop.\n";
            return;
        }
        Book* temp = top;
        cout << "Popped book: " << top->title << endl;
        top = top->next;
        delete temp;
    }

    
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        cout<< "Top Book: " << top->title <<endl;
		cout<< "Price: " << top->price<<endl;
        cout<< "Edition: " << top->edition <<endl; 
		cout<< "Pages: " << top->pages << endl;
    }

  
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Books in the stack:\n";
        Book* temp = top;
        while (temp != NULL) {
            cout << temp->title<<endl;
			cout << "  Price: " << temp->price<<endl;
            cout << "  Edition: " << temp->edition <<endl; 
			cout << "  Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BookStack stack;


    stack.push("Book A", 500.0, 1, 300);
    stack.push("Book B", 600.0, 2, 350);
    stack.push("Book C", 700.0, 3, 400);
    stack.push("Book D", 800.0, 4, 450);
    stack.push("Book E", 900.0, 5, 500);

    
    stack.pop();
    stack.pop();

    cout << "Remaining books in the stack:";
    stack.display();

    return 0;
}

