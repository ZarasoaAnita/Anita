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
            <th>Importance</th>
            <th>Date de création</th>
            <th>Date d'échéance</th>
            <th>Statut</th>
            <th>Actions</th>
        </tr>
        <?php 
            // Connexion à la base de données
            $server = "localhost";
            $user = "iris";
            $passwd = "motdepasse";
            $database = "todolist";
            $connexion = mysqli_connect($server, $user, $passwd, $database);

            // Vérifier la connexion
            if (!$connexion) {
                die("Échec de la connexion à MySQL : " . mysqli_connect_error());
            }

            // Préparation de la requête SQL
            $commande  = "SELECT * FROM tache";
            $resultat = mysqli_query($connexion, $commande);

            // Parcourir les résultats de la requête
            while ($row = mysqli_fetch_assoc($resultat)) {
        ?>
        <tr>
            <td><?php echo ($row['titre'] !== null) ? $row['titre'] : '-'; ?></td>
            <td><?php echo ($row['description'] !== null) ? $row['description'] : '-'; ?></td>
            <td><?php echo ($row['importance'] !== null) ? $row['importance'] : '-'; ?></td>
            <td><?php echo ($row['date_creation'] !== null) ? $row['date_creation'] : '-'; ?></td>
            <td><?php echo ($row['date_echeance'] !== null) ? $row['date_echeance'] : '-'; ?></td>
            <td><?php echo ($row['statut'] !== null) ? $row['statut'] : '-'; ?></td>
            <td class="action">
                <form action="update.php" method="post">
                    <input type="hidden" name="taskId" value="<?php echo $row['id']; ?>">
                    <input type="hidden" name="taskStatus" value="<?php echo $row['statut']; ?>">
                    <input class="check" type="checkbox" name="taskCompleted" <?php echo ($row['statut'] === "Déjà réalisée") ? "checked" : ""; ?> onchange="updateTaskStatus(this)">
                </form>
                <form action="delete.php" method="post">
                    <input type="hidden" name="taskId" value="<?php echo $row['id']; ?>">
                    <button type="submit">Supprimer</button>
                </form>
            </td>
        </tr>
        <?php 
            } 
            // Fermeture de la connexion
            mysqli_close($connexion);
        ?>
    </table>
    <div class="add">
        <a href="ajout.html" class="lien_gauche">Ajouter d'autres taches</a>
    </div>
        
   </div>
</body>
</html>
