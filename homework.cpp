#include <algorithm>
#include <iostream>

template<typename T>
class SimpleVector
{
    T* data;
    int currentSize; // 현재 원소의 개수
    int currentCapacity; // 용량
    
    void resize(int n)
    {
        if (n < currentCapacity) return;
        
        SimpleVector newVector(currentCapacity + n);
        for (int i = 0; i < currentSize; i++)
        {
            newVector.push_back(data[i]);
        }
        delete[] data;
        data = newVector.data;
    }
public:

    T operator[](int index)
    {
        // 예외 처리
        if (index < 0 || index > currentSize)
        {
            std::cout << "Array index out of bounds exception\n" << '\n';
            exit(1);
        }
        return data[index];
    }
    
    SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity)
    {
        data = new T[capacity];
    }

    ~SimpleVector()
    {
        delete[] data;
    }

    void push_back(const T& value)
    {
        if (currentSize - 1 < currentCapacity)
            data[currentSize++] = value;
        else
        {
            resize(currentCapacity + 5);
            data[currentSize++] = value;
        }
    }

    void pop_back()
    {
        if (currentSize > 0)
            currentSize--;
    }

    int size() const
    {
        return currentSize;
    }

    int capacity() const
    {
        return currentCapacity;
    }

    void sortData()
    {
        std::sort(data, data + currentSize);
    }
};

int main()
{
    // 기본 생성자
    SimpleVector<int> v1;

    // 용량을 받는 생성자
    SimpleVector<int> v2(3);

    // push_back
    std::cout << "v1에 push_back()을 합니다. 1, 4를 push" << '\n';
    v1.push_back(1);
    v1.push_back(4);

    std::cout << "v1[0] = " << v1[0] << '\n';
    std::cout << "v1[1] = " << v1[1] << '\n';

    std::cout << '\n';

    std::cout << "v2에 push_back()을 합니다. 0, 1, 2를 push" << '\n';
    for (int i = 0; i < 3; i++)
    {
        v2.push_back(i);
        std::cout << "v2[" << i << "] = " << v2[i] << '\n';
    }

    std::cout << '\n';
    
    // pop_back
    std::cout << "v1을 pop_back()하고 size()를 실행시킵니다." << '\n';
    std::cout << "pop_back() 전" << '\n';
    std::cout << "v1.size() = " << v1.size() << '\n';
    v1.pop_back();
    std::cout << "pop_back() 후" << '\n';
    std::cout << "v1.size() = " << v1.size() << '\n';

    std::cout << '\n';
    
    // resize
    std::cout << "꽉찬 v2에 원소를 push 하여 resize()합니다. " << '\n';
    std::cout << " push 전" << '\n';
    std::cout << "v2.size() = " << v2.size() << '\n';
    v2.push_back(99);
    std::cout << " push 후" << '\n';
    std::cout << "v2.size() = " << v2.size() << '\n';

    std::cout << '\n';
    
    // argument exception
    std::cout << "잘못된 인덱스 접근 예외 처리" << '\n';
    std::cout << "DANGER : argument exception" << '\n';
    std::cout << v2[99] << '\n';
}
