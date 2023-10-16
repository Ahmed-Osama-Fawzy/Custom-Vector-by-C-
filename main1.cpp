#include <iostream>
#include <exception>
using namespace std;
template <class t>
class anvector{
    private:
        int capacity = 0 , size = 0 ;
        t *Container;
    public:
        anvector(int cap = 1){
            capacity = cap;
            size = 0;
            Container = new t[capacity];
        }

        ~anvector(){
            delete [] Container;
        }

        t& operator[](int index){
            if(index > size-1){
                cout << "index out of range" << endl;
                exit(-1);
            }
            return Container[index];
        }
        

        void push_back(t item){
            if(size < capacity){
                Container[size++] = item;
            }else{
                cout << "Resizeto " << capacity*2 << endl;
                t* data = new t[capacity*2];
                capacity *= 2;
                for(int i = 0; i < size; i++){
                    data[i] = Container[i];
                }
                delete[] Container;
                Container = data;
                data = nullptr;
                Container[size++] = item;
            }
        }

        t pop_back() {
            try{
                if (empty()){
                    throw exception();
                }
                else{
                    t element = Container[size];
                    size--;
                    return element;
                }
            }
            catch(exception) {
                cout << "vector is empty!\n" << endl;
            }      
        }




        void erase(int iterator) {
            try {
                if (empty()  || iterator<0) {
                    throw exception();
                }else {
                    for (int i = iterator; i < size-1; i++){
                        Container[i] = Container[i + 1];
                    }
                    size--;
                }
            }catch (exception) {
                cout << "vector is empty!\n" << endl;
            }
        }


        void erase(int iterator1, int iterator2){
            try {
                if (empty()  || iterator1 < 0 || iterator2 > size) {
                    throw exception();
                }else {
                    for (int i = iterator2+1; i < size; i++){
                        Container[i-(iterator2-iterator1+1)] = Container[i];
                    }
                    size -= (iterator2-iterator1+1);
                }
            }catch (exception) {
                cout << "vector is empty!\n" << endl;
            }
        }



        void insert(int iterator, t element) {
            try{
                if (empty() || iterator < 0) {
                    throw exception();
                }else {
                    if (size == capacity)
                        resize();
                    for (int i = size; i > iterator; i--){
                        Container[i] = Container[i-1];
                    }
                    Container[iterator] = element;
                    size++;
                }
            }catch (exception) {
                cout << "vector is empty!\n" << endl;
            }
        }


        t& operator=(const anvector& other){
            if(this != &other){
                delete[] Container;
                size = other.size;
                capacity = other.capacity;
                Container = new t[capacity];
                for(int i = 0; i < other.size; i++){
                    Container[i] = other.Container[i];
                }
            }
            else{
                cout << "Cannot delete" << endl;
            }
        }
        
        
        
        
        t& operator=(const anvector&& other){
            if(this != &other){
                delete[] Container;
                size = other.size;
                capacity = other.capacity;
                Container = other.Container ;
                other.Container = nullptr;
                other.capacity = 0 ;
                other.size  = 0 ;
            }
            else{
                cout << "Cannot delete" << endl;
            }
        }


        int Size() {
            return size;
        }

        int Capacity() {
            return capacity;
        }
        
        t* begin(){
            return (Container);
        }

        t* end(){
            return (Container+size);
        }

        int resize() {
            t* arr2 = new t[capacity * 2]; 
            for (int i = 0; i < capacity; i++)
            {
                arr2[i] = Container[i];
            }
            delete Container;
            Container = arr2;
            return (capacity * 2);
        }
        
        void clear(){
          size = 0 ;
          capacity =1;
          delete [] Container ;
          Container  = new t[capacity];
        }

        bool empty() {
            return (size == 0);
        }

        bool operator< (const anvector<t>& Other){
            if(this->size < Other.size){
                return true;
            }else{
                return false ;
            }
        }

        bool operator> (const anvector<t>& Other){
            if(this->size > Other.size){
                return true;
            }else{
                return false ;
            }
        }

