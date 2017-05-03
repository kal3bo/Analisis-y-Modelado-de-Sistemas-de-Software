#include <iostream>
using namespace std;

class Counter{
    public:
    int count;
    Counter(){count = 1;}
    void increaseCounter(){count++;}
    void decreaseCounter(){count--;}
   
    int getCountInCount(){return count;}                        //Test purposes
};

class Child : public Counter{
   private:
   int *p;
   
   public:
   Child(int x){              //Normal constructor
       p = new int;                                             //When we create a new obj of type child 
       *p = x;
   }
   Child(const Child &obj){  //Copy Constructor
     p = new int;
     *p = *obj.p;
     increaseCounter();                                         //When we make a copy of the last child, there are two childs having the same pointer, so we increase the counter by 1
   }
   ~Child(){                  //Destructor
       decreaseCounter();
       if (count == 0){                                         //This ensures that the pointer is deleted only when no one else is using it
         cout << "Freeing memory..." << endl;
         delete p;
       }
   }
   int getCountInChild(){return getCountInCount();}
   int getP(){return *p;}
};

int main(){
    Child a(5);
    cout << "Number of Counts: " << a.getCountInChild() << endl;
    Child b = a;
    cout << "Number of Counts: " << b.getCountInChild() << endl;
    cout << "The value in Child B: " << b.getP() << endl;
    
}
