import javax.swing.JOptionPane; 
public class calculator {
	public static void main(String [] args)
	{
		String[] ops= {"+","-","*","/"};
		int choice=JOptionPane.showOptionDialog(null
				,"choosing feature"
				,"calculator"
				,JOptionPane.DEFAULT_OPTION
				,JOptionPane.PLAIN_MESSAGE
				,null
				,ops
				,ops[0]);
		double a=Double.parseDouble(JOptionPane.showInputDialog(null,"First number","First input",JOptionPane.PLAIN_MESSAGE));
		double b=Double.parseDouble(JOptionPane.showInputDialog(null,"Second number","Second input",JOptionPane.PLAIN_MESSAGE));
		if(choice==0) 
		{
			JOptionPane.showMessageDialog(null,a+"+"+b +"="+(a+b),"Result",JOptionPane.PLAIN_MESSAGE);
		}
		else if(choice==1)
		{
			JOptionPane.showMessageDialog(null,a+"-"+b +"="+(a-b),"Result",JOptionPane.PLAIN_MESSAGE);
		}
		else if(choice==2)
		{
			JOptionPane.showMessageDialog(null,a+"*"+b +"="+(a*b),"Result",JOptionPane.PLAIN_MESSAGE);
		}
		else if(choice==3)
		{
			if(b==0)
			{
				JOptionPane.showMessageDialog(null,"%ERROR%","Result",JOptionPane.PLAIN_MESSAGE);
				System.exit(0);
			}
			else
			JOptionPane.showMessageDialog(null,a+"/"+b +"="+(a/b),"Result",JOptionPane.PLAIN_MESSAGE);
		}
	}
}