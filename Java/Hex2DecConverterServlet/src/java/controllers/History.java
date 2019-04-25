package controllers;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * This class realise servlet that show history of conversions
 * 
 * @author Michal
 * @version 1.0
 */
public class History extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter outStream = response.getWriter();

        HttpSession session = request.getSession(true);

        Connection connection;
        if ((Connection)session.getAttribute("db") == null){    
            try {
                Class.forName(getInitParameter("driver"));
                connection = DriverManager.getConnection(getInitParameter("url"), getInitParameter("user"), getInitParameter("password"));
                session.setAttribute("db", connection);
            } catch (SQLException | ClassNotFoundException ex) {
                response.sendError(HttpServletResponse.SC_BAD_REQUEST, ex.getMessage());
            }            
        }
        
        connection = (Connection) session.getAttribute("db");        
        
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM HISTORY");
            if(!rs.next())
                outStream.println("Your data base history is empty!");
            else{
                outStream.println("Your data base history of converting:<br>");
                while (rs.next())
                    outStream.println(rs.getString("BEFORE") + " --> " + rs.getString("AFTER") + "<br>");
            }
        } catch (SQLException ex) {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, ex.getMessage());
        }
       
        
        Cookie[] history = request.getCookies();
        if(history == null){
            outStream.println("<hr>Your cookies history is empty!");
        }
        else{
            outStream.println("<hr>Your cookies history of converting:<br>");
            for(Cookie cookie: history)
                if(cookie.getName().substring(0, 7).equals("history"))
                    outStream.println(cookie.getValue()+"<br>");
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
