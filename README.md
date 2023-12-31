# SE_projet  

Ouaad Maria   
Djitli Anfal    

=================================================================================================================================================================================
Ce projet de système d’exploitation utilise un tableau à deux dimensions pour les matrices A, B et C, et une file d’attente circulaire pour le tampon T. Chaque thread producteur gère une section distincte des matrices B et C, avec des sémaphores assurant un accès protégé et synchronisé aux données partagées. L’implémentation ne présente actuellement pas de risques prévisibles grâce à l’utilisation soignée des sémaphores et des verrous de section critique.
=================================================================================================================================================================================

Q1-->  Nous utilisons un tableau bidimensionnel pour représenter les matrices A, B et C, et une file d’attente circulaire pour représenter le tampon T (BufferQueue et les éléments à l’intérieur comme BufferItem).
=================================================================================================================================================================================

Q2-->  Chaque thread producteur doit traiter une section distincte des matrices B et C. Ainsi, le partage des données se fait en divisant les tâches. Nous utilisons également des sémaphores pour protéger et synchroniser l’accès aux données partagées (matrice résultat et tampon) et verrouiller les sections critiques. Et nous suspendons les threads producteurs lorsque le tampon est plein et les threads consommateurs lorsque le tampon est vide.
=================================================================================================================================================================================

Q3-->  L’implémentation actuelle n’a pas de risques prévisibles, car nous utilisons des sémaphores pour protéger et synchroniser soigneusement l’accès aux données partagées (matrice résultat et tampon) et verrouiller les sections critiques.
=================================================================================================================================================================================
