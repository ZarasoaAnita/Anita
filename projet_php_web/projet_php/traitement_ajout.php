<?php
// Vérifier si la requête est de type POST
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $server = "localhost";
    $user = "iris";
    $passwd = "motdepasse";
    $database = "todolist";

    // Connexion à la base de données
    $connexion = mysqli_connect($server, $user, $passwd, $database);

    // Vérifier la connexion
    if (!$connexion) {
        die("Échec de la connexion à MySQL : " . mysqli_connect_error());
    } else {
        echo "Connexion réussie<br>";

        // Récupérer les données du formulaire
        //$titre = $_POST["titre"];
        //$description = $_POST["description"];
        $titre = mysqli_real_escape_string($connexion, $_POST["titre"]);
        $description = mysqli_real_escape_string($connexion, $_POST["description"]);
        $importance = $_POST["importance"];
        $dateEcheanceStr = $_POST["date_echeance"];

        // Date de création (aujourd'hui)
        $dateCreation = date('Y-m-d');

        // Préparation de la requête SQL
        $commande = "INSERT INTO tache (titre, description, importance, date_creation, date_echeance, statut) VALUES ('$titre', '$description', '$importance', '$dateCreation', '$dateEcheanceStr', 'À faire')";

        // Exécution de la requête
        $resultat = mysqli_query($connexion, $commande);

        // // Vérifier si l'insertion a réussi
        // if ($resultat) {
        //     echo "<p>Enregistrement réussi !</p><br><a href='ServletList.php'>Voir la liste des tâches</a>";
        // } else {
        //     echo "<p>Échec de l'enregistrement : " . mysqli_error($connexion) . "</p>";
        // }

        if ($resultat) {
            // Redirection vers la page de la liste des tâches
            header("Location: liste.php");
            exit; // Assure que le script ne continue pas à s'exécuter après la redirection
        } else {
            echo "<p>Échec de l'enregistrement : " . mysqli_error($connexion) . "</p>";
        }

        // Fermeture de la connexion
        mysqli_close($connexion);
    }
}
?>
