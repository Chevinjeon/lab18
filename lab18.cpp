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
