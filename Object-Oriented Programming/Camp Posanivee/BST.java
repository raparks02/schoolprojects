class BST implements Container
{
  private class treenode
  {
    public Comparable data;
    public treenode left;
    public treenode right;
  }
  treenode root;
  int count;

  public BST()
  {
    Q=new QueueLL();
    makeEmpty();
  }

  private treenode inserthelp(Comparable x, treenode r)
  // we must return the new or unchanged value of r as our function value
  // because we are faking pass-by-reference
  {
    // base case - empty tree
    if(r==null)
    {
      treenode newnode=new treenode();
      newnode.data=x;
      newnode.left=newnode.right=null;
      count++;
      return newnode; // sets r
    }
    // recursive case
    if(x.compareTo(r.data)<=0)
      r.left=inserthelp(x,r.left);
    else
      r.right=inserthelp(x,r.right);
    return r;
  }

  public void insert(Comparable x)
  {
    root=inserthelp(x,root);
  }

  private Comparable lookuphelp(Comparable key, treenode r)
  {
    if(r==null) return null; // it's not here!
    if(key.compareTo(r.data)==0) // here it is!
      return r.data;
    // recurse!
    if(key.compareTo(r.data)<0)
      return lookuphelp(key,r.left);
    else
      return lookuphelp(key,r.right);
  }

  public Comparable lookup(Comparable key)
  { return lookuphelp(key,root); }

  // ---------- Delete code

  private Comparable findmin(treenode r)
  {
    if(r==null) return null;
    if(r.left==null) return r.data; // this IS the min
    return findmin(r.left);
  }

  private Comparable itemremoved; // to return by delete()

  private treenode deletehelp(Comparable key, treenode r)
  {
    // base cases
    if(r==null) // empty subtree
    {
      itemremoved=null;
      return r;
    }
    if(key.compareTo(r.data)==0) // we found it!
    {
      itemremoved=r.data;
      count--;
      // 3 cases
      // 0 children
      if(r.left==null && r.right==null)
      {
        return null;
      }
      // 1 child - left
      if(r.right==null)
      {
        // r=r.left
        return r.left;
      }
      // 1 child - right
      if(r.left==null)
      {
        // r=r.right
        return r.right;
      }
      // 2 children
      Comparable is; // is = inorder successor
      if(r.right.left==null) // so IS is a left child of r
      {
        is=r.right.data;
        r.right=r.right.right; // delete that node
      }
      else
      {
        treenode isparent=r.right;
        while(isparent.left.left!=null)
          isparent=isparent.left;
        is=isparent.left.data;
        isparent.left=isparent.left.right;
      }
      itemremoved=r.data;
      r.data=is;
      return r;
    }
    else if(key.compareTo(r.data)<0) // delete from left subtree
      r.left=deletehelp(key,r.left);
    else
      r.right=deletehelp(key,r.right);
    return r;
  }

  public Comparable delete(Comparable key)
  {
    root=deletehelp(key,root);
    return itemremoved;
  }

  // ---------- print code
  private void printhelp(treenode r)
  {
    // base case - empty tree
    if(r==null) return;
    // recursive case
    printhelp(r.left);
    System.out.println(r.data);
    printhelp(r.right);
  }

  public void print() { printhelp(root); }

  //----- Traversal code (iterator methods)

  private Queue Q;

  public static final int PRE=0;
  public static final int IN=1;
  public static final int POST=2;

  private void traverse(treenode r, int order)
  {
    if(r==null) return;
    if(order==PRE) Q.enqueue(r.data);
    traverse(r.left,order);
    if(order==IN) Q.enqueue(r.data);
    traverse(r.right,order);
    if(order==POST) Q.enqueue(r.data);
  }

  public void reset(int order)
  {
    Q.makeEmpty();
    traverse(root,order);
  }

  public void reset() { reset(IN); }

  public boolean hasNext() { return !Q.isEmpty(); }
  public Comparable getNext() { return (Comparable)Q.dequeue(); }

  public void makeEmpty() // erases all data
  {
    root=null; count=0; Q.makeEmpty();
  }
  public int size() // returns the number of items
    { return count; }
  public boolean isEmpty() // returns true if there are no items
    { return root==null; }
  public boolean isFull() // returns true if there's no room
    { return false; }
}
