#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>

#ifndef __DEBUG__
#define __DEBUG__
#endif

template<typename T>
class Stack
{
    struct List
    {
        List* next;
        List* prev;
        T     val;
        List()
        : next(nullptr), prev(nullptr)
        {}
    };
    List*  head;
    List*  tail;
#ifdef __OLD__
    std::map<T, int> depth;
#endif
    //std::map<T, std::queue<List*>> hash;
    std::unordered_map<T, std::queue<List*>> hash;
public:
    Stack()
    : head(nullptr), tail(nullptr)
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
            tail = head;
#ifdef __OLD__
            depth[v]++;
#endif
            hash[v].push(head);
            return;
        }
        head->next = new List();
        head->next->prev = head;
        head->next->val = v;
        head = head->next;
#ifdef __OLD__
        depth[v]++;
#endif
        hash[v].push(head);
    }
    void pop_f()
    {
        if(head)
        {
            auto& s = hash[head->val];
            if(s.size() > 1)
            {
                auto del = s.front();
                if(del != tail)
                {
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                }
                else
                {
                    tail = del->next;
                    tail->prev = nullptr;
                }
                delete del;
                del = nullptr;
                s.pop();
            }
            else
            {
                if(head->prev)
                {
                    head = head->prev;
                    delete head->next;
                    head->next = nullptr;
                }
                else
                {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                s.pop();
            }
        }
    }
#ifdef __OLD__
    void pop()
    {
        if(head)
        {
            int v = depth[head->val];
            if(v > 1)
            {
                depth[head->val]--;
                List* t_buf = tail;
                while(t_buf)
                {
                    if(t_buf->val == head->val)
                    {
                        if(t_buf != tail)
                        {
                            t_buf->prev->next = t_buf->next;
                            t_buf->next->prev = t_buf->prev;
                            delete t_buf;
                        }
                        else
                        {
                            tail = t_buf->next;
                            delete tail->prev;
                            tail->prev = nullptr;
                        }
                        break;
                    }
                    t_buf = t_buf->next;
                }
            }
            else
            {
                depth.erase(head->val);
                if(head->prev)
                {
                    head = head->prev;
                    delete head->next;
                    head->next = nullptr;
                }
                else
                {
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
            }
        }
    }
#endif
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
    s.pop();
    s.Print();
    */
    
    
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
    
    return (0);
}
