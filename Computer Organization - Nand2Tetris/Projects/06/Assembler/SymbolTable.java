import java.util.Hashtable;

public class SymbolTable
{
    private Hashtable<String, Integer> symbols = new Hashtable<String, Integer>();
    private Parser parser;
    private int lineNumber;
    private int next;

    public SymbolTable(Parser parser)
    {
        this.initialize();
        this.parser = parser;
        lineNumber = 0;
        next = 16;
        this.pass1();
    }

    private void initialize()
    {
        symbols.put("SP", 0);
        symbols.put("LCL", 1);
        symbols.put("ARG", 2);
        symbols.put("THIS", 3);
        symbols.put("THAT", 4);
        for(int i=0; i<=15; i++)
        {
            String key = "R" + i;
            symbols.put(key, i);
        }
        symbols.put("SCREEN", 16384);
        symbols.put("KBD", 24576);
    }

    public int returnValue(String symbol)
    {
        return symbols.get(symbol);
    }

    private void pass1()
    {
        while(true)
        {
            if(parser.commandType().equals("LCOMMAND"))
            {
                symbols.put(parser.symbol(), lineNumber);
            }
            else lineNumber++;

            if(parser.hasMoreInstructions())
            {
                parser.updateCommand();
            }
            else
            {
                break;
            }
        }
        parser.reset();
    }

    public boolean contains(String symbol) 
    {
        return symbols.containsKey(symbol);
    }

    public void addPair(String symbol) 
    {
        symbols.put(symbol, next);
        next++;
    }

    public static String dest(String dest)
    {
        if(dest.equals("M"))
        {
            return "001";
        }
        else if(dest.equals("D"))
        {
            return "010";
        }
        else if(dest.equals("MD") || dest.equals("DM"))
        {
            return "011";
        }
        else if(dest.equals("A"))
        {
            return "100";
        }
        else if(dest.equals("AM") || dest.equals("MA"))
        {
            return "101";
        }
        else if(dest.equals("AD") || dest.equals("DA"))
        {
            return "110";
        }
        else if(dest.equals("AMD") || dest.equals("ADM") || dest.equals("DMA") || dest.equals("DAM") || dest.equals("MAD") || dest.equals("MDA"))
        {
            return "111";
        }
        else if(dest.equals("null"))
        {
            return "000";
        }
        else return "invalid";
    }
    public static String comp(String comp)
    {
        if(comp.equals("0"))
        {
            return "0101010";
        }
        else if(comp.equals("1"))
        {
            return "0111111";
        }
        else if(comp.equals("-1"))
        {
            return "0111010";
        }
        else if(comp.equals("D"))
        {
            return "0001100";
        }
        else if(comp.equals("A"))
        {
            return "0110000";
        }
        else if(comp.equals("!D"))
        {
            return "0001101";
        }
        else if(comp.equals("!A"))
        {
            return "0110001";
        }
        else if(comp.equals("-D"))
        {
            return "0001111";
        }
        else if(comp.equals("-A"))
        {
            return "0110011";
        }
        else if(comp.equals("D+1"))
        {
            return "0011111";
        }
        else if(comp.equals("A+1"))
        {
            return "0110111";
        }
        else if(comp.equals("D-1"))
        {
            return "0001110";
        }
        else if(comp.equals("A-1"))
        {
            return "0110010";
        }
        else if(comp.equals("D+A"))
        {
            return "0000010";
        }
        else if(comp.equals("D-A"))
        {
            return "0010011";
        }
        else if(comp.equals("A-D"))
        {
            return "0000111";
        }
        else if(comp.equals("D&A"))
        {
            return "0000000";
        }
        else if(comp.equals("D|A"))
        {
            return "0010101";
        }
        else if(comp.equals("M"))
        {
            return "1110000";
        }
        else if(comp.equals("!M"))
        {
            return "1110001";
        }
        else if(comp.equals("-M"))
        {
            return "1110011";
        }
        else if(comp.equals("M+1"))
        {
            return "1110111";
        }
        else if(comp.equals("M-1"))
        {
            return "1110010";
        }
        else if(comp.equals("D+M"))
        {
            return "1000010";
        }
        else if(comp.equals("D-M"))
        {
            return "1010011";
        }
        else if(comp.equals("M-D"))
        {
            return "1000111";
        }
        else if(comp.equals("D&M"))
        {
            return "1000000";
        }
        else if(comp.equals("D|M"))
        {
            return "1010101";
        }
        else return "invalid";
    }
    public static String jump(String jump)
    {
        if(jump.equals("JGT"))
        {
            return "001";
        }
        else if(jump.equals("JEQ"))
        {
            return "010";
        }
        else if(jump.equals("JGE"))
        {
            return "011";
        }
        else if(jump.equals("JLT"))
        {
            return "100";
        }
        else if(jump.equals("JNE"))
        {
            return "101";
        }
        else if(jump.equals("JLE"))
        {
            return "110";
        }
        else if(jump.equals("JMP"))
        {
            return "111";
        }
        else if(jump.equals("null"))
        {
            return "000";
        }
        else return "invalid";
    }




}