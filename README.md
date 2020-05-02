# Project ORCUS

Bienvenue dans Projet Orcus ! 

## Créateur ##

- Ali MESSELMANI P1811574
- William ESCRIVA P1702268
- Antoine DUMAS P1802788

## Voici les règles du jeu : 

**Vous devez vous échapper d'une île infesté de zombies.** 

Pour cela, vous avez une arme :gun: à disposition dès le début du jeu **(ESPACE pour tirer mais attention cadence de tire faible)**, 
ensuite chercher la clé qui vous permettra de quitter l'île et peut être qu'avant de partir vous aurez l'occasion de tester l'ak47 caché dans la carte sur les zombies. 

Pour se déplacer, utiliser les touches suivantes : 
  ### AZERTY :
    - Z pour avancer 
    - S pour reculer 
    - Q pour tourner à gauche 
    - D pour tourner à droite 

  ### QWERTY :
    - W pour avancer 
    - S pour reculer 
    - A pour tourner à gauche 
    - D pour tourner à droite 

Attention tous de même à ne pas vous faire toucher par les zombies, ce qui ferais chuter votre barre de vie et une fois vide c'est **GAME OVER**. Mais ne vous inquiétez pas !
Des kits de soin sont éparpillés un peu partout sur l'île, il vous redonnerons un peu de santé... 

## Consignes d'installattion ## 

 ### Linux ###

* Décompresser l'archive
* Dans le terminal, placez-vous à la racine du dossier du jeu et taper la commande : 
```
            make 
```
* Taper la commande : 
``` 
            bin/Orcus 
```
Et voila, vous pouvez jouer !

Concernant le documentation, toujour à la racine du dossier :
* taper la commande :
```
doxygen doc/image.docy
```
* Ensuite, taper :
```
cd doc/html 
```
* Pour finir, taper :
```
firefox index.html &
```
Une page web devrait s'ouvrir avec le documentation si vous utilisez **firefox** comme navigateur.

 ### Windows ###

    Le projet ne compile pas encore sur windows...

## Organisation de l'archive ##

Notre archive se décompose en **8 sous-dossiers**, qui sont les suivants : 

- *bin/* : il contient les éxécutables
- *obj/* : il contient les fichiers .o 
- *src/* :  il contient les fichiers .h et .cpp 
- *fonts/* : il contient les polices de caractère
- *Data/* : il contient les ressources de notre jeu (images, sprites, ...)
- *doc/* : il contient tout le documentation doxygen de notre projet
- *projetcTXT/* : il contient le mode texte de notre projet
- *Cahier des charges/* : il contient les cahier des charges du projet ainsi que le diagramme des classes

Et à la racine de l'archive nous avons le **Makefile** et le **readme**   
