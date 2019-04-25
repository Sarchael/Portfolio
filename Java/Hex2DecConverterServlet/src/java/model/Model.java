package model;

import java.util.Collections;
import java.util.Vector;

/**
 * Model class (one of 3 classes from MVC pattern), contains number conversion algorithm hex2dec and dec2hex
 * Implements methods from interface Calculation
 * 
 * @author Michał Pocheć
 * @version 2.1
 */
public class Model implements Calculation {

    /**
     * converted number
     */
    private String number = "";

    /**
     * result of conversion
     */
    private String result = "";

    /**
     * mode of conversion ("1" - Hex2Dec or "0" - Dec2Hex)
     */
    private String mode = "";

    /**
     * contains all hexadecimal digits
     */
    private String pattern = "0123456789ABCDEF";

    /**
     * Set number to convertion
     *
     * @param number number to conversion
     */
    public void setNumber(String number) {
        this.number = number;
    }

    /**
     * Set mode of convertion
     *
     * @param mode mode of conversion
     */
    public void setMode(String mode) {
        this.mode = mode;
    }

    /**
     * Main method of this class, check type of conversion and perform appropriate methods
     * Overrides method from Calculation interface
     *
     * @exception MyException when user enter unsupported mode
     */
    @Override
    public void calculate() throws MyException {
        
        if(number.length() == 0)
            throw new MyException("Enter correct number !!!");
        if(mode == null)
            throw new MyException("Mode is null !!!");
        if (mode.equals("0")) {
            dec2hex();
        } else if (mode.equals("1")) {
            hex2dec();
        } else //Throw exception when it is not hex2dec or dec2hex conversion
        {
            throw new MyException("Enter correct mode !!!");
        }
    }

    /**
     * Convert hexadecimal number into decimal number
     *
     * @exception MyException when user enter a non-hexadecimal number
     */
    
    private void hex2dec() throws MyException {

        int temporaryResult = 0;
        Vector<String> hexnumber = new Vector(); 
        
        for(int i = 0; i < number.length(); i++){
            //Convert string into safe collection of Strings
            hexnumber.add(number.substring(i, i + 1).toUpperCase());
        }
        
        //Lambda expression reverse hexadecimal number for easier counting
        Reverser<Vector<String>, Vector<String>> reverser = v -> {
            for(int i = 0; i < v.size() / 2; i++)
                Collections.swap(v, i, v.size() - i - 1);
            return v;
        }; 
        
        hexnumber = reverser.reverse(hexnumber);
        
        //check if a number is grater than 0
        if(hexnumber.elementAt(hexnumber.size()-1).equals("-"))
            throw new MyException("A negative number!!!");
        
        int index = hexnumber.size(); //number of hexadecimal digits
        for(String s: hexnumber){
            //Eheck if a digit comes from pattern
            if(!pattern.contains(s))//Error when user enter a non-hexadecimal number
                throw new MyException("Incorrect hexadecimal number !!!");
            else{
                //In every iteration add the value of single hexadecimal digit
                temporaryResult += pattern.indexOf(s) * Math.pow(16, hexnumber.size()-index);
                index--;
            } 
        }
        
        //Turn the result of conversion into string
        result = "" + temporaryResult;
    }

    /**
     * Convert decimal number into hexadecimal number
     *
     * @exception MyException when user enter a non-decimal number
     */
    private void dec2hex() throws MyException {

        //Rest from division
        int modulus;
        //Represents single hexadecimal digit
        String temp;
        Integer decimalNumber;
        //Determines if there were an error or not
        Boolean error = false;
        result="";

        try {
            //Parse number for further calculations
            decimalNumber = Integer.parseInt(number);
        } catch (NumberFormatException nfe) {
            //Error when user enter a non-decimal number
            error = true;
            throw new MyException("Incorrect decimal number !!!");
        }
        
        if (error.equals(false)) {
            //check if a number is grater than 0
            if(decimalNumber < 0)
                throw new MyException("A negative number!!!");
            
            if(decimalNumber.equals(0))
                result = "0";
            
            while (!decimalNumber.equals(0)) {
                modulus = decimalNumber % 16;
                decimalNumber /= 16;
                //Take appropriate hexadecimal digit from pattern
                temp = pattern.substring(modulus, modulus + 1);
                //Adding one hexadecimal digit in every iteration
                result = temp + result;
            }
        }
    }

    /**
     * Return result of convertion
     *
     * @return result result of conversion
     */
    public String getResult() {
        return result;
    }
    
    /**
     * Functional interface for reversing series
     */
    @FunctionalInterface
    interface Reverser<V, R> {
        
        R reverse(V vector);
    }
}
