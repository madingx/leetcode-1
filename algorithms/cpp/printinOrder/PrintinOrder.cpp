// Source : https://leetcode.com/problems/print-in-order/
// Author : Mading
// Date   : 2019-08-30

/********************************************************************************** 
* 1114. Print in Order [Easy]
* Suppose we have a class:

* public class Foo {
*   public void first() { print("first"); }
*   public void second() { print("second"); }
*   public void third() { print("third"); }
* }
* The same instance of Foo will be passed to three different threads. 
* Thread A will call first(), thread B will call second(), and thread 
* C will call third(). Design a mechanism and modify the program to 
* ensure that second() is executed after first(), and third() is 
* executed after second().

 

* Example 1:

* Input: [1,2,3]
* Output: "firstsecondthird"
* Explanation: There are three threads being fired asynchronously. 
* The input [1,2,3] means thread A calls first(), thread B calls second(), 
* and thread C calls third(). "firstsecondthird" is the correct output.
* Example 2:

* Input: [1,3,2]
* Output: "firstsecondthird"
* Explanation: The input [1,3,2] means thread A calls first(), thread 
* B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

* Note:

* We do not know how the threads will be scheduled in the operating system, 
* even though the numbers in the input seems to imply the ordering. 
* The input format you see is mainly to ensure our tests' comprehensiveness.
* 
*               
**********************************************************************************/


// 184 ms, faster than 29.15% of C++, 9 MB, less than 100.00% of C++
class Foo {
private:
    mutex mtx;
    int state;
    condition_variable cv;
public:
    Foo(): state{0}{}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&]{return state==0;});
        state=1;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&]{return state==1;});
        state=2;
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&]{return state==2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lock.unlock();
        cv.notify_all();
    }
};













typedef struct {
    // User defined data may be declared here.
    
} Foo;

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;

Foo* fooCreate() {
  Foo* obj = (Foo*) malloc(sizeof(Foo));

  // Initialize user defined data here.
  pthread_mutex_init(&mutex1, NULL);
  pthread_mutex_init(&mutex2, NULL);
  pthread_mutex_init(&mutex3, NULL);
  
  pthread_mutex_lock(&mutex2);
  pthread_mutex_lock(&mutex3);

  return obj;
}

void first(Foo* obj) {
  pthread_mutex_lock(&mutex1);

  // printFirst() outputs "first". Do not change or remove this line.
  printFirst();
  
  pthread_mutex_unlock(&mutex2);
}

void second(Foo* obj) {
  pthread_mutex_lock(&mutex2);

  // printSecond() outputs "second". Do not change or remove this line.
  printSecond();
  
  pthread_mutex_unlock(&mutex3);
}

void third(Foo* obj) {
  pthread_mutex_lock(&mutex3);
  
  // printThird() outputs "third". Do not change or remove this line.
  printThird();
  
  pthread_mutex_unlock(&mutex3);
}

void fooFree(Foo* obj) {
  // User defined data may be cleaned up here.

  pthread_mutex_destroy(&mutex1);
  pthread_mutex_destroy(&mutex2);
  pthread_mutex_destroy(&mutex3);
}