CREATE TABLE IF NOT EXISTS tache (
    id INT AUTO_INCREMENT PRIMARY KEY,
    titre VARCHAR(100) NOT NULL,
    description TEXT NOT NULL,
    importance ENUM('Faible', 'Moyenne', 'Élevée') DEFAULT 'Moyenne',
    date_creation DATE NOT NULL,
    date_echeance DATE,
    statut ENUM('À faire', 'Déjà réalisée') DEFAULT 'À faire'
);
