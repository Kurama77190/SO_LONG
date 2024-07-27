<div align="center">
  <img height="400" src="https://raw.githubusercontent.com/Kurama77190/SO_LONG/main/img/img_make.PNG"  />
</div>
<div align="center">
  <img height="400" src="https://raw.githubusercontent.com/Kurama77190/SO_LONG/main/img/2.PNG"  />
</div>


![Language](https://img.shields.io/badge/language-C-blue)
![Progress](https://img.shields.io/badge/progress-completed-green)

## So_Long - Projet de l'École 42

Bienvenue dans le projet **So_Long**, un jeu 2D inspiré de l'univers de "The Legend of Zelda: The Minish Cap". Ce projet a été réalisé dans le cadre du cursus de l'école 42, et il intègre des concepts de gestion de fenêtres, d'événements, de textures, et de gameplay basique. Ce README vous guidera à travers les fonctionnalités principales du jeu, les parties obligatoires, le parsing des cartes, les animations, et l'inspiration derrière ce projet.

[Gameplay](#Gameplay)

## Table des matières
- [Introduction](#introduction)
- [Objectifs](#objectifs)
- [Fonctionnalités du jeu](#fonctionnalités-du-jeu)
- [Partie obligatoire](#partie-obligatoire)
- [Parsing des cartes](#parsing-des-cartes)
- [Animations](#animations)
- [Inspiration](#inspiration)
- [Installation et utilisation](#installation-et-utilisation)
- [Crédits](#crédits)

## Introduction
So_Long est un jeu 2D dans lequel les joueurs doivent collecter tous les items sur la carte et atteindre la sortie. Ce projet utilise la bibliothèque graphique MiniLibX de l'école 42 pour la gestion des fenêtres, des images et des événements clavier et souris. Le jeu est conçu pour être joué à deux : un joueur incarne le héros et l'autre le monstre.

## Objectifs
Les principaux objectifs de ce projet sont :
- Améliorer les compétences en programmation C.
- Apprendre à utiliser la bibliothèque MiniLibX pour la gestion graphique.
- Implémenter des algorithmes basiques de jeu.
- Assurer une gestion correcte de la mémoire et éviter les fuites.

## Fonctionnalités du jeu
- **Déplacement du joueur** : Utilisation des touches W, A, S, D pour déplacer le personnage principal (le héros) dans les quatre directions.
- **Déplacement du monstre** : Le deuxième joueur utilise les touches fléchées pour contrôler le monstre.
- **Collecte d'items** : Le héros doit collecter tous les items (C) sur la carte.
- **Sortie** : Après avoir collecté tous les items, le héros peut atteindre la sortie (E) pour terminer le niveau.
- **Ennemis et obstacles** : Le monstre contrôlé par le deuxième joueur rend la tâche plus difficile pour le héros.

## Partie obligatoire
Le projet So_Long comporte plusieurs parties obligatoires :
1. **Gestion des fenêtres** : Création et gestion d'une fenêtre à l'aide de MiniLibX.
2. **Affichage des images** : Chargement et affichage de textures pour représenter le joueur, les items, les murs, la sortie, etc.
3. **Détection des collisions** : Assurer que le joueur ne puisse pas traverser les murs.
4. **Système de score** : Compter le nombre de mouvements du joueur et afficher ce score à l'écran.

## Parsing des cartes
Le parsing des cartes est une partie cruciale du projet. Les cartes sont stockées dans des fichiers texte où :
- `1` représente un mur.
- `0` représente une case vide.
- `C` représente un item à collecter.
- `E` représente la sortie.
- `P` représente la position initiale du héros.
- `M` représente la position initiale du monstre.

Un exemple de carte :
```sh
111111
1P0C01
1M00E1
111111
```

## Gameplay
<div align="center">
  <img height="400" src="https://raw.githubusercontent.com/Kurama77190/SO_LONG/main/img/GIF.gif"  />
</div>
<div align="center">
  <img height="400" src="https://raw.githubusercontent.com/Kurama77190/SO_LONG/main/img/GIF2.gif"  />
</div>

Le programme doit vérifier la validité de la carte avant de commencer le jeu :
- La carte doit être rectangulaire.
- Il doit y avoir au moins une sortie (E), un item (C), et un joueur (P).
- La carte doit être entourée de murs (1).

## Animations
Le jeu So_Long intègre des animations pour rendre le jeu plus dynamique :
- **Animations du héros** : Le personnage du héros a des animations pour les déplacements dans les quatre directions.
- **Animations du monstre** : Le personnage du monstre a des animations pour les déplacements.
- **Effets visuels** : Divers effets visuels comme la collecte d'items ou l'ouverture de la sortie.

## Inspiration
Le projet s'inspire fortement de l'univers de "The Legend of Zelda: The Minish Cap". Les éléments graphiques, le style de jeu, et les mécaniques de gameplay rappellent cet univers. Ce projet a été adapté pour être joué à deux, offrant une expérience collaborative où un joueur incarne le héros et l'autre le monstre.

## Installation et utilisation
Pour installer et jouer à So_Long :
1. Clonez le dépôt GitHub : `https://github.com/Kurama77190/SO_LONG.git`
2. Accédez au répertoire du projet : `cd so_long`
3. Compilez le projet : `make`
4. Lancez le jeu avec une carte : `./so_long map_bg.ber`

## Crédits
Projet réalisé par sben-tay dans le cadre du cursus de l'école 42. Inspiré par "The Legend of Zelda: The Minish Cap".


###
