public interface Container
{
  public void makeEmpty(); // empties all elements
  public int size(); // returns the size of the container
  public boolean isEmpty(); // returns true of size is 0
  public boolean isFull(); // returns true if there's no space available
}