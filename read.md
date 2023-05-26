# Projet de Naggara Samir

Ce projet consiste à trier des nombres en utilisant 2 tas différents.
Si vous ne connaissez pas le sujet, il est disponible sur ce git ou sur internet.

Dans ce readme je parle de backtraking, si vous ne connaissez pas, vous pouvez vous renseigner dessus.
Dans ce readme, je parle de l'algorythme Radix.
Si vous ne le connaissez pas, vous pouvez vous renseigner dessus avant de continuer.

## Général

De manière générale, je stock les informations des 2 piles dans une double liste chainée circulaire.
Et toutes les variables du projet sont stockés dans une structure data

J'ai des opérations capable de réaliser les moves, directement entre a et b.
Par exemple, ft_pa push directement b dans a, et renvoie 1 si ça a fonctionné

J'ai créé un tableau de fonction qui pointent vers des fonctions
Ainsi 	data->move_func[0] c'est sa
		data->move_func[1] c'est sb
		...

Ainsi chaque combinaison a un équivalent numérique.
C'est plus facile a stocké dans un tableau d'entier int *.
Et plus facile à parcourir

J'ai meme un tableau de fonction avec leurs opposées, genre l'opposé de sa c'est sa
L'opposé de ra c'est rra, etc.
C'est utile pour si je veux revenir en arriere sur un move pendant l'étape de bruteforce


## Parsing

On renvoie "Error\n" lorsqu'une situation ne nous convient pas.
Si par exemple, un argument n'est pas un nombre.
Ou un nombre trop grand.
Le erreur est renvoyer sur le stder, le output des messages d'erreurs.
En cas d'erreur, tout est free, puis on exit le programme.

Si le programe est deja trier, je stop le programme en ne renvoyant rien.

## Le brute force en back tracking

J'ai tenté le brute force pour apprendre à gérer le backtracking.
Le principe est :
	Je pars du principe qu'il existe une réponse avec une seule combinaison
	Je test la premiere combinaison, par exemple pb
	Si elle ne marche pas, je fais son coup opposé pour revenir en arriere. Ici, pa.
	Puis je test la possibilité d'apres.

Si aucune ne marche, alors je test avec 2 combinaisons.
Si aucune ne marche, alors je test avec 3, etc...

Pour consommer moins de memoire, je tente de ne meme pas essayé les possiblités incohérentes.
Par exemple, il est impossible de finir avec un pb.
Ou de commencer avec pa.

Mais même en guidant les possibilités, je stackoverflow tres tres vite.



Comme il fallait absolument que cette méthode genre jusqu'à 5 nombre, et qu'elle en gérais uniquement 4, j'ai sacrifié la performance.
ici, on test moins de coup mais on reussis bruteforcer jusqu'à 5.
Il ne teste plus rra, rrb, rrr, ss, et meme sb !
Donc forcement c'est moins performant, mais ça passe.

## Radix

Tout le reste est géré avec radix.
Radix utilise au final uniquement pa pb et ra pour trier la liste.
L'ordre des étapes est le suivant :

### Optimisation
Radix sera d'autant plus efficace que la longeur binaire de son nombre le plus grand, est petite.
Par exemple trier 121651 et 4 lui prendra enormement de coup.
Parce que le binaire de 121651 est : 11101101100110011
Donc pour les 17 bits, on va devoir trier la liste en utilisant le bit en question, et donc faire des pa, pb et ra.
Donc je pars du principe que trier 4 et 121651, bah c'est pareil que de trier 1 et 0.

Exactement les même move.

Sauf que la en binaire il n'y a qu'une seul digit, donc il le traite plus vite.

Donc cette étape optimise en ramenant la suite de nombre a une suite de 0, 1, 2, 3... gardé dans le même ordre que les nombres d'origines

### Compte le nombre de combinaison

Combien de combinaisons vas t on avoir besoin ?
C'est indispensable de le savoir pour malloc notre tableau de combinaison qui contiendra le resultat.
En vrai c'est facile, on prends chaque bit de chaque nombre, si c'est un 0 il ne sera pas poussé dans b, on le passera juste avec un RA, donc on incremente notre nombre de combinaison de 1.
Mais si on croise un 1, bah la il faut incrementer de 2, parce que dans un premier temps on va le PB, puis le PA

### Radix
Maintenant, on applique l'algo.
Je boucle pour chaque digit, de 0 à la longueur max de bit (que j'ai calculé avant).
Par exemple si le nombre max est 12 (sur la liste optimisée), 12 c'est 1100 en binaire.
Il y a 4 chiffres signification, donc on va boucler sur 4 digits.

Pour chaque digit donc, on parcours la liste chainée.
	Si on croise un 0, on fait ra.
	Si on croise un 1, on fait pb (on le push dans b).

	Une fois qu'on a fais un tour complet, tout ce qui est dans pb, on le repoussa dans a avec PA.

Et c'est bon, la liste est triée !

### Imprimer le résultat

Il me suffit alors de prendre la combinaison gagnante qui est stockée sous forme de int *.
Et de convertir chaque nombre en sa valeur.
Genre 0 c'est sa, 1 c'est sb, etc...comme dis plus haut.

Et il suffit alors de tout renvoyer

### Note
J'ai fais des fonctions pour calculer la mediane...
Finalement, je n'en ai pas eu besoin.