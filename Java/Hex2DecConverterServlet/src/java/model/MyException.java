package model;

/**
 * Exception class for objects thrown when trying to do forbidden actions
 *
 * @author Michał Pocheć
 * @version 2.1
 */
public class MyException extends Exception {

    /**
     * Non-parameter constructor
     */
    public MyException() {

    }

    /**
     * Constructor
     *
     * @param message consist message to display
     */
    public MyException(String message) {
        super(message);
    }
}
