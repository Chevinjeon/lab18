#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Node structure to store movie review data
struct ReviewNode {
    double rating;
    string comments;
    ReviewNode* next;
    
    // Constructor
    ReviewNode(double r, string c) : rating(r), comments(c), next(nullptr) {}
};

class MovieReviewList {
private:
    ReviewNode* head;
    ReviewNode* tail;
    int count;
    
public:
    // Constructor
    MovieReviewList() : head(nullptr), tail(nullptr), count(0) {}
    
    // Destructor to clean up memory
    ~MovieReviewList() {
        ReviewNode* current = head;
        while (current != nullptr) {
            ReviewNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    // Add node at the head of the linked list
    void addAtHead(double rating, string comments) {
        ReviewNode* newNode = new ReviewNode(rating, comments);
        newNode->next = head;
        head = newNode;
        
        // If this is the first node, it's also the tail
        if (tail == nullptr) {
            tail = newNode;
        }
        count++;
    }
    
    // Add node at the tail of the linked list
    void addAtTail(double rating, string comments) {
        ReviewNode* newNode = new ReviewNode(rating, comments);
        
        if (tail == nullptr) {
            // First node in the list
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    // Display all reviews and calculate average
    void displayReviews() {
        cout << "Outputting all reviews:" << endl;
        
        if (head == nullptr) {
            cout << "No reviews found." << endl;
            return;
        }
        
        ReviewNode* current = head;
        double totalRating = 0.0;
        int reviewNumber = 1;
        
        while (current != nullptr) {
            cout << "    > Review #" << reviewNumber << ": " 
                 << fixed << setprecision(1) << current->rating 
                 << ": " << current->comments << endl;
            
            totalRating += current->rating;
            current = current->next;
            reviewNumber++;
        }
        
        double average = totalRating / count;
        cout << "    > Average: " << fixed << setprecision(5) << average << endl;
    }
    
    // Get the number of reviews
    int getCount() const {
        return count;
    }
};

int main() {
    MovieReviewList reviewList;
    int choice;
    char continueChoice;
    double rating;
    string comments;
    
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice;
    
    // Validate choice
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }
    