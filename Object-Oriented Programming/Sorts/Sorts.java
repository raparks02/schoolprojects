class Sorts
{
  private static void swap(Comparable [] list, int x, int y)
  // swaps list[x] with list[y]
  {
    Comparable temp=list[x];
    list[x]=list[y];
    list[y]=temp;
  }

  private static int findmax(Comparable [] list, int last)
  {
    int maxpos=0;
    for(int i=1; i<=last; i++)
      if(list[i].compareTo(list[maxpos])>0)
        maxpos=i;
    return maxpos;
  }

  public static void selection(Comparable [] list)
  {
    for(int last=list.length-1; last>0; last--)
    {
      // find the max in 0..last
      int maxpos=findmax(list,last);
      // swap it to the last position
      swap(list,maxpos,last);
    }
  }

  public static void bubble(Comparable [] list)
  {
    for(int pass=0; pass<list.length; pass++)
    {
      // scan left-to-right
      for(int i=0; i+1<list.length; i++)
        if(list[i].compareTo(list[i+1])>0)
          swap(list,i,i+1);
    }
  }

  public static void insertion(Comparable [] list)
  {
    for(int toinsert=1; toinsert<list.length; toinsert++)
    {
      Comparable save=list[toinsert];
      int i; // so it exists outside the loop
      for(i=toinsert-1; i>=0; i--)
      {
        if(list[i].compareTo(save)>0) // then slide to the right
          list[i+1]=list[i];
        else // save goes here
        {
          list[i+1]=save;
          break; // exit the loop - we are done here
        }
      }
      if(i<0) list[0]=save;
    }
  }

  public static void insertion(Comparable [] list, int offset, int gap)
  {
    for(int toinsert=offset+gap; toinsert<list.length; toinsert+=gap)
    {
      Comparable save=list[toinsert];
      int i; // so it exists outside the loop
      for(i=toinsert-gap; i>=0; i-=gap)  // i-=gap is the same as i=i-gap
      {
        if(list[i].compareTo(save)>0) // then slide to the right
          list[i+gap]=list[i];
        else // save goes here
        {
          list[i+gap]=save;
          break; // exit the loop - we are done here
        }
      }
      if(i<0) list[offset]=save;
    }
  }

  public static void shell(Comparable [] list)
  {
    // gap == # of colors
    for(int gap=list.length/6; gap>1; gap=(int)(gap/2.2))
      for(int offset=0; offset<gap; offset++)
        insertion(list,offset,gap); // we need to write this
    insertion(list);
  }

  private static int partition(Comparable [] list, int start, int stop)
  {
    int right=start;
    Comparable pivot=list[stop];
    for(int i=start; i<stop; i++)
    {
      if(list[i].compareTo(pivot)<0)
      {
        swap(list,i,right); right++;
      }
    }
    swap(list,stop,right);
    return right;
  }

  private static void quickhelp(Comparable [] list, int start, int stop)
  {
    // base cases
    if(start>=stop) return; // size is 0 or 1
    if(start+1==stop) // size 2
    {
      if(list[start].compareTo(list[stop])>0)
        swap(list,start,stop);
      return;
    }
    // recursive case
    int pivotpos=partition(list,start,stop);
    quickhelp(list,start,pivotpos-1);
    quickhelp(list,pivotpos+1,stop);
  }

  public static void quick(Comparable [] list)
  {
    quickhelp(list,0,list.length-1);
  }

  private static void domerge(Comparable [] list, int start, int stop)
  // merging start..mid and mid+1..stop
  {
    int mid=(start+stop)/2;
    int left=start;
    int right=mid+1;
    Comparable [] A=new Comparable[stop-start+1];
    for(int i=0; i<A.length; i++)
    {
      //if(left is not empty and either right is empty or list[left]<list[right])
      if( left<=mid && (right>stop || list[left].compareTo(list[right])<0 ))
        A[i]=list[left++];
      else
        A[i]=list[right++];
    }
    for(int i=0; i<A.length; i++)
      list[start+i]=A[i];
  }

  private static void mergehelp(Comparable [] list, int start, int stop)
  {
    // base cases
    if(start>=stop) return; // size is 0 or 1
    if(start+1==stop) // size 2
    {
      if(list[start].compareTo(list[stop])>0)
        swap(list,start,stop);
      return;
    }
    // recursive case
    int mid=(start+stop)/2;
    mergehelp(list,start,mid);
    mergehelp(list,mid+1,stop);
    domerge(list,start,stop);  // write this next week
  }

  public static void merge(Comparable [] list)
  {
    mergehelp(list,0,list.length-1);
  }

}