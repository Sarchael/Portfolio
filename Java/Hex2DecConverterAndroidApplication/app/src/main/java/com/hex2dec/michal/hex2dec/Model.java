package com.hex2dec.michal.hex2dec;

import com.hex2dec.michal.hex2dec.MyException;

/**
 * Model class (one of 3 classes from MVC pattern),
 * contains number conversion algorithm hex2dec and dec2hex
 *
 * @author MichaĹ‚ PocheÄ‡
 * @version 1.1
 */

public class Model {

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
    public void setNumber(String number){
        this.number = "";
        this.number = number;
    }

    /**
     * Set mode of convertion
     *
     * @param mode mode of conversion
     */
    public void setMode(String mode){
        this.mode = mode;
    }

    /**
     * Main method of this class, check type of conversion and perform
     * appropriate methods
     *
     * @exception MyException when user enter unsupported mode
     */
    public void calculate() throws MyException {

        if(mode.equals("0"))
            dec2hex();
        else if (mode.equals("1"))
            hex2dec();
        else
            //Throw exception when it is not hex2dec or dec2hex conversion
            throw new MyException("Enter correct mode !!!");
    }

    /**
     * Convert hexadecimal number into decimal number
     *
     * @exception MyException when user enter a non-hexadecimal number
     */
    private void hex2dec() throws MyException{

        if(number.equals(""))
            throw new MyException("Incorrect hexadecimal number !!!");
        int temporaryResult = 0;

        for(int i = number.length(); i > 0; i--){
            //Eheck if a digit comes from pattern
            if(!pattern.contains(number.substring(i-1, i).toUpperCase()))
                //Error when user enter a non-hexadecimal number
                throw new MyException("Incorrect hexadecimal number !!!");
            else{
                //In every iteration add the value of single hexadecimal digit
                temporaryResult += pattern.indexOf(number.substring(i-1, i).toUpperCase()) * Math.pow(16, number.length() - i);
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
    private void dec2hex() throws MyException{

        //Rest from division
        int modulus = 0;
        //Represents single hexadecimal digit
        String temp = "";
        Integer decimalNumber = 0;
        //Determines if there were an error or not
        Boolean error = false;
        result = "";

        try{
            //Parse number for further calculations
            decimalNumber = Integer.parseInt(number);
            if (decimalNumber < 0)
                throw new MyException("Set positive number !!!");
        }
        catch(NumberFormatException nfe){
            //Error when user enter a non-decimal number
            error = true;
            throw new MyException("Incorrect decimal number !!!");
        }



        if(error.equals(false))
            while(!decimalNumber.equals(0)){
                modulus = decimalNumber % 16;
                decimalNumber /= 16;
                //Take appropriate hexadecimal digit from pattern
                temp = pattern.substring(modulus, modulus + 1);
                //Adding one hexadecimal digit in every iteration
                result = temp + result;
            }
    }

    /**
     * Return result of convertion
     *
     * @return result result of conversion
     */
    public String getResult(){
        return result;
    }
}