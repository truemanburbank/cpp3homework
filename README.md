# 템플릿을 활용하여 `vector` 구현하기

## 기본

- 클래스의 이름은 SimpleVector라고 합니다.
- 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
- 생성자는 아래와 같이 구현 합니다.
    - 기본 생성자는 크기가 10인 배열을 만듭니다.
    - 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
- 아래와 같은 멤버함수를 구현 합니다.
    - push_back  인자로 받은 원소를  맨 뒤에 추가 합니다. 반환값은 없습니다. 배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
    - pop_back은 벡터의 마지막 원소를 제거 합니다. 만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
    - size는 인자가 없고 현재 원소의 개수를 반환합니다.
    - capacity 현재 내부 배열의 크기를 반환합니다.

구현을 한 뒤에 클래스의 구조는 아래와 같습니다.

![image](https://github.com/user-attachments/assets/96b06463-d4bb-4872-9779-f688f32edaef)


# 코드

```cpp
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

```

# 결과

![image](https://github.com/user-attachments/assets/707be9e3-5d00-4338-bbc1-fffe5130acac)
