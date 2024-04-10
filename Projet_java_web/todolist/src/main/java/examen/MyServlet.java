package examen;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;


/**
 * Servlet implementation class MyServlet
 */
public class MyServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MyServlet() {
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
		// TODO Auto-generated method stub
		//doGet(request, response);
		
		 // Récupérer les données du formulaire
        String titre = request.getParameter("titre");
        String description = request.getParameter("description");
        String importance = request.getParameter("importance");
        String dateEcheanceStr = request.getParameter("date_echeance");

        // Convertir la date d'échéance en objet Date
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date dateEcheance = null;
        try {
            dateEcheance = dateFormat.parse(dateEcheanceStr);
        } catch (ParseException e) {
            e.printStackTrace();
        }

        // Créer un objet Task avec les données récupérées
        Task nouvelleTache = new Task();
        nouvelleTache.setTitre(titre);
        nouvelleTache.setDescription(description);
        nouvelleTache.setImportance(importance);
        nouvelleTache.setDateEcheance(dateEcheance);
        
     // Définir le statut sur "À faire"
        nouvelleTache.setStatut("À faire");

        // Insérer la tâche dans la base de données
        ManageData manageData = new ManageData();
        try {
			manageData.insererTache(response,nouvelleTache);
		} catch (ClassNotFoundException | ServletException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

        // Rediriger l'utilisateur vers une page de confirmation
       // response.sendRedirect("confirmation.jsp");
    }
	

}