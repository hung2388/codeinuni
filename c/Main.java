public class Main {
    public static void main(String[] args) {
        BankAccount.balance = -1000; // as we can see here, it's can be set withought setter, which is extremely dangerous, a billionaire
				 //can become homeless in just a second.
    }
}