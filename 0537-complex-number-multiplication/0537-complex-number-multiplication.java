class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        // (a+bi)*(c+di)
        // (ac-bd)+(ad+bc)i
        String[] s1= num1.split("\\+|i");
        String[] s2= num2.split("\\+|i");
        int a=Integer.parseInt(s1[0]);
        int b=Integer.parseInt(s1[1]);
        int c=Integer.parseInt(s2[0]);
        int d=Integer.parseInt(s2[1]);
        return (a*c-b*d)+"+"+(a*d+b*c)+"i";
    }
}