#include <iostream>
#include <map>

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
    std::map<T, int> depth;
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
            depth[v]++;
            return;
        }
        head->next = new List();
        head->next->prev = head;
        head->next->val = v;
        head = head->next;
        depth[v]++;
    }
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
    s.pop();
    s.Print();
    s.push(5);
    s.Print();
    s.pop();
    s.Print();
    */
    
    /*
    s.push(5);
    s.Print();
    s.pop();
    s.Print();
    */
    
    /*
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
    s.pop();
    s.Print();
    s.pop();
    s.Print();
    s.pop();
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
    s.pop();
    s.Print();
    s.pop();
    s.Print();
    s.pop();
    s.Print();
    s.pop();
    s.Print();
    */
    return (0);
}
