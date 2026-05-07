public class Myvalue extends Object{
    private int value;
    public Myvalue(int value)
    {
        this.value=value;
    }
    @Override
    public boolean equals(Object o){
        if(o instanceof Myvalue)
        {
            Myvalue val=(Myvalue)o;
            if(val.value==this.value) 
            return true;
        }
        return false;
    }
}