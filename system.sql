CREATE TABLE EMPLOYES (
    ID_employe NUMBER PRIMARY KEY,
    Nom VARCHAR(20),
    Prenom VARCHAR(20),
    telephone NUMBER,
    poste VARCHAR(20),
    Salaire NUMBER(5,3),
    presences NUMBER,
    D_date DATE,
    F_date DATE,
    ID_directeur NUMBER, 
    FOREIGN KEY (ID_directeur) REFERENCES EMPLOYES(ID_employe)
);
Create table CLIENTS (
ID_client number primary key,
Nom_complet varchar(20),
date_naissance  date,
demande_special varchar(20),
Statut varchar(20),
pays varchar(20),
telephone number,
total_points number
) ;
CREATE TABLE RESERVATIONS (
    ID_reservation NUMBER PRIMARY KEY,
    date_reservation DATE,
    date_arrivé DATE,
    date_depart DATE,
    type_chambre VARCHAR(20),
    statut_reservation VARCHAR(20),
    mode_paiment VARCHAR(20),
    montant NUMBER,
    ID_client NUMBER,
    FOREIGN KEY (ID_client) REFERENCES CLIENTS(ID_client)
);
CREATE TABLE STOCKS (
    ID_stocks NUMBER PRIMARY KEY,
    nom VARCHAR(20),
    produit VARCHAR(20),
    quantité NUMBER,
    date_entrée DATE,
    date_reaprovisionnement DATE,
    ID_employe NUMBER,
    FOREIGN KEY (ID_employe) REFERENCES EMPLOYES(ID_employe)
);
CREATE TABLE MAINTENANCES (
    ID_maintenance NUMBER PRIMARY KEY,
    chambre_concernée VARCHAR(20),
    type_maintenance VARCHAR(20),
    date_debut DATE,
    date_fin DATE,
    statut_maintenance VARCHAR(20),
    ID_reservation NUMBER,
    ID_employe NUMBER,
    FOREIGN KEY (ID_reservation) REFERENCES RESERVATIONS(ID_reservation),
    FOREIGN KEY (ID_employe) REFERENCES EMPLOYES(ID_employe)
);
CREATE TABLE GERER (
    ID_employe NUMBER,
    ID_reservation NUMBER,
    PRIMARY KEY (ID_employe, ID_reservation),
    FOREIGN KEY (ID_employe) REFERENCES EMPLOYES(ID_employe),
    FOREIGN KEY (ID_reservation) REFERENCES RESERVATIONS(ID_reservation)
);
CREATE TABLE UTILISER (
    ID_stocks NUMBER,
    ID_maintenance NUMBER,
    PRIMARY KEY (ID_stocks, ID_maintenance),
    FOREIGN KEY (ID_stocks) REFERENCES STOCKS(ID_stocks),
    FOREIGN KEY (ID_maintenance) REFERENCES MAINTENANCES(ID_maintenance)
);
CREATE TABLE CONSOMMER (
    ID_stocks NUMBER,
    ID_client NUMBER,
    PRIMARY KEY (ID_stocks, ID_client),
    FOREIGN KEY (ID_stocks) REFERENCES STOCKS(ID_stocks),
    FOREIGN KEY (ID_client) REFERENCES CLIENTS(ID_client)
);

