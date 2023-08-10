import javax.swing.JPanel;
import java.io.File;
import java.util.Scanner;
import java.util.Arrays;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
public class MyPanel extends JPanel {
    MyPanel(){
    this.setPreferredSize(new Dimension(500,500));
    }
    public void paint (Graphics g){
        Graphics2D g2D = (Graphics2D) g;
       // g2D.drawLine(0,0,500,500);
       g2D.setPaint(Color.BLACK);
       g2D.drawOval(140, 60, 100, 100);
       g2D.drawOval(340, 60, 100, 100);
       g2D.drawOval(140, 170, 100, 100);
       g2D.drawOval(140, 280, 100, 100);
       g2D.drawOval(140, 390, 100, 100);
       g2D.drawString("sat 0", 170, 110);
       g2D.drawString("sat 1", 170, 220);
       g2D.drawString("sat 2", 170, 330);
       g2D.drawString("sat 3", 170, 440);
       g2D.drawOval(340, 223, 100, 100);
       g2D.drawOval(340, 390, 100, 100);
       g2D.drawString("sat 4", 370, 110);
       g2D.drawString("sat 5", 370, 273);
       g2D.drawString("sat 6", 370, 440);
       g2D.drawString("GS", 55, 280);
       g2D.drawRect(30, 240, 70, 70);
      
   
       int []data=readFiles("file3.txt");
       System.out.println(Arrays.toString(data));
       if(data.length>0){
       if(data[0]==0){
         g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 140, 110);
       }
      else if(data[0]==1){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 140, 220);
      }
      else if(data[0]==2){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 140, 330);
      }
      else if(data[0]==3){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 140, 440);
      }
      else if(data[0]==4){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 340, 110);
      }
      else if(data[0]==5){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(240, 440, 340, 273);
      }
      else if(data[0]==6){
        g2D.setPaint(Color.BLUE);
        g2D.drawLine(100, 275, 340, 440);
      }
      
     
       for(int i=0 ; i<data.length-1;i++){
        if(data[i]==4 && data[i+1]==0){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 110);
        }
        else if(data[i]==0 && data[i+1]==4){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 110);
        }
        else if(data[i]==0 && data[i+1]==5){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 273);
        }
        else if(data[i]==5 && data[i+1]==0){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 273);
        }
        else if(data[i]==0 && data[i+1]==6){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 440);
        }
        else if(data[i]==6 && data[i+1]==0){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 110, 340, 440);
        }
        else if(data[i]==1 && data[i+1]==4){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 110);
        }
        else if(data[i]==4 && data[i+1]==1){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 110);
        }
        else if(data[i]==1 && data[i+1]==5){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 273);
        }
        else if(data[i]==5 && data[i+1]==1){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 273);
        }
        else if(data[i]==1 && data[i+1]==6){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 440);
        }
        else if(data[i]==6 && data[i+1]==1){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 220, 340, 440);
        }
       

        if(data[i]==2 && data[i+1]==4){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 110);
        }
        else if(data[i]==4 && data[i+1]==2){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 110);
        }
        else if(data[i]==2 && data[i+1]==5){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 273);
        }
        else if(data[i]==5 && data[i+1]==2){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 273);
        }
        else if(data[i]==2 && data[i+1]==6){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 440);
        }
        else if(data[i]==6 && data[i+1]==2){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 330, 340, 440);
        }
        else if(data[i]==3 && data[i+1]==4){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 110);
        }
        else if(data[i]==4 && data[i+1]==3){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 110);
        }
        else if(data[i]==3 && data[i+1]==5){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 273);
        }
        else if(data[i]==5 && data[i+1]==3){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 273);
        }
        else if(data[i]==3 && data[i+1]==6){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 440);
        }
        else if(data[i]==6 && data[i+1]==3){
            g2D.setPaint(Color.BLUE);
            g2D.drawLine(240, 440, 340, 440);
        }



    }
}
else{
    g2D.drawString("Packet not sent", 243, 40);
}
     
    
    }
    private int[] readFiles(String file) {
        try{
            File f=new File(file);
            Scanner s=new Scanner(f);
            int ctr=0;
            while(s.hasNextInt()){
                ctr++;
                s.nextInt();
            }
            int []arr=new int[ctr];
            Scanner s1=new Scanner(f);
            for(int i=0 ;i<arr.length;i++){
                arr[i]=s1.nextInt();

            }
            return arr;
        }
        catch(Exception e){
            return null;
        }
    }
   
}
