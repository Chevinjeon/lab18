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
    