# Philosophers
Parallel computing, Rigor, Unix

note finale :
113 / 100

C’est l’histoire très connue de sept philosophes.

Comme tous les philsophes, ils se posent des questions. Cette fois-ci, ils se sont mis
en tête de ne prendre leurs repas qu’avec une et une seule baguette par personne. Ils sont
convaincus qu’avec leur esprits habiles ils sauront se partager suffisement rapidement les
baguettes pour ne pas laisser l’un d’entre eux mourir de faim. Le cerveau d’un philosophe
consomme en effet beaucoup de sucre. Ils doivent donc manger très régulièrement pour
ne pas tomber en hypoglycémie.

Si vous n’avez pas réussi à les convaincre de renoncer à leur petit défi, en revanche,
vous avez pu les persuader d’utiliser un simulateur de votre conception plutôt que de
risquer leur santé.

Maintenant, leur survie ne dépend que de vous.
Le simulateur devra répondre au cahier des charges suivants :

• 7 philosophes devront être assis autour d’une table.

• Chaque philosophe possède un thread qui lui est propre.

• À la gauche de chaque philosophe se trouve une baguette (il y a donc 7 baguettes
en tout).

• Un philosophe ne peut se saisir d’une baguette que si elle se trouve adjacente à lui
(droite ou gauche).

• Deux philosophes ne peuvent pas utiliser la même baguette au même moment
(paraît-il pour des raisons d’hygiène).

• Un philosophe passe par 3 étapes :

  ◦ Mange avec les 2 baguettes (droite et gauche).
  ◦ Repos (ne mange pas) et ne détient aucune baguette (même si celle-ci est disponible).
  ◦ Réfléchit, dans ce cas le philosophe a une et une seule baguette en main.
  
• Après l’état repos, un philosophe peut soit manger, soit réfléchir. Si un voisin
réféchit déjà, le philosophe peut acquérir la baguette commune- c’est-à-dire qu’un
philosophe peut se faire prendre la baguette quand il réfléchit.

• Un philosophe qui ne mange pas perd 1 point de vie par SECONDE.

• Après qu’un philosophe ait mangé, il récupère toute sa vie, et passe en Repos.

• Un philosophe dont les points de vie tombent à 0 meurt. À cet instant la simulation
s’interrompt jusqu’à l’appui d’une touche (dont le choix vous appartient). Cet
appui provoque la libération des ressources et l’arrêt complet du progarmme.

• Les philosophes ne doivent pas manger dans un ordre arbitraire si l’on execute
plusieurs fois le programme avec les mêmes paramètres. Ils ne doivent pas manger
dans un ordre précis, pas de scheduler, un philosophe mange dès qu’il peut. Il faut
respecter le caractère aléatoire des threads et faire avec.

• Afin de faciliter la soutenance, vous devrez avoir défini dans votre projet les macros
suivantes :
  ◦ MAX_LIFE : Le nombre de points de vie maximum des philosophes.
  ◦ EAT_T : Le nombre de SECONDES que met un philosophe à manger.
  ◦ REST_T : Le nombre de SECONDES pendant lesquels un philosophe se repose.
  ◦ THINK_T : Le nombre de SECONDES pendant lesquels un philosophe réflé-
chit.
  ◦ TIMEOUT : Le temps en SECONDES après lesquels la simulation s’interrompt
en affichant “Now, it is time... To DAAAAAAAANCE ! ! !” si aucun philosophe
n’est mort de faim (le dîner en cours doit rester visible à lécran pour faire le
bilan). L’appui d’une touche provoque la libération des ressources et l’arrêt
complet du programme.

• Vous devez rendre une interface graphique (mlx, SDL, ncurses, OpenGL, ...) illustrant
clairement ce qui se passe dans le programme.
