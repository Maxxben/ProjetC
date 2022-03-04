# ProjetC

# Contexte

l’ICS (institue of Cognitives Sciences) est un laboratoire interdisciplinaire qui intègre l'expertise de
chercheurs des Sciences de la Vie (psychologie cognitive, neurosciences) et de médecine (pédopsychiatrie, neuro-pediatrie) avec celle de chercheurs des Sciences Humaines et Sociales.
(linguistique computationelle et théorique et philosophie) pour étudier la nature et la spécificité de 
l'esprit humain.

Le doctorant, qui n’est pas un développeur, a besoin d’accumuler des données expérimentales.

# Prérequis

Pour que l'application fonctionne correctement, nous avons besoin de plusieurs librairies et services :

(Les commandes qui vont suivre sont à executer dans un invite de commandes.)

- Premierement mettez à jour la liste des paquets avec la commande:
  
      sudo apt update

- Installez le compilateur gcc :
  - Mettre a jour le systeme
  
        sudo apt install build-essential
    
- Libconfig :
  - !!!!
  
        sudo apt install libconfig-devel

  - Fedora : 

        sudo yum install libconfig-devel
        
  - Ubuntu :

        sudo apt install libconfig-dev

- Documentation Doxygen :

Installation de Doxygen apt install doxygen / dnf install doxygen
Génération de la documentation make documentation
  
  - !!!!
  
        sudo apt install doxygen
        
  - Fedora :

        sudo yum install doxygen
     
- Ubuntu :

      sudo apt install doxygen


# Installation

Dans un terminal, deplacez vous a l'mplacement de votre choix puis clonez le projet :

     git clone https://github.com/Maxxben/ProjetC.git

Se rendre dans le projet :

    cd ProjetC

Generer les executables :

    make all
    
Generer la documentation doxygen :

     make documentation

# Lancement du programme

Ouvrir 2 terminals, et pour chacuns, se deplacer dans le dossier ProjetC.

 - Dans un terminal 1 executez le serveur :

        ./exec/server

- Dans un terminal 2 executez le client :

        ./exec/client

# Fichiers de configuration

  - Configuration du client :
  
        server_IP = "0.0.0.0";
        server_Port = 7799;
        id_Client = 10;

  - Configuration du serveur :

        server_IP = "0.0.0.0";
        server_Port = 7799;

        room_name = "Chasse & pêche";
        room_start_balance = 5000;
        room_client_1 = 10;
        room_client_2 = 50;
        
        
        
