
// Basic Data Types
// Home-study problem.
// Duration 60 minutes
 
// Please return the solution via email within an hour of receipt of this request arriving in your email box.  
 
// Please implement this in one of C or C++.
 
// The following are not good answers:
// 1. copied solutions from the internet/textbook 
// 2. simply call STL functions 
 
// Exercise to Do: 
// Implement an object that has methods called ‘Push’ and ‘Pop’. 
// This object should be able to handle having integer values
// passed to Push and should be able to return integer value from Pop in stack order
// (i.e. Last in First out - LIFO).
 
// Now implement an object or extend the previous object to implement methods
// called ‘Queue’ and ‘Dequeue’. This object should also be able to handle integer values
// passed to Queue and should be able to return integer values from Dequeue in queue order
// (i.e. First In, First Out - FIFO).
 
#include <cassert>

class MyLifo {
    public:
        MyLifo(unsigned int size)
            : _size(size), _index(0), _stack(new int[size])
        {
        }

        ~MyLifo()
        {
            delete _stack;
        }

        // returns 1 if success, 0 if cannot push anymore values onto LIFO
        int Push(int value)
        {
            int resp = 0;
            if( _index >= 0 && _index <= _size-1 ) {
                _stack[_index] = value;
                _index++;
                resp = 1;
            }
            return resp;
        }

        // returns next int value in LIFO order
        // or a null terminating character '\0' if nothing left in LIFO
        int Pop()
        {
            int resp = '\0';
            if( _index >= 0 && _index < _size-1 ) {
                resp = _stack[_index];
                _index--;
            }
            return resp;
        }

    private:
        const unsigned int _size;
        unsigned int _index;
        int * const _stack;

};

class MyFifo {
public:
    MyFifo(unsigned int size)
        : _size(size), _head(0), _tail(0), _stack(new int[size])
    {
    }

    ~MyFifo()
    {
        delete _stack;
    }

    // returns 1 if success, 0 if cannot push anymore values onto FIFO
    int Queue(int value)
    {
        _stack[_tail] = value;
        _tail++;
        if( _tail >= _size-1 ) {
            _tail = 0;
        }
        return 1;
    }

    // returns next int value in FIFO order
    // or a null terminating character '\0' if nothing left in FIFO
    int Dequeue()
    {
        int resp = _stack[_head];
        _head++;
        if( _head >= _size-1 ) {
            _head = 0;
        }
        return 1;
    }


private:
    const unsigned int _size;
    unsigned int _head, _tail;
    int * const _stack;

};

int main() {
    MyFifo my_fifo(3);
    MyLifo my_lifo(3);

    assert( my_lifo.Push(3) == 1 );
    assert( my_lifo.Push(5) == 1 );
    assert( my_lifo.Push(7) == 1 );
    assert( my_lifo.Push(1) == 0 );

    int value = my_lifo.Pop();
    assert( value == 7 );
    assert( my_lifo.Pop() == 5 );
    assert( my_lifo.Pop() == 3 );
    assert( my_lifo.Pop() == '\0' );

    assert( my_fifo.Queue(2) == 1 );
    assert( my_fifo.Queue(4) == 1 );
    assert( my_fifo.Queue(6) == 1 );
    assert( my_fifo.Queue(8) == 0 );

    assert( my_fifo.Dequeue() == 2 );
    assert( my_fifo.Dequeue() == 4 );
    assert( my_fifo.Dequeue() == 6 );
    assert( my_fifo.Dequeue() == '\0' );

    return 0;
}