package examen;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

/**
 * Servlet implementation class DeleteTaskServlet
 */
public class DeleteTaskServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteTaskServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		 try {
		        // Récupérer l'ID de la tâche à supprimer
		        int taskId = Integer.parseInt(request.getParameter("taskId"));

		        // Supprimer la tâche de la base de données
		        ManageData manageData = new ManageData();
		        manageData.deleteTask(taskId);

		     // Rediriger vers le servlet qui génère la liste des tâches
		        response.sendRedirect(request.getContextPath() + "/ServletList");
		    } catch (NumberFormatException e) {
		        // Gérer l'exception si le paramètre "taskId" n'est pas un entier valide
		        e.printStackTrace(); // Ou autre traitement d'erreur
		    } catch (ClassNotFoundException | SQLException e) {
		        // Gérer l'exception si une erreur se produit lors de la suppression de la tâche
		        e.printStackTrace(); // Ou autre traitement d'erreur
		    }
		 
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
