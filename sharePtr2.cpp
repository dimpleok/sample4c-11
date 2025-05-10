#include <iostream>
#include <string>
#include <memory>
#include <vector>
 
template <class T>
struct Node {
    T value;
    std::shared_ptr<struct Node> next;
    Node(const T& v, std::shared_ptr<struct Node> p) : value(v), next(p) {
    }
    ~Node() {
        std::cout << "destructor" << std::endl;
    }
};

template <class T>
std::shared_ptr<Node<T>> makeLink(const std::vector<T>& v)
{
    std::shared_ptr<Node<T>> head, lastNode; 
    for (auto e : v) {
        std::shared_ptr<Node<T>> pNode = std::make_shared<Node<T>>(e, nullptr);
        if (lastNode != nullptr) {
            lastNode->next =  pNode;
            lastNode = pNode;
        } else {
           head = lastNode = pNode;
        }
    }
    return head;
}

int main()
{
    std::vector<std::string> v;
    v.push_back("hello");
    v.push_back("world");
    v.push_back("man");
    std::shared_ptr<Node<std::string>> head = makeLink(v);
    std::cout << head->next->value << std::endl;
    return 0;
}
