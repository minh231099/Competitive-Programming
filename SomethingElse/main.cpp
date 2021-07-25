#include <iostream>
#include <vector>
using namespace std;

template <class T>
class SimpleVector {
    protected:
        T* arr;
        int cur;

    public:
        SimpleVector() {
            arr = new T[1];
            cur = 1;
        }

        void push_back (T data) {
            T *temp = new T[cur];
            for (int i = 0; i < cur - 1; i++)
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            arr[cur - 1] = data;
            cur++;
        }

        void pop() {
            cur--;
        }
        
        int size() {
            return cur - 1;
        }

        T get (int index) {
            if (index < cur)
                return arr[index];
        }
};

template <class T>
class SortableVector : public SimpleVector<T> {
    public:
        void Sort() {
            int len = this->cur - 1;
            for (int i = 0; i < len - 1; ++i) {
                for (int j = i + 1; j < len; ++j) {
                    if (this->arr[i] > this->arr[j]) {
                        T t = this->arr[i];
                        this->arr[i] = this->arr[j];
                        this->arr[j] = t;
                    }
                }
            }
        }
};

int main() {
    SortableVector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    cout << arr.get(2) << endl;
    arr.Sort();
    for (int i = 0; i < arr.size(); ++i)
        cout << arr.get(i) << " ";
    cout << endl;
    return 0;
}