        bool operator== (const anvector<t>& Other){
            if(this->size == Other.size){
                return true;
            }else{
                return false ;
            }
        }
        
        
        anvector (t* arr , int n ){
          size = capacity = n ;
          Container = new t[size];
          for (int i =0 ; i < size ; i++){
             Container[i] = arr[i];
          }
        }
        
        
        anvector (const anvector& other){
            size = other.size;
            capacity = other.capacity;
            Container = new t[capacity];
            for(int i = 0; i < other.size; i++){
                Container[i] = other.Container[i];
            }
        }
        
        //template<class t> friend ostream &operator<< (ostream & , anvector<t>) 

};

/*template<typename t>ostream &operator<<< (ostream & cout anvector<t> vec) {
    for (int i = 0; i < vec.size(); ++i){ 
        cout<<vec[i] <<" "; 
    }
    cout<<"\n";
    return cout;
}*/

int main(){

    anvector<int> m;
    cout << m.empty() << endl;
    m.push_back(10);
    m.push_back(20);
    m.push_back(30);
    m.push_back(40);
    m.push_back(50);
    cout << m.Size() << endl;
    cout << m.Capacity() << endl;
    m.push_back(60);
    m.push_back(70);
    m.push_back(80);
    cout << m.Size() << endl;
    cout << m.Capacity() << endl;
    m.push_back(90);
    cout << m.Size() << endl;
    cout << m.Capacity() << endl;
    for (size_t i = 0; i < m.Size(); i++){
        cout << m[i]  << " ";
    }
    cout << endl ;
    cout << m.Size() << endl;
    m.pop_back();
    cout << m.Size() << endl;
    m.pop_back();
    cout << m.Size() << endl;
    m.pop_back();
    cout << m.Size() << endl;
    for (size_t i = 0; i < m.Size(); i++){
        cout << m[i]  << " ";
    }
    cout << m.empty() << endl;
    m.insert(2,5);
    cout << m.Size() << endl;
    for (size_t i = 0; i < m.Size(); i++){
        cout << m[i]  << " ";
    }
    cout << endl ;
    cout << m.Size() << endl;
    m.erase(2);
    for (size_t i = 0; i < m.Size(); i++){
        cout << m[i]  << " ";
    }
    cout << endl ;
    cout << m.Size() << endl;
    m.erase(4,5);
    for (size_t i = 0; i < m.Size(); i++){
        cout << m[i]  << " ";
    }
    cout << endl ;
    cout << m.Size() << endl;
    m.clear();
    cout << m.Size() << endl;
    

   int arr[] = {1,2,3,4,5};
   anvector<int> w(arr,5);
   for (size_t i = 0; i < w.Size(); i++){
    cout << w[i] << " " ;
   }
   cout << endl ;

   anvector<int> q(w);
   for (size_t i = 0; i < q.Size(); i++){
    cout << q[i] << " " ;
   }

    anvector<int> b;
   if (q == w){
    cout<< "Equal" << endl ;
   }
   if(q > b){
        cout<< "q Grater Than b " << endl ;
    }else{
        cout<< "b Grater Than q " << endl ;
    }
    if(q < b){
        cout<< "q Smaller Than b " << endl ;
    }else{
        cout<< "b Smaller Than q " << endl ;
    }

    for (auto it = w.begin(); it != w.end(); it++){
        cout << *it << " " ;
    }
    
   return 0;
}


/*


///XYVector (int)
///XYVector (T*,int n)
///XYVector (const XYVector&)
///~XYVector()
///XYVector &operator=(const Vector&); 
///XYVector &operator=(const Vector&&);
///T& operator[](int)
///int push_back(T)
///T pop_back()
///void erase(iterator)
///void erase(iterator1, iterator2)
///void clear()
///void insert(iterator, T)
///iterator begin()
///iterator end()
///bool operator==(const XYVector<T>&)
///bool operator< (const XYVector<T>&)
///int size()
///int capacity()
///int resize()
///bool empty()
***friend ostream& operator << (ostream& out, XYvector<T>)

*/