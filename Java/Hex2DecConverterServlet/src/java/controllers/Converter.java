package controllers;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import model.Model;
import model.MyException;

/**
 * This class realise servlet that convert decimals to hexadecimals and hexadecimals to decimals
 * 
 * @author Michal
 * @version 1.0
 */
public class Converter extends HttpServlet {

    /*
    * Model object
    */
    private final Model model;
    
    /*
    * Counter to count the number of conversions
    */
    private Integer counter = 0;
    
    /*
    * Constructor that initialize model object
    */
    public Converter(){
        model = new Model();
    }
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter outStream = response.getWriter();
        
        HttpSession session = request.getSession(true);

        if ((Connection)session.getAttribute("db") == null){
            Connection connection;
            try {
                Class.forName(getInitParameter("driver"));
                connection = DriverManager.getConnection(getInitParameter("url"), getInitParameter("user"), getInitParameter("password"));
                session.setAttribute("db", connection);
            } catch (SQLException | ClassNotFoundException ex) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, ex.getMessage());
            }
            
        }
        
        
        String number = request.getParameter("number");
        String type = request.getParameter("type");
        
        model.setNumber(number);
        model.setMode(type);
        
        try{
            model.calculate();
            String result = "Your number: " + number + ", converted number: " + model.getResult();
            outStream.println(result);
            Cookie cookie = new Cookie("history" + counter.toString(), result);
            response.addCookie(cookie);
            
            
            Connection connection = (Connection) session.getAttribute("db"); //insert result to database
            Statement statement = connection.createStatement();
            statement.executeUpdate("INSERT INTO HISTORY VALUES (" + "'" + number + "'," + "'" + model.getResult() + "')");

            counter++;
        }
        catch(MyException | SQLException ex){
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, ex.getMessage());
        }
    }

    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
