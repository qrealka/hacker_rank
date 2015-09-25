#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node* Reverse(Node* head)
{
    Node* reverse = nullptr;

    while(head){
        Node* tmp = head->next;
        head->next = reverse;
        reverse = head;
        head = tmp;
    }

    return reverse;
}

int main() {
    Node two{2, nullptr};
    Node one{1, &two};
    Node root{0, &one};

    auto result = Reverse(nullptr);
    result = Reverse(&root);
    return 0;
}