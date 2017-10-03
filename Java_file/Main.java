import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    static InputStream in;
    static PrintStream out;
    static {
    
    }
    public static void main(String args[])
    {
        String file = "brackets";

        BigInteger f[][] =new BigInteger[220][220];
        try  
        {  
            Scanner cin = new Scanner(new File("brackets.in"));
            PrintWriter pw=new PrintWriter(new FileOutputStream("brackets.out"));  
      
            for(int i=0;i<=200;i++) {
                for(int j=0;j<=200;j++) 
                    f[i][j]=BigInteger.valueOf(0);
            }

            f[2][1] = BigInteger.valueOf(1);
            f[0][0]=BigInteger.valueOf(1);
            for(int i=4;i<=100;i+=2) {
                for(int j=1;j<=i/2;j++) {
                    if (j==1) f[i][j]=f[2][1];
                    else {
                        f[i][j]=f[i-2][j-1];
                        for(int l=2;l<=i-2;l+=2) {
                            for(int t=1;t<j;t++) {
                                f[i][j]=f[i][j].add(f[l-2][j-1].multiply(f[i-l][t]));
                                f[i][j]=f[i][j].add(f[l-2][t-1].multiply(f[i-l][j]));
                            }
                            f[i][j]=f[i][j].add(f[l-2][j-1].multiply(f[i-l][j]));
                        }
                    }
                }
            }
            int k,kcase=1,n;
            while(true) {
                n = 2*cin.nextInt();
                k = cin.nextInt();
                if (0==n&&0==k) {
                    break;
                }         
                pw.println("Case "+kcase + ": "+f[n][k].toString()+'\n');
                kcase++;

            }
    
            pw.close();
        }  
        catch (IOException e)  
        {  
            e.printStackTrace();  
        }  
    }
}
