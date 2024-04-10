package examen;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

/**
 * Servlet implementation class UpdateTaskStatusServlet
 */
public class UpdateTaskStatusServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdateTaskStatusServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		 try {
	            int taskId = Integer.parseInt(request.getParameter("taskId"));
	            String newStatus = request.getParameter("taskStatus");

	            // Vérifier si la case à cocher est cochée ou non
	            if (request.getParameter("taskCompleted") != null) {
	                newStatus = "Déjà réalisée";
	            } else {
	                newStatus = "À faire";
	            }

	            ManageData manageData = new ManageData();
	            manageData.updateTaskStatus(taskId, newStatus);

	         // Rediriger vers le servlet qui génère la liste des tâches
		        response.sendRedirect(request.getContextPath() + "/ServletList");
	        } catch (ClassNotFoundException | SQLException e) {
	            e.printStackTrace();
	        }
	}

}
