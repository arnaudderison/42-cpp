# Recap Module 09 (STL)

## Rappels globaux
- C++98 obligatoire (`-std=c++98`, `-Wall -Wextra -Werror`).
- STL autorisee uniquement dans les modules 08 et 09.
- Interdits: `printf`, `malloc/alloc/free`, `using namespace`, `friend` (sauf mention explicite).
- Forme canonique (Orthodox Canonical Form) pour les classes sauf exception.
- Pas d'implementation non-template dans les headers.
- Headers autonomes + include guards.
- Chaque exercice: containers imposes. Un container utilise dans un ex est interdit pour les suivants.

## ex00 — Bitcoin Exchange
**But**: Calculer la valeur d'un montant de BTC a une date donnee, via une base CSV.

**Notions importantes**
- Parsing fichier d'entree au format `date | value`.
- Validation stricte de date `YYYY-MM-DD` (mois, jours, annees bissextiles).
- Validation valeur: float ou int positif, `0 <= value <= 1000`.
- Utiliser la date la plus proche **inferieure** si la date n'existe pas dans la DB.
- Gestion d'erreurs propre (fichier manquant, date invalide, valeur invalide).
- Utilisation d'au moins un container STL (souvent `std::map`).

**Sortie**
- `YYYY-MM-DD => value = result`
- Messages d'erreur conformes aux exemples.

## ex01 — RPN (Reverse Polish Notation)
**But**: Evaluer une expression RPN passee en argument.

**Notions importantes**
- Tokenisation par espaces, operations `+ - * /`.
- Operandes < 10, pas de decimaux, pas de parentheses.
- Utiliser un container STL (souvent `std::stack`).
- Gestion d'erreurs: token invalide, division par zero, pile insuffisante, reste d'elements.
- Resultat sur stdout, erreurs sur stderr.

## ex02 — PmergeMe
**But**: Trier une sequence d'entiers positifs avec Ford-Johnson (merge-insert).

**Notions importantes**
- Parser des entiers positifs (refuser negatifs, non-numeriques, overflow).
- Utiliser **deux** containers STL differents (ex: `std::vector` + `std::deque`).
- Gerer au moins 3000 entiers.
- Mesurer et afficher le temps pour chaque container (tri + gestion donnees).
- Affichage impose:
  - `Before: ...`
  - `After: ...`
  - Temps container 1
  - Temps container 2
- L'algorithme Ford-Johnson doit etre implante (recommandation: une version par container).

