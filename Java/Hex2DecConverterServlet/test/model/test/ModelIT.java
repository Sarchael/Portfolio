package model.test;

import model.Model;
import model.MyException;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 * All tests apply to method calculate
 * 
 * @author Michal
 * @version 2.1
 */
public class ModelIT {
    
    Model model;
    
    //The same number in different notations
    final String hex = "2365A"; //expected dec2hex conversion result
    final String dec = "144986"; //expected hex2dec conversion result
    
    @Before
    public void setUp() {
        model = new Model();
    }
    
    /**
     * Test of normal conversion dec2hex
     */
    @Test
    public void testNormalDec2HexConversion() throws Exception {
        
        model.setMode("0");
        model.setNumber("144986");
            
        try{
            model.calculate();
            assertEquals("Normal dec2hex conversion", model.getResult(), hex);
        }
        catch(MyException me) {}
    }
    
    /**
     * Test of normal conversion hex2dec
     */
    @Test
    public void testNormalHex2DecConversion() throws Exception {
        
        model.setMode("1");
        model.setNumber("2365A");
        
        try{     
            model.calculate();
            assertEquals("Normal hex2dec conversion", model.getResult(), dec);
        }
        catch(MyException me){}
    }
    
    /**
     * Test of conversion dec2hex when set 0 as a number
     */
    @Test
    public void testZeroDec2HexConversion() throws Exception {
            
        model.setMode("0");
        model.setNumber("0");
            
        try{
            model.calculate();
            assertEquals("Zero dec2hex conversion", model.getResult(), "0");
        }
        catch(MyException me) {}
    }
    
    /**
     * Test of conversion hex2dec when set 0 as a number
     */
    @Test
    public void testZeroHex2DecConversion() throws Exception {
        
        model.setMode("1");
        model.setNumber("0");
        
        try{
            model.calculate();
            assertEquals("Zero hex2dec conversion", model.getResult(), "0");
        }
        catch(MyException me){}
    }
    
    /**
     * Test of conversion dec2hex when set negative number
     */
    @Test
    public void testNegativeDec2HexConversion() throws Exception {
            
        model.setMode("0");
        model.setNumber("-3291");
            
        try{
            model.calculate();
            fail("Should catch exception when set negative decimal number");
        }
        catch(MyException me) {}
    }
    
    /**
     * Test of conversion hex2dec when set negative number
     */
    @Test
    public void testNegativeHex2DecConversion() throws Exception {
        
        model.setMode("1");
        model.setNumber("-3291");
        
        try{
            model.calculate();
            fail("Should catch exception when set negative decimal number");
        }
        catch(MyException me){}
    }
    
    /**
     * Test of conversion dec2hex when set incorrect decimal number
     */
    @Test
    public void testIncorrectNumberDec2HexConversion() throws Exception {
        model.setMode("0");
        model.setNumber("wrong number");
        try{
            model.calculate();
            fail("Should catch exception when set incorrect decimal number");
        }
        catch(MyException me) {}
    }
    
    /**
     * Test of conversion hex2dec when set incorrect hexadecimal number
     */
    @Test
    public void testIncorrectNumberHex2DecConversion() throws Exception {
        model.setMode("1");
        model.setNumber("wrong number");
        try{
            model.calculate();
            fail("Should catch exception when set incorrect hexadecimal number");
        }
        catch(MyException me) {}
    }
    
    /**
     * Test of conversion when set incorrect mode
     */
    @Test
    public void testWrongModeConversion() throws Exception {
        model.setMode("3");
        model.setNumber("123");
        try{
            model.calculate();
            fail("Should catch exception when set incorrect mode");
        }
        catch(MyException me) {}
    }
}
