## 🌟 À quoi ça sert ?
La sérialisation (ici avec serialize()) consiste à transformer un pointeur en un entier (uintptr_t). Inversement, la désérialisation (deserialize()) permet de retrouver l’adresse originale à partir de cet entier.

## 👉 Pourquoi ?

Sauvegarder ou transmettre des pointeurs sous forme « brute » (par ex. en réseau ou dans un fichier binaire).

Manipuler l’adresse mémoire sous forme d’un entier (par exemple, pour du debug ou du hacking mémoire).

Utiliser un pointeur comme identifiant unique (ex. : une clé dans une map, une valeur à envoyer à un autre processus…).

## 📦 Dans quel cas c’est utile ?
✅ Quand tu as besoin de stocker un pointeur sous forme d’entier (pour l’envoyer ailleurs, ou le sauvegarder temporairement).
✅ En bas niveau (ex. : dans un OS, un pilote, ou un réseau), car les pointeurs ne peuvent pas toujours être transmis directement.
✅ Dans la manipulation « dirty » (hacking, pointeurs, allocateurs mémoire, etc.).