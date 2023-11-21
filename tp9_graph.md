````mermaid
flowchart TD
    START([DEBUT]) --> A[Déclarer la variable entier i]
    A --> B[Déclarer la variable char c]
    B --> C{i < 26 ?}
    C --OUI--> D["Définir c a 'A' + i (41 + i)"]
    D --> E[Afficher c sous forme de caractère, décimale et hexadecimal]
    E --> F[Incrémenter i de 1]
    F --> C
    C --NON--> END([FIN])
````