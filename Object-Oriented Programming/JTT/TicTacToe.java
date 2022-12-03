import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
Description of how program chooses its Moves:
	Our Program chooses its moves by having each circle assigned to a number from 1 to 9
	and selecting the first one without a current x or o in it in numerical order
*/




/**
 Class that allows for the user to click which circle they want to mark
 @author Reece Parks and my partners Matt Fleschner, Cole Bische, and Miles Mann
 */
class TicTacToe extends JFrame
implements ActionListener, MouseListener
{
    //variables
	static int [] positions = {0,0,0,0,0,0,0,0,0,0};
    Container something;
    JPanel panel, end;
    JLabel result, menu, move, select, again;
    JButton yes, no, x, o, playAgainYes, playAgainNo;
    picture Board;
    int mousex, mousey, number, n, numPlays;
    static String player;
    static String ai;
    int outcome = 0;
    int tie = 0;
    int results = 0;
    static int [] temp;
	
	/**
     Function to create a TicTacToe game object
     */
    public TicTacToe()
    {
        addWindowListener( new Closer() );
        setTitle("Jerry Tac Toe");
        setVisible(true);
        setSize(950,672);
        
        menu=new JLabel("Welcome to Jerry Tac Toe");
        move=new JLabel("Would you like to go first?");
        select=new JLabel("Which piece would you like to use?");
        again=new JLabel("Would you like to play again?");
        yes=new JButton("Yes");
        no=new JButton("No");
        x=new JButton("x");
        o=new JButton("o");
        playAgainYes=new JButton("Yes");
        playAgainNo=new JButton("No");
        Board=new picture();
        temp = new int[10];
        
        move.setVisible(false);
        yes.setVisible(false);
        no.setVisible(false);
        Board.addMouseListener(this);
        yes.addActionListener(this);
        no.addActionListener(this);
        x.addActionListener(this);
        o.addActionListener(this);
        playAgainYes.addActionListener(this);
        playAgainNo.addActionListener(this);
        
        // puts things in the window
        something=getContentPane();
        
        // allows for organization
        something.setLayout( new BorderLayout() );
        
        panel=new JPanel();
        panel.add(menu,"North");
        panel.add(move,"North");
        panel.add(select,"North");
        panel.add(yes,"Center");
        panel.add(no,"Center");
        panel.add(x,"South");
        panel.add(o,"South");
        
        something.add(panel,"Center");
    }
	
	public static void main(String [] args)
    {
        JFrame game=new TicTacToe();
    }
	
    /**
     @param e to link to specific action
     */
    public void actionPerformed(ActionEvent e)
    {
        // If you want to go first, removes question and displays the board
        if(e.getSource()==yes)
        {
            something.remove(panel);
            something.add(Board);
            something.validate();
            something.repaint();
        }

      // If you don't want to go first, makes AI randomly choose place to go and displays board
        if(e.getSource()==no)
        {
            number = (int)(1+9*Math.random());
            temp[number] = number;
            positions[number] = 2;
            something.remove(panel);
            something.add(Board);
            something.validate();
            something.repaint();
        }
        //If you want to play as X
        if(e.getSource()==x)
        {
            player = "x";
            ai = "o";
            yes.setVisible(true);
            no.setVisible(true);
            move.setVisible(true);
            select.setVisible(false);
            x.setVisible(false);
            o.setVisible(false);
        }
        // If you want to play as o
        if(e.getSource()==o)
        {
            player = "o";
            ai = "x";
            yes.setVisible(true);
            no.setVisible(true);
            move.setVisible(true);
            select.setVisible(false);
            x.setVisible(false);
            o.setVisible(false);
        }
      
        // Play again yes answer and resets board
        if(e.getSource() == playAgainYes)
        {
            results = 0;
            temp[1] = 0;
            positions[1] = 0;
            x.setVisible(true);
            o.setVisible(true);
            yes.setVisible(false);
            no.setVisible(false);
            select.setVisible(true);
            move.setVisible(false);
            something.remove(end);
            something.add(panel);
            something.validate();
            something.repaint();
        }
        
        //Don't play again and terminates game
        if(e.getSource() == playAgainNo)
        {
            System.exit(0);
        }
    }
    /**
     @param e finds out where the mouse clicks
     */
    public void mouseClicked(MouseEvent e)
    {
        // coordinates of where you clicked
        mousex = e.getX();
        mousey = e.getY();
      
        // depending on where you clicked, do certain action
        if(mousex >= 05 && mousex <= 45 && mousey >= 10 && mousey <= 40)
        {
            n = 1;
            jerry();
        }
        if(mousex >= 455 && mousex <= 495 && mousey >= 10 && mousey <= 40)
        {
            n = 2;
            jerry();
        }
        if(mousex >= 905 && mousex <= 945 && mousey >= 10 && mousey <= 40)
        {
            n = 3;
            jerry();
        }
        if(mousex >= 230 && mousex <= 270 && mousey >= 310 && mousey <= 340)
        {
            n = 4;
            jerry();
        }
        if(mousex >= 455 && mousex <= 495 && mousey >= 310 && mousey <= 340)
        {
            n = 5;
            jerry();
        }
        if(mousex >= 680 && mousex <= 720 && mousey >= 310 && mousey <= 340)
        {
            n = 6;
            jerry();
        }
        if(mousex >= 05 && mousex <= 45 && mousey >= 610 && mousey <= 640)
        {
            n = 7;
            jerry();
        }
        if(mousex >= 455 && mousex <= 495 && mousey >= 610 && mousey <= 640)
        {
            n = 8;
            jerry();
        }
        if(mousex >= 905 && mousex <= 945 && mousey >= 610 && mousey <= 640)
        {
            n = 9;
            jerry();
        }
    }
    public void mouseEntered (MouseEvent me) {}
    public void mousePressed (MouseEvent me) {}
    public void mouseReleased (MouseEvent me) {}
    public void mouseExited (MouseEvent me) {}
    
    // Displays the play again screen
    public void play()
    {
        something.remove(Board);
        // displays the result of the game
        if(results == 1)
        {
            result=new JLabel("Tie Game. ");
            end=new JPanel();
            end.add(result,"North");
            end.add(again,"North");
            end.add(playAgainYes,"Center");
            end.add(playAgainNo,"Center");
        }
        if(results == 2)
        {
            result=new JLabel("You Win!!! ");
            end=new JPanel();
            end.add(result,"North");
            end.add(again,"North");
            end.add(playAgainYes,"Center");
            end.add(playAgainNo,"Center");
        }
        if(results == 3)
        {
            result=new JLabel("You Lose.");
            end=new JPanel();
            end.add(result,"North");
            end.add(again,"North");
            end.add(playAgainYes,"Center");
            end.add(playAgainNo,"Center");
        }
        something.add(end);
        something.validate();
        something.repaint();
    }
    // function to reset the board
    public void reset()
    {
        for(int i=1; i<10; i++)
        {
            positions[i] = 0;
            temp[i] = 0;
        }
        tie = 0;
        outcome = 0;
    }
    // Play the game
    public void jerry()
    {
        // if someone already moved there
        if(positions[n] != 0)
        {
            System.out.println("Can't go there.");
        }
        else
        {
                positions[n] = 1;
                temp[n] = n;
                terminate();
                if(outcome == 0)
                {
                    // AI picks place to go
                    for(int i = 1; i<10; i++)
                    {
                        if(positions[i] == 0)
                        {
                            positions[i] = 2;
                            temp[i] = i;
                            break;
                        }
                    }
                    terminate();
                    if(tie == 0)
                    {
                        tie();
                        if(numPlays == 9)
                        {
                            System.out.println("Tie Game.");
                            results = 1;
                            reset();
                            play();
                        }
                    }
                }
            }
        repaint();
    }
    
  // function to determine if there is a tie
    public void tie()
    {
        for(int i=1; i<10; i++)
        {
            if(positions[i] != 0)
            {
                numPlays++;
            }
        }
    }
    // function to determine if the game ends
    public void terminate()
    {
        if((positions[1] == 1) && (positions[2] == 1) && (positions[3] == 1))
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[4] == 1 && positions[5] == 1 && positions[6] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[7] == 1 && positions[8] == 1 && positions[9] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[1] == 1 && positions[5] == 1 && positions[9] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[3] == 1 && positions[5] == 1 && positions[7] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[2] == 1 && positions[4] == 1 && positions[7] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[2] == 1 && positions[6] == 1 && positions[9] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[8] == 1 && positions[4] == 1 && positions[1] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[8] == 1 && positions[6] == 1 && positions[3] == 1)
        {
            outcome = 1;
            tie = 1;
            results = 2;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[1] == 2 && positions[2] == 2 && positions[3] == 2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[4] == 2 && positions[5] == 2 && positions[6] == 2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[7] == 2 && positions[8] == 2 && positions[9] == 2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[1] == 2 && positions[5] == 2 && positions[9] == 2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[3] == 2 && positions[5] == 2 && positions[7] == 2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[2]==2 && positions[4]==2 && positions[7]==2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[2]==2 && positions[6]==2 && positions[9]==2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[8]==2 && positions[4]==2 && positions[1]==2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
        if(positions[8] == 2 && positions[6]==2 && positions[3]==2)
        {
            tie = 1;
            results = 3;
            reset();
            play();
        }
        else
        {
            numPlays = 0;
        }
    }
    
/**
 A class that creates, displays, and draws the x's and o's on a Jerry Tac Toe Board 
*/
class picture extends JPanel
{
    public void paintComponent(Graphics g)
    {
        // background
        g.setColor(Color.pink);
        g.fillRect(0,0,950,650);
        // circles
        g.setColor(Color.black);
        g.fillOval(0,0,50,50);
        
        g.setColor(Color.black);
        g.fillOval(450,0,50,50);
        
        g.setColor(Color.black);
        g.fillOval(900,0,50,50);
        
        g.setColor(Color.black);
        g.fillOval(225,300,50,50);
        
        g.setColor(Color.black);
        g.fillOval(450,300,50,50);
        
        g.setColor(Color.black);
        g.fillOval(675,300,50,50);
        
        g.setColor(Color.black);
        g.fillOval(0,600,50,50);
        
        g.setColor(Color.black);
        g.fillOval(450,600,50,50);
        
        g.setColor(Color.black);
        g.fillOval(900,600,50,50);
        
        // diagonal line from 1-5
        g.setColor(Color.black);
        g.drawLine(10,10,475,625);
        // diagonal line from 8-3
        g.setColor(Color.black);
        g.drawLine(940,10,475,625);
        // top horizontal line 1-3
        g.setColor(Color.black);
        g.drawLine(10,20,940,20);
        // bottom horizontal line 7-9
        g.setColor(Color.black);
        g.drawLine(10,630,940,625);
        // diagonal line from 2-7
        g.setColor(Color.black);
        g.drawLine(475,10,20,630);
        // diagonal line from 2-9
        g.setColor(Color.black);
        g.drawLine(475,10,930,625);
        // diagonal line from 1-9
        g.setColor(Color.black);
        g.drawLine(10,10,940,635);
        // diagonal line from 3-7
        g.setColor(Color.black);
        g.drawLine(10,630,930,10);
        // middle horizontal line 4-6
        g.setColor(Color.black);
        g.drawLine(225,325,675,325);

      
        // if statements to determine whether or not to fill with x or o
        if(TicTacToe.temp[1] == 1)
        {
            if(TicTacToe.positions[1] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(10,10,40,40);
                    g.setColor(Color.white);
                    g.drawLine(40,10,10,40);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(10,10,30,30);
                }
            }
            if(TicTacToe.positions[1] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(10,10,40,40);
                    g.setColor(Color.white);
                    g.drawLine(40,10,10,40);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(10,10,30,30);
                }
            }
        }
        if(TicTacToe.temp[2] == 2)
        {
            if(TicTacToe.positions[2] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,10,490,40);
                    g.setColor(Color.white);
                    g.drawLine(490,10,460,40);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,10,30,30);
                }
            }
            if(TicTacToe.positions[2] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,10,490,40);
                    g.setColor(Color.white);
                    g.drawLine(490,10,460,40);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,10,30,30);
                }
            }
        }
        if(TicTacToe.temp[3] == 3)
        {
            if(TicTacToe.positions[3] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(910,10,940,40);
                    g.setColor(Color.white);
                    g.drawLine(940,10,910,40);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(910,10,30,30);
                }
            }
            if(TicTacToe.positions[3] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(910,10,940,40);
                    g.setColor(Color.white);
                    g.drawLine(940,10,910,40);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(910,10,30,30);
                }
            }
        }
        if(TicTacToe.temp[4] == 4)
        {
            if(TicTacToe.positions[4] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(235,310,265,340);
                    g.setColor(Color.white);
                    g.drawLine(265,310,235,340);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(235,310,30,30);
                }
            }
            if(TicTacToe.positions[4] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(235,310,265,340);
                    g.setColor(Color.white);
                    g.drawLine(265,310,235,340);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(235,310,30,30);
                }
            }
        }
        if(TicTacToe.temp[5] == 5)
        {
            if(TicTacToe.positions[5] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,310,490,340);
                    g.setColor(Color.white);
                    g.drawLine(490,310,460,340);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,310,30,30);
                }
            }
            if(TicTacToe.positions[5] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,310,490,340);
                    g.setColor(Color.white);
                    g.drawLine(490,310,460,340);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,310,30,30);
                }
            }
        }
        if(TicTacToe.temp[6] == 6)
        {
            if(TicTacToe.positions[6] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(685,310,715,340);
                    g.setColor(Color.white);
                    g.drawLine(715,310,685,340);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(685,310,30,30);
                }
            }
            if(TicTacToe.positions[6] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(685,310,715,340);
                    g.setColor(Color.white);
                    g.drawLine(715,310,685,340);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(685,310,30,30);
                }
            }
        }
        if(TicTacToe.temp[7] == 7)
        {
            if(TicTacToe.positions[7] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(10,610,40,640);
                    g.setColor(Color.white);
                    g.drawLine(40,610,10,640);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(10,610,30,30);
                }
            }
            if(TicTacToe.positions[7] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(10,610,40,640);
                    g.setColor(Color.white);
                    g.drawLine(40,610,10,640);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(10,610,30,30);
                }
            }
        }
        if(TicTacToe.temp[8] == 8)
        {
            if(TicTacToe.positions[8] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,610,490,640);
                    g.setColor(Color.white);
                    g.drawLine(490,610,460,640);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,610,30,30);
                }
            }
            if(TicTacToe.positions[8] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(460,610,490,640);
                    g.setColor(Color.white);
                    g.drawLine(490,610,460,640);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(460,610,30,30);
                }
            }
        }
        if(TicTacToe.temp[9] == 9)
        {
            if(TicTacToe.positions[9] == 1)
            {
                if(TicTacToe.player == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(910,610,940,640);
                    g.setColor(Color.white);
                    g.drawLine(940,610,910,640);
                }
                if(TicTacToe.player == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(910,610,30,30);
                }
            }
            if(TicTacToe.positions[9] == 2)
            {
                if(TicTacToe.ai == "x")
                {
                    g.setColor(Color.white);
                    g.drawLine(910,610,940,640);
                    g.setColor(Color.white);
                    g.drawLine(940,610,910,640);
                }
                if(TicTacToe.ai == "o")
                {
                    g.setColor(Color.white);
                    g.drawOval(910,610,30,30);
                }
            }
        }
        
    }
}
	
/**
 Class to close window
*/
class Closer extends WindowAdapter
{
    public void windowClosing(WindowEvent e)
    {
        System.out.println("Goodbye.");
        System.exit(0);
    }
}
      
}