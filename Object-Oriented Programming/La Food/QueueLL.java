public class QueueLL implements Queue
{
  private class node
  {
    public Object data;
    public node next;
  }

  node front, back;
  int count;

  public QueueLL()
  {
    count=0;
    back=front=null;
  }

  public void enqueue(Object x)
  {
    count++;
    node newnode=new node();
    newnode.data=x;
    newnode.next=null;
    if(count==1)
      front=newnode;
    else
      back.next=newnode;
    back=newnode;
  }

  public Object dequeue()
  {
    if(isEmpty()) return null;
    Object save=front.data;
    front=front.next;
    count--;
    if(count==0) back=null;
    return save;
  }

  public Object getFront()
  {
    if(isEmpty()) return null;
    return front.data;
  }


  public void makeEmpty() // erases all data
  { count=0; front=back=null; }
  public int size() // returns the number of items
  { return count; }
  public boolean isEmpty() // returns true if there are no items
  { return count<=0; }
  public boolean isFull() // returns true if there's no room
  { return false; }

}
