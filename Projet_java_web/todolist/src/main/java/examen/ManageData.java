package examen;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Types;
import java.util.Date;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.sql.ResultSet;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServletResponse;

public class ManageData {
    
    public ManageData() {
		
	}

    // Méthode pour insérer une tâche dans la base de données
    public void insererTache(HttpServletResponse response,Task tache) throws ClassNotFoundException , ServletException , IOException{
    	 String URL = "jdbc:mysql://localhost:3306/todolist";
    	 String USER = "iris";
    	 String PASSWORD = "motdepasse";
        Connection connection = null;
        PreparedStatement statement = null;

        try {
        	Class.forName("com.mysql.cj.jdbc.Driver");
        	
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
            String sql = "INSERT INTO tache (titre, description, importance, date_creation, date_echeance, statut) VALUES (?, ?, ?, ?, ?, ?)";
            statement = connection.prepareStatement(sql);
            statement.setString(1, tache.getTitre());
            statement.setString(2, tache.getDescription());
            statement.setString(3, tache.getImportance());
            statement.setDate(4, new java.sql.Date(new Date().getTime())); // Date de création
            
         // Vérifier si la date d'échéance est nulle avant de l'insérer dans la base de données
            if (tache.getDateEcheance() != null) {
                statement.setDate(5, new java.sql.Date(tache.getDateEcheance().getTime()));
            } else {
                statement.setNull(5, Types.DATE); // Utiliser NULL si la date d'échéance est nulle
            }
            
            statement.setString(6, tache.getStatut());

            int result = statement.executeUpdate();
            
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            if(result > 0) {
               out.println("<p>Enregistrement réussi !</p> <br> <a href=ServletList>Voir la liste des taches</a>");
            } else {
               out.println("<p>Échec de l'enregistrement.</p>");
            }
            
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (statement != null) {
                try {
                    statement.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
            if (connection != null) {
                try {
                    connection.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    
 // Méthode pour récupérer toutes les tâches de la base de données
    public List<Task> getAllTasks() throws ClassNotFoundException , SQLException {
        String URL = "jdbc:mysql://localhost:3306/todolist";
        String USER = "iris";
        String PASSWORD = "motdepasse";
        Connection connection = null;
        PreparedStatement statement = null;
        ResultSet resultSet = null;
        List<Task> taskList = new ArrayList<>();

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
            String sql = "SELECT * FROM tache";
            statement = connection.prepareStatement(sql);
            resultSet = statement.executeQuery();

            while (resultSet.next()) {
                Task task = new Task();
                task.setId(resultSet.getInt("id"));
                task.setTitre(resultSet.getString("titre"));
                task.setDescription(resultSet.getString("description"));
                task.setImportance(resultSet.getString("importance"));
                task.setDateCreation(resultSet.getDate("date_creation"));
                task.setDateEcheance(resultSet.getDate("date_echeance"));
                task.setStatut(resultSet.getString("statut"));
                taskList.add(task);
            }
        } finally {
            // Fermeture des ressources
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        }

        return taskList;
    }
 // Méthode pour mettre à jour le statut d'une tâche dans la base de données
    public void updateTaskStatus(int taskId, String newStatus) throws ClassNotFoundException, SQLException {
        String URL = "jdbc:mysql://localhost:3306/todolist";
        String USER = "iris";
        String PASSWORD = "motdepasse";
        Connection connection = null;
        PreparedStatement statement = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
            String sql = "UPDATE tache SET statut = ? WHERE id = ?";
            statement = connection.prepareStatement(sql);
            statement.setString(1, newStatus);
            statement.setInt(2, taskId);

            statement.executeUpdate();
        } finally {
            // Fermeture des ressources
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        }
    }
    
    public void deleteTask(int taskId) throws ClassNotFoundException, SQLException {
        String URL = "jdbc:mysql://localhost:3306/todolist";
        String USER = "iris";
        String PASSWORD = "motdepasse";
        Connection connection = null;
        PreparedStatement statement = null;

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(URL, USER, PASSWORD);
            String sql = "DELETE FROM tache WHERE id = ?";
            statement = connection.prepareStatement(sql);
            statement.setInt(1, taskId);

            statement.executeUpdate();
        } finally {
            // Fermeture des ressources
            if (statement != null) {
                statement.close();
            }
            if (connection != null) {
                connection.close();
            }
        }
    }

}

