#include <iostream>
#include <list>
#include <stdexcept>
 
template < typename T, typename Container = std::list<T> >
class Stack
{
    private:
        Container container_;
 
    public:
        explicit Stack(const Container& container = Container())
            : container_(container)
        {
        }
 
        void push(const T& item)
        {
            container_.push_back(item);
        }
 
        void pop()
        {
            if( container_.empty() ) throw std::underflow_error("Error: stack is empty.");
            container_.pop_back();
        }
 
        T& top()
        {
            if( container_.empty() ) throw std::underflow_error("Error: stack is empty.");            
            return container_.back();
        }
 
        const T& top() const
        {
            if( container_.empty() ) throw std::underflow_error("Error: stack is empty.");
            return container_.back();
        }
 
        bool empty() const
        {
            return container_.empty();
        }
};
 
int main()
{
    try
    {
        Stack<int> s;
        for(int i = 0; i < 10; ++i)
            s.push(i);
 
        while( !s.empty() )
        {
            std::cout << s.top() << ' ';
            s.pop();
        }
        s.pop();
    }
    catch(std::underflow_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Stack<double> s;
        double d = 0.1;
        for(int i = 0; i < 10; ++i) {
            d = d + i;
            s.push(d);
        }
 
        while( !s.empty() )
        {
            std::cout << s.top() << ' ';
            s.pop();
        }
        s.pop();
    }
    catch(std::underflow_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Stack<std::string> s;
        std::string s1 = "abc";
        std::string s2 = "ABC";
        std::string s3 = "123";
        std::string s4 = "Hello, World!";
        s.push(s1);
        s.push(s2);
        s.push(s3);
        s.push(s4);
        while( !s.empty() )
        {
            std::cout << s.top() << ' ';
            s.pop();
        }
        s.pop();
    }
    catch(std::underflow_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}