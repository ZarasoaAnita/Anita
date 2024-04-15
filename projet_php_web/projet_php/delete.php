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

// Récupérer l'ID de la tâche à supprimer
$taskId = $_POST['taskId'];

// Préparation de la requête SQL pour supprimer la tâche de la base de données
$commande = "DELETE FROM tache WHERE id='$taskId'";
$resultat = mysqli_query($connexion, $commande);

// Vérifier si la suppression a réussi
if ($resultat) {
    // Redirection vers la page liste.php après la suppression
    header('Location: liste.php');
    exit(); // Assure que le script s'arrête ici pour éviter toute exécution supplémentaire
} else {
    // En cas d'échec de la suppression
    echo "Échec de la suppression de la tâche : " . mysqli_error($connexion);
}

// Fermeture de la connexion
mysqli_close($connexion);
?>
