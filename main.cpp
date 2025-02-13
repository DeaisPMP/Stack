#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>

#if 0
#define __DEBUG__
#endif

template<typename T>
class Stack
{
    struct List
    {
        List* next;
        List* prev;
        List* up;
        T     val;
        List()
        : next(nullptr), prev(nullptr), up(nullptr)
        {}
    };
    List*  head;
    std::unordered_map<T, List*> hash;
public:
    Stack()
    : head(nullptr)
    {
        
    }
    ~Stack()
    {
        
    }
    void push(const T& v)
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
            while(l->up)
                l = l->up;
            l->up = head;
        }
    }
    void pop_f()
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
    }
    T top()
    {
        if(head == nullptr)
            throw "Stack is empty!";
        return head->val;
    }
#ifdef __DEBUG__
    void Print()
    {
        List* buf = head;
        while(buf)
        {
            std::cout << buf->val << " ";
            buf = buf->prev;
        }
        std::cout << std::endl;
    }
#endif
};

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
    
    Stack<int> s;
    
    /*
    s.push(5);
    s.Print();
    s.push(3);
    s.Print();
    s.push(2);
    s.Print();
    s.pop_f();
    s.Print();
    s.push(5);
    s.Print();
    s.pop_f();
    s.Print();
    */
    
    /*
    s.push(5);
    s.Print();
    s.pop_f();
    s.Print();
    */
    
#ifdef __DEBUG__
    s.push(5);
    s.Print();
    s.push(1);
    s.Print();
    s.push(3);
    s.Print();
    s.push(5);
    s.Print();
    s.push(4);
    s.Print();
    s.push(6);
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.push(5);
    s.Print();
    s.push(8);
    s.Print();
    s.push(5);
    s.Print();
    s.push(4);
    s.Print();
    s.push(3);
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
    s.pop_f();
    s.Print();
#endif
    
    
    return (0);
}
