#include <unordered_map>
#include <stdexcept>

template<typename T>
class Stack
{
    struct List
    {
        List* next;
        List* prev;
        List* up;
        List* hd;
        T     val;
        List()
        : next(nullptr), prev(nullptr), up(nullptr), hd(nullptr)
        {}
    };
    List*  head;
    std::unordered_map<T, List*> hash;
public:
    Stack();
    ~Stack() = default;
    void push(const T& v);
    void pop();
    T top();
};

template<typename T>
Stack<T>::Stack()
    : head(nullptr)
{}

template<typename T>
void Stack<T>::push(const T& v)
{
    if(head == nullptr)
    {
        head = new List();
        head->val = v;
        hash[v] = head;
        return;
    }
    head->next = new List();
    head->next->prev = head;
    head->next->val = v;
    head = head->next;
    auto f = hash.find(v);
    if(f == hash.end())
        hash[v] = head;
    else
    {
        auto l = f->second;
        if(l->up == nullptr)
        {
            l->up = head;
            l->hd = head;
        }
        else
        {
            l->hd->up = head;
            l->hd = head;
        }
    }
}

template<typename T>
void Stack<T>::pop()
{
    if(head)
    {
        auto s = hash[head->val];
        if(s->up)
        {
            hash[head->val] = s->up;
            if(s->prev) //s!=tail
            {
                s->prev->next = s->next;
                s->next->prev = s->prev;
            }
            else
                s->next->prev = nullptr;
            delete s;
            s = nullptr;
        }
        else
        {
            if(head->prev)
            {
                hash.erase(s->val);
                head = head->prev;
                delete head->next;
                head->next = nullptr;
            }
            else
            {
                delete head;
                head = nullptr;
                hash.clear();
            }
        }
    }
    else
        throw std::logic_error("Cannot pop() from empty stack!");
}

template<typename T>
T Stack<T>::top()
{
    if(head)
        return head->val;
    else
        throw std::logic_error("Cannot top() from empty stack!");
}
