import java.io.*;
import java.util.*;
class assembler
{
    public static void main(String [] args)throws IOException
    {
        String [] name= new String[30000];
        int [] value= new int[30000];
        String [] type= new String [30000];
        String filename;
        Scanner cin = new Scanner(System.in);
        System.out.print("File: ");
        filename = cin.next();
        System.out.print("Turning "+filename+" into ");
        cin.close();

        createTable(name,value,type,filename);
        for(int i=0;i<30000;i++){if(name[i]!=null) System.out.println(name[i]+" "+value[i]);}
        createCode(name,value,type,filename);
    }












    public static void createTable(String [] name,int [] value,String [] type,String fname) throws IOException
    {
        int count = 0;
        String tempInstruction = " ";
        int predef = 16;
        boolean [] modified=new boolean [30000];
        /*String filename;
        Scanner cin = new Scanner(System.in);
        System.out.println("File: ");
        filename = cin.next();
        System.out.println("Turning "+filename+" into hack.");
        cin.close();
        Scanner fileReader = new Scanner(new FileReader(filename));*/

        Scanner fileReader = new Scanner(new FileReader(fname));
        while(fileReader.hasNextLine())
        {
            tempInstruction = fileReader.next();
            if(tempInstruction.contains("//")||tempInstruction.isEmpty())
            {
                if(fileReader.hasNext())fileReader.nextLine();
            }
            else if(tempInstruction.contains("(") && tempInstruction.contains(")"))
            {
                boolean same=false;
                String stripped=tempInstruction.replace("(","").replace(")","");
                for(int i=0;i<30000;i++)//check if @ already exists of same name
                {
                    if(name[i]!=null)
                    {
                        if(name[i].contains("@"))
                        {
                            if(stripped.equals(name[i].replace("@","")))
                            {
                                value[i]=count;
                                same=true;
                            }
                        }
                    }
                }
                if(same)
                {

                }
                else
                {
                    name[count]=tempInstruction;
                    value[count]=count;
                } 
            }
            else if(tempInstruction.contains("@"))//////has @
            {
                if(!isInteger(tempInstruction.replace("@","")))//////@word
                {
                    boolean same=false;
                    String stripped=tempInstruction.replace("@","");
                    for(int i=0;i<30000;i++)//check if () already exists of same name
                    {
                        if(name[i]!=null)
                        {
                            if(name[i].contains("(") && name[i].contains(")"))
                            {
                                if(stripped.equals(name[i].replace("(","").replace(")","")))
                                {
                                    name[i]=tempInstruction;
                                    value[i]=count;
                                    same=true;
                                    modified[i]=true;
                                }
                            }
                        }
                    }
                    if(same)
                    {

                    }
                    else
                    {
                        //System.out.println("c");
                        count++;
                        name[count]=tempInstruction;
                        value[count]=count;
                    } 
                }
                else
                {
                    //System.out.println("u");
                    count++;
                }
            }
            else
            {
                //System.out.println("f");
                count++;
            }
        }
        fileReader.close();
        //A-Instructions
        for(int i=0;i<30000;i++)
        {
            if(name[i]!=null)//removed duplicate presets
            {
                if(name[i].replace("@","").equals("SP")||
                name[i].replace("@","").equals("LCL")||
                name[i].replace("@","").equals("ARG")||
                name[i].replace("@","").equals("THIS")||
                name[i].replace("@","").equals("THAT")||
                name[i].replace("@","").equals("R0")||
                name[i].replace("@","").equals("R1")||
                name[i].replace("@","").equals("R2")||
                name[i].replace("@","").equals("R3")||
                name[i].replace("@","").equals("R4")||
                name[i].replace("@","").equals("R5")||
                name[i].replace("@","").equals("R6")||
                name[i].replace("@","").equals("R7")||
                name[i].replace("@","").equals("R8")||
                name[i].replace("@","").equals("R9")||
                name[i].replace("@","").equals("R10")||
                name[i].replace("@","").equals("R11")||
                name[i].replace("@","").equals("R12")||
                name[i].replace("@","").equals("R13")||
                name[i].replace("@","").equals("R14")||
                name[i].replace("@","").equals("R15")||
                name[i].replace("@","").equals("SCREEN")||
                name[i].replace("@","").equals("KBD"))
                {
                    name[i]=null;
                }
            }
        }
        name[count+0]="SP";
        name[count+1]="LCL";
        name[count+2]="ARG";
        name[count+3]="THIS";
        name[count+4]="THAT";
        name[count+5]="R0";
        name[count+6]="R1";
        name[count+7]="R2";
        name[count+8]="R3";
        name[count+9]="R4";
        name[count+10]="R5";
        name[count+11]="R6";
        name[count+12]="R7";
        name[count+13]="R8";
        name[count+14]="R9";
        name[count+15]="R10";
        name[count+16]="R11";
        name[count+17]="R12";
        name[count+18]="R13";
        name[count+19]="R14";
        name[count+20]="R15";
        name[count+21]="SCREEN";
        name[count+22]="KBD";
        value[count+0]=0;
        value[count+1]=1;
        value[count+2]=2;
        value[count+3]=3;
        value[count+4]=4;
        value[count+5]=0;
        value[count+6]=1;
        value[count+7]=2;
        value[count+8]=3;
        value[count+9]=4;
        value[count+10]=5;
        value[count+11]=6;
        value[count+12]=7;
        value[count+13]=8;
        value[count+14]=9;
        value[count+15]=10;
        value[count+16]=11;
        value[count+17]=12;
        value[count+18]=13;
        value[count+19]=14;
        value[count+20]=15;
        value[count+21]=16384;
        value[count+22]=24576;
        //////////////////////////////////////////////////////delete in-program copies
        //for(int i=29999;i>=0;i--)
        for(int i=0;i<30000;i++)
        {
            for(int j=0;j<30000;j++)
            //for(int j=29999;j>=0;j--)
            {
                if(i!=j && name[i]!=null && name[j]!=null)
                {
                    if(name[i].equals(name[j]))
                    {
                        //System.out.println(name[j]);
                        name[j]=null;
                        //value[i]=value[i]-value[j];
                    }
                }
            }
        }
        //loop to assign up labels @'s
        boolean same=false;
        int x=0;
        for(int i=0;i<30000;i++)
        {
            Scanner fileRead = new Scanner(new FileReader(fname));
            same=false;
            if(name[i]!=null)
            {
                if(name[i].contains("@"))
                {
                    int j=0;
                    while(fileRead.hasNextLine())
                    {
                        tempInstruction = fileRead.next();
                        if(tempInstruction.contains("//")||tempInstruction.isEmpty())
                        {
                            if(fileRead.hasNext())fileRead.nextLine();
                        }
                        else if(tempInstruction.contains("(") && tempInstruction.contains(")"))
                        {
                            if(name[i].replace("@","").equals(tempInstruction.replace("(","").replace(")","")))
                            {

                                same = true;
                                x=j;
                            }
                        }
                        else if(tempInstruction.contains("@"))
                        {
                            j++;
                        }
                        else
                        {
                            j++;
                        }
                    }
                    if(same==true)
                    {
                        value[i]=x;
                        //System.out.print("fffff");
                    }
                    else
                    {
                        value[i]=predef;
                        predef++;
                    }
                }
            }
            fileRead.close();
        }
    }














    


