import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class token{

}
public static void main()
{
    Map<String,Integer> map=new TreeMap<>();//string key, int value //tree map sort theo key
    Scanner scan=new Scanner(System.in);
    String s=scan.nextLine();
    s=s.toLowerCase();
    for(int i=0;i<s.length();i++)
    {
        String a="";
        while(i<s.length()&&Character.isLetterOrDigit(s.charAt(i)))
        {
            
            a+=s.charAt(i);
            i++;
        }
        if(map.containsKey(a))
        {
            map.put(a,map.get(a)+1);   
        }
        else
        {
            map.put(a,1);
        } 
    }
    int index=0;
    for(Map.Entry<String,Integer> e:map.entrySet())
    {
        System.out.print(e.getKey()+"="+e.getValue());
        index++;
        if(index<map.size())
        {
            System.out.print(", ");
        }
    }
}

