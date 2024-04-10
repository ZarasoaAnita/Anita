package examen;

import java.util.Date;

public class Task {
    private int id;
    private String titre;
    private String description;
    private String importance;
    private Date dateCreation;
    private Date dateEcheance;
    private String statut;

    // Constructeur par défaut
    public Task() {
    }

    // Constructeur avec tous les champs
    public Task(int id, String titre, String description, String importance, Date dateCreation, Date dateEcheance, String statut) {
        this.id = id;
        this.titre = titre;
        this.description = description;
        this.importance = importance;
        this.dateCreation = dateCreation;
        this.dateEcheance = dateEcheance;
        this.statut = statut;
    }

    // Getters et setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitre() {
        return titre;
    }

    public void setTitre(String titre) {
        this.titre = titre;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getImportance() {
        return importance;
    }

    public void setImportance(String importance) {
        this.importance = importance;
    }

    public Date getDateCreation() {
        return dateCreation;
    }

    public void setDateCreation(Date dateCreation) {
        this.dateCreation = dateCreation;
    }

    public Date getDateEcheance() {
        return dateEcheance;
    }

    public void setDateEcheance(Date dateEcheance) {
        this.dateEcheance = dateEcheance;
    }

    public String getStatut() {
        return statut;
    }

    public void setStatut(String statut) {
        this.statut = statut;
    }
}

