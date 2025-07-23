# CPP_42

CPP 05 

Ex03:

┌─────────────────┐    makeForm()    ┌─────────────────┐
│     INTERN      │ ───────────────▶ │   FACTORY       │
│ (Client)        │                  │ (Creator)       │
└─────────────────┘                  └─────────────────┘
                                              │
                     ┌────────────────────────┼────────────────────────┐
                     │                        │                        │
                     ▼                        ▼                        ▼
            ┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
            │ ShrubberyForm   │    │ RobotomyForm    │    │ PresidentialForm│
            │ (Product)       │    │ (Product)       │    │ (Product)       │
            └─────────────────┘    └─────────────────┘    └─────────────────┘

CPP 06 

Ex01 : 

## Avantages convertion :

- **Portabilité** : Les entiers sont plus faciles à manipuler que les pointeurs
- **Transmission** : On peut envoyer des "références" d'objets via réseau
- **Stockage** : Plus compact que de sauver tout l'objet
- **Indexation** : Utiliser comme clé unique dans des structures de données
- **Performance** : Comparaisons d'entiers plus rapides que de pointeurs

**En résumé** : Convertir une adresse en entier permet de **manipuler, stocker et transmettre des "références" d'objets** de manière plus flexible !
