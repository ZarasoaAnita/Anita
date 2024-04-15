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

// Récupérer l'ID de la tâche et le statut
$taskId = $_POST['taskId'];
$newStatus = $_POST['taskStatus'];

// Vérifier si la case à cocher est cochée ou non
if (isset($_POST["taskCompleted"])) {
    $newStatus = 'Déjà réalisée';
} else {
    $newStatus = 'À faire';
}

// Préparation de la requête SQL pour mettre à jour le statut de la tâche
$commande = "UPDATE tache SET statut='$newStatus' WHERE id='$taskId'";
$resultat = mysqli_query($connexion, $commande);

// Vérifier si la mise à jour a réussi
if ($resultat) {
    // Redirection vers la page liste.php après la mise à jour
    header('Location: liste.php');
    exit(); // Assure que le script s'arrête ici pour éviter toute exécution supplémentaire
} else {
    // En cas d'échec de la mise à jour
    echo "Échec de la mise à jour : " . mysqli_error($connexion);
}

// Fermeture de la connexion
mysqli_close($connexion);
?>
