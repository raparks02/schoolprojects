import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Parser
{
    private int lineNum = 0;
    private String current;
    private ArrayList<String> instructions = new ArrayList<String>();

    public Parser(File input) throws FileNotFoundException, Exception
    {
        try
        {
            removeComments(input);
            if(!instructions.isEmpty())
            {
               current = instructions.get(lineNum);
            }
            else
            {
                throw new Exception("No valid instructions.");
            }
        }
        catch (FileNotFoundException e)
        {
            throw new FileNotFoundException(e.getMessage());
        }
    }

    public void removeComments(File input) throws FileNotFoundException
    {
        try
        {
            Scanner inputFile = new Scanner(input);

            while(inputFile.hasNext())
            {
                String next = inputFile.nextLine();
                String[] line = next.split("\\s");
                String command = "";

                for(int i=0; i<line.length; i++)
                {
                    if(line.length == 0)
                    {
                        break;
                    }
                    else if(line[i].length() > 1 && line[i].substring(0, 2).equals("//") && i != 0)
                    {
                        break;
                    }
                    else if(line[i].length() > 1 && line[i].substring(0, 2).equals("//") && i == 0)
                    {
                        break;
                    }
                    else
                    {
                        command += line[i];
                    }
                }
                if(!command.equals(""))
                {
                    instructions.add(command);
                }
            }
            inputFile.close();

        }
        catch(FileNotFoundException e)
        {
            throw new FileNotFoundException();
        }
    }

    public void reset()
    {
        lineNum = 0;
        current = instructions.get(lineNum);
    }

    public void updateCommand()
    {
        lineNum++;
        current = instructions.get(lineNum);
    }

    public boolean hasMoreInstructions()
    {
        return (lineNum < instructions.size() - 1);
    }


    public String commandType()
    {
        for(int i=1; i<current.length()-1; i++)
        {
            if(current.charAt(i) == '=' || current.charAt(i) == ';')
            {
                return "CCOMMAND";
            }
        }
        if(current.charAt(0) == '@')
        {
            return "ACOMMAND";
        }
        else if(current.charAt(0) == '(' && current.charAt(current.length()-1) == ')')
        {
            return "LCOMMAND";
        }
        else
        {
            return "INVALID INSTRUCTION";
        }
    }

    public String symbol()
    {
        if(current.charAt(0) == '@')
        {
            return current.substring(1, current.length());
        }
        else if(current.charAt(0) == '(')
        {
            return current.substring(1, current.length()-1);
        }
        else return "INVALID INSTRUCTION";
    }

    public String comp()
    {
        int equalsSign = current.indexOf('=');
        int semicolon = current.indexOf(';');
        if(equalsSign > 0)
        {
            return current.substring(equalsSign + 1);
        }
        else if(semicolon > 0)
        {
            return current.substring(0, semicolon);
        }
        else return "INVALID INSTRUCTION";
    }

    public String dest()
    {
        int equalsSign = current.indexOf('=');
        if(equalsSign > 0)
        {
            return current.substring(0, equalsSign);
        }
        else return "null";
    }

    public String jump()
    {
        int semicolon = current.indexOf(';');
        if(semicolon > 0)
        {
            return current.substring(semicolon + 1);
        }
        else return "null";
    }
}
