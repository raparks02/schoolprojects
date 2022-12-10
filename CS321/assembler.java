import java.util.*;
import java.io.*;


class assembler 
{
    public static void main(String [] args) throws IOException
    {
        HashMap<String, Integer> symbol = new HashMap<String, Integer>();
        HashMap<String, String> destination = new HashMap<String, String>();
        HashMap<String, String> jump = new HashMap<String, String>();
        HashMap<String, String> computation = new HashMap<String, String>();

        jump.put(" ", "000");
        jump.put("JGT", "001");
        jump.put("JGE","011");
        jump.put("JEQ","010");
        jump.put("JLT","100");
        jump.put("JNE","101");
        jump.put("JLE","110");
        jump.put("JMP","111");

            symbol.put("SP", 0);
            symbol.put("LCL", 1);
            symbol.put("ARG", 2);
            symbol.put("THIS", 3);
            symbol.put("THAT", 4);
            symbol.put("SCREEN", 18384);
            symbol.put("KBD", 24576);
            symbol.put("R0", 0);
            symbol.put("R1", 1);
            symbol.put("R2", 2);
            symbol.put("R3", 3);
            symbol.put("R4", 4);
            symbol.put("R5", 5);
            symbol.put("R6", 6);
            symbol.put("R7", 7);
            symbol.put("R8", 8);
            symbol.put("R9", 9);
            symbol.put("R10", 10);
            symbol.put("R11", 11);
            symbol.put("R12", 12);
            symbol.put("R13", 13);
            symbol.put("R14", 14);
            symbol.put("R15", 15);

        destination.put(" ", "000");
        destination.put("M=","001");
        destination.put("D=","010");
        destination.put("MD=","011");
        destination.put("A=","100");
        destination.put("AM=","101");
        destination.put("AD=","110");
        destination.put("AMD=","111");

        computation.put("0","0101010");
        computation.put("1","0111111");
        computation.put("-1","0111010");
        computation.put("D","0001100");
        computation.put("A","0110000");
        computation.put("M","1110000");
        computation.put("!D","0001101");
        computation.put("!A","0110001");
        computation.put("!M","1110001");
        computation.put("-D","0001111");
        computation.put("-A","0110011");
        computation.put("-M","1110011");
        computation.put("D+1","0011111");
        computation.put("A+1","0110111");
        computation.put("M+1","1110111");
        computation.put("D-1","0001110");
        computation.put("A-1","0110010");
        computation.put("M-1","1110010");
        computation.put("D+A","0000010");
        computation.put("D+M","1000010");
        computation.put("D-A","0010011");
        computation.put("D-M","1010011");
        computation.put("A-D","0000111");
        computation.put("M-D","1000111");
        computation.put("D&A","00000000");
        computation.put("D&M","1000000");
        computation.put("D|A","0010101");
        computation.put("D|M","1010101");



        String filename = "";
        String tempInstruction = " ";
        String [] instructNoComment = new String [100000];
        String [] commands = new String[100000];
        String [] splitInstruction = new String[100000];
        int count = 0;
        String tempString;
        int value = 16;
        int lineNumber = 0;


        
        
        Scanner cin = new  Scanner(System.in);
        System.out.println("Please enter an assembly file to be turned into a hack: ");
        filename = cin.next();
        System.out.println("Turning " + filename + " into hack");
        cin.close();

        Scanner fileReader = new Scanner(new FileReader(filename));

        while(fileReader.hasNextLine())
        {
            tempInstruction = fileReader.nextLine();
            
            if(tempInstruction.isEmpty())
            {}
            else
            {
                if(tempInstruction.charAt(0) == '/') 
                {
                    
                }
                else if (tempInstruction.charAt(0) == '(')
                {
                    tempInstruction = tempInstruction.replace("(","");
                    tempInstruction = tempInstruction.replace(")","");
                    symbol.put(tempInstruction,lineNumber);
                }
                else
                {
                    lineNumber++;
                    tempInstruction = tempInstruction.replace(" ","");
                    tempInstruction = tempInstruction.replace("\t","");
                    instructNoComment = tempInstruction.split("/");
                    



                    if(instructNoComment[0].contains("="))
                    {
                        splitInstruction = instructNoComment[0].split("=");
                        splitInstruction[0] += "=";
                        //System.out.println(splitInstruction[0]);
        
                        if (symbol.containsKey(splitInstruction[0]) || computation.containsKey(splitInstruction[0]) || destination.containsKey(splitInstruction[0]) || jump.containsKey(splitInstruction[0]))
                        {
                            //System.out.println("test");
                            commands[count] = instructNoComment[0];
                        }
                    }
                    else if(instructNoComment[0].contains("@"))
                    {
                        int toInt = 0;
                        tempString = instructNoComment[0].substring(1);
                        if (symbol.containsKey(tempString) || computation.containsKey(tempString) || destination.containsKey(tempString) || jump.containsKey(tempString))
                        {
                            commands[count] = instructNoComment[0];
                        }
                        else
                        {
                            try
                            {
                                if (!symbol.containsKey(tempString))
                                {
                                    toInt = Integer.parseInt(tempString);
                                    symbol.put(tempString,toInt);
                                    commands[count] = instructNoComment[0];
                                    //value++;
                                }
                            }
                            catch (Exception NumberFormatException)
                            {
                                symbol.put(tempString, value);
                                commands[count] = instructNoComment[0];
                                value++;
                            }
                        }  
                    }
                    else if(instructNoComment[0].contains(";"))
                    {
                        splitInstruction = instructNoComment[0].split(";");
                        if (symbol.containsKey(splitInstruction[0]) || computation.containsKey(splitInstruction[0]) || destination.containsKey(splitInstruction[0]) || jump.containsKey(splitInstruction[0]))
                        {
                            commands[count] = instructNoComment[0];
                        }
                    }
                    else
                    {}
                    count++;
                }
            }
        } 
        
        
        int temp = 0;
        int numzeros = 0;
        String binaryString = "";
        fileReader.close();
        String outputFile = "";
        String filenameCut = "";
        filenameCut = filename.replace(".asm","");
        outputFile = filenameCut + ".hack";
        FileWriter myWriter = new FileWriter(outputFile);


        for (int i = 0; i < commands.length; i++)
        {
            if (commands[i] != null)
            {
                //charArray = commands[i].toCharArray();
                if (commands[i].contains("@"))
                {
                    tempString = commands[i].substring(1);
                    numzeros = 16 - commands[i].length();
                    if (symbol.containsKey(tempString))
                    {
                        temp = symbol.get(tempString);
                        numzeros = 16 - Integer.toBinaryString(temp).length();
                        for (int j = 0; j < numzeros; j++)
                        {
                            binaryString+= "0";
                        }           
                        binaryString += Integer.toBinaryString(temp);
                        
                    }
                    else
                    {
                        binaryString += "0000000000000000";
                    }
                }
                else if (commands[i].contains("="))
                {
                    splitInstruction = commands[i].split("=");
                    splitInstruction[0] += "=";
                    //System.out.println("test");
                    binaryString = "111";
                    if (computation.containsKey(splitInstruction[1]))
                    {
                        binaryString += computation.get(splitInstruction[1]);
                    }
                    else
                    {
                        binaryString += "0000000";
                    }
                    if (destination.containsKey(splitInstruction[0]))
                    {
                        binaryString += destination.get(splitInstruction[0]);
                    }
                    else
                    {
                        binaryString += "000";
                    }
                    binaryString += "000";
                }
                else if (commands[i].contains(";"))
                {
                    splitInstruction = commands[i].split(";");
                    splitInstruction[0] = splitInstruction[0].replace(";","");
                    //System.out.println(splitInstruction[0]);
                    binaryString = "111";
                    if (computation.containsKey(splitInstruction[0]))
                    {
                        binaryString += computation.get(splitInstruction[0]);
                    }
                    else
                    {
                        binaryString += "0000000";
                    }
                    if (destination.containsKey(splitInstruction[0]))
                    {
                        binaryString += destination.get(splitInstruction[0]);
                    }
                    else
                    {
                        binaryString += "000";
                    }
                    if (jump.containsKey(splitInstruction[1]))
                    {
                        //binaryString += "0";
                        binaryString += jump.get(splitInstruction[1]);
                    }
                    else
                    {
                        binaryString += "000";
                    }
                }
                myWriter.write(binaryString + "\n");
                binaryString = "";
                
            }
        }
        myWriter.close();
    } 
}