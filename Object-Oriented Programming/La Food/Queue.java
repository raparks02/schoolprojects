public interface Queue extends Container
{
  public void enqueue(Object x);
  public Object dequeue();
  public Object getFront();
}