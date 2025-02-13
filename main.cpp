#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <gtest/gtest.h>

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
    void pop()
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
            return T();
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

TEST(Stack, Top)
{
    Stack<int> s;
    
    EXPECT_EQ(int(), s.top());
}

TEST(Stack, PopE)
{
    Stack<int> s;
    s.pop();
}

TEST(Stack, Push)
{
    Stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    EXPECT_EQ(7, s.top());
}

TEST(Stack, Pop)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    EXPECT_EQ(2, s.top());
}

TEST(Stack, PopDeq)
{
    Stack<int> s;
    s.push(5);
    s.push(3);
    s.push(2);
    s.pop();
    EXPECT_EQ(3, s.top());
    s.push(5);
    s.pop();
    EXPECT_EQ(5, s.top());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
