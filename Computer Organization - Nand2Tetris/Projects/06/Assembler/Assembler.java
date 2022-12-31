import java.io.*;
import java.util.*;

public class Assembler
{

    public static void main(String[] args)
    {
        
        String filename;
        Scanner cin = new  Scanner(System.in);
        System.out.println("Please enter an assembly file to be turned into a hack: ");
        filename = cin.next();
        File filereader = new File(filename);
        

        if(filereader.canRead())
        {
            try
            {
                
                String out = "";
                String filenameCut = "";
                filenameCut = filename.replace(".asm","");
                out = filenameCut + ".hack";
                File outputFile = new File(out);
                PrintWriter fileWriter = new PrintWriter(outputFile);
                Parser parser = new Parser(filereader);
                SymbolTable table = new SymbolTable(parser);
                int instruction = 0;

                while(true)
                {
                    if(parser.commandType().equals("LCOMMAND"))
                    {
                        if(parser.hasMoreInstructions())
                        {
                            parser.updateCommand();
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if(parser.commandType().equals("ACOMMAND"))
                    {
                        String binaryString = "0";
                        try
                        {
                            int number = Integer.parseInt(parser.symbol());
                            String binary = Integer.toBinaryString(number);
                            if(binary.length() < 15)
                            {
                                for(int i=0; i<15-binary.length(); i++)
                                {
                                    binaryString += "0";
                                }
                            }
                            binaryString += binary;
                        }
                        catch (NumberFormatException nfe)
                        {
                            if(table.contains(parser.symbol()))
                            {
                                String binary = Integer.toBinaryString(table.returnValue(parser.symbol()));
                                if(binary.length() < 15)
                                {
                                    for(int i = 0; i<15-binary.length(); i++)
                                    {
                                        binaryString += "0";
                                    }
                                }
                                binaryString += binary;
                            }
                            else
                            {
                                table.addPair(parser.symbol());
                                String binary = Integer.toBinaryString(table.returnValue(parser.symbol()));
                                if(binary.length() < 15)
                                {
                                    for(int i=0; i<15-binary.length(); i++)
                                    {
                                        binaryString += "0";
                                    }
                                }
                                binaryString += binary;
                            }
                        }
                        fileWriter.println(binaryString);
                        instruction++;
                    }
                    else if(parser.commandType().equals("CCOMMAND"))
                    {
                        String binaryString = "111";
                        String dest = SymbolTable.dest(parser.dest());
                        String comp = SymbolTable.comp(parser.comp());
                        String jump = SymbolTable.jump(parser.jump());
                        if(!(dest.equals("invalid") || comp.equals("invalid") || jump.equals("invalid")))
                        {
                            binaryString += comp + dest + jump;
                            fileWriter.println(binaryString);
                            instruction++;
                        }
                        else
                        {
                            System.out.println("Error at instruction " + instruction + ". The .hack file is incomplete!");
                            fileWriter.close();
                            return;
                        }
                    }
                    else
                    {
                        System.out.println("Error at instruction " + instruction + ". The .hack file is incomplete!");
                        fileWriter.close();
                        return;
                    }

                    if(parser.hasMoreInstructions())
                    {
                        parser.updateCommand();
                    }

                    else
                    {
                        break;
                    }
                }
                fileWriter.close();
            }
            catch (Exception e)
            {
                System.out.println("Error: " + e.getMessage());
            }
        }
        else System.out.println("No file was entered.");
    }
}