    public static void createCode(String [] name,int [] value,String [] type,String fname) throws IOException
    {
        String Oname=fname.replace(".asm",".hack");//changes system.out to file i/o
        System.out.println(Oname);
        File file = new File(Oname);        
        PrintStream printStreamToFile = new PrintStream(file);
        System.setOut(printStreamToFile);
        String tempInstruction = " ";
        /*String filename;
        Scanner cin = new Scanner(System.in);
        System.out.println("File: ");
        filename = cin.next();
        System.out.println("Turning "+filename+" into hack.");
        cin.close();
        Scanner fileReader = new Scanner(new FileReader(filename));*/

        Scanner fileReader = new Scanner(new FileReader(fname));
        while(fileReader.hasNextLine())
        {
            tempInstruction = fileReader.next();
            if(tempInstruction.contains("//")||tempInstruction.isEmpty())//comments removed
            {
                if(fileReader.hasNext())fileReader.nextLine();
            }
            else if(tempInstruction.contains("(") && tempInstruction.contains(")"))//labels removed ()()
            {
                if(fileReader.hasNext())fileReader.nextLine();
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////A instruction@@@@
            else if(tempInstruction.contains("@"))
            {
                if(isInteger(tempInstruction.replace("@R","")))
                {
                    binary(makeInteger(tempInstruction.replace("@R","")));
                    //System.out.println("HERE");
                }
                else if(isInteger(tempInstruction.replace("@","")))
                {
                    binary(makeInteger(tempInstruction.replace("@","")));
                }
                else 
                {
                    for(int i=0;i<30000;i++)
                    {
                        if(name[i]!=null)
                        {
                            if(name[i].equals(tempInstruction)||name[i].equals(tempInstruction.replace("@","")))
                            {
                                binary(value[i]);/////////
                            }
                        }
                    }
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////C instruction
            else
            {
                String [] b = new String[2];
                String [] f = new String[2];
                if(tempInstruction.contains(";"))
                {
                    b = tempInstruction.split(";");
                }
                if(tempInstruction.contains("="))
                {
                    f = tempInstruction.split("=");
                }
                int [] bitarray = new int [16];
                bitarray[0]=1;
                bitarray[1]=1;
                bitarray[2]=1;
                //////////////////////////////////////// if an M exists [3] is 1
                for(int i=3;i<15;i++)
                {
                    bitarray[i]=0;
                }
                if(f[0]!=null)//////////////////////////destinations [10-12]
                {
                    if(f[0].contains("M"))
                    {
                        bitarray[12]=1;
                    }
                    if(f[0].contains("D"))
                    {
                        bitarray[11]=1;
                    }
                    if(f[0].contains("A"))
                    {
                        bitarray[10]=1;
                    }
                    
                }
                else
                {
                    bitarray[10]=0;
                    bitarray[11]=0;
                    bitarray[12]=0;
                }
                if(b[1]!=null)//////////////////////////jumps [13-15]
                {
                    if(b[1].contains("JGT"))
                    {
                        bitarray[15]=1;
                    }
                    else if(b[1].contains("JEQ"))
                    {
                        bitarray[14]=1;
                    }
                    else if(b[1].contains("JLT"))
                    {
                        bitarray[13]=1;
                    }
                    else if(b[1].contains("JGE"))
                    {
                        bitarray[14]=1;
                        bitarray[15]=1;
                    }
                    else if(b[1].contains("JNE"))
                    {
                        bitarray[13]=1;
                        bitarray[15]=1;
                    }
                    else if(b[1].contains("JLE"))
                    {
                        bitarray[14]=1;
                        bitarray[13]=1;
                    }
                    else if(b[1].contains("JMP"))
                    {
                        bitarray[14]=1;
                        bitarray[15]=1;
                        bitarray[13]=1;
                    }
                }
                ////////////////////////////////////////////computations [4-9]///////////////////////////////
                if(f[1]!=null)
                {
                    if(f[1].contains("D|A")||f[1].contains("D|M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("D&A")||f[1].contains("D&M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("A-D")||f[1].contains("M-D"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("D-A")||f[1].contains("D-M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("D+A")||f[1].contains("D+M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("A-1")||f[1].contains("M-1"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("D-1"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("A+1")||f[1].contains("M+1"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("D+1"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("-A")||f[1].contains("-M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("-D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("!A")||f[1].contains("!M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("!D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("A")||f[1].contains("M"))
                    {
                        if(f[1].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("-1"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("1"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(f[1].contains("0"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("M"))
                    {
                        bitarray[3]=1;
                    }
                }
                /////////////////////////////////////////////////////////////////////////////////////////////////
                if(b[0]!=null)
                {
                    if(b[0].contains("D|A")||b[0].contains("D|M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("D&A")||b[0].contains("D&M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("A-D")||b[0].contains("M-D"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("D-A")||b[0].contains("D-M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("D+A")||b[0].contains("D+M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("A-1")||b[0].contains("M-1"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("D-1"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("A+1")||b[0].contains("M+1"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("D+1"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("-A")||b[0].contains("-M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("-D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("!A")||b[0].contains("!M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("!D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("A")||b[0].contains("M"))
                    {
                        if(b[0].contains("M"))
                        {
                            bitarray[3]=1;
                        }
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=0;
                        bitarray[7]=0;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("D"))
                    {
                        bitarray[4]=0;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=0;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("-1"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(b[0].contains("1"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=1;
                        bitarray[6]=1;
                        bitarray[7]=1;
                        bitarray[8]=1;
                        bitarray[9]=1;
                    }
                    else if(b[0].contains("0"))
                    {
                        bitarray[4]=1;
                        bitarray[5]=0;
                        bitarray[6]=1;
                        bitarray[7]=0;
                        bitarray[8]=1;
                        bitarray[9]=0;
                    }
                    else if(f[1].contains("M"))
                    {
                        bitarray[3]=1;
                    }
                }///////////////////////////////////////////////////////////////////////////////////////////////binary printing
                for(int i=0;i<16;i++)
                {
                    System.out.print(bitarray[i]);
                }
                System.out.println();
            }
        }
        fileReader.close();
    }





























    public static boolean isInteger(String s) {
        //System.out.println(String.format("Parsing string value: \"%s\"", s));
        
        if(s == null || s.equals("")) {
          //System.out.println("Cannot parse the string since it either null or empty");
          return false;
        }
        
        try {
          Integer.parseInt(s);
          return true;
        }
        catch(NumberFormatException e) {
          //System.out.println("Cannot parse the string to integer");
        }
        return false;
    }
    public static int makeInteger(String s) {
        //System.out.println(String.format("Parsing string value: \"%s\"", s));
        
        if(s == null || s.equals("")) {
          //System.out.println("Cannot parse the string since it either null or empty");
          return 0;
        }
        
        try {
          int x=Integer.parseInt(s);
          return x;
        }
        catch(NumberFormatException e) {
          //System.out.println("Cannot parse the string to integer");
        }
        return 0;
    }
    public static int [] binary(int deci)
    {
        //System.out.println(deci);
        int [] x = new int[16];
        int count = 16;

        while(deci>=1 && count-->0)
        {
            x[count] = (deci % 2);
            deci/=2;
            //System.out.println(x[count]+ " " + deci);
        }
        for(int i=0;i<16;i++)
        {
            System.out.print(x[i]);
        }
        System.out.println();
        return x;
    }
}