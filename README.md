# Projet C++ avec Makefile

## Description
Ce projet est un programme C++ structuré avec un Makefile pour faciliter la compilation et l'exécution. Il utilise le compilateur `g++` et prend en charge la gestion automatique des fichiers sources et objets.

## Structure du projet
```
/project
│── src/          # Contient les fichiers source (.cpp)
│── include/      # Contient les fichiers d'en-tête (.h)
│── build/        # Contient les fichiers objets (.o) générés
│── main          # Exécutable généré après compilation
│── Makefile      # Script de compilation
│── README.md     # Documentation du projet
```

## Compilation et Exécution
### Compilation
Utilisez la commande suivante pour compiler le projet :
```sh
make
```
L'exécutable généré s'appellera `main`.

### Exécution
Pour exécuter le programme après compilation :
```sh
make run
```
Ou directement :
```sh
./main
```

### Nettoyage
Pour supprimer les fichiers compilés et l'exécutable :
```sh
make clean
```

## Dépendances
Le projet utilise la bibliothèque X11 et pthread. Assurez-vous qu'elles sont installées sur votre système. Sur Debian/Ubuntu, vous pouvez les installer avec :
```sh
sudo apt-get install libx11-dev
sudo apt-get install libpthread-stubs0-dev
```


