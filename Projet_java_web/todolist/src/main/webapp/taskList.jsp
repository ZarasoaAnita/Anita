<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="examen.ManageData, examen.Task" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Liste des tâches</title>
    <link href="style_list.css" rel="stylesheet">
    <script>
        function updateTaskStatus(checkbox) {
            var form = checkbox.form;
            if (checkbox.checked) {
                form.elements['taskStatus'].value = 'Déjà réalisée';
            } else {
                form.elements['taskStatus'].value = 'À faire';
            }
            // Soumission automatique du formulaire lorsqu'il y a un changement de statut
            form.submit();
        }
    </script>
</head>
<body>
<div class="contenu-au-milieu">
    
    <table border="1">
    
    		<h1>To DO List</h1>
    		
        <tr>
            <th>Titre</th>
            <th>Description</th>
            <th>Date de création</th>
            <th>Date d'échéance</th>
            <th>Statut</th>
            <th>Actions</th>
        </tr>
        <% 
            ManageData manageData = new ManageData();
            List<Task> taskList = manageData.getAllTasks();
            // Débogage : Afficher le nombre total de tâches récupérées
           // out.println("Nombre total de tâches : " + taskList.size());
            for (Task task : taskList) {
        %>
        <tr>
            <td><%= (task.getTitre() != null) ? task.getTitre() : "-" %></td>
            <td><%= (task.getDescription() != null) ? task.getDescription() : "-" %></td>
            <td><%= (task.getDateCreation() != null) ? task.getDateCreation() : "-" %></td>
            <td><%= (task.getDateEcheance() != null) ? task.getDateEcheance() : "-" %></td>
            <td><%= task.getStatut() %></td>
            <td class="action">
                <form action="UpdateTaskStatusServlet" method="post">
                    <input type="hidden" name="taskId" value="<%= task.getId() %>">
                    <input type="hidden" name="taskStatus" value="<%= task.getStatut() %>">
                    <input class = "check" type="checkbox" name="taskCompleted" <%= (task.getStatut().equals("Déjà réalisée")) ? "checked" : "" %> onchange="updateTaskStatus(this)">
                </form>
          
                <form action="DeleteTaskServlet" method="post">
                    <input type="hidden" name="taskId" value="<%= task.getId() %>">
                    <button type="submit">Supprimer</button>
                </form>
            </td>
        </tr>
        <% } %>
    </table>
    	<!-- Lien vers la page d'ajout de tâches -->
    	
   </div>
</body>
</html>
