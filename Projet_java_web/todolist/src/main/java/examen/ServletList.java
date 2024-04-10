package examen;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

/**
 * Servlet implementation class ServletList
 */
public class ServletList extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletList() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
		
		System.out.println("OK");
		  // Récupérer toutes les tâches de la base de données
	    ManageData manageData = new ManageData();
	    List<Task> taskList = null;
	    try {
	        taskList = manageData.getAllTasks();
	    } catch (ClassNotFoundException | SQLException e) {
	        e.printStackTrace();
	        // Gérer les erreurs de récupération des tâches
	    }
	    
	    // Passer la liste de tâches à la page JSP pour affichage
	    request.setAttribute("taskList", taskList);
	    request.getRequestDispatcher("taskList.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
