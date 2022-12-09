/* 
I pledge that I have never given nor
received any help on this assignment
mfleschner & raparks
*/
#ifndef HASHENTRY_H
#define HASHENTRY_H
enum Status {EMPTY, OCCUPIED, REMOVED};
class HashEntry
{
public:
    //Constructor
    HashEntry(int key, int value);
    HashEntry();
    //Destructor
    ~HashEntry();
    //accessor methods
    int getKey();
    void setKey(int key);
    int getValue();
    void setValue(int value);
    Status getStatus();
    void setStatus(Status status);

private:
    int key_;
    int value_;
    Status status_;
   
};
#endif